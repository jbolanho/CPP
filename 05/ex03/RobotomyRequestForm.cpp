#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
    if (!getSign()) throw AForm::NotSignedException();
    if (executor.getGrade() > getToexec()) throw AForm::GradeTooLowException();

    std::cout << " * robotic noises * " << std::endl;
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed on " << getTarget() << std::endl;

}

