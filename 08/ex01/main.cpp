#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//     std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//     return 0;
// }



int main() {
    try {
        std::cout << " \n \033[1;32m ***Subject test*** \033[0m" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << " \n \033[1;32m ***10000 numbers test*** \033[0m" << std::endl;
        Span bigSpan(10000);
        std::vector<int> nums;
        for (int i = 0; i < 10000; i++)
            nums.push_back(rand());

        bigSpan.addRange(nums.begin(), nums.end());
        std::cout << "Big shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big longest span: " << bigSpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}