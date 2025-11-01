#include "Fixed.hpp"



Fixed::Fixed(){
    this->fix_p_v = 0;
}

Fixed::Fixed(const Fixed &a){
    this->setRawBits(a.getRawBits());
}

Fixed::Fixed(const int a) {
    this->fix_p_v = a << this->fractional;
}


Fixed& Fixed::operator=(const Fixed& other){
    if (this != &other)
    {
        this->fix_p_v = other.getRawBits();
    }
    return (*this);
}


Fixed::Fixed(const float a) {
    this->fix_p_v = ceil(a * (1 << this->fractional));
}


int Fixed::getRawBits( void ) const{
    return (this->fix_p_v);
}

void Fixed::setRawBits( int const raw ){
    this->fix_p_v = raw;
}

Fixed::~Fixed(){
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

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}


bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}


bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++(){
    this->fix_p_v++;
    return (*this);
}
Fixed Fixed::operator++(int other){
    (void) other;
    Fixed temp = *this;
    this->fix_p_v++;
    return (temp);
}

Fixed& Fixed::operator--(){
    this->fix_p_v--;
    return (*this);
}
Fixed Fixed::operator--(int other){
    (void) other;
    Fixed temp = *this;
    this->fix_p_v--;
    return (temp);
}

Fixed& Fixed::smallest(Fixed& other,Fixed& another) {
    if(other.getRawBits() < another.getRawBits())
        return (other);
    return (another);
}
const Fixed& Fixed::smallest(const Fixed& other,const Fixed& another) {
    if(other.getRawBits() < another.getRawBits())
        return (other);
    return (another);
}

Fixed& Fixed::max(Fixed& other,Fixed& another){
    if(other.getRawBits() > another.getRawBits())
        return (other);
    return (another);
}

const Fixed& Fixed::max(const Fixed& other,const Fixed& another){
    if(other.getRawBits() > another.getRawBits())
        return (other);
    return (another);
}