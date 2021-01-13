# This Python file uses the following encoding: utf-8
import math,yoda,io
from collections import OrderedDict
aos=yoda.read("LHC.yoda")


mid=io.open("points_center.dat", mode="r", encoding="utf-8")
upp=io.open("points_top.dat", mode="r", encoding="utf-8")
low=io.open("points_bottom.dat", mode="r", encoding="utf-8")
# book histo
newHist = yoda.Scatter2D()
newHist.setPath("/MC_BC_comparison/points_reference")
newHist.setAnnotation("IsRef",1)
aos["/MC_BC_comparison/points_reference" ]=newHist
step=0.155
x = 0.07+0.5*step
# read data
l1=mid.readline()
l2=upp.readline()
l3=low.readline()
y=[]
dy=[]
while l1 and l2 and l3:
	l1=l1.strip().split()
	l2=l2.strip().split()
	l3=l3.strip().split()
	y .append(float(l1[1]))
	dy.append(0.5*abs(float(l2[1])-float(l3[1])))
	l1=mid.readline()
	l2=upp.readline()
	l3=low.readline()
total = sum(y)*step
for iz in range(0,len(y)): 
	newHist.addPoint(x,y[iz]/total,(0.5*step,0.5*step),(dy[iz]/total,dy[iz]/total))
	x+=step

for val in aos :
    print val,aos[val]
# write the file
yoda.writeYODA(aos,"LHC.yoda")
