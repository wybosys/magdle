#include "magdle.h"

int main() {
    using namespace magle;

    Magdle env;
    env.init();

    auto c = env.storage.kv("test");
    c.set("abc", 123);
    env.logger.assert(c.get("abc") == 123, "abc != 123");

    return 0;
}