#pragma once
#include "ICommand.h"
#include "Client.h"

#ifndef _SendMessageCommand_
#define _SendMessageCommand_
class SendMessageCommand :
    public ICommand
{
public:
    void execute(std::vector<std::string>);
    SendMessageCommand(Role::Client* client);
private:
    Role::Client* client;
};
#endif
