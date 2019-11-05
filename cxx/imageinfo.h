#ifndef _ME_IMAGEINFO_H
#define _ME_IMAGEINFO_H

#include "linear.h"

ME_NAMESPACE_BEGIN

// exif信息
class Exif {
public:

    // 相机信息
    string camera_maker;

    // 相机型号
    string camera_model;

    // 拍摄日期
    Time datetime;

    // 分辨率
    Size<ushort> resolution;

    // 使用闪光灯
    bool flashlight;

    // 焦距
    FixedPoint<3> focallength;

    // 传感器大小
    FixedPoint<3> ccdwidth;

    // 曝光时间
    FixedPoint<3> exposuretime;

    // 光圈大小
    FixedPoint<3> aperture;

    // 焦距
    FixedPoint<3> focusdistance;
};

enum struct ImageFormat {
    UNKNOWN = 0,
    JPEG = 1,
    PNG = 2
};

// 图片信息
class ImageInfo {
public:

    // 路径
    path_type url;

    // 尺寸
    Size<ushort> size;

    // 类型
    ImageFormat format;

    // exif信息
    typedef unique_ptr<Exif> exif_type;
    exif_type exif;
};

ME_NAMESPACE_END

#endif
