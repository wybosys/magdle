#!/usr/bin/env python3

import os, shutil, shelve
import cv2

DIR_SRC = 'dataset'
DIR_RESULT = 'rmdup/result'
THR = 0.6

if os.path.exists(DIR_RESULT):
    shutil.rmtree(DIR_RESULT)

os.mkdir(DIR_RESULT)
DB = shelve.open('rmdup/result/db')
HISTS = []# if 'hists' not in DB else DB['hists']

for each in os.listdir(DIR_SRC):                
    img = cv2.imread(DIR_SRC + '/' + each)
    # 缩放
    img = cv2.resize(img, (128, 128))
    # 自动亮度    
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)    
    mg = cv2.mean(gray)[0]
    light = 0.5 * 255 / mg
    img = cv2.multiply(img, (light, light, light, 1))
    # 自动白平衡
    kb = cv2.mean(img[0])[0]
    kg = cv2.mean(img[1])[0]
    kr = cv2.mean(img[2])[0] 
    k = kb + kg + kr   
    img = cv2.multiply(img, (k/(3*kb), k/(3*kg), k/(3*kr), 1))
    # cv2.imwrite(DIR_RESULT + '/p_' + each, img) 
    # 计算直方图
    hist = cv2.calcHist(img, [0, 1, 2], None, [8, 8, 8], [0, 256, 0, 256, 0, 256])
    hist = cv2.normalize(hist, hist, 0, 255, cv2.NORM_MINMAX).flatten()
    # 自身比较作为基准
    base = cv2.compareHist(hist, hist, cv2.HISTCMP_INTERSECT)        
    skip = False
    for old in HISTS:
        # 和其他图比较
        res = cv2.compareHist(hist, old, cv2.HISTCMP_INTERSECT)                
        if res > 0:
            # 计算和基准比较的相似度用于过滤
            cmp = min(res, base) / max(res, base)            
            # print(cmp)
            if cmp > THR:
                skip = True
                break
    if skip:
        continue
    shutil.copyfile(DIR_SRC + '/' + each, DIR_RESULT + '/' + each)
    HISTS.append(hist)

DB['hists'] = HISTS