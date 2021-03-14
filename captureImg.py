import cv2
import sys
import time
import datetime
import os
from os import listdir

def lst_write(lst):
    w_file = open("./saved_images.txt", "w")
    for i in lst:
        w_file.write(i+"\n")
    w_file.close()


def set_py_flag():
    w_file = open("./py_flag.txt", "w")
    w_file.write("1")
    w_file.close()

def release_py_flag():
    w_file = open("./py_flag.txt", "w")
    w_file.write("0")
    w_file.close()

def cpp_flag():
    r_file = open("./cpp_flag.txt")
    c = r_file.read()
    r_file.close()
    if ( c == "1" ):
        return 1
    elif ( c == "0"):
        return 0
    else:
        return -1

que = listdir("./images/")

for i in que:
    os.remove("./images/"+i)

que = []

while (True):
    set_py_flag()
    print("Taking pic : ")
    time.sleep(2)
    webcam = cv2.VideoCapture(0)
    str_img_name = str(datetime.datetime.now())
    img_name = str_img_name.split(".")[0]
    filePath = "./images/" + img_name + ".jpg"
    if(len(que) == 9):
        os.remove("./images/"+que[-1]+".jpg")
        que.pop()
    que.insert(0, img_name)
    lst_write(que)
    check, frame = webcam.read()
    cv2.imwrite(filename=filePath, img=frame)
    webcam.release()
    time.sleep(1)
    release_py_flag()
    while(cpp_flag() == 1):
        time.sleep(0)

