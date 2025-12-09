#include "RunAction.hh"

#include "G4RunManager.hh"
#include "G4GenericAnalysisManager.hh"

RunAction::RunAction()
    : G4UserRunAction()
{
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run *)
{
    auto analysisManager = G4GenericAnalysisManager::Instance();

    analysisManager->CreateH1("EDep", "Energy Deposit / keV", 100, 0., 1000.);
    
    analysisManager->CreateNtuple("EDep", "Energy Deposit / keV");
    analysisManager->CreateNtupleIColumn("copyNo");
    analysisManager->CreateNtupleDColumn("EDep");
    analysisManager->FinishNtuple();

    analysisManager->OpenFile("output.csv");
}

void RunAction::EndOfRunAction(const G4Run *)
{
    auto analysisManager = G4GenericAnalysisManager::Instance();
    
    analysisManager->Write();
    analysisManager->CloseFile();
}
