#ifndef SHRUBBERYCREATIONFOR_HPP
#define SHRUBBERYCREATIONFOR_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm&operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif