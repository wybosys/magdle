#include "magdle.h"
#include <sqlite3.h>

ME_NAMESPACE_BEGIN

struct StoragePrivate {

    explicit StoragePrivate(Magdle& env)
    :env(env) {

    }

    ~StoragePrivate() {
        close();
    }

    void open() {
        string dbph = env.config.workDirectory.string() + "/db";
        sqlite3_open(dbph.c_str(), &db);

        // 创建用于kv读写的表
        sqlite3_exec(db, "create table if not exists _kv (d JSON)", NULL, NULL, NULL);
    }

    void close() {
        sqlite3_close(db);
        db = nullptr;
    }

    sqlite3 *db = nullptr;
    Magdle& env;
};

Storage::Storage(Magdle& env) {
    ME_CLASS_CONSTRUCT(env)
}

Storage::~Storage() {
    ME_CLASS_DESTORY()
}

void Storage::init() {
    d_ptr->close();
    d_ptr->open();
}

bool Storage::insert(JsonObj const& obj) {
    string sql = "insert into _kv values('" + ToJson(obj) + "')";
    char* err;
    int s = sqlite3_exec(d_ptr->db, sql.c_str(), NULL, NULL, &err);
    sqlite3_free(err);
    return SQLITE_OK == s;
}

ME_NAMESPACE_END
