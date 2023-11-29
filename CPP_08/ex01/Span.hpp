/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:21:21 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/10 01:24:29 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <cstdlib>
# include <ctime>

class Span
{
    private:
        unsigned int        _n;
        std::vector<int>    *_vector;
    
    public:
        Span();
        Span(unsigned int);
        Span(Span const&);
        ~Span();
        Span& operator=(Span const&);

        void    addNumber(int);
        int     shortestSpan();
        int     longestSpan();
        void    addRange();

        class FullSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
