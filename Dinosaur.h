#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Dinosaur {
protected:
    std::string name;
    int totalEnclosures;
    double weight, height, width;

public:
    Dinosaur(std::string name, double height, double width, double weight);
    Dinosaur();
    Dinosaur(const Dinosaur& other); // Copy constructor

    // Declare these functions as virtual
    virtual double enclosureSize() const;
    virtual double calculateFood() const;
    virtual std::string toString() const;
    virtual std::string buildEnclosure() const; // buildEnclosure is also overridden in the Pterodactyl class

    // Getters for protected members (if needed for derived classes or external access)
    std::string getName() const { return name; }
    double getHeight() const { return height; }
    double getWidth() const { return width; }
    double getWeight() const { return weight; }

    // Add virtual destructor for proper polymorphic deletion
    virtual ~Dinosaur() = default;
};

#endif // DINOSAUR_H