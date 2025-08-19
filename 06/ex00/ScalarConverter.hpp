#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter &operator=(const ScalarConverter&);
        ~ScalarConverter();

    public:
        static void convert(std::string const &literal);
};


#endif