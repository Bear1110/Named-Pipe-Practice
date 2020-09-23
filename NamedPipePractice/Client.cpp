#include <iostream>
#include <windows.h>
#include "Client.h"

using namespace std;

namespace Role {

	void Client::PrintBalance() {
		std::cout << "client" << Client::GetBalance() << endl;
	}

	void Client::WaitUserInput()
	{

		/*while (true) {

		}*/
	}

	void Client::SendMessageToServer()
	{

	}

	Client::Client() {
		Client::WaitUserInput();
	}

	Client::~Client() {
		cout << "Destruct client" << endl;
	}
}