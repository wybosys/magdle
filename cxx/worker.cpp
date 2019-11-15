#include "magdle.h"
#include "worker.h"

#include CXX_INCLUDE(thread)

ME_NAMESPACE_BEGIN

void RunWorker(WorkerPrivate *d);

struct WorkerPrivate {
    explicit WorkerPrivate(Worker *d_owner) :
            d_owner(d_owner) {
        // pass
    }

    void main() {
        if (d_owner->count == -1) {
            while (loop) {
                d_owner->main();
            }
        } else {
            for (int i = 0; i < d_owner->count; ++i) {
                d_owner->main();
            }
        }
    }

    bool loop = true;
    Worker *d_owner;
    mutex mtx;
    Workers *_owner = nullptr;
    shared_ptr<thread> t;
};

void RunWorker(WorkerPrivate *d) {
    d->main();
}

Worker::Worker() {
    ME_CLASS_CONSTRUCT(this)
}

Worker::~Worker() {
    ME_CLASS_DESTORY()
}

void Worker::start() {
    d_ptr->t.reset(new thread(RunWorker, d_ptr));
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
