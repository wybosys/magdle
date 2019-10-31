#ifndef _ME_TIME_H
#define _ME_TIME_H

ME_NAMESPACE_BEGIN

typedef ulonglong Timestamp;
typedef double Seconds;

// 时间对象
class Time {

public:

    // 获得当前时间戳
    static Timestamp Now();

    // 当前时间
    static Seconds Current();
};

// 计时器
class TimeCost {
public:

    // 开始即时
    void start();

    // 计算消耗
    Seconds cost();

private:

    // 分时记录
    vector<Seconds> _times;
};

ME_NAMESPACE_END

#endif
