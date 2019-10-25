#ifndef _ME_KERNEL_H
#define _ME_KERNEL_H

#define ME_NAMESPACE_BEGIN namespace magle {
#define ME_NAMESPACE_END }

#define ME_CLASS_PREPARE(cls) class cls##Private;
#define ME_CLASS_DECL(cls) \
private: typedef cls##Private private_class_type; \
private_class_type *d_ptr;

#define ME_CLASS_CONSTRUCT \
d_ptr = new private_class_type();
#define ME_CLASS_DESTORY \
delete d_ptr;

ME_NAMESPACE_BEGIN

ME_NAMESPACE_END

#endif
