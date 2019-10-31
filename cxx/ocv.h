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

    bool serialize(binary_oarchive &s) const override {
        // s << ::boost::serialization::make_array(_mat.ptr(), _mat.size);
        return true;
    }

    bool unserialize(binary_iarchive &s) override {
        return true;
    }

private:
    cv::Mat _mat;
};

}
ME_NAMESPACE_END

#endif
