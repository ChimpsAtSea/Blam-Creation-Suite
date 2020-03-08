#pragma once

#include <windows.h>
#include <string>
#include <vector>

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>

#include <pugixml.hpp>

#include "assembly_plugin_tool.h"
