#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <iomanip>

std::map<std::string, float> re_conatiner(std::string name)
{
    std::ifstream infile;
    int i =0;
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
        if(i == 0)
        {
            i++;
            continue;
        }
        size_t index;
        index = line.find(",");
        if(index == std::string::npos)
        {
            i++;
            continue;
        }
        std::string str1;
        std::string str2;
        float price;
        str1 = line.substr(0,index);
        str2 = line.substr(index + 1);
        price = atof(str2.c_str());
        test.insert(std::pair<std::string, float>(str1, price));
    }
    i++;
    return(test);
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr<<"Error"<<std::endl;
        return(1);
    }
    std::string buffer;
    std::ifstream infile;
    std::map<std::string, float>other_m;
    infile.open(argv[1]);
    if(!infile.is_open())
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }

    int i = 0;

    while(getline(infile, buffer))
    {
        size_t index;
        std::string s = "date | value";
        index = buffer.find(" | ");
        if(i == 0)
        {
            if(s != buffer)
            {
                std::cerr<<"Error"<<std::endl<<s<<std::endl<<buffer;
                return(1);
            }
            i++;
            continue;
        }
        if(index == std::string::npos)
        {
            other_m.insert(std::pair<std::string, float>("Error: bad input => 2001-42-42", price));
            i++;
            continue;
        }
        std::string str1;
        std::string str2;
        float price;
        str1 = buffer.substr(0,index);
        str2 = buffer.substr(index + 3);
        price = atof(str2.c_str());
        other_m.insert(std::pair<std::string, float>(str1, price));
        i++;
    }

    std::map<std::string, float>t_map = re_conatiner("data.csv");
    std::map<std::string, float>::iterator it = other_m.begin();
    std::map<std::string, float>::iterator at = other_m.end();
    while(it != at)
    {
        std::cout << it->first << " => "<<(it->second) * (t_map[it->first])<<std::endl;
        std::cout<<other_m.size()<<std::endl;
        it++;
    }

    return(0);
}