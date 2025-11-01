#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int fix_p_v;
        static const int fractional = 8;



    public:
        Fixed();
        Fixed(const Fixed &a);
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(const Fixed& other);
        ~Fixed();
};






#endif
