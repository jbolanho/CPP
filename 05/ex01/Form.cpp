#include "Form.hpp"

Form::Form(const std::string &name, int gradeTosign, int gradeToexecute)
        : name(name), sign(false), gradeTosign(gradeTosign), gradeToexecute(gradeToexecute)
{
    if (gradeTosign < 1 || gradeToexecute < 1)
        throw GradeTooHighException();
    if (gradeTosign > 150 || gradeToexecute > 150)
        throw GradeTooLowException();
} 
  
Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}   

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}

const std::string& Form::getName() const
{
     return name;
}

bool Form::getSign() const
{
	return sign;
}

int Form::getTosign() const
{
	return gradeTosign;
}

int Form::getToexec() const
{
	return gradeToexecute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeTosign)
	{
		throw GradeTooLowException();
	}
	sign = true;
}

std::ostream &operator<<(std::ostream& outp, const Form& f)
{
	outp << "Form \"" << f.getName() << "\", signed: " << (f.getSign() ? "yes" : "no")
       << ", grade to sign: " << f.getTosign()
       << ", grade to execute: " << f.getToexec();
	return outp;
}