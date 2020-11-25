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

      declare(UnstableParticles(Cuts::eta<4.5&&Cuts::eta>2.5&&Cuts::pT<25&&Cuts::pT>5), "UFS");
       

      // Book histograms
      book(_h_pT_Bc,"h_pT_Bc" ,100,  4.,26.);
      book(_h_eta_Bc,"h_eta_Bc",100,2.,5. );
      book(_h_pT_B0,"h_pT_B0", 100, 4.,26.);
      book(_h_eta_B0,"h_eta_B0",100,2.,5.);
      book(_h_pT_ratio, "h_pT_ratio");
      book(_h_eta_ratio, "h_eta_ratio");
      
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {
      Particles particles = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==541);
      Particles particleBp =  apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==521||Cuts::abspid==511);
      for(auto p : particleBp) {
	if (p.abspid() == 511||p.abspid()==521){
	  _h_pT_B0 ->fill(p.momentum().perp());
	  _h_eta_B0 ->fill(p.momentum().eta());
	}
      }
      for(auto p : particles){
	if (p.abspid() == 541){
	  _h_pT_Bc -> fill(p.momentum().perp());
	  _h_eta_Bc -> fill(p.momentum().eta());
	}

      }
      
    }
    

    /// Normalise histograms etc., after the run
    void finalize() {

      /*scale(_h_pT_Bp, crossSection()/picobarn/sumW());
      scale(_h_eta_Bp, crossSection()/picobarn/sumW());
      */
      scale(_h_pT_B0, crossSection()/picobarn/sumW());
      scale(_h_eta_B0, crossSection()/picobarn/sumW());
      scale(_h_pT_Bc, crossSection()/picobarn/sumW());
      scale(_h_eta_Bc, crossSection()/picobarn/sumW());
      divide(_h_eta_Bc,_h_eta_B0, _h_eta_ratio);
      divide(_h_pT_Bc,_h_pT_B0,_h_pT_ratio);
    }

    ///@} 


    /// @name Histograms
    ///@{
    Histo1DPtr _h_pT_B0,_h_eta_B0, _h_pT_Bc, _h_eta_Bc;
    Scatter2DPtr _h_eta_ratio, _h_pT_ratio;
    ///@}


    };


  DECLARE_RIVET_PLUGIN(MC_BC_comparison);

  }
