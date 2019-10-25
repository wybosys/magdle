#include "magdle.h"
#include <unqlite.h>

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
        unqlite_open(&db, dbph.c_str(), UNQLITE_OPEN_CREATE);
    }

    void close() {
        unqlite_close(db);
    }

    unqlite *db = nullptr;
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
