#include "Base.hpp"

Base::~Base() {}


Base* generate(void)
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3;
    if (r == 0)
    {
        std::cout << "Generated: A" << std::endl; 
        return new A();
    }
    if (r == 1)
    {
        std::cout << "Generated: B" << std::endl; 
        return new B();
    }    
    std::cout << "Generated: C" << std::endl; 
    return new C();

}


void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "ptr: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "ptr: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "ptr: C" << std::endl;
    else 
        std::cout << "Unkoun type" << std::endl;
}


void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "ref: A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "ref: B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "ref: C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}