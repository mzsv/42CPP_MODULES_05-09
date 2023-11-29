/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 01:04:26 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/28 19:02:07 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm("ShrubberyCreationForm", 145, 137),
      _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& form)
    : AForm(form),
      _target(form._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm const& form)
{
    AForm::operator=(form);
    _target = form._target;
    return (*this);
}

std::string const&      ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void                    ShrubberyCreationForm::action() const
{
    std::ofstream   file;
    std::string     filename = _target + "_shrubbery";

    file.open(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file");
    }
    file << "    A\n"
        << "   / \\\n"
        << "  B   C\n"
        << " / \\\n"
        << "D   E\n";
    file.close();
}
