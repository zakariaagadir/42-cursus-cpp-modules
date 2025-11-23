#ifndef SPAN_HPP
#define SPAN_HPP




class Span{
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
