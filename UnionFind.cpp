#include "UnionFind.h"

UnionFind::UnionFind() : fleets(), pirates() {}

void UnionFind::addFleet(int fleetId) {
    Fleet fleet(fleetId);
    fleets.insert(fleetId, fleet);
}

void UnionFind::addPirate(int pirateId, int fleetId) {
    Pirate pirate(pirateId, fleetId);
    pirates.insert(pirateId, pirate);
}

int UnionFind::findFleet(int pirateId) {
    Pirate* pirate = pirates.getData(pirateId);
    return pirate->getPointerToFleet()->getFleetId();
}

void UnionFind::unionFleets(int pirateId1, int pirateId2) {
    int fleetId1 = findFleet(pirateId1);
    int fleetId2 = findFleet(pirateId2);

    Fleet* fleet1 = fleets.getData(fleetId1);
    Fleet* fleet2 = fleets.getData(fleetId2);

    Pirate* main_pirate_fleet1 = fleet1->getPointerToPirate();
    Pirate* main_pirate_fleet2 = fleet2->getPointerToPirate();

    if (fleet1->getNumberOfPirates() >= fleet2->getNumberOfPirates()){
        
        main_pirate_fleet2->setPointerToPirate(main_pirate_fleet1);
        main_pirate_fleet2->setRank(main_pirate_fleet2->getRank() + fleet1->getNumberOfPirates() - main_pirate_fleet1->getRank());
        fleet1->setNumberOfShips(fleet1->getNumberOfShips() + fleet2->getNumberOfShips());
        fleet1->setNumberOfPirates(fleet1->getNumberOfPirates() + fleet2->getNumberOfPirates());
        fleets.remove(fleetId2);
    }

    if (fleet1->getNumberOfPirates() < fleet2->getNumberOfPirates()){
        main_pirate_fleet1->setPointerToPirate(main_pirate_fleet2);
        main_pirate_fleet1->setRank(main_pirate_fleet1->getRank() + fleet2->getNumberOfPirates() - main_pirate_fleet2->getRank());
        fleet2->setNumberOfShips(fleet1->getNumberOfShips() + fleet2->getNumberOfShips());
        fleet2->setNumberOfPirates(fleet1->getNumberOfPirates() + fleet2->getNumberOfPirates());
        fleets.remove(fleetId1);
    }
}

int UnionFind::calcRank(int pirateId)
{
    Pirate* selected_pirate = pirates.getData(pirateId);
    int sum = 0;
    while(selected_pirate->getPointerToPirate() != nullptr){
        sum += selected_pirate->getRank();
        selected_pirate = selected_pirate->getPointerToPirate();
    }
    return sum;
}

