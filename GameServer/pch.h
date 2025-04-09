#pragma once

#define WIN32_LEAN_AND_MEAN

#ifndef _DEBUG
#pragma comment(lib, "Release\\ServerCore.lib")
#else
#pragma comment(lib, "Debug\\ServerCore.lib")
#endif

#include "CorePch.h"