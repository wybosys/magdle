#include "magdle.h"

int main() {
    using namespace magle;

    Magdle env;
    env.init();

    auto c = env.storage.kv("test");

    return 0;
}