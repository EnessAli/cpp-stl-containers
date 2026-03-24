#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    
    template<typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);
    
    int shortestSpan() const;
    int longestSpan() const;
    
    unsigned int size() const;
    unsigned int maxSize() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

template<typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end) {
    while (begin != end) {
        if (_numbers.size() >= _maxSize)
            throw SpanFullException();
        _numbers.push_back(*begin);
        ++begin;
    }
}

#endif
