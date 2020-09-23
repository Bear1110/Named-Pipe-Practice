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
        void PrintBalance();
    private:
        void WaitUserInput();
        void SendMessageToServer();
    };
}


#endif#pragma once
