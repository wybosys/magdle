#include "magdle.h"
#include "similar_ocv.h"
#include "ocv.h"

ME_NAMESPACE_BEGIN

static const int VERSION = 1;

// 相似读检测用于保存数据的对象
class SimilarOcvDbObject : public ISerialableObject {
public:

    SimilarOcvDbObject() {

    }

    SimilarOcvDbObject(Variant const &r) {

    }

    bool serialize(binary_oarchive &s) const override {
        s << version;
        hist.serialize(s);
        s << base;
        return true;
    }

    bool unserialize(binary_iarchive &s) override {
        s >> version;
        hist.unserialize(s);
        s >> base;
        return true;
    }


    int version = VERSION;
    opencv::Mat hist;
    double base = 0;
};

struct SimilarOcvPrivate {
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
    // 如果已经计算过，而且版本也一致，则跳过
    if (d_ptr->db->exists(item.url)) {
        SimilarOcvDbObject rcd(d_ptr->db->get(item.url));
        if (rcd.version == VERSION)
            return;;
    }

    SimilarOcvDbObject rcd;

    // 读取原始图片
    cv::Mat img = cv::imread(item.url.string());

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
    rcd.hist = hist;

    const double base = compareHist(hist, hist, cv::HISTCMP_INTERSECT);
    rcd.base = base;

    // d_ptr->db->set(item.url, rcd);
}

ME_NAMESPACE_END
