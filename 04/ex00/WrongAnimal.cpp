#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
    std::cout << "[WrongAnimal] Constructor called\n";
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "[WrongAnimal] Destructor called\n";
}

void WrongAnimal::makeSound() const 
{
    std::cout << "[WrongAnimal] BLA BLA BLA\n";
}

std::string WrongAnimal::getType() const 
{
    return type;
}