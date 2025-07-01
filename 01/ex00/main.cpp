
#include "Zombie.hpp"

int main() 
{
    // Zombie zombie1("Foo");
    // Zombie zombie2("Fred");

    // zombie1.announce();
    // zombie2.announce();

    Zombie *newZombie1 = newZombie("Fred");
    newZombie1->announce();
    delete newZombie1;

    randomChump("Zooombie");

    return 0;
}