#include <iostream>
#include "IRole.h"
#include "Server.h"
#include "Client.h"
#include "Constant.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Less the Parameter \""+ serverCommand +"\" Or \""+ clientCommand +"\"";
        return 1;
    }
    std::string inputCommandForInit(argv[1]);           

    if (serverCommand.compare(inputCommandForInit) == 0) {
        Role::IRole* server = new Role::Server();
        server->StartWaitUserInput();
        server->waitInputThread.join();
        //server->waitCommnuicateThread.join();
        //delete server;
    }
    else if (clientCommand.compare(inputCommandForInit) == 0) {
        Role::IRole* client = new Role::Client();
        client->StartWaitUserInput();
        client->waitInputThread.join();
        //delete client;
    }
    else {
        std::cout << "Parameter should be \"" + serverCommand + "\" Or \"" + clientCommand + "\"";
    }
    return 0;
}