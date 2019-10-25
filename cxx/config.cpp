#include "magdle.h"
#include "config.h"

ME_NAMESPACE_BEGIN

Config::Config(Magdle &env)
: env(env) {

}

void Config::init() {
    // 获得当前工作目录
    auto cwd = filesystem::current_path();

    // 默认为当前目录
    if (workDirectory.empty()) {
        workDirectory = cwd.string() + "/magdle";
    }

    if (tmpDirectory.empty()) {
        tmpDirectory = workDirectory.string() + "/tmp";
    }

    // 保证目录存在
    if (!filesystem::exists(workDirectory)) {
        filesystem::create_directories(workDirectory);
    }

    if (!filesystem::exists(tmpDirectory)) {
        filesystem::create_directories(tmpDirectory);
    }

    if (!datasetDirectory.empty() && !filesystem::exists(datasetDirectory)) {
        env.logger.fatal("没有找到数据集目录");
    }
}

ME_NAMESPACE_END

