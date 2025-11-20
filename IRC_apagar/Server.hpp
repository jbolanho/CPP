#ifndef SERVER_HPP
#define SERVER_HPP

#include <map>
#include <string>
#include <vector>
#include <poll.h>
#include "Client.hpp"
#include "Channel_Manager.hpp"

// class Client;

class Server
{
    private:
        int _port;
        std::string _password;
        int _server_fd;

        std::map<int, Client*> _clients;
        ChannelManager chanman;
        std::vector<struct pollfd> fds;

    
    public:
        Server(int port, const std::string &password);
        ~Server();

        void init();
        
    private:
        
        void createServerSocket();
        void mainLoop();

        void acceptNewClient(const struct pollfd &pfd);
        void handleClientRead(int fd);
        void handleClientWrite(int fd);

        void parseLine(Client *c, const std::string &line);
        void sendNumeric(Client *c, int code, const std::string &msg);

        void cmdPASS(Client *c, const std::vector<std::string> &args);
        void cmdNICK(Client *c, const std::vector<std::string> &args);
        void cmdUSER(Client *c, const std::vector<std::string> &args);
        void cmdJOIN(Client *c, const std::vector<std::string> &args);
        void cmdPART(Client *c, const std::vector<std::string> &args);
        void cmdPRIVMSG(Client *c, const std::vector<std::string> &args);   

};

#endif