/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:59:03 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:59:03 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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