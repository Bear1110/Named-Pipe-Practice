#pragma once
#include "IRole.h"
#include <unordered_map>

#ifndef _Server_
#define _Server_

namespace Role {
    class Server :
        public IRole
    {
    public:
        Server();
        ~Server();

    private:
        std::unordered_map<std::string, int> playerTable;
        void WaitMessageFromClient();
        void SendMessageToClient(std::string message);
        std::string RegisterPlayer(std::string);
    };
}
#endif