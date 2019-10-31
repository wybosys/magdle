#ifndef _ME_OCV_H
#define _ME_OCV_H

#include <opencv2/opencv.hpp>

ME_NAMESPACE_BEGIN

namespace opencv {

class Mat : public ISerialableObject {
public:

    Mat() {
        // pass
    }

    Mat(cv::Mat const &r) : _mat(r) {
        // pass
    }

    inline operator cv::Mat &() {
        return _mat;
    }

    inline operator cv::Mat const &() const {
        return _mat;
    }

    bool serialize(BinaryOutput &s) const override {
        cv::FileStorage fs("mat.yaml", cv::FileStorage::WRITE_BASE64 | cv::FileStorage::MEMORY);
        fs << "mat" << _mat;
        cv::String str = fs.releaseAndGetString();

        Variant v;
        v.refto(str.begin(), str.length());
        s << v;

        return true;
    }

    bool unserialize(BinaryInput &s) override {
        Variant v;
        s >> v;

        cv::FileStorage fs(cv::String((char const *)v, v.length()), cv::FileStorage::MEMORY);
        fs["mat"] >> _mat;

        return true;
    }

private:
    cv::Mat _mat;
};

}
ME_NAMESPACE_END

#endif
