#include "magdle.h"
#include "similar.h"
#include "similar_ocv.h"

ME_NAMESPACE_BEGIN

struct SimilarPrivate
{
    SimilarPrivate() {
    }

    ~SimilarPrivate() {

    }

    unique_ptr<ISimilar> impl;
};

Similar::Similar(magle::Magdle &env)
: Project(env)
{
    ME_CLASS_CONSTRUCT()

    // 根据运行环境选择使用的实现类
    d_ptr->impl = make_unique<SimilarOcv>(env);
}

Similar::~Similar() {
    ME_CLASS_DESTORY()
}

void Similar::update(DataSetImages const& ds) {
    d_ptr->impl->update(ds);
}

ME_NAMESPACE_END

