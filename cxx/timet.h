#ifndef _ME_TIME_H
#define _ME_TIME_H

ME_NAMESPACE_BEGIN

typedef ulonglong Timestamp;
typedef double Seconds;

// 时间对象
class Time {

public:

    Time(Timestamp ts = 0);

    // 获得当前时间戳
    static Timestamp Now();

    // 当前时间
    static Seconds Current();

    // 获得时间戳
    inline Timestamp timestamp() const {
        return _ts;
    }

    // 暂停
    static void Sleep(Seconds);

private:
    Timestamp _ts;
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
    vector <Seconds> _times;
};

ME_NAMESPACE_END

#endif
