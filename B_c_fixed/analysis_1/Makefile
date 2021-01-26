# -*- Makefile -*- (for emacs)
# src/Makefile-UserModules.  Generated from Makefile-UserModules.in by configure.
#
# Herwig devel
#
# This Makefile is intended for compiling Herwig plugins
# You can find example plugins in the Contrib directory
#
# This Makefile received very little testing, 
# any bug reports are very welcome!
#

#
# C++ flags
# 
CXX = /mt/home/fpauwels/Desktop/Herwig_gcc/bin/g++-herwig-8.2.0 -std=c++11

CXXFLAGS = -g -W -Wall -O2 -DBOOST_UBLAS_NDEBUG

# add additional package header directories here
CPPFLAGS = -I/mt/home/fpauwels/Desktop/Herwig_gcc/include -I/mt/home/fpauwels/Desktop/Herwig_gcc/include -I/mt/home/fpauwels/Desktop/Herwig_gcc/include

# add additional libraries here
LDFLAGS = 

ALLCCFILES=$(shell echo *.cc)
all : $(ALLCCFILES:.cc=.so)

%.so : %.cc %.h 
	$(CXX) -shared -fPIC $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $< -o $@  

clean:
	rm -f $(ALLCCFILES:.cc=.so)
