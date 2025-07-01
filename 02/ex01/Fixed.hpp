

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
private:
    int _value;
    static const int _fractionalBits;

public:
    Fixed(); 
    Fixed(const Fixed& other);        
    Fixed& operator=(const Fixed& other); 
    ~Fixed();                           

    Fixed(const int intNbr);        
    Fixed(const float floatNbr); 

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};    

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif