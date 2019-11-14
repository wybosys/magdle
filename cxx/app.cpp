#include "magdle.h"
#include "app.h"

ME_NAMESPACE_BEGIN

static bool loop = true;

int CmdApp::exec() {
    while (loop) {
        int c = getchar();
        switch (c) {
            case 'q':
                goto END;
        }
    }
    END:
    return 0;
}

ME_NAMESPACE_END
