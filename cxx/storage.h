#ifndef _STORAGE_H
#define _STORAGE_H

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Storage)

class Storage {
    ME_CLASS_DECL(Storage)
    ME_SINGLETON_DECL(Storage)

protected:
    Storage();
    ~Storage();
};

ME_NAMESPACE_END

#endif