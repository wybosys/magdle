#!/usr/bin/env python3

import os

def detectDirectory():
    cwd = os.getcwd()
    dn = os.path.basename(cwd)
    if dn != '3rd':
        raise '工作目录错误，请进入3rd目录执行 ./make/xxx'
    return cwd

# 编译目录
PREFIX=detectDirectory()
print("prefix: %s" % PREFIX)
