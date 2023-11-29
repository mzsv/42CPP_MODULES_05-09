/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:23:13 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/28 18:56:31 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _signGrade;
        int const           _execGrade;

    public:
        Form();
        Form(std::string const name, int sign_grade, int exec_grade);
        Form(Form const& form);
        ~Form();
        Form&               operator=(Form const& form);

        std::string const   getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        void                beSigned(Bureaucrat const& bureaucrat);

        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&    operator<<(std::ostream& os, Form const& form);

#endif
