import numpy as np
import sys

datafile = input("which datafile?")

arr=np.loadtxt(datafile, dtype = float)
question = input("are we calculating x or y?")
err_altered =[]
	
if question == "y":
	for x in arr:   

			err_altered.append(np.sqrt(x[1]**2+x[3]**2))
elif question == "x":
	for x in arr:
		err_altered.append(np.sqrt(x[0]**2+x[2]**2))

np.savetxt(datafile + question, err_altered)

