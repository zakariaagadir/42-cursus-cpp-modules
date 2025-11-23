#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include<iostream>
#include<algorithm>
#include<exception>


class specialex : public std::exception{
    virtual const char* what() const throw()
        {
            return "Value not found in container";
        }
};

template<class T>
typename T::iterator easyfind(T &container, int tofind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), tofind);
    if(it == container.end())
        throw specialex();
    return (it);
}











#endif