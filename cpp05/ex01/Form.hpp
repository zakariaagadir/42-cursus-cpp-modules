#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private :
        const   std::string name;
        bool    isSigned;
        const   int gradeToSign;
        const   int gradeToExecute;
    public:
        Form ();
        Form (const std::string &nstr, int ngradeToSign, int ngradeToExecute);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char* what() const throw();
        };
        const std::string& getname() const;
        bool getisSigned() const;
        int getgradeToSign() const;
        int getgradeToExecute() const;
        void beSigned(Bureaucrat& other);
        const std::string& getName() const;
};

std::ostream& operator<<(std::ostream& output, const Form &other);








#endif
