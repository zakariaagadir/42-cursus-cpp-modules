#include "Form.hpp"


Form::Form():name("Default"), isSigned(false), gradeToSign(150),gradeToExecute(150)
{

}
Form::Form(const std::string &nstr, int ngradeToSign, int ngradeToExecute):name(nstr), isSigned(false), gradeToSign(ngradeToSign),gradeToExecute(ngradeToExecute)
{
    if ((ngradeToSign < 1) || (ngradeToExecute < 1))
        throw GradeTooHighException();
    else if ((ngradeToSign > 150) || (ngradeToExecute > 150))
        throw GradeTooLowException();
}

Form::Form(const Form &other): name(other.name),isSigned(other.isSigned),gradeToSign(other.gradeToSign),gradeToExecute(other.gradeToExecute)
{

}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

Form::~Form()
{

}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}


const std::string& Form::getname() const{
    return(name);
}
bool Form::getisSigned() const
{
    return (isSigned);
}
int Form::getgradeToSign() const
{
    return (gradeToSign);
}
int Form::getgradeToExecute() const
{
    return (gradeToExecute);
}
void Form::beSigned(Bureaucrat& other)
{
     if (other.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const std::string& Form::getName() const 
{
    return (this->name);
}

std::ostream& operator<<(std::ostream& output, const Form &other)
{
    output << "Form " << other.getname() << ", signed: " << (other.getisSigned() ? "true" : "false") << ", grade to sign: " << other.getgradeToSign() << ", grade to execute: " << other.getgradeToExecute();
    return (output);
}