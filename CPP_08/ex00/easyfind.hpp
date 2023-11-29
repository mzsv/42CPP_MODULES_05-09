/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:29:18 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 20:48:45 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <iterator>
# include <vector>
# include <list>
# include <deque>
# include <set>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator    it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::exception();
    }
    return (it);
}

#endif
