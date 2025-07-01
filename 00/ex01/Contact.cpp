/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:58:19 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:58:19 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() 
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::setContact(std::string f, std::string l, std::string n,
                          std::string p, std::string d) 
{
    firstName = f;
    lastName = l;
    nickname = n;
    phoneNumber = p;
    darkestSecret = d;
}

std::string Contact::getFirstName() const 
{
    return firstName;
}
std::string Contact::getLastName() const 
{
    return lastName;
}
std::string Contact::getNickname() const 
{
    return nickname;
}
std::string Contact::getPhoneNumber() const 
{
    return phoneNumber;
}
std::string Contact::getDarkestSecret() const 
{
    return darkestSecret;
}

bool Contact::isEmpty() const 
{
    return firstName.empty();
}
