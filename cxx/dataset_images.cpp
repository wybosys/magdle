#include "magdle.h"
#include "dataset_images.h"
#include <c++/9/regex>

ME_NAMESPACE_BEGIN

static const regex PAT_IMAGES("\\.(png|jpg|jpeg)$");

DataSetImages::DataSetImages(Magdle &)
: DataSet(env)
{

}

void DataSetImages::clear() {
    images.clear();
}

void DataSetImages::load(path_type const& directory) {
    clear();

    // 遍历目录，筛选出第一级的图片
    for (auto& iter: filesystem::directory_iterator(directory)) {
        if (!iter.is_regular_file())
            continue;

        // 判断是否是支持的图片
        if (!regex_search(StringT::ToLowerCase(iter.path().string()), PAT_IMAGES))
            continue;

        auto t = new DataSetImageItem();
        t->url = iter.path();
        images.emplace_back(t);
    }

    env.logger.info(stringbuilder() << "获得" << images.size() << "图片");
}

ME_NAMESPACE_END
