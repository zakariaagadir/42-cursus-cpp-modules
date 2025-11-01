#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <string>
#include <iostream>

class ScalarConverter
{
    private:
        char    s_char;
        int    s_int;
        float    s_float;
        double    s_double;
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static void convert(std::string &other);
};

#endif


