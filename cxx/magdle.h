#ifndef _ME_H
#define _ME_H

#include "kernel.h"
#include "config.h"
#include "storage.h"
#include "logger.h"

ME_NAMESPACE_BEGIN

class Magdle {

public:
    Magdle();
    ~Magdle();

    // 初始化
    void init();

    // 配置对象
    Config config;

    // 存储对象
    Storage storage;

    // 输出日志
    Logger logger;
};

// 用于实现包含的各种识别项目
class Project
{
public:

    Project(Magdle& env): env(env) {}

    Magdle& env;
};

ME_NAMESPACE_END

#endif
