import yoda
aos = yoda.read("LHCBcs.yoda")
changePt=aos["/MC_BC/h_pT_Bcs"]
changePt.setPath("/MC_BC/h_pT")
aos["/MC_BC/h_pT"]=changePt
changeEta=aos["/MC_BC/h_rap_Bcs"]
changeEta.setPath("/MC_BC/h_eta")
aos["/MC_BC/h_eta"]=changeEta
yoda.write(aos,"LHCBcs_2.yoda")
