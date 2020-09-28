#pragma once
#include "ICommand.h"
#include "BaseRole.h"

#ifndef _ExitCommand_
#define _ExitCommand_

class ExitCommand :
    public ICommand
{
public:    
    ExitCommand(Role::BaseRole*role);
    void execute(std::vector<std::string>);
private:
    Role::BaseRole* role;
};
#endif
