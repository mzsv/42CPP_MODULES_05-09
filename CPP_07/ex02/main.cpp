/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:38:27 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/11 19:49:43 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int main()
{
    Array<int>  a(5);
    Array<int>  b(2);

    std::cout << "size of a: " << a.size() << std::endl;
    std::cout << "size of b: " << b.size() << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        std::cout << "a[" << i << "]: " << a[i];
        a[i] = i;
        std::cout << " -> new: " << a[i] << std::endl;
    }
    std::cout << std::endl;

    a = b;
    std::cout << "a = b" << std::endl;
    std::cout << "size of a: " << a.size() << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        std::cout << "a[" << i << "]: " << a[i];
        a[i] = i;
        std::cout << " -> new: " << a[i] << std::endl;
    }
    std::cout << std::endl;

    Array<int>   const c(a);

    std::cout << "const c(a)" << std::endl;
    std::cout << "size of c: " << c.size() << std::endl;
    for (unsigned int i = 0; i < c.size(); i++)
    {
        std::cout << "c[" << i << "]: " << c[i] << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "a[10]: " << a[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "a[-1]: " << a[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    Array<std::string>  s(3);

    std::cout << "size of s: " << s.size() << std::endl;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        std::cout << "s[" << i << "]: " << s[i];
        s[i] = "hello";
        std::cout << " -> new: " << s[i] << std::endl;
    }
    std::cout << std::endl;

    Array<char>  ch;

    std::cout << "size of ch: " << ch.size() << std::endl;
    try
    {
        std::cout << "ch[" << 0 << "]: " << ch[0];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
