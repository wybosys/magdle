#include "magdle.h"
#include "sqlite.h"

// 项目中包含的sqlite扩展
extern "C" int sqlite3_json_init(
        sqlite3 *db,
        char **pzErrMsg,
        const sqlite3_api_routines *pApi
);

ME_NAMESPACE_BEGIN
namespace sqlite {

typedef void(*xEntryPoint)();

Sqlite3Environment::Sqlite3Environment() {
    sqlite3_initialize();
    sqlite3_auto_extension((xEntryPoint) sqlite3_json_init);
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
