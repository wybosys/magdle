#ifndef _STORAGE_H
#define _STORAGE_H

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Storage)

class Storage {
    ME_CLASS_DECL(Storage)

protected:
    explicit Storage(Magdle&);
    ~Storage();

    void init();

public:

};

ME_NAMESPACE_END

#endif