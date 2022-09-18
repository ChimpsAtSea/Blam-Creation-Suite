#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <dbghelp.h>
#include <vector>
#include <algorithm>
#include <mutex>

#include <Platform\platform-public-pch.h>
#include <SymbolsRuntime\symbolsruntime-public-pch.h>

#include "symbolslib-public-pch.h"

#include "symbol_file_section_temp.h"
#include "symbol_file_public_temp.h"
#include "symbol_file_static_temp.h"
#include "symbol_file_header_temp.h"
