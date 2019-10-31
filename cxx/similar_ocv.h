#ifndef _ME_SIMILAR_OCV_H
#define _ME_SIMILAR_OCV_H

#include "similar.h"

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(SimilarOcv);

class SimilarOcv : public ISimilar {
ME_CLASS_DECL(SimilarOcv);

public:
    explicit SimilarOcv(Magdle &);

    ~SimilarOcv() override;

    // 更新所有
    void update(DataSetImages const &) override;

    // 更新找到的一张图
    void updateOne(DataSetImageItem const &);

    // 数据库名
    string scheme = "similar";

private:
    Magdle &env;
};

ME_NAMESPACE_END

#endif
