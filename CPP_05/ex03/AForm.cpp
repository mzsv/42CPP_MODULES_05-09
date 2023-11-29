/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:48:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 00:41:42 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
    _isSigned(false),
    _signGrade(150),
    _execGrade(150)
{
    // std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(std::string const name, int sign_grade, int exec_grade) :
    _name(name),
    _isSigned(false),
    _signGrade(sign_grade),
    _execGrade(exec_grade)
{
    // std::cout << "AForm parametrized constructor" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
    {
        throw AForm::GradeTooHighException();
    }
    else if (sign_grade > 150 || exec_grade > 150)
    {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(AForm const& AForm) :
    _name(AForm._name),
    _isSigned(AForm._isSigned),
    _signGrade(AForm._signGrade),
    _execGrade(AForm._execGrade) 
{
    // std::cout << "AForm copy constructor" << std::endl;
}

AForm::~AForm()
{
    // std::cout << "AForm destructor" << std::endl;
}

AForm&               AForm::operator=(AForm const& AForm)
{
    if (this != &AForm)
    {
        this->_isSigned = AForm._isSigned;
    }
    return *this;
}

std::string const   AForm::getName() const
{
    return this->_name;
}

bool                AForm::getIsSigned() const
{
    return this->_isSigned;
}

int                 AForm::getSignGrade() const
{
    return this->_signGrade;
}

int                 AForm::getExecGrade() const
{
    return this->_execGrade;
}

void                AForm::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
    {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

void                AForm::execute(Bureaucrat const& executor) const
{
    if (executor.getGrade() > this->_execGrade)
    {
        throw AForm::GradeTooLowException();
    }
    if (!this->_isSigned)
    {
        throw AForm::FormNotSignedException();
    }
    this->action();
}

const char*         AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char*         AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char*         AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream&       operator<<(std::ostream& os, AForm const& AForm)
{
    os << AForm.getName() << ", is signed: " << AForm.getIsSigned()
        << ", sign grade: " << AForm.getSignGrade()
        << ", execution grade: " << AForm.getExecGrade();
    return os;
}
