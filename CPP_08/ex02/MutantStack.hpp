/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:03:58 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 20:51:29 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack const& obj);
        ~MutantStack();
        MutantStack&    operator=(MutantStack const& obj);

        typedef typename std::stack<T>::container_type::iterator    iterator;
        iterator        begin();
        iterator        end();
};

template <typename T>
MutantStack<T>::MutantStack() :
    std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& obj) :
    std::stack<T>(obj)
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>&    MutantStack<T>::operator=(MutantStack const& obj)
{
    std::stack<T>::operator=(obj);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

#endif
