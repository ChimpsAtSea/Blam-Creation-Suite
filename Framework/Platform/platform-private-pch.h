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
#include <dbghelp.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

#if BCS_USE_SHARED_LIBRARIES
#define BCS_DEBUG_API __declspec(dllexport)
#endif
#ifdef __cplusplus

#include "platform-public-pch.h"
#include <TemplateLibrary/string_lookup.h>

#endif
