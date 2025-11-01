#include "test.hpp"

std::string function1(std::string name, std::string last_name)
{
    return(name + " " + last_name);
}

std::string function2(int age)
{
    return(std::to_string(age) + " ");
}

std::string function3(std::string name, std::string last_name)
{
    return("thank you !");
}

int main()
{
    std::string (*array_fun[2])(std::string name, std::string last_name) = {[](std::string t, std::string u) -> std::string{return(t + " " + u);}, [](std::string t, std::string u) -> std::string {return("thank you !");}};
    std::cout<<array_fun[0]("zakaria", "mounji")<<std::endl;
    std::cout<<array_fun[1]("zakaria", "mounji")<<std::endl;


    return (0);
}