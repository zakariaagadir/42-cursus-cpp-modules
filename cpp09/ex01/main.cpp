#include "RPN.hpp"





int main(int argc, char* argv[])
{
    std::stack<int> stac;
    if(argc != 2)
    {
        std::cerr<<"error 1"<<std::endl;
        return(1);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string s = argv[i];
        for(size_t j = 0; j<s.size(); j++)
        {
            if(isdigit(s[j]))
            {
                stac.push(s[j] - '0');
            } else
            {
                if(isOperator(s[j]))
                {
                    if(stac.size() < 2)
                    {
                        std::cerr << "Error 2"<< std::endl;
                        return(1);
                    }
                    int a = stac.top();
                    stac.pop();
                    int b = stac.top();
                    stac.pop();
                    int res = makeoper(a,b, s[j]);
                    stac.push(res);
                } else if(s[j] != ' ')
                {
                    std::cerr << "Error 3"<< std::endl;
                    return(1);
                }
            }

        }
    }
    if(stac.size() != 1)
    {
        std::cerr << "Error "<< std::endl;
        return(1);
    }
    std::cout << stac.top()<< std::endl;
    return(0);
}