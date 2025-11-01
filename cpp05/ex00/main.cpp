#include <iostream>
#include "Bureaucrat.hpp"

int main() 
{
    std::cout << "=== Bureaucrat Tests ===" << std::endl;

    try {
        Bureaucrat b1("Alice", 151);
        std::cout << b1.getName() << " created with grade " << b1.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    Bureaucrat b2("Bob", 8);
    try {
        b2.decrement();
        std::cout << b2.getName() << " was decremented to " << b2.getGrade() << std::endl;
        b2.increment();
        std::cout << b2.getName() << " was incremented to " << b2.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error creating Bureaucrat b2: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b3("Charlie", 151);
        std::cout << b3.getName() << " created with grade " << b3.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error creating Bureaucrat b3: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b4("David", 10);
        Bureaucrat b5(b4);
        std::cout << "Copied " << b5.getName() << " with grade " << b5.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b6("Eve", 50);
        Bureaucrat b7("Frank", 120);
        b7 = b6;
        std::cout << "After assignment, " << b7.getName()
                  << " has grade " << b7.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
