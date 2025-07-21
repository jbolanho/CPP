#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{    
    std::cout << "\033[1;33m" << "=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Fragger");
    
    std::cout << "\033[1;33m" << "\n=== Testing attack ===" << std::endl;
    frag.attack("target01");
    
    std::cout << "\033[1;33m" << "\n=== Taking damage ===" << std::endl;
    frag.takeDamage(20);
    
    std::cout << "\033[1;33m" << "\n=== Repairing ===" << std::endl;
    frag.beRepaired(10);
    
    std::cout << "\033[1;33m" << "\n=== High Five ===" << std::endl;
    frag.highFivesGuys();
    
    // std::cout << "\033[1;33m" << "\n=== Copy & Assignment ===" << std::endl;
    // FragTrap frag2(frag);
    // FragTrap frag3;
    // frag3 = frag;
    
    std::cout << "\033[1;33m" << "\n=== Destruction ===" << std::endl;
    return 0;
    
}
// ClapTrap *bot = new FragTrap("Fraggy");

// bot->attack("target00");
// bot->beRepaired(5);
// bot->takeDamage(20);

// delete bot;

// return 0;