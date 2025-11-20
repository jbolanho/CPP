KICK - Ejetar um cliente do canal
∗ INVITE - Convidar um cliente para um canal
∗ TOPIC - Alterar ou visualizar o tópico do canal
∗ MODE - Alterar o modo do canal:

i: Definir/remover canal somente para convidados
· t: Definir/remover as restrições do comando TOPIC para operadores
de canal
· k: Definir/remover a chave do canal (senha)
· o: Dar/tirar o privilégio de operador de canal
· l: Definir/remover o limite de usuários para o canal



#include "IRCServer.hpp"
if (args.size() < 4) return;
c->username = args[0];
c->realname = args[3];


if (c->pass_ok && !c->nickname.empty()) {
c->registered = true;
sendNumeric(c, 001, ":Welcome to IRC");
}
}


void IRCServer::cmdJOIN(Client *c, const std::vector<std::string> &args) {
if (args.empty()) return;
std::string chan = args[0];


Channel *ch = chanman.get(chan);
if (!ch) ch = chanman.create(chan);


ch->addClient(c);


// Names
std::stringstream list;
for (std::set<Client*>::iterator it = ch->members.begin(); it != ch->members.end(); ++it)
list << (*it)->nickname << " ";


sendNumeric(c, 353, "= " + chan + " :" + list.str());
sendNumeric(c, 366, chan + " :End of NAMES list");
}


void IRCServer::cmdPART(Client *c, const std::vector<std::string> &args) {
if (args.empty()) return;
std::string chan = args[0];


Channel *ch = chanman.get(chan);
if (!ch) return;


ch->removeClient(c);
chanman.removeIfEmpty(chan);
}


void IRCServer::cmdPRIVMSG(Client *c, const std::vector<std::string> &args) {
if (args.size() < 2) return;
std::string target = args[0];
std::string msg = args[1];


if (target[0] == '#') {
Channel *ch = chanman.get(target);
if (!ch) return;


for (std::set<Client*>::iterator it = ch->members.begin(); it != ch->members.end(); ++it) {
if (*it == c) continue;
(*it)->outbuf += ":" + c->nickname + "!" + c->username + "@" + c->hostname + " PRIVMSG " + target + " :" + msg + "\r\n";
}
}
}


// ================= MAIN =================
#include <iostream>
int main(int argc, char **argv) {
if (argc != 3) {
std::cout << "Usage: ./ircserv <port> <password>\n";
return 1;
}


int port = std::atoi(argv[1]);
std::string pass = argv[2];


IRCServer s(port, pass);
s.start();


return 0;
}


// --- Added MODE, KICK, INVITE, TOPIC parsing handlers ---


// In Parser.cpp (append at end)
// MODE handler
void Parser::handleMODE(Server &srv, Client &c, const std::vector<std::string> &args)
{
// TODO full implementation
}


void Parser::handleKICK(Server &srv, Client &c, const std::vector<std::string> &args)
{
// TODO full implementation
}


void Parser::handleINVITE(Server &srv, Client &c, const std::vector<std::string> &args)
{
// TODO full implementation
}


void Parser::handleTOPIC(Server &srv, Client &c, const std::vector<std::string> &args)
{
// TODO full implementation
}