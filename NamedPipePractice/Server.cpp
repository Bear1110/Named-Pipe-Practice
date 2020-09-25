#include <iostream>
#include <Windows.h>
#include "Server.h"
#include "Constant.h"

using namespace std;

namespace Role {

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
        
        printf("Start Wait Meesage from client...\n");

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
                    string info = RegisterPlayer(buffer);
                    SendMessageToClient(info);
                    cout << info <<endl;
                }
            }
            DisconnectNamedPipe(hPipe);
        }
	}

	void Server::SendMessageToClient(string message) 
	{
        HANDLE hPipe;
        DWORD dwWritten;
        hPipe = CreateFile(ToClientPipeNamed,
            GENERIC_READ | GENERIC_WRITE,
            0, // no sharing 
            NULL, // default security attributes
            OPEN_EXISTING, // opens existing pipe 
            0,      // default attributes 
            NULL);  // no template file 

        if (hPipe != INVALID_HANDLE_VALUE)
        {
            WriteFile(hPipe,
                message.c_str(),
                message.length(),   // = length of string + terminating '\0' !!!
                &dwWritten,
                NULL);

            CloseHandle(hPipe);
        }
	}

    std::string Server::RegisterPlayer(std::string playerName)
    {    
        unordered_map<string, int>::iterator it = playerTable.find(playerName);
        if (it == playerTable.end())
        {
            playerTable[playerName] = 1;
            return "Register successfully. Player:"+playerName+"";
        }
        else {
            return "Register fail. Player:" + playerName + " Already Exsist.";
        }
    }

	Server::Server()
	{
        waitCommnuicateThread = thread(&Server::WaitMessageFromClient,this);
	}
	Server::~Server()
	{
		cout << "Destruct Server" << endl;
	}	
}