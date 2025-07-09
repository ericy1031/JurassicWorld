#ifndef VELOCIRAPTOR_H
#define VELOCIRAPTOR_H

#include "Dinosaur.h"
#include "Pack.h"
#include <memory> // For std::unique_ptr or std::shared_ptr

class Velociraptor : public Dinosaur {
private:
    int speed;
    // Use smart pointers for automatic memory management
    std::unique_ptr<Pack> pack; // If a Velociraptor exclusively owns a Pack
    // Or use std::shared_ptr<Pack> pack; if multiple Velociraptors can share the same Pack instance

public:
    // If the constructor takes a Pack object by value or const reference to make a copy
    Velociraptor(std::string name, double height, double width, double weight, int speed, const Pack& pack);
    // If it takes a pointer to an already existing pack (and creates its own copy)
    Velociraptor(std::string name, double height, double width, double weight, int speed, Pack* packPtr);

    Velociraptor(std::string name, double height);
    Velociraptor(const Velociraptor& other); // Copy constructor
    Velociraptor& operator=(const Velociraptor& other); // Assignment operator for complete Rule of 3/5/0
    // ~Velociraptor(); // Not needed with std::unique_ptr/std::shared_ptr

    double enclosureSize() const override;
    double calculateFood() const override;
    std::string toString() const override;

    int getSpeed() const { return speed; }
    void setSpeed(int s) { speed = s; }
    Pack* getPack() const { return pack.get(); } // Return raw pointer for observation, if needed
    void setPack(Pack* p); // Setter would need to handle old pack deletion and new pack creation/assignment
};

#endif // VELOCIRAPTOR_H