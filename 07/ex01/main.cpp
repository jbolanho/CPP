#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const &x)
{
    std::cout << x << std::endl;
}


template <typename T>
void increment(T &x)
{
    x += 1;
}

int main()
{
    int arrInt[] = {1, 2, 3, 42};
    std::string arrStr[] = {"hi", "hello", "bye"};
    
    std::cout << "\n \033[1;32m***Str test***\033[0m" << std::endl;
    iter(arrStr, 3, printElement<std::string>);

    std::cout << " \n \033[1;32m***Int test***\033[0m" << std::endl;
    iter(arrInt, 4, printElement<int>);

    std::cout << " \n \033[1;32m***Increment test***\033[0m" << std::endl;
    iter(arrInt, 4, increment<int>);
    iter(arrInt, 4, printElement<int>);

    return 0;
}