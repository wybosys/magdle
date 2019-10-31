#include "magdle.h"
#include "similar_ocv.h"
#include "ocv.h"

ME_NAMESPACE_BEGIN

SimilarOcv::SimilarOcv(Magdle &env)
        : env(env) {
    env.logger.log("实例化基于OpenCV的Similar实现");
}

void SimilarOcv::update(DataSetImages const &ds) {
    for (auto &each : ds.images) {
        updateOne(*each);
    }
}

void SimilarOcv::updateOne(const DataSetImageItem &item) {
    // 判断是否已经计算过

    // 读取原始图片
    Mat img = imread(item.url.string());

    // 缩放到统一大小
    resize(img, img, cv::Size(128, 128));

    // 自动亮度
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    const double mg = mean(gray)[0];
    const double light = 0.5 * 255 / mg;
    auto f = vector<double>({light, light, light, 1});
    f.resize(img.channels());
    multiply(img, f, img);

    // 自动白平衡
    auto ks = mean(img);
    const double kb = ks[0];
    const double kg = ks[1];
    const double kr = ks[2];
    const double k = kb + kg + kr;
    multiply(img, vector<double>({k / (3 * kb), k / (3 * kg), k / (3 * kr)}), img);

    // 计算直方图
    Mat hist;
    vector<Mat> channs;
    split(img, channs);
    calcHist(channs, vector<int>({0, 1, 2}), Mat(), hist, vector<int>({8, 8, 8}), vector<float>({0, 256, 0, 256, 0, 256}));
    normalize(hist, hist, 0, 255, NORM_MINMAX);

    // 自身比较作为基准
    const double base = compareHist(hist, hist, HISTCMP_INTERSECT);

}

ME_NAMESPACE_END
