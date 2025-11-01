#include "Intern.hpp"




Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string &target) = {
        [](const std::string &t) -> AForm* { return new ShrubberyCreationForm(t); },
        [](const std::string &t) -> AForm* { return new RobotomyRequestForm(t); },
        [](const std::string &t) -> AForm* { return new PresidentialPardonForm(t); }
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    return nullptr;
}
