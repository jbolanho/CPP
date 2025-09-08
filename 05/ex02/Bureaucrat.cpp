#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
    if(this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}


void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

        

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high! Can't see something annoying without to claim it.";
}

const char *Bureaucrat:: GradeTooLowException::what() const throw()
{
    return "Grade too low! Rules are just suggestions, right?";

}

std::ostream &operator<<(std::ostream& outp, const Bureaucrat& b)
{
    outp << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return outp;
}

void Bureaucrat::signAForm(AForm& f) const 
{
    try 
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << name << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << name << " could't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    
}
