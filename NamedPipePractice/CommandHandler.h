#pragma once
#include <unordered_map>
#include "ICommand.h"

#ifndef _CommandHandler_
#define _CommandHandler_
namespace Command {
    class CommandHandler
    {
    public:
        std::unordered_map<std::string, ICommand*>unordered_dict;
        void registerCommand(std::string commandName, ICommand *command);
        void lookupAndexecuteCommand(std::string command);
        CommandHandler();
    private:
        std::vector<std::string> prepocessCommand(std::string rawCommand);
    };
}
#endif