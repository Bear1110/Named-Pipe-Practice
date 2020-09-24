#pragma once
#include <string>
#include <Windows.h>

#ifndef _Constant_
#define _Constant_

#define BUFSIZE 512

const LPCTSTR ToServerPipeNamed = TEXT("\\\\.\\pipe\\namedpipeToServer");
const LPCTSTR ToClientPipeNamed = TEXT("\\\\.\\pipe\\namedpipeToClient");

const std::string clientCommand = "/client";
const std::string serverCommand = "/server";
#endif // !1


