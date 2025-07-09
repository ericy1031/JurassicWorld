#ifndef PACK_H
#define PACK_H

#include <string>

class Pack {
    public:
        int size;
        std::string packName;

        Pack(int size, std::string packName);
        std::string toString() const;
};

#endif