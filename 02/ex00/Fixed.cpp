/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:02:12 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:02:12 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    _value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    std::cout << "get function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "set function called" << std::endl;
    _value = raw;
}