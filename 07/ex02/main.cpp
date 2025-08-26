#include <iostream>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T> &arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;    
}

int main()
{
    try
    {
        std::cout << "\n \033[1;32m***Empty constructor test***\033[0m" << std::endl;
        Array<int> a;
        std::cout << "Size: " << a.size() << std::endl;

        std::cout << "\n \033[1;32m***Constructor size test***\033[0m" << std::endl;
        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i * 2;
        printArray(b);

        std::cout << "\n \033[1;32m***Copy constructor test***\033[0m" << std::endl;
        Array<int> c(b);
        printArray(c);
        
        
        std::cout << "\n \033[1;32m***Modified copy test***\033[0m" << std::endl;
        c[0] = 999;
        printArray(b);
        printArray(c);


        std::cout << "\n \033[1;32m***Assignment test***\033[0m" << std::endl;
        Array<int> d;
        d = b;
        printArray(d);

        std::cout << "\n \033[1;32m***Out of bounds test***\033[0m" << std::endl;
        std::cout << b[10] << std::endl;

    
    
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}


