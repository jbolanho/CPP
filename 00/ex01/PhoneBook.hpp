/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:58:50 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:58:50 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook 
{
private:
    Contact contacts[8];
    int count;
    int oldestIndex;

    std::string truncateField(const std::string& str) const;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
    void displayContact(int index) const;
};