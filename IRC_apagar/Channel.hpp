#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <set>

class Client;

class Channel
{
    public:
        std::string _name;
        std::string topic;
        std::set<Client*> _members;
        std::set<Client*> _operators;
    
        Channel(const std::string &name);

        bool i_invite_only;
        bool t_topic_lock;
        std::string k_key;
        size_t l_user_limit;

        bool addClient(Client *c);
        void removeClient(Client *c);
        bool isMember(Client *c);
        bool isOp(Client *c);

};

#endif



        
        // const std::string& getName() const;
        // void join(Client *c);
        // void part(Client *c);

        // const std::set <Client*>& getMembers() const;