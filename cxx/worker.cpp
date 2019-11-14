#include "magdle.h"
#include "worker.h"

#include CXX_INCLUDE(thread)

ME_NAMESPACE_BEGIN

void Worker::start() {
    
}

struct WorkersPrivate {
    typedef Workers::worker_type worker_type;
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
    ME_AUTOLOCK(d_ptr->mtx);
    if (d_ptr->workers.end() != d_ptr->workers.find(name)) {
        return false;
    }
    d_ptr->workers.insert(make_pair(name, worker));
    worker->start();
    return true;
}

ME_NAMESPACE_END
