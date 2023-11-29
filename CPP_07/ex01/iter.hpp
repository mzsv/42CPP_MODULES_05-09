/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:07:08 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/11 19:46:01 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename U>
void    iter(T* array, size_t len, void (*f)(U&))
{
    if (!array)
    {
        return ;
    }
    for (size_t i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

#endif
