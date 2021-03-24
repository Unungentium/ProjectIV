// -*- C++ -*-
//
// This is the implementation of the non-inlined, non-templated member
// functions of the QtoQBcSplitting class.
//

#include "Q2QBcstarSplitting.h"
#include "ThePEG/Interface/ClassDocumentation.h"
#include "ThePEG/EventRecord/Particle.h"
#include "ThePEG/Repository/UseRandom.h"
#include "ThePEG/Repository/EventGenerator.h"
#include "ThePEG/Utilities/DescribeClass.h"


#include "ThePEG/Persistency/PersistentOStream.h"
#include "ThePEG/Persistency/PersistentIStream.h"

using namespace Herwig;

Q2QBcstarSplitting::Q2QBcstarSplitting() {}
const double  Q2QBcstarSplitting::v=1.;
Q2QBcstarSplitting::~Q2QBcstarSplitting() {}

IBPtr Q2QBcstarSplitting::clone() const {
  return new_ptr(*this);
}

IBPtr Q2QBcstarSplitting::fullclone() const {
  return new_ptr(*this);
}


// If needed, insert default implementations of virtual function defined
// in the InterfacedBase class here (using ThePEG-interfaced-impl in Emacs).


void Q2QBcstarSplitting::persistentOutput(PersistentOStream & os) const {
  // *** ATTENTION *** os << ; // Add all member variable which should be written persistently here.
}

void Q2QBcstarSplitting::persistentInput(PersistentIStream & is, int) {
  // *** ATTENTION *** is >> ; // Add all member variable which should be read persistently here.
}


//The following static variable is needed for the type
// description system in ThePEG.
DescribeClass<Q2QBcstarSplitting,SudakovFormFactor>
  describeHerwigQ2QBcstarSplitting("Herwig::Q2QBcstarSplitting", "Q2QBcstarSplitting.so");

void Q2QBcstarSplitting::Init() {

  static ClassDocumentation<Q2QBcstarSplitting> documentation
    ("There is no documentation for the Q2QBcstarSplitting class");

}

void Q2QBcstarSplitting::guesstz(Energy2 t1,unsigned int iopt,
			   const IdList &ids,
			   double enhance,bool ident,
			   double detune, 
			   Energy2 &t_main, double &z_main) {
  Energy M = ids[0]->mass()+ids[1]->mass();
  double a = ids[0]->mass()/M;
  unsigned int pdfopt = iopt!=1 ? 0 : pdfFactor();
  double lower = integOverP(zLimits().first ,ids,pdfopt);
  double upper = integOverP(zLimits().second,ids,pdfopt);
  // Energy2 pre = 64.*O1_*sqr(Constants::pi)/243./m_;
  Energy3 psi_0= pow<3,1>(0.917*GeV);
  // todo prefactor here
  Energy2 pre =(64*sqr(Constants::pi)*psi_0)/(27.*sqr(-1 + a)*M);
  //Here: test if this part of the code is executing properly
  // cout << "something is happening";
  Energy2 c = (upper - lower) * colourFactor() * pre *
    sqr(alpha()->overestimateValue()/Constants::twopi) * enhance * detune;
  double r = UseRandom::rnd();
  assert(iopt<=2);
  if(iopt==1) {
    c *= pdfMax();
    //symmetry of FS gluon splitting
    if(ident) c*= 2;
  }
  else if(iopt==2) c*=-1.;
  // guess t
  t_main = t1/(1.-t1/c*log(r));
  // guess z
  z_main = invIntegOverP(lower + UseRandom::rnd()*(upper - lower),ids,pdfopt);
}
