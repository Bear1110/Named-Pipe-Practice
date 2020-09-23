#include <iostream>
#include <Windows.h>
#include "Server.h"

using namespace std;

namespace Role {

	void Server::PrintBalance() {
		std::cout << "server" << Server::GetBalance() << endl;
	}

	void Server::StartWaitMessage()
	{

	}

	Server::Server() {
		Server::StartWaitMessage();
	}

	Server::~Server() {
		cout << "Destruct Server" << endl;
	}
}