import yoda
aos = yoda.read("LHCtogether.yoda")
aos1 = yoda.read("LHC1p1.yoda")
aos2 = yoda.read("LHC3p0.yoda")
aos3 = yoda.read("LHC3p1.yoda")
aos4 = yoda.read("LHC3p2.yoda")
sum_pT = aos1["/MC_BC/h_pT"]+aos2["/MC_BC/h_pT"]+aos3["/MC_BC/h_pT"]+aos4["/MC_BC/h_pT"]
sum_pT.SetPath("/MC_BC/h_pT")
aos["MC_BC/h_pT"]=sum_pT
yoda.write(aos,"LHC_sum.yoda")
