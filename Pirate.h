#ifndef PIRATE_H
#define PIRATE_H

class Fleet;  // Forward declaration of the Fleet class

class Pirate {
private:
    int pirateId;
    int fleetId;
    int money;
    int rank;
    Fleet* pointer_to_fleet;
    Pirate* pointer_to_pirate;

public:
    // Constructor
    Pirate(int pirateId, int fleetId);

    // Destructor
    ~Pirate();

    // Getters
    int getPirateId() const;
    int getFleetId() const;
    int getMoney() const;
    int getRank() const;
    Fleet* getPointerToFleet() const;
    Pirate* getPointerToPirate() const;

    // Setters
    void setPirateId(int id);
    void setFleetId(int id);
    void setMoney(int money);
    void setRank(int rank);
    void setPointerToFleet(Fleet* fleetPtr);
    void setPointerToPirate(Pirate* piratePtr);
};

#endif // PIRATE_H
