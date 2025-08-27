#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    try
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);

        std::vector<int>::iterator itVec = easyfind(vec, 20);
        std::cout << "Found in vector: " << *itVec << std::endl;

        std::list<int>::iterator itLst = easyfind(lst, 15);
        std::cout << "Found in list: " << *itLst << std::endl;

        easyfind(vec, 99);

    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}