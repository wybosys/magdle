#!/usr/bin/env python3

import os, shutil
import cv2

DIR_SRC = 'dataset'
DIR_RESULT = 'rmdup/result'
THR = 0.36

if os.path.exists(DIR_RESULT):
    shutil.rmtree(DIR_RESULT)

os.mkdir(DIR_RESULT)

for each in os.listdir(DIR_SRC):                
    img = cv2.imread(DIR_SRC + '/' + each)
    # 缩放
    img = cv2.resize(img, (128, 128))
    # 自动亮度
    cv2.imwrite(DIR_RESULT + '/.tmp.jpg', img)
    gray = cv2.imread(DIR_RESULT + '/.tmp.jpg', cv2.IMREAD_GRAYSCALE)    
    mg = cv2.mean(gray)[0]
    light = 0.6 * 255 / mg
    img = cv2.multiply(img, (light, light, light, 1))
    # 自动白平衡
    kb = cv2.mean(img[0])[0]
    kg = cv2.mean(img[1])[0]
    kr = cv2.mean(img[2])[0] 
    k = kb + kg + kr   
    img = cv2.multiply(img, (k/(3*kb), k/(3*kg), k/(3*kr), 1))
    # 计算直方图
    hist = cv2.calcHist(img, [0, 1, 2], None, [8, 8, 8], [0, 256, 0, 256, 0, 256])
    hist = cv2.normalize(hist, hist, 0, 255, cv2.NORM_MINMAX).flatten()
    # 自身比较作为基准
    base = cv2.compareHist(hist, hist, cv2.HISTCMP_INTERSECT)        
    skip = False
    for old in HISTS:
        # 和其他图比较
        res = cv2.compareHist(hist, old[1], cv2.HISTCMP_INTERSECT)                
        if res > 0:
            # 计算和基准比较的相似度用于过滤
            cmp = min(res / base, base / res)            
            if cmp > THR:
                skip = True
                break
    if skip:
        continue
    shutil.copyfile(DIR_SRC + '/' + each, DIR_RESULT + '/' + each)
    # cv2.imwrite(DIR_RESULT + '/' + each, img) 
    HISTS.append((base, hist))
