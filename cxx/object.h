#ifndef _ME_OBJECT_H
#define _ME_OBJECT_H

#include "boost.h"

ME_NAMESPACE_BEGIN

interface ISerialableObject {

    // 输出
    virtual bool serialize(binary_oarchive &) const = 0;

    // 读入
    virtual bool unserialize(binary_iarchive &) = 0;
};

ME_NAMESPACE_END

#endif
