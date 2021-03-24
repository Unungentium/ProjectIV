# This Python file uses the following encoding: utf-8
import math,yoda,io, numpy
from collections import OrderedDict
aos=OrderedDict()
mid=io.open("points_center.dat", mode="r", encoding="utf-8")
upp=io.open("points_top.dat", mode="r", encoding="utf-8")
low=io.open("points_bottom.dat", mode="r", encoding="utf-8")
right=io.open("points_right.dat", mode="r", encoding="utf-8")
# book histo
newHist = yoda.Scatter2D()
newHist.setPath("/REF/LHCB_2019_I1762092/d01-x01-y01")
newHist.setAnnotation("IsRef",1)
aos["/LHCB_2019_I1762092/d01-x01-y01"]=newHist
dx=[]
x = []
# read data
l1=mid.readline()
l2=upp.readline()
l3=low.readline()
l4=right.readline()
y=[]
dy=[]
bins=[4,5,6,7,8,9,10,13,25]
a=0
while l1 and l2 and l3 and l4:
	l1=l1.strip().split()
	l2=l2.strip().split()
	l3=l3.strip().split()
	l4=l4.strip().split()
	x.append(0.5*(bins[a]+bins[a+1]))
	y .append(float(l1[1]))
	dy.append(numpy.sqrt((abs(float(l2[1])-float(l1[1])))**2+float(l1[3])**2))
	dx.append(0.5*(bins[a+1]-bins[a]))
	a+=1
	l1=mid.readline()
	l2=upp.readline()
	l3=low.readline()
	l4=right.readline()
empty_arr=numpy.zeros(len(y))
for iz in range(0,len(y)): 
	newHist.addPoint(x[iz],y[iz],(dx[iz],dx[iz]),(dy[iz],dy[iz]))
	#print(x[iz],y[iz],(dx[iz],dx[iz]),(dy[iz],dy[iz]))

"""for val in aos :
    print val,aos[val]"""
# write the file
yoda.writeYODA(aos,"LHCB_2019_I1762092.yoda")