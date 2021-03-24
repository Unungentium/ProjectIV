import yoda

aos = yoda.read("LHC100.yoda")

for (key,val) in aos.items() :
    if "RAW" in key or "/_" in key :
        continue
    if type(val)==yoda.core.Histo1D:
		val.scaleW(1./100.)
    if type(val)==yoda.core.Scatter2D:
		val.scaleY(1./100.)


yoda.write(aos,"LHC100.yoda")
