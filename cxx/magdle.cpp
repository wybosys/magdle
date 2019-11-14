#include "magdle.h"

ME_NAMESPACE_BEGIN

Magdle::Magdle()
        : config(*this),
          storage(*this),
          workers(*this) {
    // pass
}

Magdle::~Magdle() {
    // pass
}

void Magdle::init() {
    config.init();
    storage.init();
}

Project::Project(Magdle &env, string const &name)
        : env(env), name(name) {
    if (workDirectory.empty()) {
        workDirectory = env.config.workDirectory.string() + "/" + name;
    }
    if (tmpDirectory.empty()) {
        tmpDirectory = env.config.tmpDirectory.string() + "/" + name;
    }

    if (!filesystem::exists(workDirectory)) {
        filesystem::create_directories(workDirectory);
    }

    if (!filesystem::exists(tmpDirectory)) {
        filesystem::create_directories(tmpDirectory);
    }
}

void Project::clean() {
    for (auto &iter: filesystem::directory_iterator(tmpDirectory)) {
        filesystem::remove_all(iter);
    }
}

ME_NAMESPACE_END
