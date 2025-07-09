#include "Velociraptor.h"
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

// Constructor that takes a const reference to a Pack and copies it
Velociraptor::Velociraptor(std::string name, double height, double width, double weight, int speed, const Pack& packObj)
    : Dinosaur(name, height, width, weight), pack(std::make_unique<Pack>(packObj)) { // Copy the Pack object
    if (speed < 0) {
        this->speed = 30;
    } else {
        this->speed = speed;
    }
}

// Constructor that takes a raw pointer to a Pack and copies it (if it's not null)
Velociraptor::Velociraptor(std::string name, double height, double width, double weight, int speed, Pack* packPtr)
    : Dinosaur(name, height, width, weight) {
    if (speed < 0) {
        this->speed = 30;
    } else {
        this->speed = speed;
    }
    if (packPtr) {
        this->pack = std::make_unique<Pack>(*packPtr); // Deep copy
    } else {
        this->pack = nullptr;
    }
}

Velociraptor::Velociraptor(std::string name, double height)
    : Dinosaur(name, height, 10.0, 300.0), speed(30), pack(nullptr) {} // Initialize speed and pack
// ... (rest of the class) ...

Velociraptor::Velociraptor(const Velociraptor& other)
    : Dinosaur(other), speed(other.speed) {
    if (other.pack) {
        this->pack = std::make_unique<Pack>(*other.pack); // Deep copy
    } else {
        this->pack = nullptr;
    }
}

Velociraptor& Velociraptor::operator=(const Velociraptor& other) {
    if (this != &other) { // Handle self-assignment
        Dinosaur::operator=(other); // Call base class assignment operator
        speed = other.speed;
        if (other.pack) {
            pack = std::make_unique<Pack>(*other.pack); // Deep copy
        } else {
            pack = nullptr;
        }
    }
    return *this;
}

// No explicit destructor needed with unique_ptr

double Velociraptor::enclosureSize() const {
    if (pack == nullptr) { // use .get() for raw pointer access
        return 4 * width * height;
    } else {
        return pack->size * width * height; // Access through unique_ptr using ->
    }
}

double Velociraptor::calculateFood() const {
    return weight * speed * height;
}

std::string Velociraptor::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(0);

    if (pack == nullptr) {
        oss << name << " requires a " << enclosureSize() << " square foot enclosure and "
            << calculateFood() << " pounds of food.";
    } else {
        oss << pack->packName << " is a family of dinosaurs of size " << pack->size << "! "
            << name << " requires a " << enclosureSize() << " square foot enclosure and "
            << calculateFood() << " pounds of food.";
    }
    return oss.str();
}

void Velociraptor::setPack(Pack* p) {
    if (p) {
        pack = std::make_unique<Pack>(*p);
    } else {
        pack = nullptr;
    }
}