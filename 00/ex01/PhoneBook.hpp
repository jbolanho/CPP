
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