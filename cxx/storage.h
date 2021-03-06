#ifndef _STORAGE_H
#define _STORAGE_H

#include "json.h"

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Storage)

ME_CLASS_PREPARE(CollectionCursor)

// 数据游标
class CollectionCursor {
ME_CLASS_DECL(CollectionCursor)
public:

    explicit CollectionCursor(void *bind = nullptr);

    ~CollectionCursor();

    // 默认代表游历所有数据
    static string const KEY_ALL;

    // 读取一行数据, 返回false代表已经没有数据
    bool next();

    // 当前读取了多少数据
    size_t readed() const;
};

inline string const CollectionCursor::KEY_ALL = "";

class CollectionKeyValuesCursor : public CollectionCursor {
public:
    explicit CollectionKeyValuesCursor(void *bind = nullptr) : CollectionCursor(bind) {}

    // 获得当前数据
    Variant value();
};

// 基于文档的数据集合
class CollectionDocument {
    friend class Storage;

protected:
    explicit CollectionDocument(Storage &, string const &scheme);

public:

    // 插入文档数据
    bool insert(JsonObj const &);

    Storage &storage;
    string const &scheme;
};

// 基于key的数据集合
class CollectionKeyValues {
    friend class Storage;

protected:
    explicit CollectionKeyValues(Storage &, string const &scheme);

public:

    typedef shared_ptr <CollectionKeyValuesCursor> cursor_type;

    // 设置数据
    bool set(string const &key, Variant const &val);

    // 添加数据
    bool insert(string const &key, Variant const &val);

    // 是否存在
    bool exists(string const &key);

    // 获取数据
    Variant get(string const &key);

    // 获得数据游标
    cursor_type cursor(string const &key = CollectionCursor::KEY_ALL);

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

    Magdle &env;

public:

    typedef shared_ptr <CollectionDocument> collection_document_type;
    typedef shared_ptr <CollectionKeyValues> collection_keyvalues_type;

    // 获得文档数据
    collection_document_type document(string const &scheme);

    // 获得KV数据
    collection_keyvalues_type kv(string const &scheme);

};

ME_NAMESPACE_END

#endif