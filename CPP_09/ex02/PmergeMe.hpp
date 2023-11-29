/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:41:03 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/07 20:45:27 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <sstream>
# include <cmath>
# include <list>
# include <iterator>

typedef std::vector<std::pair<int, int> > pVector;
typedef std::list<std::pair<int, int> > pList;

class PmergeMe
{
    public:
        static std::vector<int> _vector;
        static std::list<int>   _list;

        PmergeMe();
        PmergeMe(PmergeMe const&);
        PmergeMe& operator=(PmergeMe const&);

    public:
        ~PmergeMe();

        /* VECTOR */
        static void                 setVector(char** const&);
        static std::vector<int>&    getVector();
        static void                 printVector();
        static void                 vMergeInsertionSort();

        /* LIST */
        static void                 setList(char** const&);
        static std::list<int>&      getList();
        static void                 printList();
        static void                 lMergeInsertionSort();
};

class InvalidInputException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
