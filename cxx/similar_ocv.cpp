#include "magdle.h"
#include "similar_ocv.h"

ME_NAMESPACE_BEGIN

SimilarOcv::SimilarOcv(Magdle &env)
: env(env)
{
    env.logger.log("实例化基于OpenCV的Similar实现");
}

ME_NAMESPACE_END
