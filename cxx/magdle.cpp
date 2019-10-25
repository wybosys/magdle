#include "magdle.h"

ME_NAMESPACE_BEGIN

Magdle::Magdle()
: storage(*this) {

}

Magdle::~Magdle() {

}

void Magdle::init() {
    config.init();
    storage.init();
}

ME_NAMESPACE_END
