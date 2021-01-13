import yoda

aos = yoda.read("LHC.yoda")

for (key,val) in aos.items() :
    if "RAW" in key or "/_" in key :
        continue
    val.scaleW(1./100.)
yoda.write(aos,"rescale.yoda")
