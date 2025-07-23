#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
    ClapTrap a("Clappy");
    a.attack("target1");
    a.beRepaired(2);
    std::cout << std::endl;

    ScavTrap s("Scavy");
    s.attack("target2");
    s.guardGate();
    std::cout << std::endl;

    // std::cout << "\033[0m" << "Copying ScavTrap:\n";
    // ScavTrap s2 = s;

    // std::cout << "\033[0m" << "\nExiting program...\n";
    return 0;
}