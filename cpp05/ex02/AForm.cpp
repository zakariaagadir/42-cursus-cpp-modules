#include "AForm.hpp"


AForm::AForm():name("Default"), isSigned(false), gradeToSign(150),gradeToExecute(150)
{

}
AForm::AForm(const std::string &nstr, int ngradeToSign, int ngradeToExecute):name(nstr), isSigned(false), gradeToSign(ngradeToSign),gradeToExecute(ngradeToExecute)
{
    if ((ngradeToSign < 1) || (ngradeToExecute < 1))
        throw GradeTooHighException();
    else if ((ngradeToSign > 150) || (ngradeToExecute > 150))
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other): name(other.name),isSigned(other.isSigned),gradeToSign(other.gradeToSign),gradeToExecute(other.gradeToExecute)
{

}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

AForm::~AForm()
{

}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low!";
}


const std::string& AForm::getname() const{
    return(name);
}
bool AForm::getisSigned() const
{
    return (isSigned);
}
int AForm::getgradeToSign() const
{
    return (gradeToSign);
}
int AForm::getgradeToExecute() const
{
    return (gradeToExecute);
}
void AForm::beSigned(Bureaucrat& other)
{
     if (other.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const std::string& AForm::getName() const 
{
    return (this->name);
}

std::ostream& operator<<(std::ostream& output, const AForm &other)
{
    output << "AForm " << other.getname() << ", signed: " << (other.getisSigned() ? "true" : "false") << ", grade to sign: " << other.getgradeToSign() << ", grade to execute: " << other.getgradeToExecute();
    return (output);
}