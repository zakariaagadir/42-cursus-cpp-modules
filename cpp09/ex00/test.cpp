#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib> // for exit()
#include <iomanip> // for setprecision

std::map<std::string, float> re_conatiner(std::string name)
{
    std::ifstream infile;
    std::map<std::string, float>test;
    infile.open(name.c_str());
    if(!infile.is_open())
    {
        return(test);
    }
    std::string line;
    std::getline(infile, line);
    while(std::getline(infile, line))
    {
        size_t index;
        index = line.find(",");
        if(index == std::string::npos)
        {
            continue;
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc !=2)
    {
        std::cout<<"Error"<<std::endl;
        return(1);
    }

    std::ifstream infile;
    infile.open(argv[1]);
    if(!infile.is_open())
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }

    std::map<std::string, float>t_map = re_conatiner("data.csv");


    return(0);
}