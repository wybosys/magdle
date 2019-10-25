#include "magdle.h"
#include "dataset_images.h"

ME_NAMESPACE_BEGIN

void DataSetImages::clear() {
    images.clear();
}

void DataSetImages::load(path_type const& directory) {
    clear();
}

ME_NAMESPACE_END
