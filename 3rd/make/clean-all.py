#!/usr/bin/env python3

import env
import shutil, os

for e in ["include", "bin", "lib", "share"]:
    if os.path.exists(e):
        shutil.rmtree(e)
