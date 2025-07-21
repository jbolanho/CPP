// #include "ClapTrap.hpp"

// int main() {
//     ClapTrap a("Blip");
//     ClapTrap b("Blop");

//     a.attack("Blop");
//     b.takeDamage(2);

//     b.attack("Blip");
//     a.takeDamage(2);

//     a.beRepaired(5);
//     b.beRepaired(2);

//     return 0;
// }


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap a("Clappy");
    a.attack("target1");
    a.beRepaired(2);
    std::cout << std::endl;

    ScavTrap s("Scavy");
    s.attack("target2");
    s.guardGate();
    std::cout << std::endl;

    // std::cout << "Copying ScavTrap:\n";
    // ScavTrap s2 = s;

    std::cout << "\033[0m" << "\nExiting program...\n";
    return 0;
}