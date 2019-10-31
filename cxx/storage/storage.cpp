#include "magdle.h"

int main() {
    using namespace magle;

    Magdle env;
    env.init();

    auto c = env.storage.kv("test");
    c.set("abc", 123);
    c.insert("time", stringbuilder() << Time::Now());
    env.logger.assert(c.get("abc") == 123, "abc != 123");
    
    auto doc = env.storage.document("nosql");
    doc.insert(JsonObj()("abc", 123));

    TimeCost cost;
    cost.start();
    auto cur = c.cursor();
    while (cur.next()) {
        env.logger.info(cur.get());
    }
    env.logger.info(stringbuilder() << "耗时:" << cost.cost());

    return 0;
}