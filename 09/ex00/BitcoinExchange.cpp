#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
    loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    if (this!= &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}



void BitcoinExchange::loadDatabase() 
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data.csv");

    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            continue;
        _database[date] = std::atof(valueStr.c_str());
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        if (!isValidDate(date) || !isValidValue(valueStr))
            continue;

        float value = std::atof(valueStr.c_str());
        float rate = getExchangeRate(date);
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (std::cerr << "Error: bad date format => " << date << std::endl), false;

    int year, month, day;
    char dash1, dash2;
    std::stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return (std::cerr << "Error: invalid date => " << date << std::endl), false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr)
{
    float val = std::atof(valueStr.c_str());
    if (val < 0)
        return (std::cerr << "Error: not a positive number." << std::endl), false;
    if (val > 1000)
        return (std::cerr << "Error: too large a number." << std::endl), false;
    return true;
}

std::string BitcoinExchange::getClosestDate(const std::string &date)
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
    if (it == _database.begin())
        return it->first;
    if (it == _database.end() || it->first != date)
        --it;
    return it->first;
}

float BitcoinExchange::getExchangeRate(const std::string &date)
{
    std::map<std::string, float>::const_iterator it = _database.find(date);
    if (it == _database.end()) 
    {
        std::string closest = getClosestDate(date);
        return _database.find(closest)->second;
    }
    return it->second;
}