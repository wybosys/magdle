#ifndef _ME_CONFIG_H
#define _ME_CONFIG_H

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Config)

class Config {
    ME_CLASS_DECL(Config)

public:

    // 工作目录
    filesystem::path workDirectory;

    // 临时目录
    filesystem::path tmpDirectory;

protected:
    void init();
};

ME_NAMESPACE_END

#endif

