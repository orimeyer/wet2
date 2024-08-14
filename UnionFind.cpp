#include "UnionFind.h"

UnionFind::UnionFind() : fleets(), pirates() {}

void UnionFind::addFleet(int fleetId) {
    Fleet fleet(fleetId);
    fleets.insert(fleetId, fleet);
}

void UnionFind::addPirate(int pirateId, int money, int rank, int fleetId) {
    Pirate pirate(pirateId, money, rank);
    if (fleetId != -1) {
        pirate.setPointerToFleet(fleets.get(fleetId));
    }
    pirates.insert(pirateId, pirate);
}

int UnionFind::findFleet(int pirateId) {
    Pirate* pirate = pirates.get(pirateId);
    if (pirate == nullptr) return -1;

    Fleet* fleet = pirate->getPointerToFleet();
    if (fleet == nullptr) return -1;

    return fleet->getFleetId();
}

void UnionFind::unionFleets(int pirateId1, int pirateId2) {
    int fleetId1 = findFleet(pirateId1);
    int fleetId2 = findFleet(pirateId2);

    if (fleetId1 == -1 || fleetId2 == -1 || fleetId1 == fleetId2) return;

    // Merge fleets by linking all pirates of fleetId2 to fleetId1
    Fleet* fleet1 = fleets.get(fleetId1);
    Fleet* fleet2 = fleets.get(fleetId2);

    if (fleet1 == nullptr || fleet2 == nullptr) return;

    // Update fleet pointers for all pirates in fleet2
    for (int i = 0; i < fleet2->getNumberOfPirates(); i++) {
        Pirate* pirate = pirates.get(fleet2->getPirateId(i));
        if (pirate != nullptr) {
            pirate->setPointerToFleet(fleet1);
        }
    }

    fleet1->setNumberOfShips(fleet1->getNumberOfShips() + fleet2->getNumberOfShips());
    fleet1->setNumberOfPirates(fleet1->getNumberOfPirates() + fleet2->getNumberOfPirates());

    fleets.remove(fleetId2);
}
