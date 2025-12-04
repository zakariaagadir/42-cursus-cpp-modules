#include"BitcoinExchange.hpp"

std::map<std::string, double> re_conatiner(std::string name)
{
    std::ifstream infile;
    std::string s = "date,exchange_rate\n";
    int i = 0;
    std::map<std::string, double>test;
    infile.open(name.c_str());
    if(!infile.is_open())
    {
        return(test);
    }
    std::string line;
    while(std::getline(infile, line))
    {
        if(i == 0)
        {
            if(s.compare(line) == 0)
            {
                std::cerr<<"Error"<<std::endl<<s<<std::endl<<line;
                return(test);
            }
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
        double price;
        str1 = line.substr(0,index);
        str2 = line.substr(index + 1);
        price = atof(str2.c_str());
        test.insert(std::pair<std::string, double>(str1, price));
        i++;
    }
    return(test);
}