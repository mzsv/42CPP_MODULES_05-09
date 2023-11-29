/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:49:23 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/03 17:32:04 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class   RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

        RobotomyRequestForm();
    
    public:
        RobotomyRequestForm(std::string const& target);
        RobotomyRequestForm(RobotomyRequestForm const& form);
        ~RobotomyRequestForm();
        RobotomyRequestForm&    operator=(RobotomyRequestForm const& form);

        std::string const&      getTarget() const;
        void                    action() const;
};

#endif
