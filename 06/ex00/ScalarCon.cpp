#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &literal)
{
      if ((literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) ||
        (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')) 
    {
        char c = (literal.size() == 1) ? literal[0] : literal[1];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }

    char* end = NULL;
    errno = 0;
    double val = std::strtod(literal.c_str(), &end);

    bool isFloat = (end && *end == 'f' && *(end+1) == '\0');

    if ((end && *end != '\0' && !isFloat) || errno == ERANGE) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    if (std::isnan(val) || val < 0 || val > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<int>(val)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(val) << "'\n";

    if (std::isnan(val) || val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(val) << "\n";

    {
        float f = static_cast<float>(val);
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f\n";
    }

    {
        double d = static_cast<double>(val);
        std::cout << "double: " << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "\n";
    }
}