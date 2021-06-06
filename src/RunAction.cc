#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "g4csv.hh"

#include "RunAction.hh"

RunAction::RunAction()
    : G4UserRunAction()
{
    // auto analysisManager = G4AnalysisManager::Instance();
    // analysisManager->CreateH1("Edep", "Energy Deposition in the box", 1024, 0., 3. * MeV);
    // analysisManager->CreateNtuple("G4_Minimal", "Energy Deposition");
    // analysisManager->CreateNtupleDColumn("EDep");
    // analysisManager->FinishNtuple();
}

RunAction::~RunAction()
{
    // delete G4AnalysisManager::Instance();
}

void RunAction::BeginOfRunAction(const G4Run *)
{
    // auto analysisManager = G4AnalysisManager::Instance();
    // analysisManager->OpenFile("G4_Minimal");
}

void RunAction::EndOfRunAction(const G4Run *)
{
    // auto analysisManager = G4AnalysisManager::Instance();
    // analysisManager->Write();
    // analysisManager->CloseFile();
}
