#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool sign;
        const int gradeTosign;
        const int gradeToexecute;

    public:
        Form(const std::string &name, int gradeTosign, int gradeToexecute);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        const std::string& getName() const;
        bool getSign() const;
        int getTosign() const;
        int getToexec() const;

        void beSigned(const Bureaucrat &b);

};

std::ostream &operator<<(std::ostream& outp, const Form& f);

#endif