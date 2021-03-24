// -*- C++ -*-
//
// This is the implementation of the non-inlined, non-templated member
// functions of the QtoQBcSplit1p1 class.
//

#include "QtoQBcSplit1p1.h"
#include "ThePEG/Interface/ClassDocumentation.h"
#include "ThePEG/EventRecord/Particle.h"
#include "ThePEG/Repository/UseRandom.h"
#include "ThePEG/Repository/EventGenerator.h"
#include "ThePEG/Utilities/DescribeClass.h"


#include "ThePEG/Persistency/PersistentOStream.h"
#include "ThePEG/Persistency/PersistentIStream.h"

using namespace Herwig;

QtoQBcSplit1p1::QtoQBcSplit1p1() {}
const double  QtoQBcSplit1p1::v=10.;
QtoQBcSplit1p1::~QtoQBcSplit1p1() {}

IBPtr QtoQBcSplit1p1::clone() const {
  return new_ptr(*this);
}

IBPtr QtoQBcSplit1p1::fullclone() const {
  return new_ptr(*this);
}


// If needed, insert default implementations of virtual function defined
// in the InterfacedBase class here (using ThePEG-interfaced-impl in Emacs).


void QtoQBcSplit1p1::persistentOutput(PersistentOStream & os) const {
  // *** ATTENTION *** os << ; // Add all member variable which should be written persistently here.
}

void QtoQBcSplit1p1::persistentInput(PersistentIStream & is, int) {
  // *** ATTENTION *** is >> ; // Add all member variable which should be read persistently here.
}


//The following static variable is needed for the type
// description system in ThePEG.
DescribeClass<QtoQBcSplit1p1,SudakovFormFactor>
  describeHerwigQtoQBcSplit1p1("Herwig::QtoQBcSplit1p1", "QtoQBcSplit1p1.so");

void QtoQBcSplit1p1::Init() {

  static ClassDocumentation<QtoQBcSplit1p1> documentation
    ("There is no documentation for the QtoQBcSplit1p1 class");

}

void QtoQBcSplit1p1::guesstz(Energy2 t1,unsigned int iopt,
			   const IdList &ids,
			   double enhance,bool ident,
			   double detune, 
			   Energy2 &t_main, double &z_main) {
  Energy M = ids[0]->mass()+ids[1]->mass();
  double a = ids[1]->mass()/M;
  unsigned int pdfopt = iopt!=1 ? 0 : pdfFactor();
  double lower = integOverP(zLimits().first ,ids,pdfopt);
  double upper = integOverP(zLimits().second,ids,pdfopt);
  // Energy2 pre = 64.*O1_*sqr(Constants::pi)/243./m_;
  Energy5 psi_0= pow<5,1>(0.807*GeV);
  // todo prefactor here
  Energy2 pre =16*(sqr(Constants::pi)*psi_0)/(27*pow((-1 + a),4)*sqr(a)*pow<3,1>(M));
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