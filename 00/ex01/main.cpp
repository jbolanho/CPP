
#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to Your Awesome PhoneBook!\n";
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
            std::cout << "Goodbye!\n";
            break;
        } 
        else 
        {
            std::cout << "Invalid command.\n";
        }
    }
    return 0;
}