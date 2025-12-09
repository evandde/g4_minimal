#ifndef EVENTACTION_HH
#define EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"

class EventAction : public G4UserEventAction
{
public:
    EventAction();
    ~EventAction() override;

    void BeginOfEventAction(const G4Event *) override;
    void EndOfEventAction(const G4Event *) override;

private:
    G4int fHCID;
};

#endif // EVENTACTION_HH
