#include "magdle.h"
#include "similar_ocv.h"

ME_NAMESPACE_BEGIN

SimilarOcv::SimilarOcv(Magdle &env)
: env(env)
{
    env.logger.log("实例化基于OpenCV的Similar实现");
}

void SimilarOcv::update(DataSetImages const& ds) {
    for (auto& each : ds.images) {
        updateOne(*each);
    }
}

void SimilarOcv::updateOne(const DataSetImageItem & item) {
    // 判断是否已经计算过
}

ME_NAMESPACE_END
