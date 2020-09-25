#pragma once
#include "ICommand.h"
#include "IRole.h"

#ifndef _ExitCommand_
#define _ExitCommand_

class ExitCommand :
    public ICommand
{
public:    
    ExitCommand(Role::IRole *role);
    void execute(std::vector<std::string>);
private:
    Role::IRole* role;
};
#endif
