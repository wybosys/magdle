#include "magdle.h"
#include "similar.h"
#include "dataset_images.h"

int main() {
    using namespace magle;

    Magdle env;
    env.config.datasetDirectory = "../../dataset";
    env.init();

    Similar prj(env);

    DataSetImages images;
    images.load(env.config.datasetDirectory);
    env.logger.info(stringbuilder() << "获得" << images.images.size() << "图片");

    return 0;
}