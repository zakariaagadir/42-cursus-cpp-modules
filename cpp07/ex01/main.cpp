#include <iostream>
#include "iter.hpp"
#include <string>


int main( void ) {
    std::string ar[] = {"1","2","3","4","5","6","7","8","9"};

    iter(ar,9,function<std::string>);
    std::cout<<ar[5]<<std::endl;
    return 0;
}
