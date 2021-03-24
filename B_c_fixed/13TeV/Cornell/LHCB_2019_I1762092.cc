// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/DressedLeptons.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/PromptFinalState.hh"
#include "Rivet/Projections/UnstableParticles.hh"
namespace Rivet {


  /// @brief Add a short analysis description here
  class LHCB_2019_I1762092 : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(LHCB_2019_I1762092);


    /// @name Analysis methods
    ///@{

    /// Book histograms and initialise projections before the run
    void init() {

      declare(UnstableParticles(Cuts::eta<4.5&&Cuts::eta>2.5&&Cuts::pT<25&&Cuts::pT>4), "UFS");
       

      // Book histograms
      book(_h_pT_Bc,"h_pT_Bc" ,refData(1,1,1));
      book(_h_eta_Bc,"h_eta_Bc", refData(2,1,1));
      book(_h_pT_B0,"h_pT_B0", refData(1,1,1));
      book(_h_eta_B0,"h_eta_B0",refData(2,1,1));
      book(_h_pT_ratio, 1,1,1);
      book(_h_eta_ratio, 2,1,1);
      
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


  DECLARE_RIVET_PLUGIN(LHCB_2019_I1762092);

}
