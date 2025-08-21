#include "Base.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    Base* obj = generate();

    std::cout << "Identify by ";
    identify(obj);

    std::cout << "Identify by ";
    identify(*obj);

    delete obj;
}