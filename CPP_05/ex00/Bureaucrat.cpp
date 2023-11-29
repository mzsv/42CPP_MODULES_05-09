/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:35:49 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/28 18:53:42 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
    _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) :
    _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        _grade = grade;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& bureaucrat) :
    _name(bureaucrat._name),
    _grade(bureaucrat._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&         Bureaucrat::operator=(Bureaucrat const& bureaucrat)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &bureaucrat)
    {
        _grade = bureaucrat._grade;
    }
    return *this;
}

std::string const   Bureaucrat::getName() const
{
    return this->_name;
}

int                 Bureaucrat::getGrade() const
{
    return this->_grade;
}

void                Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        _grade--;
    }
}

void                Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        _grade++;
    }
}

const char*         Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char*         Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream&       operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
