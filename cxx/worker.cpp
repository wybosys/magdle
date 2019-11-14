#include "magdle.h"
#include "worker.h"

#include CXX_INCLUDE(thread)

ME_NAMESPACE_BEGIN

void DoMain() {

}

struct WorkerPrivate {
    WorkerPrivate() : t(DoMain) {
        // pass
    }

    mutex mtx;
    Workers *_owner = nullptr;
    thread t;
};

Worker::Worker() {
    ME_CLASS_CONSTRUCT()
}

Worker::~Worker() {
    ME_CLASS_DESTORY()
}

void Worker::start() {

}

Workers &Worker::owner() {
    return *d_ptr->_owner;
}

struct WorkersPrivate {
    map<string, Workers::worker_type> workers;
    mutex mtx;
};

Workers::Workers(Magdle &env) : env(env) {
    ME_CLASS_CONSTRUCT()
}

Workers::~Workers() {
    ME_CLASS_DESTORY()
}

bool Workers::start(string const &name, Workers::worker_type::pointer worker) {
    ME_AUTOLOCK(worker->d_ptr->mtx);
    if (worker->d_ptr->_owner) {
        return false;
    }

    ME_AUTOLOCK(d_ptr->mtx);
    if (d_ptr->workers.end() != d_ptr->workers.find(name)) {
        return false;
    }

    d_ptr->workers.insert(make_pair(name, worker));
    worker->d_ptr->_owner = this;

    worker->start();
    return true;
}

ME_NAMESPACE_END
