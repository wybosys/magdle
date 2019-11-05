#ifndef _ME_LINEAR_H
#define _ME_LINEAR_H

ME_NAMESPACE_BEGIN

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
