/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:01:05 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:01:05 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) 
{
}

Weapon::~Weapon() 
{
    // std::cout <<  "Weapon is destroyed." << std::endl;
}

const std::string& Weapon::getType() const 
{
    return this->type;
}

void Weapon::setType(const std::string& newType) 
{
    this->type = newType;
}