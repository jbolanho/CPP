#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>


class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span();    
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();


        void addNumber(int n);

        int shortestSpan() const;

        int longestSpan() const;

        template <typename InputIterator>
        void addRange(InputIterator begin, InputIterator end)
        {
            if (_numbers.size() + std::distance(begin, end) > _maxSize)
                throw FullSpanException();
            _numbers.insert(_numbers.end(), begin, end);
        }
    
        class FullSpanException : public std::exception 
        {
            public:
                const char* what() const throw();
        };

        class NotEnoughNumbersException : public std::exception 
        {
            public:
                const char* what() const throw();
        }; 
};

#endif