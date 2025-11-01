#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat(): name("default"), grade(150){
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.getName()), grade(other.getGrade()){

}

Bureaucrat::Bureaucrat (const std::string &str, int grd): name(str){
    if (grd < 1)
        throw GradeTooHighException();
    else if (grd > 150)
        throw GradeTooLowException();
    else
        this->grade = grd;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other)
    {
        this->grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const std::string& Bureaucrat::getName() const{
    return (this->name);
}
int Bureaucrat::getGrade() const{
    return (this->grade);
}


void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::increment()
{
    if((this->grade - 1) >= 1)
        this->grade--;
}
void Bureaucrat::decrement()
{
    if((this->grade + 1) <= 150)
        this->grade++;
}
