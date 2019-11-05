#ifndef _ME_LINEAR_H
#define _ME_LINEAR_H

ME_NAMESPACE_BEGIN

template<int LEN, typename T=int>
class FixedPoint {
    typedef FixedPoint self_type;
    static const T FACTOR = 1 << (LEN - 1);

public:

    FixedPoint() : _m(0) {
        // pass
    }

    explicit FixedPoint(real d) : _m(d * FACTOR) {
        // pass
    }

    inline self_type &operator+=(self_type const &x) {
        _m += x._m;
        return *this;
    }

    inline self_type &operator-=(self_type const &x) {
        _m -= x._m;
        return *this;
    }

    inline self_type &operator*=(self_type const &x) {
        _m *= x._m;
        _m >>= LEN;
        return *this;
    }

    inline self_type &operator/=(self_type const &x) {
        _m /= x._m;
        _m *= FACTOR;
        return *this;
    }

    inline self_type &operator*=(T x) {
        _m *= x;
        return *this;
    }

    inline self_type &operator/=(T x) {
        _m /= x;
        return *this;
    }

    inline self_type operator-() {
        return self_type(-_m);
    }

    inline operator real() const {
        return real(_m) / FACTOR;
    }

    inline operator T() const {
        return _m;
    }

    // 设置原始数据
    inline self_type &setReal(real d) {
        _m = d * FACTOR;
        return *this;
    }

private:
    T _m;

    friend inline self_type operator+(self_type x, self_type const &y) {
        return x += y;
    }

    friend inline self_type operator-(self_type x, self_type const &y) {
        return x -= y;
    }

    friend inline self_type operator*(self_type x, self_type const &y) {
        return x *= y;
    }

    friend inline self_type operator/(self_type x, self_type const &y) {
        return x /= y;
    }

    friend inline bool operator==(self_type const &x, self_type const &y) {
        return x.m == y.m;
    }

    friend inline bool operator!=(self_type const &x, self_type const &y) {
        return x.m != y.m;
    }

    friend inline bool operator>(self_type const &x, self_type const &y) {
        return x.m > y.m;
    }

    friend inline bool operator<(self_type const &x, self_type const &y) {
        return x.m < y.m;
    }

    friend inline bool operator>=(self_type const &x, self_type const &y) {
        return x.m >= y.m;
    }

    friend inline bool operator<=(self_type const &x, self_type const &y) {
        return x.m <= y.m;
    }
};

template<typename T>
class Point {
public:

    Point(T x = 0, T y = 0)
            : x(x), y(y) {}

    T x, y;
};

template<typename T>
class Size {
public:
    Size(T w = 0, T h = 0)
            : w(w), h(h) {}

    T w, h;
};

template<typename T>
class Rect : public Point<T>, public Size<T> {
public:
};

ME_NAMESPACE_END

#endif
