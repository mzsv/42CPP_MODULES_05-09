/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:03:34 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/11 23:17:39 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "MutantStack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout << "---------------------" << std::endl;
    }
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << "top: " << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << "size: " << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "std::list:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
        std::cout << "---------------------" << std::endl;
    }
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        MutantStack<int>::iterator it = mstack.begin();
        std::cout << "it_begin: " << *it << std::endl;
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        std::cout << "++it: " << *it << std::endl;
        --it;
        std::cout << "--it: " << *it << std::endl;
        std::cout << "MutantStack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "MutantStack_Copy:" << std::endl;
        MutantStack<int> s(mstack);
        it = s.begin();
        ite = s.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return 0;
}
