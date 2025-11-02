#include "ScalarConverter.hpp"


int main(void)
{

    std::cout << "\n=== Testing INT literals ===\n";
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-123");
    ScalarConverter::convert("2147483648"); // Overflow

    std::cout << "\n=== Testing FLOAT literals ===\n";
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("-123.45f");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");

    std::cout << "\n=== Testing DOUBLE literals ===\n";
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("3.14159");
    ScalarConverter::convert("-123.456");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");

    std::cout << "\n=== Testing INVALID literals ===\n";
    ScalarConverter::convert("hello");
    ScalarConverter::convert("42abc");

    return 0;
}




