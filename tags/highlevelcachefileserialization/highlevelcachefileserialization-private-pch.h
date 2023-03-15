#pragma once

#include <platform/platform-public-pch.h>
#include <templatelibrary/templatelibrary-public-pch.h>
#include <shared/shared-public-pch.h>
#include <stringdefinitions/stringdefinitions-public-pch.h>
#include <cachefileserialization/cachefileserialization-public-pch.h>
#include <tagframework/tagframework-public-pch.h>
#include <tagdefinitions/tagdefinitions-public-pch.h>
#include <tagreflection/tagreflection-public-pch.h>
#include <tagfileserialization/tagfileserialization-public-pch.h>

#include <platform/platform-exports-pch.h>
#include "highlevelcachefileserialization-public-pch.h"

#define ZLIB_CONST
#include <zlib/zlib.h>
#include <oozle/oozle.h>
#include <murmur3/murmur3.h>
#include <lzxlib/lzxdecoder.h>

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include <TagDefinitions/Halo3/halo3-tools-pc64.h>
#include <Generated/low_level_halo3_pc64/lowlevel-halo3-pc64-public-pch.h>
#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include <TagDefinitions/Eldorado/eldorado-pc32.h>
#include <Generated/low_level_eldorado_pc32/lowlevel-eldorado-pc32-public-pch.h>
#include <Generated/high_level_eldorado_pc32/highlevel-eldorado-pc32-public-pch.h>
#endif
