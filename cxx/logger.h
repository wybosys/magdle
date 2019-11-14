#ifndef _ME_LOGGER_H
#define _ME_LOGGER_H

ME_NAMESPACE_BEGIN

class Logger {
public:

    void info(string const &msg) const;

    void warn(string const &msg) const;

    void log(string const &msg) const;

    void fatal(string const &msg) const;

    template<typename T>
    void ensure(T const &v, string const &msg) const {
        if (!v) {
            fatal(msg);
        }
    }
};

ME_NAMESPACE_END

#endif
