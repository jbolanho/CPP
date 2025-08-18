#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:

        AForm *makeForm(const std::string &formName, const std::string target);

    private:
        typedef AForm* (*FormCreator)(const std::string &target);
        static AForm* createShrubbery(const std::string &target);
        static AForm* createRobotomy(const std::string &target);
        static AForm* createPresidential(const std::string &target);

    

}

#endif