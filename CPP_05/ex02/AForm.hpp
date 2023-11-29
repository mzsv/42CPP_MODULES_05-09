/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:49:01 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/28 18:59:51 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class AForm
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _signGrade;
        int const           _execGrade;

    public:
        AForm();
        AForm(std::string const name, int sign_grade, int exec_grade);
        AForm(AForm const& AForm);
        virtual ~AForm();
        AForm&               operator=(AForm const& AForm);

        std::string const   getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        void                beSigned(Bureaucrat const& bureaucrat);
        void                execute(Bureaucrat const& executor) const;
        virtual void        action() const = 0;

        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class   GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class   FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&    operator<<(std::ostream& os, AForm const& AForm);

#endif
