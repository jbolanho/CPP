#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Bib", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    

    try
    {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();
        std::cout << b2 << std::endl;

        b2.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception:" << e.what() << std::endl;
    }
    

    try
    {
        Bureaucrat b3("InvalidHigh", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

    try
    {
        Bureaucrat b4("InvalidLow", 200);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }


    return 0;
}