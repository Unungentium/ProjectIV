import yoda
aos = yoda.read("LHCtogether.yoda")
aos1 = yoda.read("LHC1p1.yoda")
aos2 = yoda.read("LHC3p0.yoda")
aos3 = yoda.read("LHC3p1.yoda")
aos4 = yoda.read("LHC3p2.yoda")
sum_pT = aos1["/MC_BC/h_pT_1p0"]+aos2["/MC_BC/h_pT_3p0"]+aos3["/MC_BC/h_pT_3p1"]+aos4["/MC_BC/h_pT_3p2"]
sum_pT.setPath("/MC_BC/h_pT_Bc")
aos["MC_BC/h_pT_Bc"]=sum_pT
sum_eta = aos1["/MC_BC/h_rap_1p0"]+aos2["/MC_BC/h_rap_3p0"]+aos3["/MC_BC/h_rap_3p1"]+aos4["/MC_BC/h_rap_3p2"]
sum_eta.setPath("/MC_BC/h_rap_Bc")
aos["MC_BC/h_rap_Bc"]=sum_eta
yoda.write(aos,"LHC_sum_pwave.yoda")
