// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/UnstableParticles.hh"

namespace Rivet {


  /// @brief Simply eta_c analysis
  class MC_BC : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(MC_BC);


    /// @name Analysis methods
    ///@{

    /// Book histograms and initialise projections before the run
    void init() {

      declare(UnstableParticles(), "UFS");

      // Book histograms
      book(_h_pT ,"h_pT" ,100,  0.,100.);
      book(_h_rap,"h_rap",100,-10.,10. );

    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {
      Particles particles = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==541);
      for(auto p : particles) {
	_h_pT ->fill(p.momentum().perp()    );
	_h_rap->fill(p.momentum().rapidity());
      }
    }
    //Todo figure out how to analyse for more particles
    /* void analyze(const Event& event) {
      Particles particles = apply<UstableFinalState>(event,"UFS").particles(Cuts::abspid==-541);
      for(auto p : particles) {
	_h_pT ->fill(p.momentum().perp()    );
	_h_rap->fill(p.momentum().rapidity());
      }
    }
    */

    /// Normalise histograms etc., after the run
    void finalize() {

      scale(_h_pT, crossSection()/picobarn/sumW());
      scale(_h_rap, crossSection()/picobarn/sumW());

    }

    ///@}


    /// @name Histograms
    ///@{
    Histo1DPtr _h_pT,_h_rap;
    ///@}


  };


  DECLARE_RIVET_PLUGIN(MC_BC);

}
