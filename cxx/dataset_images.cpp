#include "magdle.h"
#include "dataset_images.h"
#include <c++/9/regex>
#include <c++/9/iostream>

ME_NAMESPACE_BEGIN

static const regex PAT_IMAGES("\\.(png|jpg|jpeg)$");

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
        cout << iter.path() << endl;
        if (!regex_match(iter.path().string(), PAT_IMAGES, regex_constants::match_any))
            continue;

        auto t = new DataSetImageItem();
        t->url = iter.path();
        images.emplace_back(t);
    }
}

ME_NAMESPACE_END
