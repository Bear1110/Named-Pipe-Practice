#pragma once
#include "BaseRole.h"
#include <unordered_map>

#ifndef _Server_
#define _Server_

namespace Role {
    class Server :
        public BaseRole
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