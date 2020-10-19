// -*- C++ -*-
//
// This is the implementation of the non-inlined, non-templated member
// functions of the QtoQBcSplitting class.
//

#include "QtoQBcSplitting.h"
#include "ThePEG/Interface/ClassDocumentation.h"
#include "ThePEG/EventRecord/Particle.h"
#include "ThePEG/Repository/UseRandom.h"
#include "ThePEG/Repository/EventGenerator.h"
#include "ThePEG/Utilities/DescribeClass.h"


#include "ThePEG/Persistency/PersistentOStream.h"
#include "ThePEG/Persistency/PersistentIStream.h"

using namespace Herwig;

QtoQBcSplitting::QtoQBcSplitting() {}

QtoQBcSplitting::~QtoQBcSplitting() {}

IBPtr QtoQBcSplitting::clone() const {
  return new_ptr(*this);
}

IBPtr QtoQBcSplitting::fullclone() const {
  return new_ptr(*this);
}


// If needed, insert default implementations of virtual function defined
// in the InterfacedBase class here (using ThePEG-interfaced-impl in Emacs).


void QtoQBcSplitting::persistentOutput(PersistentOStream & os) const {
  // *** ATTENTION *** os << ; // Add all member variable which should be written persistently here.
}

void QtoQBcSplitting::persistentInput(PersistentIStream & is, int) {
  // *** ATTENTION *** is >> ; // Add all member variable which should be read persistently here.
}


//The following static variable is needed for the type
// description system in ThePEG.
DescribeClass<QtoQBcSplitting,SudakovFormFactor>
  describeHerwigQtoQBcSplitting("Herwig::QtoQBcSplitting", "QtoQBcSplitting.so");

void QtoQBcSplitting::Init() {

  static ClassDocumentation<QtoQBcSplitting> documentation
    ("There is no documentation for the QtoQBcSplitting class");

}

void QtoQBcSplitting::guesstz(Energy2 t1,unsigned int iopt,
			   const IdList &ids,
			   double enhance,bool ident,
			   double detune, 
			   Energy2 &t_main, double &z_main) {
  unsigned int pdfopt = iopt!=1 ? 0 : pdfFactor();
  double lower = integOverP(zLimits().first ,ids,pdfopt);
  double upper = integOverP(zLimits().second,ids,pdfopt);
  // Energy2 pre = 64.*O1_*sqr(Constants::pi)/243./m_;

  // todo prefactor here
  Energy2 pre =(64*Power(Pi,2)*Power(Abs(Subscript(\[Psi],0)(0)),2)/  (27.*M*Power(Subscript(\[Alpha],1),2)* Power(Power(q,2) - Power(M,2)*Power(Subscript(\[Alpha],2),2),2)) ;
  
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
  t_main = t1/(1.-t1/pre*log(r));
  // guess z
  z_main = invIntegOverP(lower + UseRandom::rnd()*(upper - lower),ids,pdfopt);
}
