#ifndef _ME_SIMILAR_H
#define _ME_SIMILAR_H

#include "dataset_images.h"

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Similar)

interface ISimilar {
    virtual ~ISimilar() = default;

    // 更新图片基础数据
    virtual void update(DataSetImages const &) = 0;
};

class Similar : public Project, public ISimilar {
ME_CLASS_DECL(Similar)

public:

    explicit Similar(Magdle &env);

    ~Similar() override;

    void update(DataSetImages const &) override;
};

ME_NAMESPACE_END

#endif
