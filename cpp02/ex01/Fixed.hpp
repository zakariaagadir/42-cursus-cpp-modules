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
        int getRawBits( void ) const;
        float toFloat( void ) const;
        int toInt( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point_object);






#endif
