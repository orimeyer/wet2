#include "Pirate.h"

// Constructor
Pirate::Pirate(int pirateId, int fleetId)
    : pirateId(pirateId), fleetId(fleetId), money(0), rank(0), pointer_to_fleet(nullptr), pointer_to_pirate(nullptr) {}

// Destructor
Pirate::~Pirate() {
    // No dynamic memory to clean up in this simple class
}

bool Pirate::operator==(const Pirate& other) const {
    return this->pirateId == other.pirateId;
}

// Getters
int Pirate::getPirateId() const {
    return pirateId;
}

int Pirate::getFleetId() const {
    return fleetId;
}

int Pirate::getMoney() const {
    return money;
}

int Pirate::getRank() const {
    return rank;
}

Fleet* Pirate::getPointerToFleet() const {
    return pointer_to_fleet;
}

Pirate* Pirate::getPointerToPirate() const {
    return pointer_to_pirate;
}

// Setters
void Pirate::setPirateId(int id) {
    pirateId = id;
}

void Pirate::setFleetId(int id) {
    fleetId = id;
}

void Pirate::setMoney(int money) {
    this->money = money;
}

void Pirate::setRank(int rank) {
    this->rank = rank;
}

void Pirate::setPointerToFleet(Fleet* fleetPtr) {
    pointer_to_fleet = fleetPtr;
}

void Pirate::setPointerToPirate(Pirate* piratePtr) {
    pointer_to_pirate = piratePtr;
}
