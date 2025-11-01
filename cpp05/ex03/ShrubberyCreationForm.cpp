#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getisSigned())
        throw AForm::GradeTooLowException();

    if (executor.getGrade() > getgradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: could not open file for writing." << std::endl;
        return;
    }

    outfile << "       /\\\n"
               "      /\\*\\\n"
               "     /\\O\\*\\\n"
               "    /*/\\/\\/\\\n"
               "   /\\O\\/\\*\\/\\\n"
               "  /\\*\\/\\*\\/\\/\\\n"
               " /\\O\\/\\/*/\\/O/\\\n"
               "       ||\n"
               "       ||\n"
               "       ||\n";

    outfile.close();

    std::cout << "🌲 ShrubberyCreationForm: created file '"
              << _target << "_shrubbery'" << std::endl;
}
