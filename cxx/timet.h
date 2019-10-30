#ifndef _ME_TIME_H
#define _ME_TIME_H

ME_NAMESPACE_BEGIN

typedef ulonglong Timestamp;

class Time {

public:
    // 获得当前时间戳
    static Timestamp Now();
};

ME_NAMESPACE_END

#endif
