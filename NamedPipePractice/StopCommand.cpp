#include "StopCommand.h"
#include <iostream>
StopCommand::StopCommand(Role::IRole* role) :role(role) {};
void StopCommand::execute(std::vector<std::string> a) {
    role->stop = true;
}