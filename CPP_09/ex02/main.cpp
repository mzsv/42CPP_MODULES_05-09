/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:40:35 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 20:57:26 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

static void printTime(clock_t& start, clock_t end, \
    std::string const& container, int n_elements)
{
    double time = (end - start);

    time /= CLOCKS_PER_SEC;
    std::cout << "Time to process a range of "
        << n_elements << " elements with std::" << container << " : "
        << std::fixed << std::setprecision(5) << time * 1000 << " ms" <<std::endl;
}

template <typename Container>
bool isSorted(const Container& container)
{
    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator next = it;
    ++next;
    for (; next != container.end(); ++it, ++next)
    {
        if (*it > *next)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    /* VECTOR */
    try
    {
        clock_t start = clock();

        PmergeMe::setVector(argv + 1);
        std::cout << "Before: ";
        PmergeMe::printVector();
        PmergeMe::vMergeInsertionSort();
        std::cout << "After:  ";
        PmergeMe::printVector();
        printTime(start, clock(), "vector", argc - 1);
        if (!isSorted(PmergeMe::getVector()))
        {
            std::cout << "Error" << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    /* LIST */
    try
    {
        clock_t start = clock();

        PmergeMe::setList(argv + 1);
        std::cout << "Before: ";
        PmergeMe::printList();
        PmergeMe::lMergeInsertionSort();
        std::cout << "After:  ";
        PmergeMe::printList();
        printTime(start, clock(), "list  ", argc - 1);
        if (!isSorted(PmergeMe::getList()))
        {
            std::cout << "Error" << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
