#pragma once

#ifndef _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING //#TODO: Replace with WideCharToMultiByte and MultiByteToWideChar
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef WIN32_MEAN_AND_LEAN
#define WIN32_MEAN_AND_LEAN
#endif

#include "macro_utils.h"
#include "intrinsics.h"
#include "windows_api.h"
#include "error_handling.h"
#include "platform_types.h"
#include "threading.h"
#include "language_runtime.h"
#include "debug_util.h"
#include "runtime_util.h"
#include "filesystem_util.h"

#include "Windows/window_win32.h"
#include "Windows/command_line.h"
#include "Windows/console.h"

#include "!Resources/resources_manager.h"