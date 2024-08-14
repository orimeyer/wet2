#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "HashTable.h"
#include "Fleet.h"
#include "Pirate.h"

class UnionFind {
private:
    HashTable<Fleet> fleets;
    HashTable<Pirate> pirates;

public:
    UnionFind();

    void addFleet(int fleetId);
    void addPirate(int pirateId, int money, int rank, int fleetId = -1);

    int findFleet(int pirateId);
    void unionFleets(int pirateId1, int pirateId2);
};

#endif // UNIONFIND_H
