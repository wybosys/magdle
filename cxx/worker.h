#ifndef _ME_WORKER_H
#define _ME_WORKER_H

#include CXX_INCLUDE(atomic)
#include CXX_INCLUDE(mutex)

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Workers);

class Worker {
    ME_FRIEND(Workers);

public:

    virtual ~Worker() = default;

    // 执行一次
    virtual void once() {}

    // 多次执行
    virtual void loop() {}

    // 执行次数
    atomic_int count = -1;

    // 隶属
    inline Workers &owner() {
        return *_owner;
    }

protected:

    // 启动
    virtual void start() {}

private:
    Workers *_owner = nullptr;
};

class Workers {
ME_CLASS_DECL(Workers);

protected:
    explicit Workers(Magdle &);

    ~Workers();

public:

    typedef unique_ptr <Worker> worker_type;

    Magdle &env;

    // 启动
    bool start(string const &name, worker_type::pointer);
};

#define ME_AUTOLOCK(mtx) lock_guard __al__##__LINE__(mtx);

ME_NAMESPACE_END

#endif

