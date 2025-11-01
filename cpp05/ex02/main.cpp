#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid-level", 50);
        Bureaucrat low("Intern", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n=== Initial States ===" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n=== Signing Forms ===" << std::endl;
        low.signAForm(shrub);
        mid.signAForm(robot);
        boss.signAForm(pardon); 

        std::cout << "\n=== Executing Forms ===" << std::endl;
        low.executeForm(shrub);
        mid.executeForm(robot);
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "❌ Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
