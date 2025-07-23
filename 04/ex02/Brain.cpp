// #include "Brain.hpp"

// Brain::Brain()
// {
//     std::cout << "\033[1;33m" << "[Brain] Constructor called\n";
//     for (int i= 0; i < 100; ++i)
//         ideas[i] = "Empty";
// }

// Brain::Brain(const Brain &other)
// {
//     std::cout << "\033[1;33m" << "[Brain] Copyconstructor called\n";
//     for (int i = 0; i < 100; ++i)
//         ideas[i] = other.ideas[i];

// }

// Brain& Brain::operator=(const Brain &other)
// {
//     std::cout << "\033[1;33m" << "[Brain] Assignment operator called\n";
//     if (this != &other)
//     {
//         for (int i = 0; i < 100; ++i)
//             ideas[i] = other.ideas[i];
//     }
//     return *this;
// }
        
// Brain::~Brain()
// {
//     std::cout << "\033[1;33m" << "[Brain] Destructor called\n";
// }


// void Brain::setIdea(int index, const std::string &idea)
// {
//     if (index >= 0 && index < 100)
//         ideas[index] = idea;
// }

// std::string Brain::getIdea(int index) const
// {
//     if (index >= 0 && index < 100)
//         return ideas[index];
//     return "";
// }