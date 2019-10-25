#ifndef _ME_SIMILAR_OCV_H
#define _ME_SIMILAR_OCV_H

#include "similar.h"

ME_NAMESPACE_BEGIN

class SimilarOcv: public ISimilar
{
public:
    explicit SimilarOcv(Magdle&);

    void update(DataSetImages const&) override;
    void updateOne(DataSetImageItem const&);

private:
    Magdle& env;
};

ME_NAMESPACE_END

#endif
