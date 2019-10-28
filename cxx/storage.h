#ifndef _STORAGE_H
#define _STORAGE_H

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

    // 根据key获得数据
};

ME_NAMESPACE_END

#endif