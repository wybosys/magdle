#include "magdle.h"
#include <unqlite.h>

ME_NAMESPACE_BEGIN

struct StoragePrivate {
    StoragePrivate(Magdle& env)
    :env(env) {

    }

    ~StoragePrivate() {
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

ME_NAMESPACE_END
