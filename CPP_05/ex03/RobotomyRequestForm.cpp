/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:49:44 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 00:44:45 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
    AForm("RobotomyRequestForm", 72, 45),
    _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& form) :
    AForm(form),
    _target(form._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm const& form)
{
    AForm::operator=(form);
    return (*this);
}

std::string const&      RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void                    RobotomyRequestForm::action() const
{
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
    {
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "Failed to robotomize " << this->_target << std::endl;
    }
}
