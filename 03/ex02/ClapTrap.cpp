
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : _name("Initial"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m" << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(2) 
{
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << "Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage) 
{
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << "Copy constructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << "Copy assignment operator called for " << _name << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << "Destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0) 
    {
        std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << _name << " can't attack. No hit points or energy left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int value)
{
    _hitPoints -= value;
    if (_hitPoints < 0) _hitPoints = 0;
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << _name << " took " << value
              << " points of damage! Hit points now: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int value)
{
    if (_hitPoints <= 0 || _energyPoints <= 0) 
    {
        std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << _name << " can't be repaired. No hit points or energy left!" << std::endl;
        return;
    }
    _hitPoints += value;
    _energyPoints--;
    std::cout << "\033[1;35m[ClapTrap]" <<"\033[0m"  << _name << " repaired itself for " << value
              << " points! Hit points now: " << _hitPoints << std::endl;
}
