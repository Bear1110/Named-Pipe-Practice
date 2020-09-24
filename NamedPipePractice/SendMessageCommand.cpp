#include "SendMessageCommand.h"

void SendMessageCommand::execute(std::vector<std::string> parameters)
{
    client->SendMessageToServer(parameters[1]);
}
SendMessageCommand::SendMessageCommand(Role::Client* client) : client(client) {}
