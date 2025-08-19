#include "ScalarConverter.hpp"

// int main (int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         ScalarConverter::convert(argv[1]);
//     }
//     else
//     {
//         std::cout << "Please, use: ./converter <literal>" << std::endl;
//     }
//     return 0;
// }

int main()
{
    std::string input;

    std::cout << "Give me a literal: ";
    std::getline(std::cin, input);

    ScalarConverter::convert(input);
}