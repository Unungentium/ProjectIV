#BEGIN HISTOGRAM /MC_BC_comparison/h_pT_ratio
Title=Production Cross section ratio $\frac{f_{c}}{f_{u}+f_{d}}$ against $p_\perp$
XLabel=$p_\perp$[GeV]
YLabel= $\frac{f_{c}}{f_{u}+f_{d}}$
LogY=0
XMax=15
ErrorBars=1
ConnectGaps=0
ConnectBins=0
#END HISTOGRAM

#BEGIN PLOT /MC_BC_comparison/h_pT_ratio
LogY=0
ConnectGaps=0
XMax=15

#END PLOT
#BEGIN HISTOGRAM /MC_BC_comparison/h_eta_ratio
Title=Production Cross section ratio $\frac{f_{c}}{f_{u}+f_{d}}$ against $\eta$
XLabel=$\eta$
YLabel= $\frac{f_{c}}{f_{u}+f_{d}}$
LogY=0
ErrorBars=1
ConnectBins=0
ConnectGaps=0
#END HISTOGRAM
#BEGIN PLOT /MC_BC_comparison/h_eta_ratio
LogY=0
ConnectGaps=0

#END PLOT
#BEGIN HISTOGRAM /MC_BC_comparison/points_reference
Title = Production Cross section ratio $\frac{f_{c}}{f_{u}+f_{d}}$ against $p_\perp$
XLabel = $p_\perp$[GeV]
YLabel=  $\frac{f_{c}}{f_{u}+f_{d}}*10^{-3} $
LogY=0

ErrorBars=1
ConnectGaps=0
ConnectBins=0
#END HISTOGRAM
#BEGIN PLOT /MC_BC_comparison/points_reference
LogY=0
ConnectGaps=0
XMax=15
YMin=2
#END PLOT