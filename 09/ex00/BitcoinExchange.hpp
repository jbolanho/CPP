#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

class BitcoinExchange 
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
    
        void processInput(const std::string &filename);

    private:
        std::map<std::string, float> _database;

    private:

        void loadDatabase();

        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);

        std::string getClosestDate(const std::string &date);
        float getExchangeRate(const std::string &date);
};

#endif