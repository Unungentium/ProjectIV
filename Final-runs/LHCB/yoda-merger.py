import yoda

aos = yoda.read("LHC_LHCB_fixedspin_2.yoda")
ratio_pT = aos["/LHCB_2019_I1762092/h_pT_Bc"]/aos["/LHCB_2019_I1762092/h_pT_B0"]
ratio_pT.setPath("/LHCB_2019_I1762092/d01-x01-y01")
aos["/LHCB_2019_I1762092/d01-x01-y01"] = ratio_pT
ratio_eta = aos["/LHCB_2019_I1762092/h_eta_Bc"]/aos["/LHCB_2019_I1762092/h_eta_B0"]
ratio_eta.setPath("/LHCB_2019_I1762092/d02-x01-y01")
aos["/LHCB_2019_I1762092/d02-x01-y01"] = ratio_eta
yoda.write(aos,"LHC_LHCB_fixedspin_2_output.yoda")

