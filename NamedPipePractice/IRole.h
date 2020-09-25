#pragma once
#ifndef _IRole_
#define _IRole_
#include "CommandHandler.h"
#include <thread>

namespace Role {
	class IRole
	{
	public:
		std::thread waitInputThread;
		std::thread waitCommnuicateThread;

		void StartWaitUserInput();   
		IRole();
		virtual ~IRole() = 0;
		// Pure virtual function. virtual void PrintBalance() = 0; 
		bool stop = false;
	protected:
		Command::CommandHandler handler;
	private:
		void continueWaitInputToCmd();
	};
}

#endif
