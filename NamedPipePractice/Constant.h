#pragma once
#include <string>
#include <Windows.h>

#ifndef _Constant_
#define _Constant_

LPCTSTR lpszPipename = TEXT("\\\\.\\pipe\\mynamedpipe");

const std::string clientCommand = "client";
const std::string serverCommand = "server";
#endif // !1


