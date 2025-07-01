/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:00:51 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:00:51 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB 
{
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(const std::string& name);
    ~HumanB();

    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif