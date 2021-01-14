# This Python file uses the following encoding: utf-8
import math,yoda,io, numpy
from collections import OrderedDict
aos=yoda.read("LHC.yoda")


mid=io.open("points_center.dat", mode="r", encoding="utf-8")
upp=io.open("points_top.dat", mode="r", encoding="utf-8")
low=io.open("points_bottom.dat", mode="r", encoding="utf-8")
right=io.open("points_right.dat", mode="r", encoding="utf-8")
# book histo
newHist = yoda.Scatter2D()
newHist.setPath("/MC_BC_comparison/points_reference")
newHist.setAnnotation("IsRef",1)
aos["/MC_BC_comparison/points_reference" ]=newHist
dx=[]
x = []
# read data
l1=mid.readline()
l2=upp.readline()
l3=low.readline()
l4=right.readline()
y=[]
dy=[]
while l1 and l2 and l3 and l4:
	l1=l1.strip().split()
	l2=l2.strip().split()
	l3=l3.strip().split()
	l4=l4.strip().split()
	x.append(float(l1[0]))
	y .append(float(l1[1]))
	dy.append(numpy.sqrt((abs(float(l2[1])-float(l1[1])))**2+float(l1[3])**2))
	dx.append(numpy.sqrt((abs(float(l4[0])-float(l1[0])))**2+float(l1[2])**2))
	l1=mid.readline()
	l2=upp.readline()
	l3=low.readline()
	l4=right.readline()
empty_arr=numpy.zeros(len(y))
for iz in range(0,len(y)): 
	newHist.addPoint(x[iz],y[iz],(dx[iz],dx[iz]),(dy[iz],dy[iz]))
	print(x[iz],y[iz],(dx[iz],dx[iz]),(dy[iz],dy[iz]))

"""for val in aos :
    print val,aos[val]"""
# write the file
yoda.writeYODA(aos,"LHC.yoda")
