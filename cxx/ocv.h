#ifndef _ME_OCV_H
#define _ME_OCV_H

#include <opencv2/opencv.hpp>

ME_NAMESPACE_BEGIN

namespace opencv {

class Mat {
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

private:
    cv::Mat _mat;
};

}
ME_NAMESPACE_END

#endif
