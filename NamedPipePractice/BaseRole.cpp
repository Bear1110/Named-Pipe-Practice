#include "BaseRole.h"
#include <iostream>
#include "ExitCommand.h"

using namespace std;

namespace Role {

	void BaseRole::StartWaitUserInput()
	{
		waitInputThread = thread(&BaseRole::continueWaitInputToCmd,this);
	}

	BaseRole::BaseRole()
	{
		handler.registerCommand("exit", new ExitCommand(this));
	}

	void BaseRole::continueWaitInputToCmd()
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

	BaseRole::~BaseRole() {
		cout << "Destruct BaseRole" << endl;
	}
}