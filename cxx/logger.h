#ifndef _ME_LOGGER_H
#define _ME_LOGGER_H

ME_NAMESPACE_BEGIN

class Logger
{
public:

    void info(string const& msg);
    void warn(string const& msg);
    void log(string const& msg);
    void fatal(string const& msg);
};

ME_NAMESPACE_END

#endif
