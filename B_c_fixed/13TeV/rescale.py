import yoda

aos = yoda.read("LHC_cornell_1.yoda")

for (key,val) in aos.items() :
    if "RAW" in key or "/_" in key :
        continue
    if type(val)==yoda.core.Histo1D:
		val.scaleW(3.)
    if type(val)==yoda.core.Scatter2D:
		val.scaleY(3.)


yoda.write(aos,"LHC_cornell_2.yoda")
