#include "Client.hpp"
#include <unistd.h>

Client::Client(int fd, const std::string &host) 
: fd(fd), hostname(host), registered(false), pass_ok(false), to_delete(false)
{}


Client::~Client()
{
    if (fd >= 0)
        close(fd);
}


//implementar logica de registro, true qndo PASS, NICK, USER estiverem OK


bool Client::isRegistered() const
{
    if (registered && pass_ok)
        return true;
    return false;
}

void Client::markForDeletion()
{
    to_delete = true;
}