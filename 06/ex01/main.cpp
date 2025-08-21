#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data info;
    info.id = 540;
    info.name = "String name";
    info.value = 4.2;

    std::cout << "Original pointer: " << &info << std::endl;

    uintptr_t test = Serializer::serialize(&info);
    std::cout << "Serialized pointer: " << test << std::endl;

    Data* restored = Serializer::deserialize(test);
    std::cout << "Restored pointer: " << restored << std::endl;

    if (restored == &info)
        std::cout << "\nPointers match! Worked" << std::endl;

    else
        std::cout << "\nViiixxx....something did't work" << std::endl;
    
    
    std::cout << "\nRestored pointer data: " << std::endl;
    std::cout << "    id: " << restored->id << std::endl;
    std::cout << "    name: " << restored->name << std::endl;
    std::cout << "    value: " << restored->value << std::endl;
}