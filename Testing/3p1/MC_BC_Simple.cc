// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/DressedLeptons.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/PromptFinalState.hh"

namespace Rivet {


  /// @brief Add a short analysis description here
  class MC_BC_Simple : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(MC_BC_Simple);


    /// @name Analysis methods
    ///@{

    /// Book histograms and initialise projections before the run
    void init() {

      // Initialise and register projections

      declare(FinalState(Cuts::pid==20543),"FS");
      // Book histograms
      book(_h_BC, "h_BC", 50, 0.0, 1.0);

    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      for(const Particle & p : apply<FinalState>(event,"FS").particles()) {
	_h_BC->fill(2.*p.momentum().E()/sqrtS());
      }
    }


    /// Normalise histograms etc., 
    void finalize() {
      scale(_h_BC, 0.5/sumW());

    }

    ///@}


    /// @name Histograms
    ///@{
    Histo1DPtr _h_BC;
    ///@}


  };


  DECLARE_RIVET_PLUGIN(MC_BC_Simple);

}
