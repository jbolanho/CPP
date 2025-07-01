
#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) 
{
}

Weapon::~Weapon() 
{
    // std::cout <<  "Weapon is destroyed." << std::endl;
}

const std::string& Weapon::getType() const 
{
    return this->type;
}

void Weapon::setType(const std::string& newType) 
{
    this->type = newType;
}