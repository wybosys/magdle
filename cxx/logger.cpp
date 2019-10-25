#include "magdle.h"
#include "logger.h"
#include <iostream>

ME_NAMESPACE_BEGIN

void Logger::log(const string &msg) {
    cout << msg << endl;
}

ME_NAMESPACE_END
