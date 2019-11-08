#include "magdle.h"
#include "sqlite.h"

#define SQLITE_FULLPACKAGE

// 项目中包含的sqlite扩展
#ifndef SQLITE_FULLPACKAGE
extern "C" int sqlite3_json_init(
        sqlite3 *db,
        char **pzErrMsg,
        const sqlite3_api_routines *pApi
);
#endif

ME_NAMESPACE_BEGIN
namespace sqlite {

typedef void(*xEntryPoint)();

Sqlite3Environment::Sqlite3Environment() {
    sqlite3_initialize();
#ifndef SQLITE_FULLPACKAGE
    sqlite3_auto_extension((xEntryPoint) sqlite3_json_init);
#endif
}

Sqlite3Environment::~Sqlite3Environment() {
    sqlite3_shutdown();
}

Sqlite3Environment __sqlite3_environment;

void Sqlite3Environment::Init() {
    __sqlite3_environment.init();
}

void Sqlite3Environment::init() {
    // pass
}

}
ME_NAMESPACE_END
