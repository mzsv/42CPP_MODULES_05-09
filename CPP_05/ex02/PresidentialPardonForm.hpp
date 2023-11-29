/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:50:25 by amenses-          #+#    #+#             */
/*   Updated: 2023/09/28 03:09:47 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

        PresidentialPardonForm();

    public:
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(PresidentialPardonForm const& form);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(PresidentialPardonForm const& form);

        std::string const&      getTarget() const;
        void                    action() const;
};

#endif
