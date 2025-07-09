#ifndef PTERODACTYL_H
#define PTERODACTYL_H

#include "Dinosaur.h"

class Pterodactyl : public Dinosaur {
private: double flightCeiling;

public:
    Pterodactyl(std::string name, double height, double width, double weight, double flightCeiling);
    Pterodactyl(std:: string name, double width);
    Pterodactyl(std::string name);
    Pterodactyl(const Pterodactyl& other);

    double enclosureSize() const override;
    std::string toString() const override;

    double getFlightCeiling() const { return flightCeiling; }
    void setFlightCeiling(double ceiling) { this->flightCeiling = ceiling; }
};

#endif