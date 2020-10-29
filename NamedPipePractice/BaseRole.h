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
		bool stop = false;

		void StartWaitUserInput();
		BaseRole();
		virtual ~BaseRole() = 0;

	protected:
		Command::CommandHandler handler;
	private:
		void continueWaitInputToCmd();
	};
}

#endif
