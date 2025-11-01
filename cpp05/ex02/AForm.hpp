#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private :
        const   std::string name;
        bool    isSigned;
        const   int gradeToSign;
        const   int gradeToExecute;
    public:
        AForm ();
        AForm (const std::string &nstr, int ngradeToSign, int ngradeToExecute);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();
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
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& output, const AForm &other);








#endif
