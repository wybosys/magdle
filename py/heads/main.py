#!/usr/bin/env python3

import os, shutil
import cv2

DIR_SRC = 'dataset'
DIR_RESULT = 'heads/result'
THR = 0.36

if os.path.exists(DIR_RESULT):
    shutil.rmtree(DIR_RESULT)

os.mkdir(DIR_RESULT)

detect = cv2.CascadeClassifier('/usr/share/opencv/haarcascades/haarcascade_frontalface_default.xml')

for each in os.listdir(DIR_SRC):                
    img = cv2.imread(DIR_SRC + '/' + each, cv2.IMREAD_GRAYSCALE)
    faces = detect.detectMultiScale(img, scaleFactor=1.2, minNeighbors=5)
    if len(faces) == 0:
        continue
    # shutil.copyfile(DIR_SRC + '/' + each, DIR_RESULT + '/' + each)
    for (x,y,w,h) in faces:
        img = cv2.rectangle(img, (x,y), (x+w,y+h), (255,0,0), 2)
    cv2.imwrite(DIR_RESULT + '/' + each, img)
