// -*- C++ -*-
//
// This is the implementation of the non-inlined, non-templated member
// functions of the QtoQBcSplitPwave class.
//

#include "QtoQBcSplitPwave.h"
#include "ThePEG/Interface/ClassDocumentation.h"
#include "ThePEG/EventRecord/Particle.h"
#include "ThePEG/Repository/UseRandom.h"
#include "ThePEG/Repository/EventGenerator.h"
#include "ThePEG/Utilities/DescribeClass.h"


#include "ThePEG/Persistency/PersistentOStream.h"
#include "ThePEG/Persistency/PersistentIStream.h"

using namespace Herwig;

QtoQBcSplitPwave::QtoQBcSplitPwave() {}
const double  QtoQBcSplitPwave::v=1.;
QtoQBcSplitPwave::~QtoQBcSplitPwave() {}

IBPtr QtoQBcSplitPwave::clone() const {
  return new_ptr(*this);
}

IBPtr QtoQBcSplitPwave::fullclone() const {
  return new_ptr(*this);
}


// If needed, insert default implementations of virtual function defined
// in the InterfacedBase class here (using ThePEG-interfaced-impl in Emacs).


void QtoQBcSplitPwave::persistentOutput(PersistentOStream & os) const {
  // *** ATTENTION *** os << ; // Add all member variable which should be written persistently here.
}

void QtoQBcSplitPwave::persistentInput(PersistentIStream & is, int) {
  // *** ATTENTION *** is >> ; // Add all member variable which should be read persistently here.
}


//The following static variable is needed for the type
// description system in ThePEG.
DescribeClass<QtoQBcSplitPwave,SudakovFormFactor>
  describeHerwigQtoQBcSplitPwave("Herwig::QtoQBcSplitPwave", "QtoQBcSplitPwave.so");

void QtoQBcSplitPwave::Init() {

  static ClassDocumentation<QtoQBcSplitPwave> documentation
    ("There is no documentation for the QtoQBcSplitPwave class");

}

void QtoQBcSplitPwave::guesstz(Energy2 t1,unsigned int iopt,
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
  Energy3 psi_0= pow<3,1>(0.4*GeV);
  // todo prefactor here
  Energy2 pre =(sqr(Constants::pi)*psi_0)/(27*pow((-1 + a),4)*sqr(a)*M);
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
