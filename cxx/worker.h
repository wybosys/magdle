#ifndef _ME_WORKER_H
#define _ME_WORKER_H

#include CXX_INCLUDE(atomic)
#include CXX_INCLUDE(thread)
#include CXX_INCLUDE(mutex)

ME_NAMESPACE_BEGIN

interface IWorker {

};

class Workers {
public:

    typedef unique_ptr <IWorker> worker_type;
};

ME_NAMESPACE_END

#endif

