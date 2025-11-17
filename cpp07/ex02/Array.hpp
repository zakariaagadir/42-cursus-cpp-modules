#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>


template <class T>
class Array
{
    private:
        T *arr;
        unsigned int n;
    public:
        Array()
        {
            arr = 0;
            n = 0;
        }
        Array(const Array& other)
        {
            n = other.n;
            arr = new T[n]();
            for(unsigned int i = 0; i< n ; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        Array(unsigned int n)
        {
            this->n = n;
            arr = new T[n]();

        }
        Array& operator=(const Array& other)
        {
            if(this != &other)
            {
                delete[] (arr);
                arr = 0;
                n = other.n;
                arr = new T[n]();
                for(unsigned int i = 0; i < n; i++)
                {
                    arr[i] = other.arr[i];
                }
            }
            return(*this);
        }
        T& operator[](unsigned int n)
        {
            if((this->n <= n) || (n < 0))
            {
                throw std::exception();
            }
            return(arr[n]);
        }
        ~Array()
        {
            delete[] (arr);
        }
};







#endif
