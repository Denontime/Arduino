'''
Descripttion: Null
version: 1.0
Author: Mar Ping
Date: 2020-11-05 23:33:55
LastEditors: Mar Ping
LastEditTime: 2020-11-06 18:14:37
'''
import tkinter as tk
import tkinter.messagebox
import os

def File():
    with open('list.txt', 'r') as word:
        return word.read()

def connection():
    Tip = 'Connection to ' + List.get(List.curselection()) + ' successful!'
    tkinter.messagebox.showinfo(title='Massage', message=Tip)
    Log.insert("insert", File())

win = tk.Tk()
win.geometry('1000x700+350+50')
win.iconbitmap('Analog.ico')
win.title('Camera focus')
#win.overrideredirect(True)
#win.config(background='#87CEEB')

portlist = tk.StringVar()
portlist.set(('COM1','COM2','COM2','COM4','COM5'))

imgBtn1 = tk.PhotoImage(file='Button1.png')
imgBtn2 = tk.PhotoImage(file='Button2.png')
Label = tk.PhotoImage(file='Label.png')
Chose = tk.PhotoImage(file='Chose.png')

Log = tk.Text(win,
            bd=0,
            #bg='#F0F8FF'
            bg='#87CEEB',
            highlightthickness=5,
            highlightbackground='#AFFEEE',
            highlightcolor='#6495ED')
Log.grid(row=1, column=0, padx=30, pady=0, ipadx=10, ipady=0)

Port = tk.Label(win, image=Label)
Port.grid(row=0, column=1, padx=0, pady=0, ipadx=10, ipady=10)

List = tk.Listbox(win,
                font=('Microsoft YaHei UI', 14),
                bg='#ADD8E6',
                borderwidth=0,
                selectbackground='#1E90FF',
                highlightthickness=5,
                highlightbackground='#AFFEEE',
                highlightcolor='#6495ED',
                selectborderwidth=0,
                relief='flat',
                listvariable=portlist)
List.grid(row=1, column=1, padx=10, pady=0, ipadx=10, ipady=10)

Enter = tk.Button(win,image=Chose, bd=0, command=connection)
Enter.grid(row=2, column=1, padx=10, pady=10, ipadx=10, ipady=10)

Start = tk.Button(win, bd=0, image=imgBtn1)
Start.grid(row=2, column=0, padx=0, pady=0, ipadx=0, ipady=0)

Exit = tk.Button ( win, bd=0,image=imgBtn2, command=win.destroy)
Exit.grid(row=3, column=0, padx=0, pady=0, ipadx=0, ipady=0)

win.mainloop()  # 进入消息循环
