#include "magdle.h"
#include "logger.h"

ME_NAMESPACE_BEGIN

void Logger::info(const string &msg) const {
    cout << msg << endl;
}

void Logger::warn(std::string const &msg) const {
    cerr << msg << endl;
}

void Logger::log(const string &msg) const {
    clog << msg << endl;
}

void Logger::fatal(const string &msg) const {
    cerr << msg << endl;
    exit(1);
}

ME_NAMESPACE_END
