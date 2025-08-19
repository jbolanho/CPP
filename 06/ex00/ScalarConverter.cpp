#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &literal)
{
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || 
        literal == "+inff" || literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal[literal.size()-1] == 'f')
        {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.size()-1) << std::endl;
        }
        else
        {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        return;
    }

    if ((literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') || literal.length() == 1)
    {
        char c;
        if (literal.length() == 3)
            c = literal[1];
        else
            c = literal[0];

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    char* end;
    errno = 0;
    double val = std::strtod(literal.c_str(), &end);

    bool isFloat = (end && *end == 'f' && *(end+1) == '\0');

    if ((end && *end != '\0' && !isFloat) || errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;


    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    {
        float f = static_cast<float>(val);
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    {
        double d = static_cast<double>(val);
        std::cout << "double: " << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << std::endl;

    }
}