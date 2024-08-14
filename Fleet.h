#ifndef FLEET_H
#define FLEET_H

class Pirate;  // Forward declaration of the Pirate class

class Fleet {
private:
    int fleetId;
    int number_of_ships;
    int number_of_pirates;
    Pirate* pointer_to_pirate;

public:
    // Constructor
    Fleet(int id);

    // Destructor
    ~Fleet();

    bool operator==(const Fleet& other) const;

    // Getters
    int getNumberOfShips() const;
    int getNumberOfPirates() const;
    int getFleetId() const;
    Pirate* getPointerToPirate() const;

    // Setters
    void setNumberOfShips(int ships);
    void setNumberOfPirates(int pirates);
    void setFleetId(int id);
    void setPointerToPirate(Pirate* ptr);
};

#endif // FLEET_H

