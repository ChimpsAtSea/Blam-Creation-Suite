#pragma once

#define ModulePtr(name) GetModuleHandleA(name)
#define ModuleCharPtr(name) reinterpret_cast<char*>(ModulePtr(name))

#include "logging.h"
#include "detour_helpers.h"
#include "defs.h"

#include "DataReference.h"