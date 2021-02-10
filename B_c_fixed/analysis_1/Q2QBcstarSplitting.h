// -*- C++ -*-
#ifndef Herwig_Q2QBcstarSplitting_H
#define Herwig_Q2QBcstarSplitting_H
//
// This is the declaration of the Q2QBcstarSplitting class.
//

#include "Herwig/Shower/QTilde/SplittingFunctions/SudakovFormFactor.h"
#include "Herwig/Shower/ShowerHandler.h"
#include "Herwig/Decay/TwoBodyDecayMatrixElement.h"

namespace Herwig {

using namespace ThePEG;

/**
 * Here is the documentation of the Q2QBcstarSplitting class.
 *
 * @see \ref Q2QBcstarSplittingInterfaces "The interfaces"
 * defined for Q2QBcstarSplitting.
 */
class Q2QBcstarSplitting: public SudakovFormFactor {

public:

  /** @name Standard constructors and destructors. */
  //@{
  /**
   * The default constructor.
   */
  Q2QBcstarSplitting();

  /**
   * The destructor.
   */
  virtual ~Q2QBcstarSplitting();
  //@}
  
public:

  /**
   *  Concrete implementation of the method to determine whether this splitting
   *  function can be used for a given set of particles.
   *  @param ids The PDG codes for the particles in the splitting.
   */
  bool accept(const IdList & ids) const {
    // // three particles
    // if(ids.size()!=3) return false;
    // // incoming and outgoing quark the same
    // if(ids[0]!=ids[1]) return false;
    // // its a 1S0 state
    // if(ids[2]->id()%100000 == ids[0]->id()*110+1)
    //   return true;
    // return false;
    return true;
  }
  
  /**
   *   Methods to return the splitting function.
   */
  //@{
  /**
   * Value of the energy fraction and value of the scale for the veto algorithm
   * @param iopt The option for calculating z
   * @param ids The PDG codes of the particles in the splitting
   * - 0 is final-state
   * - 1 is initial-state for the hard process
   * - 2 is initial-state for particle decays
   * @param t1 The starting value of the scale
   * @param enhance The radiation enhancement factor
   * @param identical Whether or not the outgoing particles are identical
   * @param t_main rerurns the value of the energy fraction for the veto algorithm
   * @param z_main returns the value of the scale for the veto algorithm
   */
  virtual void guesstz(Energy2 t1,unsigned int iopt, const IdList &ids,
		       double enhance,bool ident,
		       double detune, Energy2 &t_main, double &z_main);
  
  /**
   * The concrete implementation of the splitting function, \f$P(z,t)\f$.
   * @param z   The energy fraction.
   * @param t   The scale.
   * @param ids The PDG codes for the particles in the splitting.
   * @param mass Whether or not to include the mass dependent terms
   * @param rho The spin density matrix
   */
  double P(const double z, const Energy2 t,
	   const IdList &ids , const bool, const RhoDMatrix &) const {
    //cout << "i am printing";
    Energy M = ids[0]->mass()+ids[1]->mass();
    double a = ids[0]->mass()/M;
    return (12*(-1 + a)*a*sqr(sqr(M)))/sqr(t) + 
      (sqr(M)*(6 + a*(-4 + 4*(1 - z) - 3*sqr(1 - z)) - 9*(1 - z) + 
	       2*sqr(a)*(1 - z)*(3 - z)))/
      ((-(t)*(-1 + a*(1 - z)))) + 
      ((1 - 2*(-1 + a)*(1 - z) + (3 - 2*a + sqr(a))*sqr(1 - z))*z)/
      sqr(-1 + a*(1 - z));
  }
  /**
   * The concrete implementation of the overestimate of the splitting function,
   * \f$P_{\rm over}\f$.
   * @param z   The energy fraction.
   * @param ids The PDG codes for the particles in the splitting.
   */
  double overestimateP(const double z, const IdList &ids) const {
    /*float v = 10000;*/
    cout << "this is happening";
    
    return v/(z*(1-pow(z,2)));
    
  }
  
  /**
   * The concrete implementation of the
   * the ratio of the splitting function to the overestimate, i.e.
   * \f$P(z,t)/P_{\rm over}(z)\f$.
   * @param z   The energy fraction.
   * @param t   The scale.
   * @param ids The PDG codes for the particles in the splitting.
   * @param mass Whether or not to include the mass dependent terms
   * @param rho The spin density matrix
   */
  double ratioP(const double z, const Energy2 t,
		const IdList &ids , const bool, const RhoDMatrix &) const {
    Energy M = ids[0]->mass()+ids[1]->mass();
    double count = 0;
    double a = ids[0]->mass()/M;
    double x=((z*(1 - pow(z,2)))/v)*(((12*(-1 + a)*a*sqr(sqr(M))))/sqr(t) - ((-1 + z)*(1 - 2*(-1 + a)*z + (3 - 2*a + sqr(a))*sqr(z)))/(sqr(-1 + a*z)) + 
				     (sqr(M)*(6 - 9*z + 2*sqr(a)*z*(2 + z) + a*(-4 + 4*z - 3*sqr(z))))/(t*(-1 + a*z)));
    if (x>1){ cout << "something " << x<<endl;
    }
    
    return x;
  }
  
