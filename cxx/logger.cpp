#include "magdle.h"
#include "logger.h"

ME_NAMESPACE_BEGIN

static mutex m;

void Logger::info(const string &msg) const {
    ME_AUTOLOCK(m);
    cout << msg << endl;
}

void Logger::warn(std::string const &msg) const {
    ME_AUTOLOCK(m);
    cerr << msg << endl;
}

void Logger::log(const string &msg) const {
    ME_AUTOLOCK(m);
    clog << msg << endl;
}

void Logger::fatal(const string &msg) const {
    ME_AUTOLOCK(m);
    cerr << msg << endl;
    exit(1);
}

ME_NAMESPACE_END
