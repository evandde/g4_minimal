#include "PrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4RandomTools.hh"
#include "G4Gamma.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
    : G4VUserPrimaryGeneratorAction()
{
    fPrimary = new G4ParticleGun();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fPrimary;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
    fPrimary->SetParticleDefinition(G4Gamma::Definition());
    fPrimary->SetParticleEnergy(0.662*MeV);
    fPrimary->SetParticlePosition(G4ThreeVector());
    fPrimary->SetParticleMomentumDirection(G4RandomDirection());
    
    fPrimary->GeneratePrimaryVertex(anEvent);
}
