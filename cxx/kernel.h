#ifndef _ME_KERNEL_H
#define _ME_KERNEL_H

#ifndef interface
#define interface struct
#endif

#define ME_NAMESPACE_BEGIN namespace magle { \
class Magdle;
#define ME_NAMESPACE_END }

#define ME_FRIEND(cls) friend class cls;
#define ME_NOCOPY(cls) private: cls(cls&);
#define ME_PRIVATECLASS(cls) cls##Private

#define ME_CLASS_PREPARE(cls) \
class cls; \
class ME_PRIVATECLASS(cls);

#define ME_CLASS_DECL(cls) \
protected: typedef ME_PRIVATECLASS(cls) private_class_type; \
private_class_type *d_ptr = nullptr; \
friend class Magdle; \
private: ME_NOCOPY(cls);

#define ME_CLASS_CONSTRUCT(...) \
d_ptr = new private_class_type(__VA_ARGS__);
#define ME_CLASS_DESTORY() \
delete d_ptr;

#define ME_SINGLETON_DECL(cls) \
public: static cls& shared();
#define ME_SINGLETON_IMPL(cls) \
static cls* _shared = nullptr; \
cls& cls::shared() { \
if (_shared == nullptr) { \
_shared = new cls(); \
} \
return *_shared; \
}

#define CXX17_INCLUDE(file) <experimental/file>
#define CXX_INCLUDE(file) <file>

#include CXX_INCLUDE(string)
#include CXX_INCLUDE(filesystem)
#include CXX_INCLUDE(algorithm)
#include CXX_INCLUDE(memory)
#include CXX_INCLUDE(iostream)

ME_NAMESPACE_BEGIN

using namespace ::std;

typedef ::std::filesystem::path path_type;
typedef ::std::byte *bytes;
typedef long long longlong;
typedef unsigned long long ulonglong;

ME_NAMESPACE_END

#include "object.h"
#include "threadt.h"
#include "stringt.h"
#include "variant.h"
#include "timet.h"

#endif
