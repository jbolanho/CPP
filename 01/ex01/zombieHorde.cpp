/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:00:11 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:00:11 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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