#!/usr/bin/env python3

import env, os, shutil

class Opencv(env.Library):
    def build(self):
        env.Library.build(self)
        os.chdir('opencv')
        if not os.path.exists('build'):
            os.mkdir('build')
        os.chdir('build')
        env.cmd(
            env.CmdStr("cmake . .. -DCMAKE_INSTALL_PREFIX=$PREFIX -DBUILD_JAVA=NO -DBUILD_TESTS=NO -DBUILD_PERF_TESTS=NO -DBUILD_opencv_python2=NO -DBUILD_opencv_python3=NO -DBUILD_opencv_apps=NO -DBUILD_DOCS=NO -DBUILD_opencv_data=NO -DBUILD_opencv_doc=NO")
            .test(not env.SHARED, "-DBUILD_SHARED_LIBS=NO")
            .test(env.MACOS, "-DWITH_EIGEN=NO")
        )
        env.cmd('make')
        env.cmd('make install')
    def clean(self):
        os.chdir('opencv')        
        if os.path.exists('build'):
            shutil.rmtree('build')

if __name__ == "__main__":
    Opencv().build()
