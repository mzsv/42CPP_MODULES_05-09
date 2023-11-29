/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:22:07 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/28 18:56:43 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat  a("a", 10);
        Form        f("f", 100, 100);
        
        std::cout << a << std::endl;
        std::cout << f << std::endl;
        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat  a("a", 100);
        Form        f("f", 10, 10);
        
        std::cout << a << std::endl;
        std::cout << f << std::endl;
        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Form        f("f", 10, 10);
        Form        cpy(f);
        Form        cpy2;

        cpy2 = f;
        std::cout << f << std::endl;
        std::cout << cpy << std::endl;
        std::cout << cpy2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
