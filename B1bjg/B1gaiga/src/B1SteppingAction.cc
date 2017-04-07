//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B1SteppingAction.cc 74483 2013-10-09 13:37:06Z gcosmo $
//
/// \file B1SteppingAction.cc
/// \brief Implementation of the B1SteppingAction class

#include "B1SteppingAction.hh"
#include "B1EventAction.hh"
#include "B1DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"

#include <iostream>
#include <fstream>
using namespace std;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::B1SteppingAction(B1EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::~B1SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



void B1SteppingAction::UserSteppingAction(const G4Step* step)
{
  G4double eenergy=step->GetTrack()->GetKineticEnergy();
G4String particlename;

  if (!fScoringVolume) { 
    const B1DetectorConstruction* detectorConstruction
      = static_cast<const B1DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   
  }

  // get volume of the current step

    G4String PreVolumeName="Out of World";
  G4VPhysicalVolume* volume1=step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    if (volume1) PreVolumeName=volume1->GetName();


    G4String PostVolumeName="Out of World";
    G4VPhysicalVolume* volume2=step->GetPostStepPoint()->GetTouchableHandle()->GetVolume();
    if (volume2) PostVolumeName=volume2->GetName();

    particlename=step->GetTrack()->GetDefinition()->GetParticleName();
    G4int stepid=step->GetTrack()->GetCurrentStepNumber();

    if ((stepid==1)&&(particlename=="gamma")&&(eenergy>0*eV)){
        G4cout<<particlename<<": "<<eenergy/eV<<"; "<<step->GetTrack()->GetPolarization()<<G4endl;
    }

  /*if (PreVolumeName == "logicag" && PostVolumeName != "logicag"){
      if (particlename == "gamma")
       {
           G4double eenergy=step->GetTrack()->GetKineticEnergy();
           G4ThreeVector edirection=step->GetTrack()->GetMomentumDirection();
       }
      else //if (particlename == "photon")
       {
           G4double photonenergy=step->GetTrack()->GetKineticEnergy();
           G4ThreeVector photondirection=step->GetTrack()->GetMomentumDirection();
       }
   }
//data output

    std::fstream file("shuchu",std::ios::out|std::ios::app);
    file<<eenergy/keV<<G4endl;

  G4double edepStepm = step->GetTotalEnergyDeposit();
  fEventAction->AddEdepm(edepStepm);  */



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

