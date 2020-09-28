#include "ExitCommand.h"
#include <iostream>
ExitCommand::ExitCommand(Role::BaseRole* role) :role(role) {};
void ExitCommand::execute(std::vector<std::string> a) {
    role->stop = true;
}