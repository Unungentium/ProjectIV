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
BEGIN PLOT /LHCB_2019_I1762092/d02-x01-y01
Title=Ratio of production cross sections $\frac{f_c}{f_u+f_d}$ plotted against $\eta$
XLabel=$\eta$
YLabel=$\frac{f_c}{f_u+f_d}$ x$10^-3$
END PLOT
BEGIN HISTOGRAM /LHCB_2019_I1762092/d02-x01-y01
ErrorBars=1
ConnectGaps=0
ConnectBins=0
END HISTOGRAM