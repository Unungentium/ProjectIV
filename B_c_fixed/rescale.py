import yoda

aos = yoda.read("LHC.yoda")

for (key,val) in aos.items() :
    if "RAW" in key or "/_" in key :
        continue
    if type(val)==yoda.core.Histo1D:
		val.scaleW(1./100.)
    if type(val)==yoda.core.Scatter2D:
		continue


yoda.write(aos,"rescale.yoda")
