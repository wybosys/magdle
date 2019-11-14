#include "magdle.h"
#include "app.h"

int main() {
    using namespace magle;

    class TestWorker : public Worker {
    public:
        TestWorker() {
            this->count = -1;
        }
        void main() override {
            owner().env.logger.info("worker");
            Time::Sleep(1);
        }
    };

    Magdle env;
    env.init();

    auto c = env.storage.kv("test");
    c->set("123", 123);
    c->insert("time", stringbuilder() << Time::Now());
    env.logger.ensure(c->get("123") == 123, "123 != 123");

    auto doc = env.storage.document("nosql");
    doc->insert(JsonObj()("123", 123));

    TimeCost cost;
    cost.start();
    auto cur = c->cursor();
    while (cur->next()) {
        env.logger.info(cur->value());
    }
    env.logger.info(stringbuilder() << "耗时:" << cost.cost() << " 读取:" << cur->readed());

    env.workers.start("test", new TestWorker());

    return CmdApp().exec();
}