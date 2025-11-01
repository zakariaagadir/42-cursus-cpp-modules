#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Form tesstform("testform",50, 40);
    Bureaucrat brahim("brahim",50);
    Form other_other("form",60, 60);

    try
    {
        Form falseform("falseform",180, 40);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form true_form("true_form",60, 60);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        brahim.signForm(other_other);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    return 0;
}

