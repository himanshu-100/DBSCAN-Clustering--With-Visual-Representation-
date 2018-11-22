import numpy as np
import matplotlib.pyplot as plt
x=[]
y=[]
f=open("f17.txt")
plt.plot(x,y,'r.')
for w in f:
    q=w.split()
    x.append(int(q[0]))
    y.append(int(q[1]))
plt.plot(x,y,'r.')
plt.axis([0,15,0,15])
plt.show()
f=open("fd1.txt")
x1=[]
y1=[]
for w in f:
    q=w.split()
    x1.append(int(q[0]))
    y1.append(int(q[1]))
x2=[]
y2=[]
f=open("fd2.txt")
for w in f:
    q=w.split()
    x2.append(int(q[0]))
    y2.append(int(q[1]))
x3=[]
y3=[]
f=open("fd3.txt")
for w in f:
    q=w.split()
    x3.append(int(q[0]))
    y3.append(int(q[1]))
x4=[]
y4=[]
f=open("fd4.txt")
for w in f:
    q=w.split()
    x4.append(int(q[0]))
    y4.append(int(q[1]))
plt.plot(x1,y1,'r.',x2,y2,'y.',x3,y3,'b.',x4,y4,'g.')
plt.axis([0,15,0,15])
plt.show()