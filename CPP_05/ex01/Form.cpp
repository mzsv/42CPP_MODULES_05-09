/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:23:18 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/28 18:56:22 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
    _isSigned(false),
    _signGrade(150),
    _execGrade(150)
{
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(std::string const name, int sign_grade, int exec_grade) :
    _name(name),
    _isSigned(false),
    _signGrade(sign_grade),
    _execGrade(exec_grade)
{
    std::cout << "Form parametrized constructor" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const& form) :
    _name(form._name),
    _isSigned(form._isSigned),
    _signGrade(form._signGrade),
    _execGrade(form._execGrade) 
{
    std::cout << "Form copy constructor" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor" << std::endl;
}

Form&               Form::operator=(Form const& form)
{
    if (this != &form)
    {
        this->_isSigned = form._isSigned;
    }
    return *this;
}

std::string const   Form::getName() const
{
    return this->_name;
}

bool                Form::getIsSigned() const
{
    return this->_isSigned;
}

int                 Form::getSignGrade() const
{
    return this->_signGrade;
}

int                 Form::getExecGrade() const
{
    return this->_execGrade;
}

void                Form::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char*         Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char*         Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream&       operator<<(std::ostream& os, Form const& form)
{
    os << form.getName() << ", is signed: " << form.getIsSigned()
        << ", sign grade: " << form.getSignGrade()
        << ", execution grade: " << form.getExecGrade();
    return os;
}
