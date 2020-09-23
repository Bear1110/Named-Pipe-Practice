#pragma once
#include "IRole.h"

#ifndef _Server_
#define _Server_

namespace Role {
    class Server :
        public IRole
    {
    public:
        Server();
        ~Server();
        void PrintBalance();

    private:
        void StartWaitMessage();
    };
}
#endif