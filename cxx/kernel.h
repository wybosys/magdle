#ifndef _ME_KERNEL_H
#define _ME_KERNEL_H

#ifndef interface
#define interface struct
#endif

#define ME_NAMESPACE_BEGIN namespace magle { \
class Magdle;
#define ME_NAMESPACE_END }

#define ME_CLASS_PREPARE(cls) \
class cls; \
class cls##Private;
#define ME_CLASS_DECL(cls) \
private: typedef cls##Private private_class_type; \
private_class_type *d_ptr = nullptr; \
friend class Magdle;

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

#define ME_FRIEND(cls) friend class cls;

#include <c++/9/string>
#include <c++/9/filesystem>
#include <c++/9/algorithm>
#include <c++/9/memory>

ME_NAMESPACE_BEGIN

using namespace ::std;

typedef ::std::filesystem::path path_type;
typedef ::std::byte *bytes;
typedef long long longlong;
typedef unsigned long long ulonglong;

ME_NAMESPACE_END

#include "stringt.h"
#include "variant.h"
#include "timet.h"

#endif
