#include "magdle.h"
#include "similar.h"
#include "dataset_images.h"

int main() {
    using namespace magle;

    Magdle env;
    env.config.datasetDirectory = "../../dataset";
    env.init();

    Similar prj(env);
    prj.clean();

    DataSetImages images(env);
    images.load(env.config.datasetDirectory);
    prj.update(images);

    return 0;
}