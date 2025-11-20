#include "Channel_Manager.hpp"
#include <algorithm>


ChannelManager::ChannelManager()
{}

ChannelManager::~ChannelManager()
{
    std::map<std::string, Channel*>::iterator it = channels.begin();

    while (it != channels.end()) 
    {
        delete it->second;
        ++it;
    }
}

Channel* ChannelManager::get(const std::string &name)
{
    std::map<std::string, Channel*>::iterator it = channels.find(name);
    if (it != channels.end())
        return it->second;
    return NULL;
}

Channel* ChannelManager::create(const std::string &name)
{
    Channel *c = new Channel(name);
    channels[name] = c;
    return c;
}

void ChannelManager::removeIfEmpty(const std::string &name)
{
    Channel *c = get(name);
    if (!c)
        return;
    if (c->_members.empty())
    {
        channels.erase(name);
        delete c;
    }
}