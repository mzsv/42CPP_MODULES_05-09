/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:21:10 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 20:50:07 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() :
    _n(0),
    _vector(new std::vector<int>())
{
}

Span::Span(unsigned int n) :
    _n(n),
    _vector(new std::vector<int>())
{
}

Span::Span(Span const& src)
{
    *this = src;
}

Span::~Span()
{
    _vector->clear();
    delete _vector;
}

Span& Span::operator=(Span const& obj)
{
    if (this != &obj)
    {
        _n = obj._n;
        _vector = obj._vector;
    }
    return (*this);
}

void        Span::addNumber(int number)
{
    if (_vector->size() == _n)
    {
        throw FullSpanException();
    }
    _vector->push_back(number);
}

int         Span::shortestSpan()
{
    if (_vector->size() < 2)
    {
        throw NoSpanException();
    }
    int result = std::abs(_vector->at(0) - _vector->at(1));
    for (std::vector<int>::iterator it = _vector->begin(); it != _vector->end() - 1; it++)
    {
        for (std::vector<int>::iterator it2 = it + 1; it2 != _vector->end(); it2++)
        {
            result = std::min(result, std::abs(*it - *it2));
        }
    }
    return result;
}

int         Span::longestSpan()
{
    if (_vector->size() < 2)
    {
        throw NoSpanException();
    }
    return std::abs(*std::min_element(_vector->begin(), _vector->end()) - \
        *std::max_element(_vector->begin(), _vector->end()));
}

void        Span::addRange()
{
    try
    {
        for (unsigned int i = 0; i < _n; i++)
        {
            addNumber(rand() % 123);
        }
    }
    catch(const std::exception& e)
    {
        return ;
    }
}

const char* Span::FullSpanException::what() const throw()
{
    return ("Span is full");
}

const char* Span::NoSpanException::what() const throw()
{
    return ("Not enough elements in span");
}
