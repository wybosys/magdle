#ifndef _ME_CONFIG_H
#define _ME_CONFIG_H

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Config)

class Config {
    ME_CLASS_DECL(Config)

public:

    explicit Config(Magdle&);

    // 工作目录
    path_type workDirectory;

    // 临时目录
    path_type tmpDirectory;

    // 数据集目录
    path_type datasetDirectory;

protected:
    void init();

    Magdle& env;
};

ME_NAMESPACE_END

#endif

