#include "kernel.h"
#include "storage.h"
#include <unqlite.h>

ME_NAMESPACE_BEGIN

struct StoragePrivate {
    StoragePrivate() {

    }

    ~StoragePrivate() {
        unqlite_close(db);
    }

    unqlite *db;
};

Storage::Storage() {
    ME_CLASS_CONSTRUCT
}

Storage::~Storage() {
    ME_CLASS_DESTORY
}

ME_SINGLETON_IMPL(Storage)

ME_NAMESPACE_END
