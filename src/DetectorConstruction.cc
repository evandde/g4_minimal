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
    auto nist = G4NistManager::Instance();
    auto matAir = nist->FindOrBuildMaterial("G4_AIR");
    auto matWater = nist->FindOrBuildMaterial("G4_WATER");

    // World
    auto worldSize = 1. * m;
    auto worldSol = new G4Box("World", .5 * worldSize, .5 * worldSize, .5 * worldSize);
    auto worldLog = new G4LogicalVolume(worldSol, matAir, "World");
    auto worldPhy = new G4PVPlacement(nullptr, G4ThreeVector(), worldLog, "World", nullptr, false, 0);

    // Water phantom
    auto phantomSize = 5. * cm;
    auto phantomPos = G4ThreeVector(0., 0., 10.*cm);
    auto phantomSol = new G4Box("phantom", .5 * phantomSize, .5 * phantomSize, .5 * phantomSize);
    auto phantomLog = new G4LogicalVolume(phantomSol, matWater, "phantom");
    new G4PVPlacement(nullptr, phantomPos, phantomLog, "phantom", worldLog, false, 0);

    return worldPhy;
}

void DetectorConstruction::ConstructSDandField()
{
    auto mfd = new G4MultiFunctionalDetector("Detector");
    G4SDManager::GetSDMpointer()->AddNewDetector(mfd);
    auto psEDep = new G4PSEnergyDeposit("EDep");
    mfd->RegisterPrimitive(psEDep);
    SetSensitiveDetector("phantom", mfd);
}
