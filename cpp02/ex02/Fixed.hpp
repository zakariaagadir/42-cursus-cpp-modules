#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int fix_p_v;
        static const int fractional = 8;



    public:
        Fixed();
        Fixed(const int a);
        Fixed(const float a);
        Fixed(const Fixed &a);
        Fixed& operator=(const Fixed& other);
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed& operator++();
        Fixed operator++(int other);
        Fixed& operator--();
        Fixed operator--(int other);
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        int getRawBits( void ) const;
        float toFloat( void ) const;
        int toInt( void ) const;
        void setRawBits( int const raw );
        static Fixed& smallest(Fixed& other,Fixed& another) ;
        static const Fixed& smallest(const Fixed& other,const Fixed& another);
        static Fixed& max(Fixed& other,Fixed& another);
        static const Fixed& max(const Fixed& other,const Fixed& another);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point_object);






#endif
