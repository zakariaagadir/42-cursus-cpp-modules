#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{

}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string &other)
{
    float s_float = std::stof(other);
    int s_int = static_cast<int>(s_float);
    char s_char = static_cast<char>(s_float);
    double s_double = static_cast<double>(s_float);
}








