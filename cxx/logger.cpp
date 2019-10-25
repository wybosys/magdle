#include "magdle.h"
#include "logger.h"
#include <iostream>

ME_NAMESPACE_BEGIN

void Logger::info(const string &msg) {
    cout << msg << endl;
}

void Logger::log(const string &msg) {
    clog << msg << endl;
}

void Logger::fatal(const string &msg) {
    cerr << msg << endl;
    exit(1);
}

ME_NAMESPACE_END
