/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:57 by amenses-          #+#    #+#             */
/*   Updated: 2023/09/29 00:11:42 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class   Intern
{
    protected:
        static std::string const    _form_list[3];
        static AForm*               (Intern::*_funcPtr[3])(std::string) const;

    public:
        Intern();
        Intern(Intern const &);
        ~Intern();
        Intern& operator=(Intern const&);

        AForm*  makeShrubberyCreationForm(std::string) const;
        AForm*  makeRobotomyRequestForm(std::string) const;
        AForm*  makePresidentialPardonForm(std::string) const;
        AForm*  makeForm(std::string, std::string) const;

        class   InvalidFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
