#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <fileapi.h>
#include <ShlObj.h>
#include <strsafe.h>
#include <psapi.h>

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if _DEBUG
#define BCS_DEBUG_API __declspec(dllexport)
#endif
#ifdef __cplusplus

#include "platform-public-pch.h"

#endif