  /**
   * The concrete implementation of the indefinite integral of the 
   * overestimated splitting function, \f$P_{\rm over}\f$.
   * @param z   The energy fraction.
   * @param ids The PDG codes for the particles in the splitting.
   * @param PDFfactor Which additional factor to include for the PDF
   *                  0 is no additional factor,
   *                  1 is \f$1/z\f$, 2 is \f$1/(1-z)\f$ and 3 is \f$1/z/(1-z)\f$
   */
  double integOverP(const double z, const IdList & ,
		    unsigned int PDFfactor=0) const {
    // cout << "integ over P \n";
    return v*(log(z)-0.5*log(1-pow(z,2)));
  }

  /**
   * The concrete implementation of the inverse of the indefinite integral.
   * @param r Value of the splitting function to be inverted
   * @param ids The PDG codes for the particles in the splitting.
   * @param PDFfactor Which additional factor to include for the PDF
   *                  0 is no additional factor,
   *                  1 is \f$1/z\f$, 2 is \f$1/(1-z)\f$ and 3 is \f$1/z/(1-z)\f$
   */ 
  double invIntegOverP(const double r, const IdList & ,
		       unsigned int PDFfactor=0) const {
    // cout << "inverse integ \n";
    assert(PDFfactor==0);
    return exp(r/v)/pow(1+exp(2*r/v),0.5);
  }
  //@}

  /**
   * Method to calculate the azimuthal angle for forward evolution
   * @param z The energy fraction
   * @param t The scale \f$t=2p_j\cdot p_k\f$.
   * @param ids The PDG codes for the particles in the splitting.
   * @param The azimuthal angle, \f$\phi\f$.
   * @return The weight
   */
  vector<pair<int,Complex> >
  generatePhiForward(const double , const Energy2 , const IdList &,
		     const RhoDMatrix & ) {
    // no dependence on the spin density matrix, dependence on off-diagonal terms cancels
    // and rest = splitting function for Tr(rho)=1 as required by defn
    return {{ {0, 1.} }};
  }

  /**
   * Method to calculate the azimuthal angle for backward evolution
   * @param z The energy fraction
   * @param t The scale \f$t=2p_j\cdot p_k\f$.
   * @param ids The PDG codes for the particles in the splitting.
   * @param The azimuthal angle, \f$\phi\f$.
   * @return The weight
   */
  vector<pair<int,Complex> >
  generatePhiBackward(const double , const Energy2, const IdList &,
		      const RhoDMatrix & ) {
    // no dependence on the spin density matrix, dependence on off-diagonal terms cancels
    // and rest = splitting function for Tr(rho)=1 as required by defn
    return {{ {0, 1.} }};
  }
  
  
  /**
   * Calculate the matrix element for the splitting
   * @param z The energy fractionx
   * @param t The scale \f$t=2p_j\cdot p_k\f$.
   * @param ids The PDG codes for the particles in the splitting.
   * @param The azimuthal angle, \f$\phi\f$.
   */
  DecayMEPtr matrixElement(const double z, const Energy2 t, 
			   const IdList &, const double phi, bool) {
    // calculate the kernal
    DecayMEPtr kernal(new_ptr(TwoBodyDecayMatrixElement(PDT::Spin1Half,
    							PDT::Spin1Half,
    							PDT::Spin1)));
    (*kernal)(0,0,0) = 1.;
    (*kernal)(1,1,0) = 1.;
    (*kernal)(0,1,0) = 1.;
    (*kernal)(1,0,0) = 1.;
    (*kernal)(0,0,1) = 1.;
    (*kernal)(1,1,1) = 1.;
    (*kernal)(0,1,1) = 1.;
    (*kernal)(1,0,1) = 1.;
    (*kernal)(0,0,2) = 1.;
    (*kernal)(1,1,2) = 1.;
    (*kernal)(0,1,2) = 1.;
    (*kernal)(1,0,2) = 1.;
    return kernal;
  }
  
public:

  /** @name Functions used by the persistent I/O system. */
  //@{
  /**
   * Function used to write out object persistently.
   * @param os the persistent output stream written to.
   */
  void persistentOutput(PersistentOStream & os) const;

  /**
   * Function used to read in object persistently.
   * @param is the persistent input stream read from.
   * @param version the version number of the object when written.
   */
  void persistentInput(PersistentIStream & is, int version);
  //@}

  /**
   * The standard Init function used to initialize the interfaces.
   * Called exactly once for each class by the class description system
   * before the main function starts or
   * when this class is dynamically loaded.
   */
  static void Init();

protected:

  /** @name Clone Methods. */
  //@{
  /**
   * Make a simple clone of this object.
   * @return a pointer to the new object.
   */
  virtual IBPtr clone() const;

  /** Make a clone of this object, possibly modifying the cloned object
   * to make it sane.
   * @return a pointer to the new object.
   */
  virtual IBPtr fullclone() const;
  //@}

private:
  static const double v;

  /**
   * The assignment operator is private and must never be called.
   * In fact, it should not even be implemented.
   */
  Q2QBcstarSplitting & operator=(const Q2QBcstarSplitting &);

};

}

#endif /* Herwig_Q2QBcstarSplitting_H */