#include "EventAction.hh"

#include "G4SDManager.hh"
#include "G4THitsMap.hh"
#include "G4SystemOfUnits.hh"

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

    for (const auto &iter : *(hitsMap->GetMap()))
    {
        auto copyNo = iter.first;
        auto eDep = *(iter.second);
        if (eDep > 0.)
        {
            G4cout << "CopyNo: " << copyNo << " Edep: " << eDep / keV << " keV" << G4endl;
        }
    }
}
