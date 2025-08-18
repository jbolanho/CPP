#include "Intern.hpp"
#include "Bureaucrat.hpp"



AForm* Intern::makeForm(const std::string &formName, const std::string target)
{
    const std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cerr << "Error: Form \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}

static AForm* Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}


static AForm* Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm* Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}