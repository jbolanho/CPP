#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeTosign, int gradeToexecute, const std::string &target)
        : name(name), sign(false), gradeTosign(gradeTosign), gradeToexecute(gradeToexecute), target(target)
{
    if (gradeTosign < 1 || gradeToexecute < 1)
        throw GradeTooHighException();
    if (gradeTosign > 150 || gradeToexecute > 150)
        throw GradeTooLowException();
} 
  
AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high!";
}   

AForm::AForm(const AForm& other) 
    : name(other.name), sign(other.sign), gradeTosign(other.gradeTosign), gradeToexecute(other.gradeToexecute), target(other.target)
{}


AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->sign= other.sign;
    }
    return *this;
}



const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low!";
}

const char* AForm::NotSignedException::what() const throw() 
{
    return "Form is not signed!";
}

const std::string& AForm::getName() const
{
     return name;
}

bool AForm::getSign() const
{
	return sign;
}

int AForm::getTosign() const
{
	return gradeTosign;
}

int AForm::getToexec() const
{
	return gradeToexecute;
}

const std::string &AForm::getTarget() const 
{
    return target;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeTosign)
	{
		throw GradeTooLowException();
	}
	sign = true;
}

std::ostream &operator<<(std::ostream& outp, const AForm& f)
{
	outp << "AForm \"" << f.getName() << "\", signed: " << (f.getSign() ? "yes" : "no")
       << ", grade to sign: " << f.getTosign()
       << ", grade to execute: " << f.getToexec();
	return outp;
}