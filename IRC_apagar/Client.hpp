#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <netinet/in.h>

class Client
{
    public:
        int fd;
        std::string inbuf;
        std::string outbuf;
        
        bool registered;
        bool pass_ok;
        bool to_delete;

        std::string nickname;
        std::string username;
        std::string realname;
        std::string hostname;
      
        Client(int fd, const std::string &host);
        ~Client();

        bool isRegistered() const;
        void markForDeletion();


};

#endif