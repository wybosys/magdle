#!/usr/bin/env python3

import os, shutil, sys

TGTS = ['perf', 'test', 'samples', 'java', 'python', 'data']

def clean(dir):    
    bn = os.path.basename(dir)
    if bn in TGTS:
        print("remove " + dir)
        shutil.rmtree(dir)
        return
    for each in os.listdir(dir):
        c = dir + '/' + each
        if os.path.isdir(c):
            clean(c)

if len(sys.argv) == 1:
    clean(os.getcwd())
else:
    dir = sys.argv[1]
    if not os.path.isdir(dir):
        raise "wrong target directory"
    clean(dir)
