#include "Pterodactyl.h"
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

Pterodactyl::Pterodactyl(std::string name, double height, double width, double weight, double flightCeiling)
    : Dinosaur(name, height, width, weight) { // Call base class constructor
    if (flightCeiling > 100 || flightCeiling < 10) {
        this->flightCeiling = 50;
    } else {
        this->flightCeiling = flightCeiling;
    }
}

// Corrected this constructor based on Java's 'this(name, width)' which implies
// that the 'height' parameter from the main constructor is implicitly set.
// The Java code had `this(name, width);` in a constructor that only took `name` and `width`.
// This would lead to a recursive call in Java. Assuming the intent was to call the
// 5-parameter constructor with default height and weight, or that the original Java
// was slightly malformed for the 3-parameter constructor `Pterodactyl(String name, double width)`.
// I'm interpreting the most likely intent: a constructor taking name and width, setting default height, weight, and flightCeiling.
Pterodactyl::Pterodactyl(std::string name, double width)
    : Dinosaur(name, 15.0, width, 1000.0) { // Default height and weight similar to default Dinosaur
    this->flightCeiling = 50;
}

Pterodactyl::Pterodactyl(std::string name)
    : Pterodactyl(name, 12.0) { // Calls the Pterodactyl(string, double) constructor
    // Java's `this(name, 12);` where 12 would correspond to `width`
}

Pterodactyl::Pterodactyl(const Pterodactyl& other)
    : Dinosaur(other), flightCeiling(other.flightCeiling) { // Call base copy constructor and copy flightCeiling
}

double Pterodactyl::enclosureSize() const {
    // There was a typo in the original Java code: `wdith` should be `width`
    return ((4 * width * height) + flightCeiling);
}

std::string Pterodactyl::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(0)
        << name << " can fly " << flightCeiling << " feet into the air! "
        << name << " requires a " << enclosureSize() << " square foot enclosure and "
        << calculateFood() << " pounds of food.";
    return oss.str();
}

// Empty getter() and setter() methods from Java were likely placeholders.
// Actual getters/setters are provided in the header.