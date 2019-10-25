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

Storage* _shared = nullptr;

Storage& Storage::shared() {
    if (_shared == nullptr) {
        _shared = new Storage();
    }
    return *_shared;
}

ME_NAMESPACE_END
