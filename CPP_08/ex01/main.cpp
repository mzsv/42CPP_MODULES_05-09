/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:21:01 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/11 21:16:22 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "---------------------" << std::endl;
        Span a = Span(5);

        a.addNumber(6);
        a.addNumber(3);
        a.addNumber(17);
        a.addNumber(9);
        a.addNumber(11);
        std::cout << a.shortestSpan() << std::endl;
        std::cout << a.longestSpan() << std::endl;
        std::cout << "---------------------" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "---------------------" << std::endl;
        Span b = Span(10000);

        srand(time(0));
        b.addRange();
        std::cout << b.shortestSpan() << std::endl;
        std::cout << b.longestSpan() << std::endl;
        std::cout << "---------------------" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "---------------------" << std::endl;
        Span c = Span(7);
    
        c.addNumber(0);
        c.addNumber(1);
        c.addNumber(1);
        c.addNumber(2);
        c.addNumber(3);
        c.addNumber(5);
        c.addNumber(8);
        std::cout << c.shortestSpan() << std::endl;
        std::cout << c.longestSpan() << std::endl;
        c.addNumber(13);
        std::cout << "---------------------" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "---------------------" << std::endl;
        Span d = Span(7);
        
        d.addNumber(0);
        try
        {
            std::cout << d.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << d.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "---------------------" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
