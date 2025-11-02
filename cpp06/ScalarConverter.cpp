#include "ScalarConverter.hpp"


// ScalarConverter::ScalarConverter()
// {

// }

// ScalarConverter::ScalarConverter(const ScalarConverter& other)
// {

// }

// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
// {

// }

// ScalarConverter::~ScalarConverter()
// {

// }


float strToFloat(const std::string &s)
{
    float f;
    std::stringstream ss(s);
    ss >> f;
    if (ss.fail() || !ss.eof()) // check conversion success
        throw std::invalid_argument("invalid float");
    return f;
}

double strToDouble(const std::string &s)
{
    double d;
    std::stringstream ss(s);
    ss >> d;
    if (ss.fail() || !ss.eof())
        throw std::invalid_argument("invalid double");
    return d;
}

int strToInt(const std::string &s)
{
    int i;
    std::stringstream ss(s);
    ss >> i;
    if (ss.fail() || !ss.eof())
        throw std::invalid_argument("invalid int");
    return i;
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

void ScalarConverter::convert(std::string other)
{
    leteral_type type = get_type(other);
    float s_float;
    int s_int;
    char s_char;
    double s_double;
    switch (type)
    {
        case type_char :

            try {
                s_float = strToFloat(other);
                s_int = static_cast<int>(s_float);
                s_char = other[0];
                s_double = static_cast<double>(s_float);
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
                return;
            }
            break;
        case type_int :
            try {
                s_float = strToFloat(other);
                s_int = static_cast<int>(s_float);
                s_char = static_cast<char>(s_float);
                s_double = static_cast<double>(s_float);
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
                return;
            }
            break;
        case type_float :
            try {
                s_float = strToFloat(other);
                s_int = static_cast<int>(s_float);
                s_char = static_cast<char>(s_float);
                s_double = static_cast<double>(s_float);
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
                return;
            }
            break;
        case type_double :
            try {
                s_float = strToFloat(other);
                s_int = static_cast<int>(s_float);
                s_char = static_cast<char>(s_float);
                s_double = static_cast<double>(s_float);
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
                return;
            }
            break;
        case type_pseudo :
            try {
                s_float = strToFloat(other);
                s_int = static_cast<int>(s_float);
                s_char = static_cast<char>(s_float);
                s_double = static_cast<double>(s_float);
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
                return;
            }
            break;
        case type_invalid :
            try {
                s_float = strToFloat(other);
                s_int = static_cast<int>(s_float);
                s_char = static_cast<char>(s_float);
                s_double = static_cast<double>(s_float);
            } catch (std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
                return;
            }
            break;
        default :
            std::cout << "Unknown or invalid literal" << std::endl;
            return;
    }
    printConversions(s_char, s_int, s_float, s_double);
}








