#include <iostream>
#include <windows.h>
#include "Client.h"
#include "Constant.h"

using namespace std;

namespace Role {

	void Client::PrintBalance() {
		std::cout << "client" << Client::GetBalance() << endl;
	}

	void Client::WaitUserInput()
	{
		SendMessageToServer("abcdefg");
		/*while (true) {

		}*/
	}

	void Client::WaitServerResponse()
	{
		/*while (true) {

		}*/
	}

	void Client::SendMessageToServer(std::string message)
	{
		HANDLE hPipe;
		DWORD dwWritten;
		hPipe = CreateFile(ToServerPipeNamed,
			GENERIC_READ | GENERIC_WRITE,
			0, // no sharing 
			NULL, // default security attributes
			OPEN_EXISTING, // opens existing pipe 
			0,      // default attributes 
			NULL);  // no template file 

		std::cout << message.length() << "!!" << message.size() << std::endl;
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

	Client::Client() {
		Client::WaitUserInput();
	}

	Client::~Client() {
		cout << "Destruct client" << endl;
	}
}