#!/usr/bin/env python3

import env, os, shutil

class Jsoncpp(env.Library):
    def build(self):
        env.Library.build(self)
        os.chdir('jsoncpp')
        if not os.path.exists('build'):
            os.mkdir('build')
        os.chdir('build')
        env.cmd("cmake . .. -DCMAKE_INSTALL_PREFIX=$PREFIX -DJSONCPP_WITH_TESTS=no")
        env.cmd("make")
        env.cmd("make install")
    def clean(self):
        os.chdir('jsoncpp')        
        if os.path.exists('build'):
            shutil.rmtree('build')

if __name__ == "__main__":
    Jsoncpp().build()
