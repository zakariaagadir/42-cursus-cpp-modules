#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 2);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // LIST example
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
