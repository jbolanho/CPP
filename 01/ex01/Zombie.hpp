/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:00:03 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:00:03 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
private:
    std::string _name;

public:
    Zombie();    
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
};

Zombie* zombieHorde( int N, char** names);

#endif