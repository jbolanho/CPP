#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _name = "Default FragTrap";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "\033[1;36m[FragTrap] \033[0mDefault constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "\033[1;36m[FragTrap]" <<"\033[0m" << " Constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "\033[1;36m[FragTrap]" << "\033[0m" << "Copy constructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "\033[1;36m[FragTrap]" <<"\033[0m" << "Copy assiggnment operator called\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[1;36m[FragTrap]" <<"\033[0m" << "Destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "\033[1;36m[FragTrap]" <<"\033[0m" << _name << "can't attack. No energy or hit points!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "\033[1;36m[FragTrap]" <<"\033[0m" << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "\033[1;36m[FragTrap]" <<"\033[0m" << _name << " says: HEY, UHUUULLL!!! HIGH FIVE!" << std::endl;
}



// FragTrap::FragTrap() : ClapTrap()
// {
//     _name = "Default FragTrap";
//     _hitPoints = 100;
//     _energyPoints = 100;
//     _attackDamage = 30;
//     std::cout << "\033[1;36m" << "FragTrap default constructor called" << std::endl;
// }

// FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
// {
//     _hitPoints = 100;
//     _energyPoints = 100;
//     _attackDamage = 30;
//     std::cout << "\033[1;36m" << "FragTrap constructor called for " << _name << std::endl;
// }

// FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
// {
//     std::cout << "\033[1;36m" << "FragTrap copy constructor called for " << _name << std::endl;
// }

// FragTrap &FragTrap::operator=(const FragTrap &other)
// {
//     std::cout << "\033[1;36m" << "FragTrap copy assiggnment operator called\n";
//     if (this != &other)
//     {
//         ClapTrap::operator=(other);
//     }
//     return *this;
// }

// FragTrap::~FragTrap()
// {
//     std::cout << "\033[1;36m" << "FragTrap destructor called for " << _name << std::endl;
// }

// void FragTrap::attack(const std::string &target)
// {
//     if (_hitPoints <= 0 || _energyPoints <= 0)
//     {
//         std::cout << "\033[1;36m" << "FragTrap " << _name << "can't attack. No energy or hit points!" << std::endl;
//         return;
//     }
//     _energyPoints--;
//     std::cout << "\033[1;36m" << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
// }

// void FragTrap::highFivesGuys(void)
// {
//     std::cout << "\033[1;36m" << "FragTrap " << _name << " says: HEY, UHUUULLL!!! HIGH FIVE!" << std::endl;
// }