/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:50:08 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 00:44:21 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
    AForm("PresidentialPardonForm", 25, 5),
    _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& form) :
    AForm(form),
    _target(form._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& form)
{
    AForm::operator=(form);
    _target = form._target;
    return (*this);
}

std::string const&      PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void                    PresidentialPardonForm::action() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
