#pragma once

#include "Base/warnings.h"

#ifndef PLATFORM_EXCLUDE_BANNED
#include "Base/banned.h"
#endif

#include <stdint.h>
#include <vadefs.h>

#include <xxhash/xxhash.h>
#include <xxhash/xxhash_cx.h>
using namespace xxhash;
using namespace xxhash::literals;

#include "PlatformSpecific/platform-specific-define-platform.h"

#include "Base/bcs_api.h"
#include "Base/macros.h"
#include "Base/integral_limits.h"

#include "Shared/intrinsics.h"
#include "Shared/atomic.h"
#include "Shared/crc32.h"
#include "Shared/bcs_assert.h"
#include "Shared/bcs_result.h"
#include "Shared/bcs_result_handle.h"
#include "Shared/callback.h"
#include "Shared/debug_point.h"
#include "Shared/float16.h"
#include "Shared/strings.h"
#include "Shared/keys.h"
#include "Shared/aes128.h"
#include "Shared/platform.h"
#include "Shared/mutex.h"
#include "Shared/stopwatch.h"

#include "PlatformSpecific/platform-specific-public-pch.h"

#include "Shared/engine_platform_build.h"
