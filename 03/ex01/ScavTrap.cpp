
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _name = "Default ScavTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\033[1;33m" << "ScavTrap default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) 
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\033[1;33m" << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    _name = other._name;
    std::cout << "\033[1;33m" << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "\033[1;33m" << "ScavTrap copy assignment operator called\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[1;33m" << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "\033[1;33m" << "ScavTrap " << _name << " can't attack. No energy or hit points!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "\033[1;33m" << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "\033[1;33m" << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}



