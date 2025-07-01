/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:59:13 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:59:13 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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