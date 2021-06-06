#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4THitsMap.hh"
#include "g4csv.hh"

#include "EventAction.hh"

EventAction::EventAction()
    : G4UserEventAction(), fHCID(-1)
{
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event *)
{
}

void EventAction::EndOfEventAction(const G4Event *anEvent)
{
    auto HCE = anEvent->GetHCofThisEvent();
    if (!HCE)
        return;

    // if (fHCID == -1)
    //     fHCID = G4SDManager::GetSDMpointer()->GetCollectionID("Detector/EDep");

    // auto analysisManager = G4AnalysisManager::Instance();

    // auto hitsMap = static_cast<G4THitsMap<G4double> *>(HCE->GetHC(fHCID));
    // for (const auto &iter : *(hitsMap->GetMap()))
    // {
    //     auto eDep = *(iter.second);
    //     if (eDep > 0.)
    //     {
    //         analysisManager->FillH1(0, eDep);
    //         analysisManager->FillNtupleDColumn(0, eDep);
    //         analysisManager->AddNtupleRow();
    //     }
    // }
}
