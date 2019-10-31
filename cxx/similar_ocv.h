#ifndef _ME_SIMILAR_OCV_H
#define _ME_SIMILAR_OCV_H

#include "similar.h"

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(SimilarOcv);

class SimilarOcv : public ISimilar {
ME_CLASS_DECL(SimilarOcv);

public:
    explicit SimilarOcv(Magdle &);

    ~SimilarOcv();

    void update(DataSetImages const &) override;

    void updateOne(DataSetImageItem const &);

private:
    Magdle &env;
};

ME_NAMESPACE_END

#endif
