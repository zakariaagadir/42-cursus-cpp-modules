#include"BitcoinExchange.hpp"



int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr<<"Error: could not open file."<<std::endl;
        return(1);
    }
    std::string buffer;
    std::ifstream infile;
    std::map<std::string, double>other_m;
    infile.open(argv[1]);
    if(!infile.is_open())
    {
        std::cerr<<"Error"<<std::endl;
        return 1;
    }

    int i = 0;
    std::map<std::string, double>t_map = re_conatiner("data.csv");
    if(t_map.size() == 0)
    {
        return(1);
    }
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
            std::cout << "Error: bad input => " << buffer << std::endl;
            i++;
            continue;
        }
        std::string str1;
        std::string str2;
        double price;
        str1 = buffer.substr(0,index);
        str2 = buffer.substr(index + 3);
        price = atof(str2.c_str());
        if((price < 0 ) || (price > 1000))
        {
            if(price < 0)
                std::cout<<"Error: not a positive number."<<std::endl;
            if(price > 1000)
                std::cout<<"Error: too large a number."<<std::endl;
            i++;
            continue;
        }
        std::cout << str1 << " => "<< price <<" = "<<(price) * (t_map[str1])<<std::endl;
        i++;
    }

    return(0);
}