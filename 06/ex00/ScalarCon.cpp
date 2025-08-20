#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &literal)
{
    if ((literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) ||
        (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')) 
    {
        char c;
        if (literal.length() == 3)
            c = literal[1];
        else
            c = literal[0];

        std::cout << "char: '" << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }


    char* end = NULL;
    errno = 0;
    double val = std::strtod(literal.c_str(), &end);

    // bool isFloat = (end && *end == 'f' && *(end+1) == '\0');

    if (std::isnan(val) || val < 0 || val > 127)
        std::cout << "char: Not displayable" << std::endl;
    else if (!std::isprint(static_cast<int>(val)))
        std::cout << "char: Not displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;


    if (std::isnan(val) || val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
   
    float f = static_cast<float>(val);
    std::cout << "FLOAT:: " << f << std::endl;
    std::cout << "VAL:: " << val << std::endl;
    if (std::isnan(f) || std::isinf(val) ||
        f < -std::numeric_limits<float>::max() ||
        f > std::numeric_limits<float>::max()) 
            std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f\n";
    }
        
    double d = static_cast<double>(val);
    std::cout << "DOUBLE:: " << f << std::endl;
    if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max() || std::isnan(d) || std::isinf(d)) 
        std::cout << "double: impossible" << std::endl;
    else
    {
   
        std::cout << "double: " << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "\n";
    }
}