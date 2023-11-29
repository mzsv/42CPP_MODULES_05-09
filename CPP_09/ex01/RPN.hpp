/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:50:31 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/17 23:28:48 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>
# include <sstream>
# include <cstdlib>

enum eOperation
{
    ADD = '+',
    SUBTRACT = '-',
    MULTIPLY = '*',
    DIVIDE = '/'
};

class RPN
{
    private:
        static std::stack<double>   _stack;

        RPN();
        RPN(RPN const& obj);
        RPN& operator=(RPN const& obj);

    public:
        ~RPN();

        static void calculate(std::string const& input);
};

class InvalidInputException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
