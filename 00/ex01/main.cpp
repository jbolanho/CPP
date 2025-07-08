/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:58:34 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 14:58:34 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to PhoneBook!\n";
    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof()) 
        {
            std::cout << "\nExiting...\n";
            break;
        }

        if (command == "ADD") 
        {
            phonebook.addContact();
        } 
        else if (command == "SEARCH") 
        {
            phonebook.searchContacts();
        } 
        else if (command == "EXIT") 
        {
            std::cout << "Bye bye!\n";
            break;
        } 
        else 
        {
            std::cout << "Invalid command.\n";
        }
    }
    return 0;
}