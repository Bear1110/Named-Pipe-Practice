#include "IRole.h"
#include <iostream>
#include "ExitCommand.h"

using namespace std;

namespace Role {

	void IRole::StartWaitUserInput()
	{
		waitInputThread = thread(&IRole::continueWaitInputToCmd,this);
	}

	IRole::IRole()
	{
		handler.registerCommand("exit", new ExitCommand(this));
	}

	void IRole::continueWaitInputToCmd()
	{
		cout << "Successfully! Please input command.\n";
		while (true)
		{
			string inputString;
			getline(std::cin, inputString);
			handler.lookupAndexecuteCommand(inputString);

			if (stop)
				break;
		}
	}

	IRole::~IRole() {
		cout << "Destruct IRole" << endl;
	}	
}