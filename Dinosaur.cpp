#include "Dinosaur.h"
#include <sstream> // Required for std::ostringstream

Dinosaur::Dinosaur(std::string name, double height, double width, double weight) {
    if (!name.empty()) { // Check if name is not empty
        this->name = name;
    } else {
        this->name = "Barney";
    }
    this->height = height;
    this->width = width;
    this->weight = weight;
    this->totalEnclosures = 0; // Initialize as it was declared but not used in Java
}

Dinosaur::Dinosaur() {
    this->name = "Barney";
    this->height = 15.0;
    this->width = 20.0;
    this->weight = 1000.0;
    this->totalEnclosures = 0; // Initialize
}

Dinosaur::Dinosaur(const Dinosaur& other) {
    this->name = other.name;
    this->height = other.height;
    this->width = other.width;
    this->weight = other.weight;
    this->totalEnclosures = other.totalEnclosures; // Copy
}

double Dinosaur::enclosureSize() const {
    return 10 * width * height;
}

double Dinosaur::calculateFood() const {
    return weight * width * height;
}

std::string Dinosaur::toString() const {
    std::ostringstream oss;
    // Note: C++ printf-like formatting doesn't automatically cast doubles to ints like Java's %d
    // So, explicitly cast or use appropriate format specifiers for doubles.
    // Assuming enclosureSize() and calculateFood() are intended to be displayed as whole numbers based on Java's %d
    oss << std::fixed << std::setprecision(0) // Set precision to 0 decimal places for whole numbers
        << name << " requires a " << enclosureSize() << " square foot enclosure and "
        << calculateFood() << " pounds of food";
    return oss.str();
}

std::string Dinosaur::buildEnclosure() const {
    std::ostringstream oss;
    if (enclosureSize() > 6000.0 || calculateFood() > 80000.0) {
        oss << " " << name << " is too expensive for the park!";
    } else {
        oss << " " << name << " has been added to the park!";
    }
    return oss.str();
}