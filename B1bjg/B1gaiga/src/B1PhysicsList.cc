
#include "globals.hh"
#include "B1PhysicsList.hh"
#include "G4EmLivermorePolarizedPhysics.hh"
#include "G4SystemOfUnits.hh"

B1PhysicsList::B1PhysicsList() :G4VModularPhysicsList()
{
 G4int ver = 0;
 SetVerboseLevel(ver);


	RegisterPhysics(new G4EmLivermorePolarizedPhysics(ver));

}
B1PhysicsList::~B1PhysicsList()
{ }

void B1PhysicsList::SetCuts()
{

G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(100*eV,1*GeV);

}
