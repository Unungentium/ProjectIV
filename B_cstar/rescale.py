import yoda

aos = yoda.read("EE.yoda")

for (key,val) in aos.items() :
    if "RAW" in key or "/_" in key :
        continue
    val.scaleW(1000.)
yoda.write(aos,"rescale.yoda")
