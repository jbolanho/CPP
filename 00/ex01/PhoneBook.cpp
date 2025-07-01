/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:58:44 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:58:44 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() 
{
    count = 0;
    oldestIndex = 0;
}

std::string PhoneBook::truncateField(const std::string& str) const 
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::addContact() 
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty()
        || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "All fields are required! Contact not saved.\n";
        return;
    }

    contacts[oldestIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    oldestIndex = (oldestIndex + 1) % 8;
    if (count < 8)
        count++;

    std::cout << "Contact added successfully!\n";
}

void PhoneBook::searchContacts() const 
{
    if (count == 0) 
    {
        std::cout << "Phonebook is empty.\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    int i = 0;
    while (i < count) 
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getNickname()) << std::endl;
        i++;
    }

    std::cout << "Enter index to view details: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= count) 
    {
        std::cout << "Invalid index.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayContact(index);
}

void PhoneBook::displayContact(int index) const 
{
    const Contact& c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}