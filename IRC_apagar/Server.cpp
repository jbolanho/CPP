#include "Server.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

Server::Server(int port, const std::string &password)
    : _port(port), _password(password), _server_fd(-1)
{

}

Server::~Server()
{
    for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        delete it->second;
    
    if(_server_fd != -1)
        close(_server_fd);
}   

void Server::init()
{
    createServerSocket();
    mainLoop()
}

int Server::createServerSocket()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
        std::cout << "Error: socket() failed. \n";
        return -1;
    
    int opt = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        std::cout << "Error: setsockopt() failed \n";
        close(fd);
        return -1;
    }
    
    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(_port);

    if (bind(fd, (sockaddr*) &addr, sizeof(addr)) < 0)
    {
        std::cout << "Error: bind() failed \n";
        close(fd);
        return -1;
    }
    
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1 || fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0) 
    {
        std::cout << "Error: fcntl() failed \n";
        close(fd);
        return -1;

    };

    if (listen(fd, 128) < 0)
    {
        std::cout << "Error: listen() failed \n";
        close(fd);
        return -1;
    }

    return fd;
}

bool Server::init()
{
    _server_fd = createServerSocket();
    if (_server_fd < 0)
    {
        std::cout << "Failed to create server socket\n";
        return false;
    }
    std::cout << "Server listening on port " << _port << "\n";
    return true;
}

void Server::run()
{
    while (true)
    {
        std::vector<pollfd> pfds;
        pfds.reserve(_clients.size() + 1);

        pollfd p0;
        p0.fd = _server_fd;
        p0.events = POLLIN;
        pfds.push_back(p0);

        for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        {
            pollfd p;
            p.fd = it->first;
            p.events = POLLIN;
           
            if (!it->second->outbuf.empty())
                p.events |= POLLOUT;
            
            pfds.push_back(p);
        }

        int ret = poll(&pfds[0], pfds.size(), -1);
        if (ret < 0)
        {
            if (errno == EINTR)
                continue;
            std::cout << "poll() error\n";
            break;
        }

        for (size_t i = 0; i < pfds.size(); i++)
        {
            pollfd &pfd = pfds[i];

            if (pfd.fd == _server_fd)
            {
                if (pfd.fd == _server_fd)
                {
                    if (pfd.revents & POLLIN)
                        acceptNewClient(pfd);
                    continue;
                }
            }

            if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL))
            {
                close(pfd.fd);
                delete _clients[pfd.fd];
                _clients.erase(pfd.fd);
                continue;
            }

            if (pfd.revents & POLLIN)
                handleClientRead(pfd.fd);
            
            if (pfd.revents & POLLOUT)
                handleClientWrite(pfd.fd);
        }
    }
}

void Server::acceptNewClient(const pollfd &pfd)
{
    while (true)
    {
        sockaddr_in peer;
        socklen_t len = sizeof(peer);

        int newfd = accept(_server_fd, (sockaddr*)&peer, &len);
        if (newfd < 0)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                break;
            std::cout << "accept() error\n";
            break;
        }

        //excluiressa linha fcntl(newfd, F_SETFL, O_NONBLOCK) feito com flags;
        // if (fcntl(newfd, F_SETFL, O_NONBLOCK) < 0) 
        int flags = fcntl(newfd, F_GETFL, 0);
        if (flags == -1 || fcntl(newfd, F_SETFL, flags | O_NONBLOCK) < 0) 
        {
            std::cout << "fcntl() error \n";
            close(newfd);
            continue;
        }  
           
        _clients[newfd] = new Client(newfd);
    }
}

void Server::handleClientRead(int fd)
{
    Client *c = _clients[fd];
    char buf[4096];

    while (true)
    {
        ssize_t n = recv(fd, buf, sizeof(buf), 0);
        if (n > 0)
        {
            c->inbuf.append(buf, n);

            size_t pos;
            while((pos = c->inbuf.find("\r\n")) != std::string::npos)
            {
                std::string line = c->inbuf.substr(0, pos);
                c->inbuf.erase(0, pos + 2);

                // fazer parse irc da linha????sim. tem que fazer
                c->outbuf.push_back("Echo:" + line + "\r\n");
            }
        }
        else if (n == 0)
        {
            close (fd);
            delete c;
            _clients.erase(fd);
            return;            
        }
        else
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                break;
            close(fd);
            delete c;
            _clients.erase(fd);
            return;
        }
    }
}

void Server::handleClientWrite(int fd)
{
    Client *c = _clients[fd];

    while (!c->outbuf.empty())
    {
        std::string &msg = c->outbuf.front();

        ssize_t sent = send(fd, msg.c_str(), msg.size(), 0);
        if (sent < 0)
        {
           if (errno == EAGAIN || errno == EWOULDBLOCK)
                return;

            close(fd);
            delete c;
            _clients.erase(fd);
            return;
        }

        if ((size_t)sent < msg.size()) 
        {
            msg.erase(0, sent);
            return;
        } 
        else 
        {
            c->outbuf.erase(c->outbuf.begin());
        }
    }
}







// criar parser de comandos 
//vf acessos após erase. O fd está fechado e cliente removido. 