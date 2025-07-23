#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
        Animal();

    public:
        Animal(const Animal &other);
        Animal& operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const = 0;   //abstract class
        std::string getType() const;
};

#endif