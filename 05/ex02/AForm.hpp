#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int gradeTosign;
        const int gradeToexecute;
        const std::string target;

    public:
        AForm(const std::string &name, int gradeTosign, int gradeToexecute, const std::string &target);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        class GradeTooHighException : public std::exception
        {
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char *what() const throw();
        };

        class NotSignedException : public std::exception
        {
            const char *what() const throw();
        };

        const std::string& getName() const;
        bool getSign() const;
        int getTosign() const;
        int getToexec() const;
        const std::string &getTarget() const;

        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator<<(std::ostream& outp, const AForm& f);

#endif