BEGIN PLOT /LHCB_2019_I1762092/d01-x01-y01
Title=Ratio of production cross sections $\frac{f_c}{f_u+f_d}$ plotted against $p_\perp$
XLabel=$p_\perp$ [GeV]
YLabel=$\frac{f_c}{f_u+f_d}$ x$10^{-3}$
# + any additional plot settings you might like, see make-plots documentation
LogY=0

#GofLegend=1
#GofFrame=/REF/LHCB_2019_I1762092/d01-x01-y01
#GofReference=/REF/LHCB_2019_I1762092/d01-x01-y01
#GofType=chi2
END PLOT
BEGIN HISTOGRAM /LHCB_2019_I1762092/d01-x01-y01
ErrorBars=1
ConnectGaps=0
ConnectBins=0
END HISTOGRAM 
# ... add more histograms as you need them ...
BEGIN FUNCTION /LHCB_2019_I1762092/d01-x01-y01
LineColor=red
Code=
import numpy as np
x=np.array([5.500000e+00,6.500000e+00,7.500000e+00,8.500000e+00,9.500000e+00,1.150000e+01,1.900000e+01])
y=np.array([2.773723e+00,2.977233e+00,2.920962e+00,3.018868e+00,3.100775e+00,2.297200e+00,1.837456e+00])
m,b=np.polyfit(x,y,1)
a=[]
for x in range(25):
    a.append(m*x+b)
return a
END FUNCTION