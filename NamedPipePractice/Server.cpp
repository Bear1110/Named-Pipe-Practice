#include <iostream>
#include <Windows.h>
#include "Server.h"
#include "Constant.h"

using namespace std;

namespace Role {

	void Server::PrintBalance()
	{
		std::cout << "server" << Server::GetBalance() << endl;
	}

	void Server::WaitMessageFromClient()
	{
        HANDLE hPipe;
        char buffer[BUFSIZE];  /////////
        DWORD dwRead;


        hPipe = CreateNamedPipe(ToServerPipeNamed,
            PIPE_ACCESS_DUPLEX, // read/write access 
            PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
            1,       // max. instances  
            BUFSIZE, // output buffer size 
            BUFSIZE, // input buffer size 
            NMPWAIT_USE_DEFAULT_WAIT, // client time-out 
            NULL);


        if (hPipe == INVALID_HANDLE_VALUE)
        {
            printf("CreateNamedPipe failed, GLE=%d.\n", GetLastError());
            return;
        }
        
        

        while (hPipe != INVALID_HANDLE_VALUE)
        {
            BOOL fConnected = FALSE;
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);

            if (fConnected)   // wait for someone to connect to the pipe
            {
                while (ReadFile(hPipe, buffer, sizeof(buffer)-1, &dwRead, NULL) != FALSE)
                {
                    /* add terminating zero */
                    buffer[dwRead] = '\0';

                    /* do something with data in buffer */
                    printf("%s\n", buffer);
                }
            }

            DisconnectNamedPipe(hPipe);
        }
	}

	void Server::SendMessageToClient() 
	{

	}

	Server::Server()
	{
		Server::WaitMessageFromClient();
	}
	Server::~Server()
	{
		cout << "Destruct Server" << endl;
	}
	
	
}