#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getSign()) throw AForm::NotSignedException();
    if (executor.getGrade() > getToexec()) throw AForm::GradeTooLowException();

    std::string filename(getTarget() + "_shrubbery");
    std::ofstream file(filename.c_str());
    file << "   ^  \n  /|\\  \n  / | \\\n" <<std::endl;
    file.close();
}

