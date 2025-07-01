/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:02:17 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:02:17 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed 
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed(); 
    Fixed(const Fixed& other);        
    Fixed& operator=(const Fixed& other); 
    ~Fixed();                           

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif