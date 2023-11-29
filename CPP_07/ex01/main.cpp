/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:06:58 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/11 19:46:41 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void    test_print(T const& x)
{
    std::cout << x << std::endl;
}

int main()
{
    int     int_array[5] = {1, 2, 3, 4, 5};
    char    char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    float   float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    std::cout << "int_array:" << std::endl;
    iter(int_array, 5, test_print<int>);
    std::cout << "char_array:" << std::endl;
    iter(char_array, 5, test_print<char>);
    std::cout << "float_array:" << std::endl;
    iter(float_array, 5, test_print<float>);
    return 0;
}
