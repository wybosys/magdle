#ifndef _STORAGE_H
#define _STORAGE_H

#include "json.h"

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Storage)

// 基于文档的数据集合
class CollectionDocument {
    friend class Storage;

protected:
    explicit CollectionDocument(Storage &, string const &scheme);

public:
    Storage &storage;
    string const &scheme;
};

// 基于key的数据集合
class CollectionKeyValues {
    friend class Storage;

protected:
    explicit CollectionKeyValues(Storage &, string const &scheme);

public:

    // 设置数据
    bool set(string const &key, Variant const &val);

    // 获取数据
    Variant get(string const &key);

    Storage &storage;
    string const &scheme;
};

// 数据存储器
class Storage {
ME_CLASS_DECL(Storage)

    friend class CollectionDocument;

    friend class CollectionKeyValues;

protected:
    explicit Storage(Magdle &);

    ~Storage();

    // 初始化数据库
    void init();

public:

    // 获得文档数据
    CollectionDocument &document(string const &scheme);

    // 获得KV数据
    CollectionKeyValues &kv(string const &scheme);

    bool insert(JsonObj const &);

    vector<JsonObj> query(JsonObj const &filter);
};

ME_NAMESPACE_END

#endif