#pragma once
#include "IRole.h"

#ifndef _Client_
#define _Client_

namespace Role {
    class Client :
        public IRole
    {
    public:
        
        Client();
        ~Client();
        void SendMessageToServer(std::string message);
    private:
        void WaitMessageFromServer();
    };
}


#endif#pragma once
