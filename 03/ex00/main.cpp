
#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Blip");
    ClapTrap b("Blop");

    a.attack("Blop");
    b.takeDamage(2);

    b.attack("Blip");
    a.takeDamage(2);

    a.beRepaired(5);
    b.beRepaired(2);

    return 0;
}
