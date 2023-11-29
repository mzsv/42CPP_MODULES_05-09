/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:38:50 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/03 02:20:30 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() :
    _array(new T[0]()),
    _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) :
    _array(new T[n]()),
    _size(n)
{
}

template <typename T>
Array<T>::Array(Array const& obj) :
    _array(new T[obj._size]),
    _size(obj._size)
{
    (*this) = obj;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_array;
}

template <typename T>
Array<T>&       Array<T>::operator=(Array const& obj)
{
    if (this == &obj)
    {
        return (*this);
    }
    if (this->_array)
    {
        delete[] _array;
    }
    this->_array = new T[obj._size];
    this->_size = obj._size;
    for (unsigned int i = 0; i < obj._size; i++)
    {
        this->_array[i] = obj._array[i];
    }
    return (*this);
}

template <typename T>
T&              Array<T>::operator[](unsigned int const& i)
{
    if (i >= this->_size)
    {
        throw OutOfRangeException();
    }
    return (this->_array[i]);
}

template <typename T>
T const&        Array<T>::operator[](unsigned int const& i) const
{
    if (i >= _size)
    {
        throw OutOfRangeException();
    }
    return (this->_array[i]);
}

template <typename T>
unsigned int    Array<T>::size() const
{
    return (this->_size);
}

const char*     OutOfRangeException::what() const throw()
{
    return ("Index out of range");
}
