#ifndef xAODAnaHelpers_PhotonContainer_H
#define xAODAnaHelpers_PhotonContainer_H

#include <TTree.h>
#include <TLorentzVector.h>

#include <vector>
#include <string>

#include "xAODEgamma/PhotonContainer.h"

#include <xAODAnaHelpers/HelperClasses.h>

#include <xAODAnaHelpers/Photon.h>
#include <xAODAnaHelpers/ParticleContainer.h>

typedef SG::AuxElement::Accessor< std::vector< float > > floatAccessor ;

namespace xAH {

  class PhotonContainer : public ParticleContainer<Photon,HelperClasses::PhotonInfoSwitch>
    {
    public:
      PhotonContainer(const std::string& name = "ph", const std::string& detailStr="", float units = 1e3, bool mc = false);
      virtual ~PhotonContainer();
    
      virtual void setTree(TTree *tree);
      virtual void setBranches(TTree *tree);
      virtual void clear();
      virtual void FillPhoton( const xAOD::Photon* photon );
      virtual void FillPhoton( const xAOD::IParticle* particle );
      using ParticleContainer::setTree; // make other overloaded version of execute() to show up in subclass

    protected:
      virtual void updateParticle(uint idx, Photon& photon);
    
    private:

      // isolation
      std::vector<int>*   m_isIsolated_Cone40CaloOnly;
      std::vector<int>*   m_isIsolated_Cone40;
      std::vector<int>*   m_isIsolated_Cone20;
      //std::vector<float>* m_etcone20;
      std::vector<float>* m_ptcone20;
      std::vector<float>* m_ptcone30;
      std::vector<float>* m_ptcone40;
      std::vector<float>* m_ptvarcone20;
      std::vector<float>* m_ptvarcone30;
      std::vector<float>* m_ptvarcone40;
      std::vector<float>* m_topoetcone20;
      std::vector<float>* m_topoetcone30;
      std::vector<float>* m_topoetcone40;
    
      // PID
      int m_n_IsLoose;
      std::vector<int>*   m_IsLoose;
      int m_n_IsMedium;
      std::vector<int>*   m_IsMedium;
      int m_n_IsTight;
      std::vector<int>*   m_IsTight;
    
      //Purity
      std::vector<float>* m_radhad1;
      std::vector<float>* m_radhad;
      std::vector<float>* m_e277;
      std::vector<float>* m_reta;
      std::vector<float>* m_rphi;
      std::vector<float>* m_weta2;
      std::vector<float>* m_f1;
      std::vector<float>* m_wtot;
      //std::vector<float>* m_w1;
      std::vector<float>* m_deltae;
      std::vector<float>* m_eratio;
    
      // effSF
      std::vector<float> *m_LooseEffSF;
      std::vector<float> *m_MediumEffSF;
      std::vector<float> *m_TightEffSF;

      std::vector<float> *m_LooseEffSF_Error;
      std::vector<float> *m_MediumEffSF_Error;
      std::vector<float> *m_TightEffSF_Error;

      // trigger
      std::vector<std::vector<std::string> > *m_trigMatched;
    };
}
#endif // xAODAnaHelpers_PhotonContainer_H
