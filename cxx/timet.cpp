#include "magdle.h"
#include "timet.h"
#include CXX_INCLUDE(chrono)
#include CXX_INCLUDE(ctime)
#include CXX_INCLUDE(thread)

ME_NAMESPACE_BEGIN

Time::Time(magle::Timestamp ts) : _ts(ts) {
    // pass
}

Timestamp Time::Now() {
    auto now = chrono::system_clock::now().time_since_epoch();
    return chrono::duration_cast<chrono::seconds>(now).count();
}

Seconds Time::Current() {
    auto now = chrono::system_clock::now().time_since_epoch();
    return chrono::duration_cast<chrono::microseconds>(now).count() / 1000000.;
}

void Time::Sleep(Seconds s) {
    this_thread::sleep_for(chrono::milliseconds(int(s) * 1000));
}

void TimeCost::start() {
    _times.push_back(Time::Current());
}

Seconds TimeCost::cost() {
    Seconds s = _times[0];
    _times.clear();
    Seconds c = Time::Current();
    return c - s;
}

ME_NAMESPACE_END
