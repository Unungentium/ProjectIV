import yoda

aos1 = yoda.read("LHC_sum.yoda")
aos = yoda.read("LHC_sum_pwave.yoda")
ratio_pT = aos1["/MC_BC/h_pT_Bc"]-aos["/MC_BC/h_pT_Bc"]
ratio_pT.setPath("/MC_BC/h_pT")
aos["/MC_BC/h_pT"] = ratio_pT

yoda.write(aos,"LHC_difference.yoda")

