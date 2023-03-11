#pragma once

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>
#include <shared\shared-public-pch.h>
#include <stringdefinitions\stringdefinitions-public-pch.h>
#include <cachefileserialization\cachefileserialization-public-pch.h>
#include <graphicslib\graphicslib-public-pch.h>
#include <symbolslib\symbolslib-public-pch.h>
#include <tagframework\tagframework-public-pch.h>
#include <tagdefinitions\tagdefinitions-public-pch.h>
#include <tagreflection\tagreflection-public-pch.h>
#include <tagvalidate\tagvalidate-public-pch.h>
#include <tagfileserialization\tagfileserialization-public-pch.h>
#include <highlevelcachefileserialization\highlevelcachefileserialization-public-pch.h>

#include <platform\platform-exports-pch.h>
#include "mandrilllib-public-pch.h"

#define ZLIB_CONST
#include <zlib/zlib.h>
#include <oozle/oozle.h>

#include <murmur3/murmur3.h>

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
#include <tagdefinitions/halo3/halo3-tools-pc64.h>
#include <generated/low_level_halo3_pc64/lowlevel-halo3-pc64-public-pch.h>
#include <generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
#endif
