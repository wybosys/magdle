#ifndef _ME_H
#define _ME_H

#include "kernel.h"
#include "config.h"
#include "storage.h"

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
};

class Project
{
public:

    Project(Magdle& env): env(env) {}

    Magdle& env;
};

ME_NAMESPACE_END

#endif
