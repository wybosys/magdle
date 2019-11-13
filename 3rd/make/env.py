#!/usr/bin/env python3

import os, sys, platform

def detectDirectory():
    cwd = os.getcwd()
    dn = os.path.basename(cwd)
    if dn != '3rd':
        raise '工作目录错误，请进入3rd目录执行 ./make/xxx'
    return cwd

def detectSystem():
    sys = platform.system()
    macos = sys == 'Darwin'
    win = sys == 'Windows'
    linux = sys == 'Linux'
    return (macos, win, linux)

def detectIsShared():
    return True

# 判断系统类型
(MACOS, WIN, LINUX) = detectSystem()

# 编译目录
PREFIX=detectDirectory()
# print("prefix: %s" % PREFIX)

# 判断类库类型
SHARED=detectIsShared()

from string import Template

# 拼接命令
class CmdStr:
    def __init__(self, str = ""):
        self._buf = str
    def __str__(self):
        return self._buf
    def test(self, t, str, elstr = None):
        if t:
            if str:
                self._buf += ' ' + str
        elif elstr:
            self._buf += ' ' + elstr
        return self

# 执行命令
def cmd(fmt, args = {}):
    if 'PREFIX' not in args:
        args['PREFIX'] = PREFIX
    t = Template(str(fmt))
    s = t.substitute(args)
    print(s)
    os.system(s)

# 类库接口
class Library:
    def build(self):
        print("编译 %s" % self.__class__.__name__)
        # 切换到工作目录
        os.chdir(PREFIX)
    def clean(self):
        os.chdir(PREFIX)
        print("清空 %s" % self.__class__.__name__)
