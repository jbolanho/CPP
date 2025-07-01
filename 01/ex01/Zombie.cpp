/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:59:55 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:59:55 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) 
{
    _name = name;
}

Zombie::~Zombie() 
{
    std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce(void) 
{
    std::cout << _name << ": UUUUhhhaaaaaahhhh..." << std::endl;
}
