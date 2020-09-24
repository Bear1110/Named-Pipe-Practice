#include <iostream>
#include <windows.h>
#include "Client.h"
#include "Constant.h"
#include "StopCommand.h"
#include "SendMessageCommand.h"

using namespace std;

namespace Role {

	void Client::SendMessageToServer(std::string message)
	{
		cout << "Prepare send Message:" << message << endl;

		HANDLE hPipe;
		DWORD dwWritten;
		hPipe = CreateFile(ToServerPipeNamed,
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


	void Client::WaitMessageFromServer()
	{
		HANDLE hPipe;
		char buffer[BUFSIZE];
		DWORD dwRead;

		hPipe = CreateNamedPipe(ToClientPipeNamed,
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
				while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
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

	Client::Client()
	{
		handler.registerCommand("stop", new StopCommand(this));
		handler.registerCommand("register", new SendMessageCommand(this));
		waitCommnuicateThread = thread(&Client::WaitMessageFromServer, this);
	}

	Client::~Client() {
		cout << "Destruct client" << endl;
	}
}