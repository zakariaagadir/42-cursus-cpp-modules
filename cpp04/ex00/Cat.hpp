#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

#include <iostream>


class Cat : public Animal{
    public :
        Cat();
        Cat(const Cat& newcat);
        Cat& operator=(const Cat& newcat);
        const std::string& getType() const;
        void setType(std::string& newtype);
        void makeSound() const;
        ~Cat();
};





#endif