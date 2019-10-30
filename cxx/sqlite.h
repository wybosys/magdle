#ifndef _ME_SQLITE_H
#define _ME_SQLITE_H

#include <sqlite3.h>

ME_NAMESPACE_BEGIN
namespace sqlite {

class Stmt {
public:

    ~Stmt() {
        sqlite3_finalize(_s);
    }

    inline operator sqlite3_stmt *() {
        return _s;
    }

    inline operator sqlite3_stmt **() {
        return &_s;
    }

private:
    sqlite3_stmt *_s = nullptr;
};

class String {
public:

    ~String() {
        sqlite3_free(_s);
    }

    inline operator char **() {
        return &_s;
    }

    inline operator char const *() const {
        return _s;
    }

    inline operator string() const {
        return _s;
    }

private:
    char *_s = nullptr;
};

}
ME_NAMESPACE_END

#endif

