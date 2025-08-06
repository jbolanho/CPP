#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() 
{
    try {
        Bureaucrat bib("Bib", 1);
        Bureaucrat bob("Bob", 140);
        ShrubberyCreationForm shrub("Shrubble");
        RobotomyRequestForm robo("Robble");
        PresidentialPardonForm pardon("Presidenbble");

        std::cout << "\n== Signing and executing ShrubberyCreationForm ==\n";
        bob.signAForm(shrub);
        bob.executeForm(shrub);

        std::cout << "\n== Signing and executing RobotomyRequestForm ==\n";
        bib.signAForm(robo);
        bib.executeForm(robo);

        std::cout << "\n== Signing and executing PresidentialPardonForm ==\n";
        bib.signAForm(pardon);
        bib.executeForm(pardon);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
