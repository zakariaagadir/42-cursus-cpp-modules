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

leteral_type ScalarConverter::get_type(std::string& other)
{
    if (other == "-inff" || other == "+inff" || other == "nanf")
        return (type_pseudo);
    if (other == "-inf" || other == "+inf" || other == "nan")
        return (type_pseudo);
    if ((other.size() == 1) && isprint(other[0]) && !isdigit(other[0]))
        return(type_char);
    int i = 0;
    if (other[i] == '-' || other[i] == '+')
        i++;
    while(i < other.length())
    {
        if (!isdigit(other[i]))
            break;
        if (i == (other.length() - 1))
            return(type_int);
        i++;
    }
    bool virgule = false;
    bool f = false;
    while(i < other.length())
    {
        if (!isdigit(other[i]))
        {
            if(other[i] == '.' && !virgule)
            {
                virgule = true;
            }
            else if (other[i] == 'f' && i == (other.length() - 1))
            {
                f = true;
            }
            else
            {
                return type_invalid;
            }

        }
        
        i++;
    }
    if (virgule && f)
        return(type_float);
    if (virgule && !f)
        return(type_double);
    return (type_invalid);
}

void ScalarConverter::printConversions(char c, int i, float f, double d)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << i << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
}

void ScalarConverter::convert(std::string &other)
{
    leteral_type type = get_type(other);
    float s_float;
    int s_int;
    char s_char;
    double s_double;
    switch (type)
    {
        case type_char :
            s_float = std::stof(other);
            s_int = static_cast<int>(s_float);
            s_char = static_cast<char>(s_float);
            s_double = static_cast<double>(s_float);
            break;
        case type_int :
            s_float = std::stof(other);
            s_int = static_cast<int>(s_float);
            s_char = static_cast<char>(s_float);
            s_double = static_cast<double>(s_float);
            break;
        case type_float :
            s_float = std::stof(other);
            s_int = static_cast<int>(s_float);
            s_char = static_cast<char>(s_float);
            s_double = static_cast<double>(s_float);
            break;
        case type_double :
            s_float = std::stof(other);
            s_int = static_cast<int>(s_float);
            s_char = static_cast<char>(s_float);
            s_double = static_cast<double>(s_float);
            break;
        case type_pseudo :
            s_float = std::stof(other);
            s_int = static_cast<int>(s_float);
            s_char = static_cast<char>(s_float);
            s_double = static_cast<double>(s_float);
            break;
        case type_invalid :
            s_float = std::stof(other);
            s_int = static_cast<int>(s_float);
            s_char = static_cast<char>(s_float);
            s_double = static_cast<double>(s_float);
            break;
        default :
            std::cout << "Unknown or invalid literal" << std::endl;
            return;
    }
    printConversions(s_char, s_int, s_float, s_double);
}








