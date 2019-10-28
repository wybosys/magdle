#ifndef _STORAGE_H
#define _STORAGE_H

#include "json.h"

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Storage)

class Storage {
    ME_CLASS_DECL(Storage)

protected:
    explicit Storage(Magdle&);
    ~Storage();

    // 初始化数据库
    void init();

public:

    bool insert(JsonObj const&);
};

ME_NAMESPACE_END

#endif