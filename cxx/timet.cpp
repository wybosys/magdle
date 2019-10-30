#include "magdle.h"
#include "timet.h"
#include <c++/9/chrono>

ME_NAMESPACE_BEGIN

Timestamp Time::Now() {
    auto now = chrono::system_clock::now().time_since_epoch();
    return chrono::duration_cast<chrono::seconds>(now).count();
}

ME_NAMESPACE_END
