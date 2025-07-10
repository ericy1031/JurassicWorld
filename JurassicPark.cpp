#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "Dinosaur.h"
#include "Pterodactyl.h"
#include "Velociraptor.h"
#include "Pack.h"

// main file to run program
class JurassicPark {
private:
    std::vector<std::unique_ptr<Dinosaur>> dinosaurs;
    std::string parkName;

public:
    // Constructor for the JurassicPark class.
    // Initializes the park with a given name.
    JurassicPark(const std::string& name = "Jurassic Park") : parkName(name) {
        std::cout << "Welcome to " << parkName << "!" << std::endl;
    }

    // Adds a dinosaur to the park.
    // Takes ownership of the passed unique_ptr.
    void addDinosaur(std::unique_ptr<Dinosaur> dino) {
        if (dino) { // Ensure the unique_ptr is not null
            std::cout << "Adding " << dino->getName() << " to " << parkName << "..." << std::endl;
            dinosaurs.push_back(std::move(dino));
            std::cout << dinosaurs.back()->getName() << " successfully added." << std::endl;
        } else {
            std::cout << "Attempted to add a null dinosaur. No action taken." << std::endl;
        }
    }

    // Lists information about all dinosaurs currently in the park.
    // It iterates through the collection and calls toString() and buildEnclosure()
    // polymorphically for each dinosaur.
    void listDinoInfo() const {
        if (dinosaurs.empty()) {
            std::cout << "The park currently has no dinosaurs." << std::endl;
            return;
        }
        std::cout << "\n--- Dinosaurs in " << parkName << " ---" << std::endl;
        for (const auto& dino : dinosaurs) {
            // Polymorphic calls to toString() and buildEnclosure()
            std::cout << dino->toString() << std::endl;
            std::cout << dino->buildEnclosure() << std::endl;
            std::cout << "-------------------------------------" << std::endl;
        }
    }

    // Displays the total number of dinosaurs in the park.
    size_t getTotalDinosaurs() const {
        return dinosaurs.size();
    }

    // Gets the name of the park.
    std::string getParkName() const {
        return parkName;
    }

    // Destructor: std::unique_ptr handles memory deallocation automatically,
    // so a custom destructor is not strictly necessary here unless
    // there's other cleanup logic.
    ~JurassicPark() = default;
};

int main() {
    // Create a Jurassic Park instance
    JurassicPark myPark("Isla Nublar");

    // Create Dinosaur objects using unique_ptr for automatic memory management
    // and to allow polymorphic behavior when stored in the park's vector.
    std::unique_ptr<Dinosaur> dino1 = std::make_unique<Dinosaur>("T-Rex", 18, 25, 1200);
    std::unique_ptr<Dinosaur> dino2 = std::make_unique<Dinosaur>(); // Default Dinosaur

    std::unique_ptr<Pterodactyl> ptero1 = std::make_unique<Pterodactyl>("Ptero1", 10, 15, 500, 80);
    std::unique_ptr<Pterodactyl> ptero2 = std::make_unique<Pterodactyl>("Ptero2", 14); // Partial constructor

    Pack raptorPack(5, "Raptor Squad"); // Create a Pack object
    // When creating Velociraptors, pass the Pack object by const reference
    // so the Velociraptor's constructor can make its own deep copy.
    std::unique_ptr<Velociraptor> velo1 = std::make_unique<Velociraptor>("Blue", 6, 10, 300, 40, raptorPack);
    std::unique_ptr<Velociraptor> velo2 = std::make_unique<Velociraptor>("Echo", 7); // Partial constructor

    // Add dinosaurs to the park
    myPark.addDinosaur(std::move(dino1)); // Transfer ownership
    myPark.addDinosaur(std::move(dino2));
    myPark.addDinosaur(std::move(ptero1));
    myPark.addDinosaur(std::move(ptero2));
    myPark.addDinosaur(std::move(velo1));
    myPark.addDinosaur(std::move(velo2));

    // List all dinosaurs and their enclosure/food info
    myPark.listDinoInfo();

    std::cout << "\nTotal dinosaurs in " << myPark.getParkName() << ": " << myPark.getTotalDinosaurs() << std::endl;

    // --- Testing copy constructors (as per original Java main) ---
    // Note: These tests are done on individual objects, not via the park's collection.
    // This demonstrates the copy constructor functionality of each class.

    std::cout << "\n--- Testing Copy Constructors ---" << std::endl;

    // Re-create originalDino for copy testing as its ownership was moved to myPark
    Dinosaur originalDino("Original T-Rex", 20, 30, 1500);
    Dinosaur dinoCopy = originalDino; // Calls Dinosaur copy constructor
    std::cout << "Original Dinosaur: " << originalDino.toString() << std::endl;
    std::cout << "Copied Dinosaur:   " << dinoCopy.toString() << std::endl;
    std::cout << "Original Enclosure: " << originalDino.buildEnclosure() << std::endl;
    std::cout << "Copied Enclosure:   " << dinoCopy.buildEnclosure() << std::endl;

    // Re-create originalPtero for copy testing
    Pterodactyl originalPtero("Original Ptero", 12, 18, 600, 90);
    Pterodactyl pteroCopy = originalPtero; // Calls Pterodactyl copy constructor
    std::cout << "\nOriginal Pterodactyl: " << originalPtero.toString() << std::endl;
    std::cout << "Copied Pterodactyl:   " << pteroCopy.toString() << std::endl;

    // Re-create originalVelo for copy testing
    Pack anotherRaptorPack(3, "Delta Squad");
    Velociraptor originalVelo("Original Blue", 7, 12, 350, 45, anotherRaptorPack);
    Velociraptor veloCopy = originalVelo; // Calls Velociraptor copy constructor
    std::cout << "\nOriginal Velociraptor: " << originalVelo.toString() << std::endl;
    std::cout << "Copied Velociraptor:   " << veloCopy.toString() << std::endl;

    // Test toString for Velociraptors (original Java main's final step)
    std::cout << "\n--- Final toString test for Velociraptors (from copy test) ---" << std::endl;
    std::cout << originalVelo.toString() << std::endl;
    std::cout << veloCopy.toString() << std::endl;

    return 0;
}
