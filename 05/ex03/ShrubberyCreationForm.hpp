#ifndef SHRUBBERYCREATIONFOR_HPP
#define SHRUBBERYCREATIONFOR_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(const std::string &target);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif