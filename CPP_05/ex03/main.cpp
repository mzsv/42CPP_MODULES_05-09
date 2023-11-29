/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:27:37 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/03 17:32:33 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    try
    {
        Intern      someRandomIntern;
        AForm*      rrf;
        AForm*      ppf;
        AForm*      srf;
        Bureaucrat  b("Gaga", 1);

        srand(time(0));
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        b.signForm(*rrf);
        rrf->execute(b);
        std::cout << std::endl;

        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
        std::cout << *ppf << std::endl;
        b.signForm(*ppf);
        ppf->execute(b);
        std::cout << std::endl;

        srf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        std::cout << *srf << std::endl;
        b.signForm(*srf);
        srf->execute(b);
        std::cout << std::endl;

        delete rrf;
        delete ppf;
        delete srf;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    try
    {
        Intern      someRandomIntern;
        AForm*      rrf;
        Bureaucrat  b("Gaga", 1);

        rrf = someRandomIntern.makeForm("invalid request", "Bender");
        std::cout << *rrf << std::endl;
        b.signForm(*rrf);
        rrf->execute(b);

        delete rrf;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
