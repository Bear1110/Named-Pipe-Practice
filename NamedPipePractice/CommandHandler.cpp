#include "CommandHandler.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace Command {

    CommandHandler::CommandHandler(){ }

    std::vector<std::string> CommandHandler::prepocessCommand(string rawCommand)
    {
        istringstream in(rawCommand);
        vector<string> v;
        string t;
        while (in >> t) {
            v.push_back(t);
        }
        return v;
    }


    void CommandHandler::registerCommand(string commandName, ICommand *command)
    {
        unordered_dict.insert(pair<string, ICommand*>(commandName, command));
    }

    void CommandHandler::lookupAndexecuteCommand(string command)
    {
        if (command.compare("") == 0)
            return;
        vector<string> parameters = prepocessCommand(command);
        unordered_map<string, ICommand*>::iterator it = unordered_dict.find(parameters[0]);

        if (it != unordered_dict.end())
        {
            it->second->execute(parameters);
        }
        else {
            cout << parameters[0] <<" is not a command." << endl;
        }
    }
}
