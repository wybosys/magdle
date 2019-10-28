#include "magdle.h"
#include <sqlite3.h>

ME_NAMESPACE_BEGIN

struct StoragePrivate {
    StoragePrivate(Magdle& env)
    :env(env) {

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

ME_NAMESPACE_END
