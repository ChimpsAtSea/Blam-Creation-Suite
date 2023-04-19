#pragma once

#include <xxhash/xxhash.h>

#include "base/warnings.h"

#ifndef PLATFORM_EXCLUDE_BANNED
#include "base/banned.h"
#endif

#include <stdint.h>

typedef unsigned __int8		bool8_t;
typedef unsigned __int16	bool16_t;
typedef unsigned __int32	bool32_t;
typedef unsigned __int64	bool64_t;
typedef	uint8_t				enum8_t;
typedef	uint16_t			enum16_t;
typedef	uint32_t			enum32_t;
typedef	uint64_t			enum64_t;
typedef	uint8_t				bitfield8_t;
typedef	uint16_t			bitfield16_t;
typedef	uint32_t			bitfield32_t;
typedef	uint64_t			bitfield64_t;
typedef	uint8_t				bitflag8_t;
typedef	uint16_t			bitflag16_t;
typedef	uint32_t			bitflag32_t;
typedef	uint64_t			bitflag64_t;
typedef	uint8_t				undefined8_t;
typedef	uint16_t			undefined16_t;
typedef	uint32_t			undefined32_t;
typedef	uint64_t			undefined64_t;
#if 0 /*__cplusplus <= 201703L*/
typedef char				char8_t;
#endif
//typedef wchar_t			char16_t;


#ifdef _MSC_VER
#include <vadefs.h>
#else
#include <stdarg.h>
#endif

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
#include "shared/aes128.h"
#include "shared/platform.h"
#include "shared/mutex.h"
#include "shared/stopwatch.h"
#include "shared/registry.h"

#include "platformspecific/platform-specific-public-pch.h"

#include "shared/engine_platform_build.h"
