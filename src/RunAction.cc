#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "RunAction.hh"

RunAction::RunAction()
    : G4UserRunAction()
{
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run *)
{
}

void RunAction::EndOfRunAction(const G4Run *)
{
}
