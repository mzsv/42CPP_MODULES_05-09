/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:52 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 00:43:43 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string const Intern::_form_list[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

AForm*  (Intern::*Intern::_funcPtr[3])(std::string) const = {
    &Intern::makeShrubberyCreationForm,
    &Intern::makeRobotomyRequestForm,
    &Intern::makePresidentialPardonForm
};

Intern::Intern()
{
    // std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(Intern const &intern)
{
    // std::cout << "Intern copy constructor" << std::endl;
    *this = intern;
}

Intern::~Intern()
{
    // std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator=(Intern const& intern)
{
    // std::cout << "Intern assignment operator" << std::endl;
    (void)intern;
    return (*this);
}

AForm*  Intern::makeShrubberyCreationForm(std::string target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm*  Intern::makeRobotomyRequestForm(std::string target) const
{
    return (new RobotomyRequestForm(target));
}

AForm*  Intern::makePresidentialPardonForm(std::string target) const
{
    return (new PresidentialPardonForm(target));
}

AForm*  Intern::makeForm(std::string form_name, std::string target) const
{
    AForm*  form = 0;

    for (int i = 0; i < 3; i++)
    {
        if (form_name == _form_list[i])
        {
            form = (this->*_funcPtr[i])(target);
            std::cout << "Intern creates " << form_name << std::endl;
            return form;
        }
    }
    throw InvalidFormException();
    return form;
}

const char* Intern::InvalidFormException::what() const throw()
{
    return ("Invalid form request");
}
