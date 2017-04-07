#ifndef B1PhysicsList_h
#define B1PhysicsList_h 1

#include "globals.hh"
#include "G4VUserPhysicsList.hh"
#include "G4VModularPhysicsList.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class B1PhysicsList : public G4VModularPhysicsList
{
  public:

    B1PhysicsList();
    virtual ~B1PhysicsList();
    void SetCuts();
};
#endif
