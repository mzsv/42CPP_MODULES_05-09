/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:00:24 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/17 15:50:09 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <limits>
# include <map>

struct Data
{
    int     year;
    int     month;
    int     day;
    double  value;

    std::string getDate() const;
};

class BitcoinExchange
{
    private:
        static std::map<std::string, double>   _database;

        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const& obj);
        BitcoinExchange& operator=(BitcoinExchange const& obj);

    public:
        ~BitcoinExchange();

        static void setDatabase(std::string const filename);
        static void convert(std::string const& input_filename);
};

class FileErrorException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class BadInputException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class NegativeValueException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class TooLargeNumberException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class InvalidFormatException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif
