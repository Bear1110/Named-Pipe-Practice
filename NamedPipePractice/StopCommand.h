#pragma once
#include "ICommand.h"
#include "IRole.h"

#ifndef _StopCommand_
#define _StopCommand_

class StopCommand :
    public ICommand
{
public:    
    StopCommand(Role::IRole *role);
    void execute(std::vector<std::string>);
private:
    Role::IRole* role;
};
#endif
