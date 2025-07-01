
#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "====== TEST DEBUG ======" << std::endl;
    harl.complain("DEBUG");

    std::cout << "====== TEST INFO ======" << std::endl;
    harl.complain("INFO");

    std::cout << "====== TEST WARNING ======" << std::endl;
    harl.complain("WARNING");

    std::cout << "====== TEST ERROR ======" << std::endl;
    harl.complain("ERROR");

    std::cout << "====== TEST INVALID LEVEL ======" << std::endl;
    harl.complain("NOTHING");

    return 0;
}



// #include "Harl.hpp"
// #include <iostream>

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
//         return 1;
//     }

//     Harl harl;
//     std::string level = argv[1];

//     harl.complain(level);

//     return 0;
// }