#ifndef _ME_DATASET_H
#define _ME_DATASET_H

ME_NAMESPACE_BEGIN

class DataSetItem
{

};

class DataSet
{
public:
    DataSet();
    ~DataSet();

    // 清空
    virtual void clear();
};

ME_NAMESPACE_END

#endif
