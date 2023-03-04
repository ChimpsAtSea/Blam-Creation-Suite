#pragma once

#include "base/warnings.h"

#ifndef PLATFORM_EXCLUDE_BANNED
#include "base/banned.h"
#endif

#include <stdint.h>
#ifdef _MSC_VER
#include <vadefs.h>
#else
#include <stdarg.h>
#endif

#include <xxhash/xxhash.h>
#include <xxhash/xxhash_cx.h>
using namespace xxhash;
using namespace xxhash::literals;

#include "platformspecific/platform-specific-define-platform.h"

#include "base/bcs_api.h"
#include "base/macros.h"
#include "base/integral_limits.h"

#include "shared/intrinsics.h"
#include "shared/atomic.h"
#include "shared/crc32.h"
#include "shared/bcs_assert.h"
#include "shared/bcs_result.h"
#include "shared/bcs_result_handle.h"
#include "shared/callback.h"
#include "shared/debug_point.h"
#include "shared/float16.h"
#include "shared/strings.h"
#include "shared/keys.h"
#include "shared/aes128.h"
#include "shared/platform.h"
#include "shared/mutex.h"
#include "shared/stopwatch.h"
#include "shared/registry.h"

#include "platformspecific/platform-specific-public-pch.h"

#include "shared/engine_platform_build.h"
