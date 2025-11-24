#include"Span.hpp"

Span::Span(unsigned int n): max_(n)
{
}

Span::Span(const Span& other): max_(other.max_), data_(other.data_)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        max_ = other.max_;
        data_ = other.data_;
    }
    return *this;
}

Span::~Span()
{

}
void Span::addNumber(int number)
{
    if (data_.size() >= max_)
        throw std::out_of_range("Span is full");
    data_.push_back(number);
}

void Span::addNumbers(int* numbers, unsigned int count)
{
    if (data_.size() + count > max_)
        throw std::out_of_range("Not enough space to add numbers");
    for (unsigned int i = 0; i < count; ++i)
    {
        data_.push_back(numbers[i]);
    }
}

unsigned int Span::shortestSpan() const
{
    if (data_.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sortedData = data_;
    std::sort(sortedData.begin(), sortedData.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedData.size(); ++i)
    {
        unsigned int span = sortedData[i] - sortedData[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (data_.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    int minVal = *std::min_element(data_.begin(), data_.end());
    int maxVal = *std::max_element(data_.begin(), data_.end());

    return static_cast<unsigned int>(maxVal - minVal);
}


