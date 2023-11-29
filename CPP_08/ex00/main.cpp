/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:29:07 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 20:49:04 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int>    vector;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);
    std::cout << "Vector: "
        << vector[0] << vector[1] << vector[2] << vector[3] << vector[4] << std::endl;
    try
    {
        std::cout << *easyfind(vector, 3) << std::endl;
        std::cout << *easyfind(vector, 0) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::list<int>  list;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    std::cout << "List: ";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    try
    {
        std::cout << *easyfind(list, 3) << std::endl;
        std::cout << *easyfind(list, 0) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::deque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_back(4);
    deque.push_back(5);
    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    try
    {
        std::cout << *easyfind(deque, 3) << std::endl;
        std::cout << *easyfind(deque, 0) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::set<int>   set;

    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);
    std::cout << "Set: ";
    for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    try
    {
        std::cout << *easyfind(set, 3) << std::endl;
        std::cout << *easyfind(set, 0) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
}
