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
    void addPirate(int pirateId, int fleetId);

    int findFleet(int pirateId);
    void unionFleets(int pirateId1, int pirateId2);

    int calcRank(int pirateId);
};

#endif // UNIONFIND_H
