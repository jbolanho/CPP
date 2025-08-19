#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
    }
    else
    {
        std::cout << "Please, use: ./converter <literal>" << std::endl;
    }
    return 0;
}