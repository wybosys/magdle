#include "magdle.h"
#include "sqlite.h"

ME_NAMESPACE_BEGIN

#define DB storage.d_ptr->db
#define EXEC storage.d_ptr->exec
#define STORAGE storage.d_ptr

struct StoragePrivate {

    explicit StoragePrivate(Magdle &env)
            : env(env) {

    }

    ~StoragePrivate() {
        close();
    }

    void open() {
        string dbph = env.config.workDirectory.string() + "/db";
        sqlite3_open(dbph.c_str(), &db);
    }

    void close() {
        sqlite3_close(db);
        db = nullptr;
    }

    bool scheme_exists(string const &scheme) {
        stringbuilder ss;
        ss << "select count(*) from sqlite_master where name='" << scheme << "' and type='table'";
        int count;
        sqlite3_exec(db, ss, [](void *result, int ret, char **val, char **col) -> int {
            *((int *) result) = atoi(*val);
            return 0;
        }, &count, nullptr);
        return count == 1;
    }

    bool exec(string const &sql) {
        sqlite::String msg;
        int s = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, msg);
        if (s == SQLITE_OK)
            return true;
        env.logger.warn(msg);
        return false;
    }

    sqlite3 *db = nullptr;
    Magdle &env;

    // 已经打开的集合
    map<string, CollectionDocument> documents;
    map<string, CollectionKeyValues> keyvalues;
};

CollectionDocument::CollectionDocument(Storage &s, string const &scheme)
        : storage(s), scheme(scheme) {
    if (!STORAGE->scheme_exists(scheme)) {
        stringbuilder ss;
        ss << "create table " << scheme << " (val JSON, PRIMARY KEY(val));";
        EXEC(ss);
    }
}

bool CollectionDocument::insert(JsonObj const &obj) {
    stringbuilder ss;
    ss << "insert into " << scheme << " values('" << ToJson(obj) << "');";
    return EXEC(ss);
}

CollectionKeyValues::CollectionKeyValues(Storage &s, string const &scheme)
        : storage(s), scheme(scheme) {
    if (!STORAGE->scheme_exists(scheme)) {
        stringbuilder ss;
        ss << "create table " << scheme << " (key VARCHAR(256), val BLOB, typ INT);";
        ss << "create index key on " << scheme << " (key);";
        EXEC(ss);
    }
}

bool CollectionKeyValues::set(std::string const &key, magle::Variant const &val) {
    stringbuilder ss;
    ss << "replace into " << scheme << " (key, val, typ) values (?, ?, ?)";

    sqlite::Stmt s;
    int t = sqlite3_prepare(DB, ss, ss.length(), s, nullptr);
    if (t != SQLITE_OK)
        return false;

    sqlite3_bind_text(s, 1, key.c_str(), key.length(), SQLITE_STATIC);
    sqlite3_bind_blob(s, 2, val.buffer(), val.length(), SQLITE_STATIC);
    sqlite3_bind_int(s, 3, (int) val.type);

    t = sqlite3_step(s);
    return t == SQLITE_DONE;
}

bool CollectionKeyValues::insert(std::string const &key, magle::Variant const &val) {
    stringbuilder ss;
    ss << "insert into " << scheme << " (key, val, typ) values (?, ?, ?)";

    sqlite::Stmt s;
    int t = sqlite3_prepare(DB, ss, ss.length(), s, nullptr);
    if (t != SQLITE_OK)
        return false;

    sqlite3_bind_text(s, 1, key.c_str(), key.length(), SQLITE_STATIC);
    sqlite3_bind_blob(s, 2, val.buffer(), val.length(), SQLITE_STATIC);
    sqlite3_bind_int(s, 3, (int) val.type);

    t = sqlite3_step(s);
    return t == SQLITE_DONE;
}

Variant CollectionKeyValues::get(std::string const &key) {
    stringbuilder ss;
    ss << "select val,typ from " << scheme << " where key=? limit 1";

    sqlite::Stmt s;
    int t = sqlite3_prepare(DB, ss, ss.length(), s, nullptr);
    if (t != SQLITE_OK)
        return false;

    sqlite3_bind_text(s, 1, key.c_str(), key.length(), SQLITE_STATIC);
    t = sqlite3_step(s);
    if (t != SQLITE_ROW) {
        return Variant();
    }

    void const *raw = sqlite3_column_blob(s, 0);
    int len = sqlite3_column_bytes(s, 0);
    int typ = sqlite3_column_int(s, 1);
    return Variant(raw, len, (VariantType) typ);
}

Storage::Storage(Magdle &env) {
    ME_CLASS_CONSTRUCT(env)
}

Storage::~Storage() {
    ME_CLASS_DESTORY()
}

void Storage::init() {
    d_ptr->close();
    d_ptr->open();
}

CollectionDocument &Storage::document(const std::string &scheme) {
    auto fnd = d_ptr->documents.find(scheme);
    if (fnd != d_ptr->documents.end()) {
        return fnd->second;
    }
    auto res = d_ptr->documents.insert(make_pair(scheme, CollectionDocument(*this, scheme)));
    return res.first->second;
}

CollectionKeyValues &Storage::kv(const std::string &scheme) {
    auto fnd = d_ptr->keyvalues.find(scheme);
    if (fnd != d_ptr->keyvalues.end()) {
        return fnd->second;
    }
    auto res = d_ptr->keyvalues.insert(make_pair(scheme, CollectionKeyValues(*this, scheme)));
    return res.first->second;
}

ME_NAMESPACE_END
