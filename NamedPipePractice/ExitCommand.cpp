#include "ExitCommand.h"
#include <iostream>
ExitCommand::ExitCommand(Role::IRole* role) :role(role) {};
void ExitCommand::execute(std::vector<std::string> a) {
    role->stop = true;
}