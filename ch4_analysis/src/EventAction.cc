#include "EventAction.hh"

#include "G4SDManager.hh"
#include "G4THitsMap.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericAnalysisManager.hh"

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

    if (fHCID == -1)
        fHCID = G4SDManager::GetSDMpointer()->GetCollectionID("PhantomSD/Edep");

    auto hitsMap = static_cast<G4THitsMap<G4double> *>(HCE->GetHC(fHCID));

    auto analysisManager = G4GenericAnalysisManager::Instance();

    for (const auto &iter : *(hitsMap->GetMap()))
    {
        auto copyNo = iter.first;
        auto eDep = *(iter.second);
        if (eDep > 0.)
        {
            analysisManager->FillH1(0, eDep / keV);

            analysisManager->FillNtupleDColumn(0, copyNo);
            analysisManager->FillNtupleDColumn(1, eDep / keV);
            analysisManager->AddNtupleRow();
        }
    }
}
