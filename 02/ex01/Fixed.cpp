

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_fractionalBits = 8;

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
    if (this != &other) 
    {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intNbr) 
{
    std::cout << "Int constructor called" << std::endl;
    _value = intNbr << _fractionalBits;
}

Fixed::Fixed(const float floatNbr) 
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(floatNbr * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const 
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const 
{
    return _value >> _fractionalBits;
}


int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) 
{
    out << value.toFloat();
    return out;
}