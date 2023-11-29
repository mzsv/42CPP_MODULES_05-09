/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:40:47 by amenses-          #+#    #+#             */
/*   Updated: 2023/11/29 20:56:09 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_vector;
std::list<int>   PmergeMe::_list;

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const& obj)
{
    *this = obj;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe&   PmergeMe::operator=(PmergeMe const& obj)
{
    if (this != &obj)
    {
        this->_vector = obj._vector;
    }
    return *this;
}

static bool isNegative(int const& n)
{
    return n < 0;
}

/* UTILS */

template <typename C>
static void setContainer(C& container, char** const& argv)
{
    int n = 0;

    for (int i = 0; argv[i]; ++i)
    {
        std::istringstream  iss(argv[i]);
        iss >> n;
        if (iss.fail() || iss.bad())
        {
            throw InvalidInputException();
        }
        container.push_back(n);
    }
    if (std::find_if(container.begin(), container.end(), isNegative) != container.end())
    {
        throw InvalidInputException();
    }  
}

template <typename C>
static void printContainer(C& container)
{
    typename C::iterator it;

    for (it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static bool pCompare(std::pair<int, int>& a, std::pair<int, int>& b)
{
    return a.first < b.first;
}

/* returns what is also referred to as the Jacobsthal number in the literature */
static size_t batchEnd(int const& batch, size_t const& chain_size)
{
    size_t result = 1 << (batch + 1);

    if (batch % 2 == 0)
    {
        result += 1;
    }
    else
    {
        result -= 1;
    }
    result /= 3;
    return result > chain_size ? chain_size : result;
}

/* VECTOR*/

void        PmergeMe::setVector(char** const& argv)
{
    setContainer<std::vector<int> >(_vector, argv);
    if (std::find_if(_vector.begin(), _vector.end(), isNegative) != _vector.end())
    {
        throw InvalidInputException();
    }  
}

std::vector<int>& PmergeMe::getVector()
{
    return (_vector);
}

void        PmergeMe::printVector()
{
    printContainer<std::vector<int> >(_vector);
}

static void pMerge(pVector&  left, pVector&  right, pVector& merged)
{
    size_t  i = 0;
    size_t  j = 0;
    size_t  k = 0;

    while (i < left.size() && j < right.size())
    {
        if (pCompare(left[i], right[j]))
        {
            merged[k++] = left[i++];
        }
        else
        {
            merged[k++] = right[j++];
        }
    }
    while (i < left.size())
    {
        merged[k++] = left[i++];
    }
    while (j < right.size())
    {
        merged[k++] = right[j++];
    }
}

static void pMergeSort(pVector&  pairs)
{
    pVector left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    pVector right(pairs.begin() + pairs.size() / 2, pairs.end());

    if (pairs.size() <= 1)
    {
        return ;
    }
    pMergeSort(left);
    pMergeSort(right);
    pMerge(left, right, pairs);
}

static void setMainChain(std::vector<int>& vector, pVector& sorted_pairs)
{
    size_t size = vector.size();

    vector.clear();
    vector.reserve(size);
    vector.push_back(sorted_pairs[0].second);
    for (pVector::iterator it = sorted_pairs.begin(); it != sorted_pairs.end(); ++it)
    {
        vector.push_back(it->first);
    }
}

static int binarySearch(std::vector<int>& vector, int const& value, \
    size_t low, size_t high)
{
    if (high <= low)
    {
        return value > vector[low] ? low + 1 : low;
    }

    size_t mid = (low + high) / 2;

    if (value == vector[mid])
    {
        return mid + 1;
    }
    if (value > vector[mid])
    {
        return binarySearch(vector, value, mid + 1, high);
    }
    return binarySearch(vector, value, low, mid > 0 ? mid - 1 : mid);
}

static void batchInsertion(std::vector<int>& vector, pVector& pairs)
{
    size_t  batch = 2;
    size_t  start = 1;
    size_t  end = 0;
    size_t  pos = 0;
    size_t  b_chain_size = pairs.size();

    while (end < b_chain_size)
    {
        end = batchEnd(batch, b_chain_size);
        for (size_t i = end - 1; i >= start; --i)
        {
            pos = binarySearch(vector, pairs[i].second, 0, vector.size() - 1);
            vector.insert(vector.begin() + pos, pairs[i].second);
        }
        batch++;
        start = end;
    }
}

void PmergeMe::vMergeInsertionSort()
{
    pVector pairs;
    size_t  mid = _vector.size() / 2;
    int     odd_element = -1;

    if (_vector.size() <= 1)
    {
        return ;
    }
    for (size_t i = 0; i < mid; ++i)
    {
        pairs.push_back(std::make_pair(_vector[i], _vector[mid + i]));
        if (pairs[i].first < pairs[i].second)
        {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
    if (_vector.size() % 2 != 0)
    {
        odd_element = _vector[_vector.size() - 1];
    }
    pMergeSort(pairs);
    setMainChain(_vector, pairs);
    if (odd_element != -1)
    {
        pairs.push_back(std::make_pair(-1, odd_element));
    }
    batchInsertion(_vector, pairs);
}

/* LIST */

void        PmergeMe::setList(char** const& argv)
{
    setContainer<std::list<int> >(_list, argv);
    if (std::find_if(_list.begin(), _list.end(), isNegative) != _list.end())
    {
        throw InvalidInputException();
    }   
}

std::list<int>& PmergeMe::getList()
{
    return (_list);
}

void        PmergeMe::printList()
{
    printContainer<std::list<int> >(_list);
}

static void pMerge(pList&  left, pList&  right, pList& merged)
{
    pList::iterator it1 = left.begin();
    pList::iterator it2 = right.begin();
    pList::iterator it = merged.begin();

    while (it1 != left.end() && it2 != right.end())
    {
        if (pCompare(*it1, *it2))
        {
            *it = *it1;
            ++it1;
            
        }
        else
        {
            *it = *it2;
            ++it2;
        }
        ++it;
    }
    while (it1 != left.end())
    {
        *it = *it1;
        ++it;
        ++it1;
    }
    while (it2 != right.end())
    {
        *it = *it2;
        ++it;
        ++it2;
    }
}

static void pMergeSort(pList& pairs)
{
    if (pairs.size() <= 1)
    {
        return ;
    }

    pList::iterator it = pairs.begin();

    std::advance(it, pairs.size() / 2);

    pList   left(pairs.begin(), it);
    pList   right(it, pairs.end());

    pMergeSort(left);
    pMergeSort(right);
    pMerge(left, right, pairs);
}

static void setMainChain(std::list<int>& list, pList& sorted_pairs)
{
    list.clear();
    list.push_back(sorted_pairs.front().second);
    for (pList::iterator it = sorted_pairs.begin(); it != sorted_pairs.end(); ++it)
    {
        list.push_back(it->first);
    }
}

static bool isAhead(std::list<int>::iterator it1, std::list<int>::iterator it2, \
    std::list<int>& list)
{
    if (it1 == it2)
    {
        return false;
    }
    while (it1 != list.end())
    {
        if (it1 == it2)
        {
            return true;
        }
        ++it1;
    }
    return false;
}

static std::list<int>::iterator binarySearch(std::list<int>& list, int const& value, \
    std::list<int>::iterator low, std::list<int>::iterator high)
{
    if (!isAhead(low, high, list))
    {
        return value > *low ? ++low : low;
    }

    std::list<int>::iterator mid = low;

    std::advance(mid, std::distance(low, high) / 2);
    if (value == *mid)
    {
        return ++mid;
    }
    if (value > *mid)
    {
        return binarySearch(list, value, ++mid, high);
    }
    return binarySearch(list, value, low, mid != list.begin() ? --mid : mid);
}

static void batchInsertion(std::list<int>& list, pList sorted_pairs)
{
    size_t                      batch = 2;
    pList::iterator             start_it = sorted_pairs.begin();
    pList::iterator             end_it = start_it;
    size_t                      b_chain_size = sorted_pairs.size();
    std::list<int>::iterator    pos_it = list.begin();

    while (end_it != --sorted_pairs.end())
    {
        end_it = sorted_pairs.begin();
        std::advance(end_it, batchEnd(batch, b_chain_size) - 1);
        for (pList::iterator it = end_it; it != start_it; --it)
        {
            pos_it = binarySearch(list, it->second, list.begin(), --list.end());
            list.insert(pos_it, it->second);
        }
        batch++;
        start_it = end_it;
    }
}

void             PmergeMe::lMergeInsertionSort()
{
    pList                       pairs;
    int                         odd_element = -1;
    std::list<int>::iterator    it = _list.begin();

    std::advance(it, _list.size() / 2);

    std::list<int>::iterator    it2 = it;
    std::list<int>::iterator    mid_it = it2;

    if (_list.size() <= 1)
    {
        return ;
    }
    for (it = _list.begin(); it != mid_it; ++it)
    {
        pairs.push_back(std::make_pair(*it, *it2));
        if (pairs.back().first < pairs.back().second)
        {
            std::swap(pairs.back().first, pairs.back().second);
        }
        ++it2;
    }
    if (_list.size() % 2 != 0)
    {
        odd_element = _list.back();
    }
    pMergeSort(pairs);
    setMainChain(_list, pairs);
    if (odd_element != -1)
    {
        pairs.push_back(std::make_pair(-1, odd_element));
    }
    batchInsertion(_list, pairs);
}

/* EXCEPTIONS */

const char* InvalidInputException::what() const throw()
{
    return "Error";
}
