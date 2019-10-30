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

}
ME_NAMESPACE_END

#endif

