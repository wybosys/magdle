#!/usr/bin/env python3

import env, os

class Sqlite(env.Library):
    def build(self):
        env.Library.build(self)
        os.chdir('sqlite')        
        env.cmd(
            env.CmdStr("./configure --prefix=$PREFIX --disable-static-shell --disable-dependency-tracking --enable-json1 --enable-fts5 --disable-fts4 --disable-fts3")
            .test(env.SHARED, "--enable-shared --disable-static", "--disable-shared --enable-static"))
        env.cmd("make install")        
    def clean(self):
        os.chdir('sqlite')        
        env.cmd("make clean")

if __name__ == "__main__":
    Sqlite().build()
