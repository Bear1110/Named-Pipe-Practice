#include <string>
#include <vector>

#ifndef _ICommand_
#define _ICommand_

class ICommand {
public:
    // pure virtual function
    virtual void execute(std::vector<std::string>) = 0; //virtual void execute() = 0;
};
#endif