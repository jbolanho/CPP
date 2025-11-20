#include "Server.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Please, use: ./ircserv <port> <password>\n";
        return 1;
    }

    int port = std::atoi(argv[1]);
    //validar intervalo possivel de porta???

    std::string password = argv[2];

    Server server(port, password);

    if (!server.init())
        return 1;
    
    server.run();

    return 0;
}


//ponto de entrada do servidor, lê a porta e a senha enviadas como argumento, cria o Sever e roda o loop