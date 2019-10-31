#include "magdle.h"
#include "similar_ocv.h"
#include "ocv.h"

ME_NAMESPACE_BEGIN

// 相似读检测用于保存数据的对象
class SimilarOcvDbObject {
public:

    SimilarOcvDbObject() {
        _obj.set("hist", nullptr);
        _obj.set("version", 0);
    }

private:
    JsonObj _obj;
};

struct SimilarOcvPrivate {

    // 获得单张图的hist
    opencv::Mat calcHist(string const &url) {
        // 读取原始图片
        cv::Mat img = cv::imread(url);

        // 缩放到统一大小
        resize(img, img, cv::Size(128, 128));

        // 自动亮度
        cv::Mat gray;
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
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
        cv::Mat hist;
        vector<cv::Mat> channs;
        split(img, channs);
        cv::calcHist(channs, vector<int>({0, 1, 2}), cv::Mat(), hist, vector<int>({8, 8, 8}), vector<float>({0, 256, 0, 256, 0, 256}));
        normalize(hist, hist, 0, 255, cv::NORM_MINMAX);

        return hist;
    }

    Storage::collection_keyvalues_type db;
};

SimilarOcv::SimilarOcv(Magdle &env)
        : env(env) {
    ME_CLASS_CONSTRUCT()
    env.logger.log("实例化基于OpenCV的Similar实现");
}

SimilarOcv::~SimilarOcv() {
    ME_CLASS_DESTORY()
}

void SimilarOcv::update(DataSetImages const &ds) {
    // 打开数据库
    d_ptr->db = env.storage.kv(scheme);

    // 更新数据集中对应图片数据
    for (auto &each : ds.images) {
        updateOne(*each);
    }
}

void SimilarOcv::updateOne(const DataSetImageItem &item) {
    // 判断是否已经计算过
    if (d_ptr->db->exists(item.url)) {

    } else {

    }

    // 自身比较作为基准
    // const double base = compareHist(hist, hist, HISTCMP_INTERSECT);

}

ME_NAMESPACE_END
