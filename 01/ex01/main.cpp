/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:59:43 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:59:43 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2) {
        std::cout << "Please, try: " << argv[0] << " <ZombieName1> <ZombieName2> ..." << std::endl;
        return 1;
    }

    int N = argc - 1;
    char** names = argv + 1;

    Zombie* horde = zombieHorde(N, names);
    if (horde == NULL) 
    {
        std::cout << "Failed to create zombie horde." << std::endl;
        return 1;
    }
    int i = 0;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;

    return 0;
}