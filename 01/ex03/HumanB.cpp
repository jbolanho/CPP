/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:00:46 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:00:46 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon& weapon) 
{
    this->weapon = &weapon;
}

void HumanB::attack() const 
{
    if (this->weapon != NULL) 
    {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    } 
    else 
    {
        std::cout << this->name << " has no weapon to attack" << std::endl;
    }
}