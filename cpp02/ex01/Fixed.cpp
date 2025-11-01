#include "Fixed.hpp"



Fixed::Fixed(){
    std::cout<< "Default constructor called" << std::endl;
    this->fix_p_v = 0;
}

Fixed::Fixed(const Fixed &a){
    std::cout<< "Copy constructor called" << std::endl;
    *this = a;
}

Fixed::Fixed(const int a) {
    std::cout << "Int constructor called" << std::endl;
    this->fix_p_v = a << this->fractional;
}


Fixed& Fixed::operator=(const Fixed& other){
    std::cout<< "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fix_p_v = other.getRawBits();
    }
    return (*this);
}


Fixed::Fixed(const float a) {
    std::cout << "Float constructor called" << std::endl;
    this->fix_p_v = roundf(a * (1 << this->fractional));
}


int Fixed::getRawBits( void ) const{
    return (this->fix_p_v);
}

void Fixed::setRawBits( int const raw ){
    std::cout<< "setRawBits member function called" << std::endl;
    this->fix_p_v = raw;
}

Fixed::~Fixed(){
    std::cout<< "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {

    return static_cast<float>(this->fix_p_v) / (1 << this->fractional);
}

int Fixed::toInt(void) const {
    return this->fix_p_v >> this->fractional;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point_object) {
    os << fixed_point_object.toFloat();
    return os;
}

