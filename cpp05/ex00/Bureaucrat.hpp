#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat{
    private :
        const std::string name;
        int grade;
    public:
        Bureaucrat ();
        Bureaucrat (const std::string &str, int grd);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

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
        const std::string& getName() const;
        int getGrade() const;
        void increment();
        void decrement();

};








#endif
