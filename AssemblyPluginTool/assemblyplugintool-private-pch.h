#pragma once

#define return_error(error) do { tool_error = error; return; } while(false)
#define nodecmp(node, str_name) (_stricmp(node.name(), str_name) == 0)

#include <windows.h>
#include <string>
#include <vector>

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

#include <pugixml.hpp>

#include "assembly_data_type.h"
#include "assembly_plugin_tool_error.h"
#include "assembly_bitfield_definition.h"
#include "assembly_enum_definition.h"
#include "assembly_field_definition.h"
#include "assembly_structure_definition.h"
#include "assembly_plugin_tool.h"

using namespace pugi;

#define ENABLE_LOGGING 1
#if ENABLE_LOGGING
#define log printf
#else
#define log(format, ...)
#endif
