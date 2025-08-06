#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    try 
    {
        Bureaucrat b1("Bib", 5);
        Bureaucrat b2("Bob", 100);

        Form f1("Form1", 50, 30);
        Form f2("Form2", 5, 1);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b2.signForm(f1); 
        b1.signForm(f1); 
        b1.signForm(f2); 

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}