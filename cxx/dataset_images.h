#ifndef _ME_DS_IMAGES_H
#define _ME_DS_IMAGES_H

#include "dataset.h"
#include <c++/9/vector>

ME_NAMESPACE_BEGIN

class DataSetImageItem : public DataSetItem
{

};

// 图片数据集
class DataSetImages : public DataSet
{
public:

    void clear() override;

    // 读取目录
    void load(path_type const &directory);

    // 图片源
    vector<DataSetImageItem> images;
};

ME_NAMESPACE_END

#endif
