#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4RandomTools.hh"
#include "G4Gamma.hh"

#include "PrimaryGeneratorAction.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
    : G4VUserPrimaryGeneratorAction()
{
    fPrimary = new G4ParticleGun();

    // fPrimary->SetParticleDefinition(G4Gamma::Gamma());
    // fPrimary->SetParticleEnergy(0.662*MeV);
    // fPrimary->SetParticlePosition(G4ThreeVector());
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fPrimary;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
    // fPrimary->SetParticleMomentumDirection(G4RandomDirection());

    fPrimary->GeneratePrimaryVertex(anEvent);
}
