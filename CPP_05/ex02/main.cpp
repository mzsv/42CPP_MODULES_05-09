/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:53:20 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/03 17:31:48 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm   shrubbery("alpha");
        RobotomyRequestForm     robotomy("beta");
        PresidentialPardonForm  presidential("gamma");
        Bureaucrat              bureaucrat("Gaga", 1);

        std::cout << bureaucrat << std::endl;
        std::cout << shrubbery << std::endl;
        bureaucrat.signForm(shrubbery);
        std::cout << shrubbery << std::endl;
        bureaucrat.executeForm(shrubbery);
        std::cout << std::endl;

        srand(time(0));
        std::cout << robotomy << std::endl;
        bureaucrat.signForm(robotomy);
        std::cout << robotomy << std::endl;
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(robotomy);
        std::cout << std::endl;

        std::cout << presidential << std::endl;
        bureaucrat.signForm(presidential);
        std::cout << presidential << std::endl;
        bureaucrat.executeForm(presidential);
        std::cout << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm   shrubbery("alpha1");
        RobotomyRequestForm     robotomy("beta");
        PresidentialPardonForm  presidential("gamma");
        Bureaucrat              bureaucrat("Gaga", 50);

        std::cout << bureaucrat << std::endl;
        std::cout << shrubbery << std::endl;
        bureaucrat.signForm(shrubbery);
        std::cout << shrubbery << std::endl;
        bureaucrat.executeForm(shrubbery);
        std::cout << std::endl;

        std::cout << robotomy << std::endl;
        bureaucrat.signForm(robotomy);
        std::cout << robotomy << std::endl;
        bureaucrat.executeForm(robotomy);
        std::cout << std::endl;

        std::cout << presidential << std::endl;
        bureaucrat.signForm(presidential);
        std::cout << presidential << std::endl;
        bureaucrat.executeForm(presidential);
        std::cout << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    try
    {
        AForm*      a = new ShrubberyCreationForm("alpha2");
        AForm*      b = new RobotomyRequestForm("beta");
        AForm*      c = new PresidentialPardonForm("gamma");
        Bureaucrat* d = new Bureaucrat("Gaga", 50);

        std::cout << *d << std::endl;
        std::cout << *a << std::endl;
        d->signForm(*a);
        std::cout << *a << std::endl;
        d->executeForm(*a);
        std::cout << std::endl;

        std::cout << *b << std::endl;
        d->signForm(*b);
        std::cout << *b << std::endl;
        d->executeForm(*b);
        std::cout << std::endl;

        std::cout << *c << std::endl;
        d->signForm(*c);
        std::cout << *c << std::endl;
        d->executeForm(*c);
        std::cout << std::endl;

        delete a;
        delete b;
        delete c;
        delete d;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
