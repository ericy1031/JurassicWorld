#include "Pack.h"
#include <sstream>

Pack::Pack(int size, std::string packName) {
    if (size < 0) {
        this->size = 4;
    } else {
        this->size = size;
    }

    if (packName.empty()) {
        this->packName = "";
    } else {
        this->packName = packName;
    }
}

std::string Pack::toString() const {
    std::ostringstream oss;
    oss << packName << " is a family of a dinosaurs of size " << size << "!";
    return oss.str();
}