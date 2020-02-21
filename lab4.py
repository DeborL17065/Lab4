from tkinter import *
import serial
import time
import sys
import binascii
import wx

#Definición de variables
volt_POT1 = 0.00
volt_POT2 = 0.00
real_POT1 = 0
real_POT2 = 0


#Configuración del Puerto Serial
puerto = 'COM6'
ser = serial.Serial(port = puerto, baudrate = 9600,
                    parity = serial.PARITY_NONE,
                    stopbits = serial.STOPBITS_ONE,
                    bytesize = serial. EIGHTBITS, timeout = 0)


#Configuración de la ventana
ventana = Tk()
ventana.title("Laboratorio 4")
ventana.geometry("670x250")
ventana.config(bg='cadetblue')


#num = int(entrada.get())

#Configuración de los botones
def gra1():
   # print(entrada.get())
    #print(dato)
    
    ser.write(bytes([int(entrada.get())]))
    print(bytes([int(entrada.get())])) #Si se oprime este botón, se envia el dato del contador
    print(ser.read())
    ser.flushOutput()
    time.sleep(.05)
  
    


#Se definen los identificadores de las casillas
pot1 = Label(ventana, text="Potenciometro 1", background = 'pale turquoise', font=('Arial', 15)).place(x=60,y=120)
pot2 = Label(ventana, text="Potenciometro 2", background = 'pale turquoise', font=('Arial', 15)).place(x=400,y=120)
nombre1 = Label(ventana, text="Contador:", background = 'pale turquoise', font=('Arial', 15)).place(x=60,y=40)

#campo de texto

entrada = Entry(width =20)
entrada.grid(row=6,column=1,padx=60,pady=80)
entrada.focus_set()

#txt=Entry(ventana,textvariable =entrada ,font=('Arial', 10),width=20).place(x=60,y=80)


#Se definen los botones
grabar1 = Button(ventana, text ="Enviar", background = 'pale turquoise',font=('Arial', 10),width=10,command=gra1).place(x=250,y=75)


#Se configuran las casillas en donde irá la información
POT_1_1 = Label(ventana,text="V" ,fg="Deep Sky Blue2",font=(18))
POT_1_1.place(x=515,y=170)

POT_2_1 = Label(ventana,text="V" ,fg="Deep Sky Blue2",font=(18))
POT_2_1.place(x=175,y=170)




while True:
    dato = ser.read()
    try:
        if dato == '':
            pass
        else:
            dato_POT1 = ser.read()
            time.sleep(.5)
            dato_POT2 = ser.read()

            real_POT1 = ord(dato_POT1)
            real_POT2 = ord(dato_POT2)

            print(str(real_POT1) + ',' + str(real_POT2))
            ser.flushInput()
            time.sleep(.05)
            
    except:
        print('.')
    volt_POT1 = float((real_POT1)/float (51))
    volt_POT2 = float((real_POT2)/float (51))
    #Se configuran las casillas en donde irá la información
    POT_1 = Label(ventana,text=str(volt_POT1)[0:4] ,fg="Deep Sky Blue2",font=(18))
    POT_1.place(x=460,y=170)

    POT_2 = Label(ventana,text=str(volt_POT2)[0:4] ,fg="Deep Sky Blue2",font=(18))  
    POT_2.place(x=120,y=170)

    
   # voltaje_1.config(text = str(volt_POT1)[0:4])
   # voltaje_2.config(text = str(volt_POT2)[0:4])
    ventana.update_idletasks()
    ventana.update() 
    time.sleep(.2)

ventana.mainloop()
