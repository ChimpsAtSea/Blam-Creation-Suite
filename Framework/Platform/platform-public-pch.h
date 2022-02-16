#pragma once

#include "warnings.h"

#include <vadefs.h>
#include <xxhash/xxhash.h>
#include <xxhash/xxhash_cx.h>
using namespace xxhash;
using namespace xxhash::literals;

#include "bcs_api.h"

#include "intrinsics.h"
#include "macros.h"
#include "crc32.h"
#include "integral_limits.h"
#include "bcs_assert.h"
#include "bcs_result_handle.h"
#include "callback.h"
#include "debug_point.h"
#include "command_line.h"
#include "clipboard.h"
#include "filesystem.h"
#include "process_module.h"
#include "settings.h"
#include "resources.h"
#include "stack_trace.h"
#include "console.h"
#include "threading.h"
#include "float16.h"
#include "url.h"
#include "strings.h"
#include "keys.h"

#include "engine_platform_build.h"
