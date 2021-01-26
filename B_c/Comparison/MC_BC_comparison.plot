#BEGIN HISTOGRAM /MC_BC_comparison/h_pT_ratio

XLabel=$p_\perp$[GeV]
YLabel= $\frac{f_{c}}{f_{u}+f_{d}}$
LogY=0
XMax=15
ErrorBars=1
ConnectGaps=0
ConnectBins=0
#END HISTOGRAM

#BEGIN PLOT /MC_BC_comparison/h_pT_ratio
Title=Production Cross section ratio $\frac{f_{c}}{f_{u}+f_{d}}$ against $p_\perp$
LogY=0
ConnectGaps=0


#END PLOT
#BEGIN HISTOGRAM /MC_BC_comparison/h_eta_ratio
$
XLabel=$\eta$
YLabel= $\frac{f_{c}}{f_{u}+f_{d}}$
LogY=0
ErrorBars=1
ConnectBins=0
ConnectGaps=0
#END HISTOGRAM
#BEGIN PLOT /MC_BC_comparison/h_eta_ratio
LogY=0
Title=Production Cross section ratio $\frac{f_{c}}{f_{u}+f_{d}}$ against $\eta$
ConnectGaps=0

#END PLOT
#BEGIN HISTOGRAM /MC_BC_comparison/points_reference
XLabel = $p_\perp$[GeV]
YLabel=  $\frac{f_{c}}{f_{u}+f_{d}}*10^{-3} $
LogY=0

ErrorBars=1
ConnectGaps=0
ConnectBins=0
#END HISTOGRAM
#BEGIN PLOT /MC_BC_comparison/points_reference
LogY=0
Title = Production Cross section ratio $\frac{f_{c}}{f_{u}+f_{d}}$ against $p_\perp, reference$
ConnectGaps=0

YMin=2
#END PLOT

#BEGIN PLOT /MC_BC_comparison/h_eta_B0
Title= Total number of $B^0$ and $B^{+}$ particles present in the simulation against $\eta$
LogY=0
YLabel = Number of particles
XLabel=$\eta$
#END PLOT
#BEGIN HISTOGRAM /MC_BC_comparison/h_eta_B0
ErrorBars=1
ConnectBins=0
#END HISTOGRAM
#BEGIN PLOT /MC_BC_comparison/h_pT_B0
Title=Total number of $B^0$ and $B^{+}$ particles present in the simulation against $p_\perp$
LogY=0
YLabel = Number of Particles
XLabel=$p_\perp$ [GeV]
#END PLOT
#BEGIN HISTOGRAM /MC_BC_comparison/h_pT_B0
ErrorBars=1
ConnectBins=0
#END HISTOGRAM