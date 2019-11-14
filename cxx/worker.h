#ifndef _ME_WORKER_H
#define _ME_WORKER_H

#include CXX_INCLUDE(atomic)
#include CXX_INCLUDE(mutex)

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Worker);

ME_CLASS_PREPARE(Workers);

class Worker {
    ME_FRIEND(Workers);
ME_CLASS_DECL(Worker);

public:

    Worker();

    virtual ~Worker();

    // 多次执行
    virtual void main() {}

    // 执行次数
    atomic_int count = 1;

    // 隶属
    Workers &owner();

protected:

    // 启动
    virtual void start();
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

#define ME_AUTOLOCK(mtx) lock_guard _ME_COMBINE(__al__, __LINE__)(mtx);

ME_NAMESPACE_END

#endif

