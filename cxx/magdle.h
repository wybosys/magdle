#ifndef _ME_H
#define _ME_H

#include "kernel.h"
#include "config.h"
#include "storage.h"
#include "logger.h"
#include "json.h"
#include "worker.h"

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

    // 子工作
    Workers workers;
};

// 用于实现包含的各种识别项目
class Project {
public:

    explicit Project(Magdle &, string const &);

    // 清理
    void clean();

    // 项目名称
    string name;

    // 执行环境
    Magdle &env;

    // 当前的工作目录
    path_type workDirectory;

    // 当前的工作的临时目录
    path_type tmpDirectory;
};

ME_NAMESPACE_END

#endif
