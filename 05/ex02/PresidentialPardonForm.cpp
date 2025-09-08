#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5, "default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}


PresidentialPardonForm::~PresidentialPardonForm()
{}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getSign()) throw AForm::NotSignedException();
    if (executor.getGrade() > getToexec()) throw AForm::GradeTooLowException();

    std::cout << getTarget() << " has been pardoned." << std::endl;
}