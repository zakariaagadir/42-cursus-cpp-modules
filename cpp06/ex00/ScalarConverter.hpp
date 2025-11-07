#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip>

enum leteral_type
{
    type_char,
    type_int,
    type_float,
    type_double,
    type_pseudo,
    type_invalid
};


class ScalarConverter
{
    private:
        static double c_double;
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static leteral_type get_type(std::string& other);
        static void printConversions(char c, int i, float f, double d);
        static void strToDouble(const std::string &s);

    public:
        static void convert(std::string other);
};

#endif


