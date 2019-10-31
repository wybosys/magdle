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
        if (_mat.empty()) {
            s.write(nullptr, 0);
            return true;
        }

        s << _mat.type() << _mat.rows << _mat.cols;
        s.write(_mat.data, _mat.elemSize() * _mat.total());
        return true;
    }

    bool unserialize(BinaryInput &s) override {

        int rows, cols, type;
        s >> type >> rows >> cols;
        if (rows == 0 || cols == 0) {
            _mat = cv::Mat();
            return true;
        }

        // 创建读取
        _mat.release();
        _mat.create(rows, cols, type);
        s.copyto(_mat.data, _mat.elemSize() * _mat.total());

        return true;
    }

private:
    cv::Mat _mat;
};

}
ME_NAMESPACE_END

#endif
