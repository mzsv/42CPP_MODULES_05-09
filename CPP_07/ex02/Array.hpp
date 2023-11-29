/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:38:39 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/02 00:30:15 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class   Array
{
    private:
        T*              _array;
        unsigned int    _size;

    public:
        Array();
        Array(unsigned int);
        Array(Array const&);
        ~Array();
        Array&      operator=(Array const&);
        T&          operator[](unsigned int const&);
        T const&    operator[](unsigned int const&) const;

        unsigned int    size() const;
};

class   OutOfRangeException : public std::exception
{
    public:
        virtual const char *what() const throw();
};

#endif
