// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/UnstableParticles.hh"

namespace Rivet {


  /// @brief Simply eta_c analysis
  class MC_BC_comparison : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(MC_BC_comparison);


    /// @name Analysis methods
    ///@{

    /// Book histograms and initialise projections before the run
    void init() {

      declare(UnstableParticles(), "UFS");
      const FinalState fs(Cuts::eta<4.5&&Cuts::eta>2.5&&Cuts::pT<25&&Cuts::pT>5);
     

      // Book histograms
      book(_h_pT_Bc_ ,"_h_pT_Bc_" ,100,  4.,26.);
      book(_h_rap_Bc_,"_h_rap_Bc_",100,2.,5. );
      book(_h_pT_B_ ,"_h_pT_B_", 100, 4.,26.);
      book(_h_rap_B_,"_h_rap_B_",100,2.,5.);
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {
      Particles particles = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==541);
      Particles particleB = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==511&&Cuts::abspid==521&&Cuts::abspid==-521&&Cuts::abspid==-511);

      for(auto p : particles) {
	_h_pT_Bc_ ->fill(p.momentum().perp());
	_h_rap_Bc_ ->fill(p.momentum().rapidity());
      }
      for(auto p1: particleB){
	_h_pT_B_ ->fill(p1.momentum().perp());
	_h_rap_B_ ->fill(p1.momentum().rapidity());


      }
    }
    

    /// Normalise histograms etc., after the run
    void finalize() {

      scale(_h_pT_Bc_, crossSection()/picobarn/sumW());
      scale(_h_rap_Bc_, crossSection()/picobarn/sumW());
      scale(_h_pT_B_, crossSection()/picobarn/sumW());
      scale(_h_rap_B_, crossSection()/picobarn/sumW());

    }

    ///@}


    /// @name Histograms
    ///@{
    Histo1DPtr _h_pT_Bc_,_h_rap_Bc_,_h_pT_B_,_h_rap_B_;
    ///@}


    };


  DECLARE_RIVET_PLUGIN(MC_BC_comparison);

  }
