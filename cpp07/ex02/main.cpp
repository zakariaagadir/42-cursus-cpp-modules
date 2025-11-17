#include <iostream>
#include "Array.hpp"
#include <string>


int main( void ) {

    Array<int> u (15);
    for(int i = 0; i < 15; i++)
    {
        u[i] = i;
    }
    for(int i = 0; i < 15; i++)
    {
        std::cout<<u[i] << std::endl;
    }
    try {
        u[25] = 9;

    } catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
