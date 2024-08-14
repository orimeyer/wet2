#include "Fleet.h"

// Constructor
Fleet::Fleet(int id)
    : number_of_ships(1), number_of_pirates(0), fleetId(id), pointer_to_pirate(nullptr) {}

// Destructor
Fleet::~Fleet() {
    // No dynamic memory to clean up in this simple class
}

// Getters
int Fleet::getNumberOfShips() const {
    return number_of_ships;
}

int Fleet::getNumberOfPirates() const {
    return number_of_pirates;
}

int Fleet::getFleetId() const {
    return fleetId;
}

Pirate* Fleet::getPointerToPirate() const {
    return pointer_to_pirate;
}

// Setters
void Fleet::setNumberOfShips(int ships) {
    number_of_ships = ships;
}

void Fleet::setNumberOfPirates(int pirates) {
    number_of_pirates = pirates;
}

void Fleet::setFleetId(int id) {
    fleetId = id;
}

void Fleet::setPointerToPirate(Pirate* ptr) {
    pointer_to_pirate = ptr;
}

