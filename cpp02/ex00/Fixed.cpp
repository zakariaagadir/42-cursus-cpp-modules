#include "Fixed.hpp"



Fixed::Fixed(){
    std::cout<< "Default constructor called" << std::endl;
    this->fix_p_v = 0;
}

Fixed::Fixed(const Fixed &a){
    std::cout<< "Copy constructor called" << std::endl;
    *this = a;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout<< "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fix_p_v = other.getRawBits();
    }
    return (*this);
}


int Fixed::getRawBits( void ) const{
    std::cout<< "getRawBits member function called" << std::endl;
    return (this->fix_p_v);
}

void Fixed::setRawBits( int const raw ){
    std::cout<< "setRawBits member function called" << std::endl;
    this->fix_p_v = raw;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout<< "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fix_p_v = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(){
    std::cout<< "Destructor called" << std::endl;
}

