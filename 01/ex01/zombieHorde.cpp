
#include "Zombie.hpp"

Zombie* zombieHorde(int N, char** names) 
{
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        new(&horde[i]) Zombie(names[i]);
        i++;
    }
    return horde;
}