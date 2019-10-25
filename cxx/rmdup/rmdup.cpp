#include "magdle.h"
#include "similar.h"

int main() {
    magle::Magdle env;
    env.config.datasetDirectory = "../../dataset";
    env.init();

    magle::Similar prj(env);

    return 0;
}