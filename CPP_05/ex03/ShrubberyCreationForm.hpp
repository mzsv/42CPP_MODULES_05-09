/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 01:04:02 by amenses-          #+#    #+#             */
/*   Updated: 2023/09/28 03:09:36 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class   ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(ShrubberyCreationForm const& form);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm&  operator=(ShrubberyCreationForm const& form);

        std::string const&      getTarget() const;
        void                    action() const;
};

#endif
