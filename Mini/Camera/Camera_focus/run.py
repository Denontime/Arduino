from final_ui import camera_Open,camera_Close,takePhoto,returnName
from rw import *
import tkinter
import tkinter.messagebox

'''
Descripttion: Null
version: 1.0
Author: Mar Ping
Date: 2020-10-24 17:21:28
LastEditors: Mar Ping
LastEditTime: 2020-11-01 13:50:15

from final_ui import camera_Open
from final_ui import takePhoto
from final_ui import camera_Close
from final_ui import listDir
from final_ui import returnName
'''

port_rec = {
    "ok": "OK\r\n".encode(),
    "end": "END\r\n".encode()
}

def start():
    cap = camera_Open()
    port = open_serial("COM3")

    while(port.readline() != port_rec["ok"]):
        stepper_init(port)  # 初始化
    i = 1
    while (i):
        takePhoto(cap, i)
        stepper_turn(port)
        time.sleep(0.2)
        if (port.readline() == "END\r\n".encode()):
            break
        i = i + 1

    while(port.readline() != "OK\r\n".encode()):
        stepper_init(port)  # 初始化

    name = int(returnName()[0:-4]) + 1
    print(name)
    for times in range(1,name):
        stepper_turn(port)
        time.sleep(0.5)
        while (port.readline() == ''):
            pass

    camera_Close(cap)
    port_close(port)



'''
path='./images/'   #the path of the photo
list_name=[]    #list of file paths
listDir(path,list_name)
pro_name=os.listdir(path)    #list of all file names


with open('./list.txt','w') as f:   # export list_name to list.txt
    write=''
    filelengh=0    #number of statistical files
    for i in list_name:
        write=write+str(i)+'\n'
        filelengh=filelengh+1
    f.write(write)
'''
# returnName()

top = tkinter.Tk()
B = tkinter.Button(top,text="开始", command=start)
B.pack()
top.mainloop()
