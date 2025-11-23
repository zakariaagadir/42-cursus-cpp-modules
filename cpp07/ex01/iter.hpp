#ifndef ITER_HPP
#define ITER_HPP



#include <iostream>




template <class A>
void function(A i)
{
    std::cout<< i<<std::endl;
}


template <class T, class U>
void iter(T arr[], const int size, U f)
{
    if(arr && f)
    {
        for(int i = 0; i < size;i++)
        {
            f(arr[i]);
        }
    }


}

std::string function2();









#endif
