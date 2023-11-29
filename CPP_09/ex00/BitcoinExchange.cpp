/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:00:14 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/17 16:43:04 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double>       BitcoinExchange::_database;

std::string Data::getDate() const
{
    std::string         date;
    std::ostringstream  oss;

    oss << std::setfill('0') << std::setw(4) << year << "-"
        << std::setfill('0') << std::setw(2) << month << "-"
        << std::setfill('0') << std::setw(2) << day;
    return (oss.str());
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& obj)
{
    *this = obj;
}

BitcoinExchange&    BitcoinExchange::operator=(BitcoinExchange const& obj)
{
    (void)obj;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

static bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return (year % 400 == 0);
        }
        return (true);
    }
    return (false);
}

static bool isValidDate(Data data)
{
    if (data.year < 0)
    {
        return (false);
    }
    if (!(data.month >= 1 && data.month <= 12))
    {
        return (false);
    }
    if (!(data.day >= 1 && data.day <= 31))
    {
        return (false);
    }
    if (data.month == 2)
    {
        if (isLeapYear(data.year))
        {
            return (data.day <= 29);
        }
        return (data.day <= 28);
    }
    if (data.month == 4 || data.month == 6 || data.month == 9 || data.month == 11)
    {
        return (data.day <= 30);
    }
    return (true);
}

template <typename T>
static T    streamRead(std::istringstream& iss)
{
    T   value;

    iss >> value;
    if (iss.fail() || iss.bad())
    {
        throw InvalidFormatException();
    }
    return (value);
}

static void readData(Data& data, std::string line, char const& value_del)
{
    std::istringstream  iss(line);
    char                del[2];

    std::memset(&data, 0, sizeof(data));
    try
    {
        data.year = streamRead<int>(iss);
        del[0] = streamRead<char>(iss);
        data.month = streamRead<int>(iss);
        del[1] = streamRead<char>(iss);
        data.day = streamRead<int>(iss);
    }
    catch (InvalidFormatException& e)
    {
        throw ;
    }
    if (del[0] != '-' || del[1] != '-')
    {
        throw InvalidFormatException();
    }
    if (!isValidDate(data) || data.getDate() < "2009-01-02")
    {
        throw BadInputException();
    }
    try
    {
        del[0] = streamRead<char>(iss);
        if (del[0] != value_del)
        {
            throw InvalidFormatException();
        }
        data.value = streamRead<double>(iss);
    }
    catch (InvalidFormatException& e)
    {
        throw ;
    }
    if (data.value < 0)
    {
        throw NegativeValueException();
    }
    if (data.value > std::numeric_limits<int>::max())
    {
        throw TooLargeNumberException();
    }
}

void BitcoinExchange::setDatabase(std::string const filename)
{
    std::ifstream   file;
    std::string     line;
    Data            data;

    file.open(filename.c_str());
    if (!file.is_open())
    {
        throw FileErrorException();
    }
    try
    {
        std::getline(file, line);
        while (std::getline(file, line))
        {
            readData(data, line, ',');
            _database.insert(std::make_pair(data.getDate(), data.value));
        }
    }
    catch(const std::exception& e)
    {
        file.close();
        throw;
    }
    file.close();
}

void BitcoinExchange::convert(std::string const& input_filename)
{
    std::ifstream                           file;
    std::string                             line;
    Data                                    data;
    std::map<std::string, double>::iterator it;

    file.open(input_filename.c_str());
    if (!file.is_open())
    {
        throw FileErrorException();
    }
    try
    {
        while (std::getline(file, line))
        {
            if (line == "date | value")
            {
                continue ;
            }
            try
            {
                readData(data, line, '|');
                if (data.value > 1000)
                {
                    throw TooLargeNumberException();
                }
                it = _database.upper_bound(data.getDate());
                --it;
                std::cout << data.getDate() << " => " << data.value << " = "
                    << data.value * it->second << std::endl;
            }
            catch (BadInputException& e)
            {
                std::cout << e.what()
                    << " => " << data.getDate() << std::endl;
            }
            catch (std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        throw;
    }
}

const char* FileErrorException::what() const throw()
{
    return ("Error: could not open file.");
}

const char* BadInputException::what() const throw()
{
    return ("Error: bad input");
}

const char* NegativeValueException::what() const throw()
{
    return ("Error: not a positive number.");
}

const char* TooLargeNumberException::what() const throw()
{
    return ("Error: too large a number.");
}

const char* InvalidFormatException::what() const throw()
{
    return ("Error: invalid format.");
}
