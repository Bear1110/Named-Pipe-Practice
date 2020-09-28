#pragma once
#ifndef _BaseRole_
#define _BaseRole_
#include "CommandHandler.h"
#include <thread>

namespace Role {
	class BaseRole
	{
	public:
		std::thread waitInputThread;
		std::thread waitCommnuicateThread;

		void StartWaitUserInput();
		BaseRole();
		virtual ~BaseRole() = 0;
		// Pure virtual function. virtual void PrintBalance() = 0;
		bool stop = false;
	protected:
		Command::CommandHandler handler;
	private:
		void continueWaitInputToCmd();
	};
}

#endif
