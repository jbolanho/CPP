#include "Channel.hpp"
#include "Client.hpp"

Channel::Channel(const std::string &name) 
: _name(name), i_invite_only(false), t_topic_lock(false), l_user_limit(0) 
{}

bool Channel::addClient(Client *c)
{
    if (_members.count(c))
        return false;
    _members.insert(c);
    return true;
}

void Channel::removeClient(Client *c)
{
    _members.erase(c);
    _operators.erase(c);
}

bool Channel::isMember(Client *c)
{
    if(_members.count(c) > 0)
        return true;
    return false;
}

bool Channel::isOp(Client *c)
{
    if(_operators.count(c) > 0)
        return true;
    return false;
}

//vf se precisa de channel manager
//implementar bradcast de msg para os mem,bros do canal
//implementar canais join part privmsg



// const std::string& Channel::getName() const 
// {
//     return _name;
// }

// void Channel::join(Client *c)
// {
//     _members.insert(c);
// }

// void Channel::part(Client *c)
// {
//     _members.erase(c);
// }

// const std::set<Client*>& Channel::getMembers() const
// {
//     return _members;
// }