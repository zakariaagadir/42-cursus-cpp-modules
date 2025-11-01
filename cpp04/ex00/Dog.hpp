#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#include <iostream>


class Dog: public Animal{
    public :
        Dog();
        Dog(Dog& newdog);
        Dog& operator=(const Dog& newdog);
        const std::string& getType() const;
        void setType(std::string& newtype);
        void makeSound() const;
        ~Dog();
};





#endif