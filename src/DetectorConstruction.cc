#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SDManager.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4PSEnergyDeposit.hh"

#include "DetectorConstruction.hh"

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume *DetectorConstruction::Construct()
{
    // materials
    G4NistManager *nist = G4NistManager::Instance();
    auto matAir = nist->FindOrBuildMaterial("G4_AIR");
    // auto matWater = nist->FindOrBuildMaterial("G4_WATER");

    // World
    auto worldSize = 1. * m;
    auto worldSol = new G4Box("World", .5 * worldSize, .5 * worldSize, .5 * worldSize);
    auto worldLog = new G4LogicalVolume(worldSol, matAir, "World");
    auto worldPhy = new G4PVPlacement(0, G4ThreeVector(), worldLog, "World", nullptr, false, 0);

    // Water box
    // auto boxSize = 5. * cm;
    // auto boxPos = G4ThreeVector(0., 0., 10.*cm);
    // auto boxSol = new G4Box("Box", .5 * boxSize, .5 * boxSize, .5 * boxSize);
    // auto boxLog = new G4LogicalVolume(boxSol, matWater, "Box");
    // new G4PVPlacement(nullptr, boxPos, boxLog, "Box", worldLog, false, 0);

    return worldPhy;
}

void DetectorConstruction::ConstructSDandField()
{
    // auto mfd = new G4MultiFunctionalDetector("Detector");
    // G4SDManager::GetSDMpointer()->AddNewDetector(mfd);
    // auto psEDep = new G4PSEnergyDeposit("EDep");
    // mfd->RegisterPrimitive(psEDep);
    // SetSensitiveDetector("Box", mfd);
}
