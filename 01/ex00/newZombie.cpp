

#include "Zombie.hpp"

Zombie* newZombie(std::string name) 
{
    return new Zombie(name);
}

// // Destrutor
// Zombie::~newZombie() 
// {
//     std::cout << name << " is destroyed." << std::endl;
// }

// void newZombie::announce(void) 
// {
//     std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
// }