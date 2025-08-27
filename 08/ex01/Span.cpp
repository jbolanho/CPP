#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}



const char* Span::FullSpanException::what() const throw()
{
    return "Span is full or out of range";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to find a span";
}


void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxSize)
        throw FullSpanException();
    _numbers.push_back(n);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}
