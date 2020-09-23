#pragma once
#ifndef _IRole_
#define _IRole_


namespace Role {
	class IRole
	{
	public:
		double GetBalance();   // Obtain balance.
		virtual void PrintBalance() = 0;   // Pure virtual function.
		virtual ~IRole() = 0;
	private:
		//double _balance;
	};
}

#endif
