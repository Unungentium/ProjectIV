BEGIN PLOT /LHCB_2019_I1762092/d01-x01-y01
Title= Ratio of the production cross sections of B_c against B^0 and B^+, against transverse momentum,
XLabel=Transverse momentum $p_\perp$ [GeV]
YLabel=$\frac{f_c}{f_u+f_d}$
# + any additional plot settings you might like, see make-plots documentation
LogY=0
END PLOT
BEGIN HISTOGRAM /LHCB_2019_I1762092/d01-x01-y01
ErrorBars=1
ConnectGaps=0
ConnectBins=0
END HISTOGRAM 
# ... add more histograms as you need them ...
