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
      book(_h_pT_1p1 ,"h_pT_1p1" ,100,  0.,30.);
      book(_h_rap_1p1,"h_rap_1p1",100,-10.,10. );
      book(_h_pT_3p0 ,"h_pT_3p0" ,100,  0.,30.);
      book(_h_rap_3p0,"h_rap_3p0",100,-10.,10. );  
      book(_h_pT_3p1 ,"h_pT_3p1" ,100,  0.,30.);
      book(_h_rap_3p1,"h_rap_3p1",100,-10.,10. );
      book(_h_pT_3p2 ,"h_pT_3p2" ,100,  0.,30.);
      book(_h_rap_3p2,"h_rap_3p2",100,-10.,10. );
      book(_h_pT_1s0 ,"h_pT_1s0" ,100,  0.,30.);
      book(_h_rap_1s0,"h_rap_1s0",100,-10.,10. );
      book(_h_pT_3s1 ,"h_pT_3s1" ,100,  0.,30.);
      book(_h_rap_3s1,"h_rap_3s1",100,-10.,10. );


    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {
      Particles particles_1p1 = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==10543);
      for(auto p : particles_1p1) {
	_h_pT_1p1 ->fill(p.momentum().perp()    );
	_h_rap_1p1->fill(p.momentum().rapidity());
      }
      Particles particles_3p0 = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==10541);
      for(auto p : particles_3p0) {
	_h_pT_3p0 ->fill(p.momentum().perp()    );
	_h_rap_3p0->fill(p.momentum().rapidity());
      }
      Particles particles_3p1 = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==20543);
      for(auto p : particles_3p1) {
	_h_pT_3p1 ->fill(p.momentum().perp()    );
	_h_rap_3p1->fill(p.momentum().rapidity());
      }
      Particles particles_3p2 = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==545);
      for(auto p : particles_3p2) {
	_h_pT_3p2 ->fill(p.momentum().perp()    );
	_h_rap_3p2->fill(p.momentum().rapidity());
      }
      Particles particles_1s0 = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==541);
      for(auto p : particles_1s0) {
	_h_pT_1s0 ->fill(p.momentum().perp()    );
	_h_rap_1s0->fill(p.momentum().rapidity());
      }
      Particles particles_3s1 = apply<UnstableFinalState>(event,"UFS").particles(Cuts::abspid==543);
      for(auto p : particles_3s1) {
	_h_pT_3s1 ->fill(p.momentum().perp()    );
	_h_rap_3s1->fill(p.momentum().rapidity());
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

      scale(_h_pT_1p1, crossSection()/picobarn/sumW());
      scale(_h_rap_1p1, crossSection()/picobarn/sumW());
      scale(_h_pT_3p0, crossSection()/picobarn/sumW());
      scale(_h_rap_3p0, crossSection()/picobarn/sumW());
      scale(_h_pT_3p1, crossSection()/picobarn/sumW());
      scale(_h_rap_3p1, crossSection()/picobarn/sumW());
      scale(_h_pT_3p2, crossSection()/picobarn/sumW());
      scale(_h_rap_3p2, crossSection()/picobarn/sumW());
      scale(_h_pT_1s0, crossSection()/picobarn/sumW());
      scale(_h_rap_1s0, crossSection()/picobarn/sumW());
      scale(_h_pT_3s1, crossSection()/picobarn/sumW());
      scale(_h_rap_3s1, crossSection()/picobarn/sumW());
    }

    ///@}


    /// @name Histograms
    ///@{
    Histo1DPtr _h_pT_1p1,_h_rap_1p1,_h_pT_3p0,_h_rap_3p0,_h_pT_3p1,_h_rap_3p1,_h_pT_3p2,_h_rap_3p2,_h_pT_1s0,_h_rap_1s0,_h_pT_3s1,_h_rap_3s1;
    ///@}


  };


  DECLARE_RIVET_PLUGIN(MC_BC);

}