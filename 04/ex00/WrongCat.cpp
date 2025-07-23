#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    type = "WrongCat";
    std::cout << "[WrongCat] Constructor called\n";
}

WrongCat::~WrongCat() 
{
    std::cout << "[WrongCat] Destructor called\n";
}

void WrongCat::makeSound() const 
{
    std::cout << "MINHAU!\n";
}