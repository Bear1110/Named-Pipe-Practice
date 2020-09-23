#include "IRole.h"
#include <iostream>
using namespace std;

namespace Role {
	double IRole::GetBalance()
	{
		return 0.0;
	}

	IRole::~IRole() {
		cout << "Destruct IRole" << endl;
	}
}