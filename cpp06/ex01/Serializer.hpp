#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>  // for uintptr_t
#include "Data.hpp"

class Serializer
{
private:
    Serializer();  // prevent instantiation
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
