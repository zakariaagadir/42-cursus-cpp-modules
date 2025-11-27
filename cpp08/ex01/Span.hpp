#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>




class Span{
    private:
        unsigned int max_;
        std::vector<int> data_;
        Span();
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        void addNumbers(int* numbers, unsigned int count);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};





#endif
