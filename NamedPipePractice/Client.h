#pragma once
#include "BaseRole.h"

#ifndef _Client_
#define _Client_

namespace Role {
    class Client :
        public BaseRole
    {
    public:

        Client();
        ~Client() override;
        void SendMessageToServer(std::string message);
    private:
        void WaitMessageFromServer();
    };
}


#endif#pragma once
