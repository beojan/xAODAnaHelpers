#ifndef xAODAnaHelpers_ElectronHistsAlgo_H
#define xAODAnaHelpers_ElectronHistsAlgo_H

#include "xAODAnaHelpers/IParticleHistsAlgo.h"

class ElectronHistsAlgo : public IParticleHistsAlgo
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:

  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!

  // this is a standard constructor
  ElectronHistsAlgo ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode execute ();

  // these are the functions not inherited from Algorithm
  virtual EL::StatusCode AddHists( std::string name );

  /// @cond
  // this is needed to distribute the algorithm to the workers
  ClassDef(ElectronHistsAlgo, 1);
  /// @endcond

};

#endif
