#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <StringDefinitions\stringdefinitions-public-pch.h>
#include <CacheFileSerialization\cachefileserialization-public-pch.h>
#include <TagFramework\tagframework-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <TagFileSerialization\tagfileserialization-public-pch.h>

#include <Platform\platform-exports-pch.h>
#include "highlevelcachefileserialization-public-pch.h"

#define ZLIB_CONST
#include <zlib/zlib.h>
#include <oozle/oozle.h>
#include <murmur3/murmur3.h>
#include <lzxlib\lzxlib.h>

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
#include <TagDefinitions/Halo3/halo3-tools-pc64.h>
#include <Generated/low_level_halo3_pc64/lowlevel-halo3-pc64-public-pch.h>
#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include <TagDefinitions/Eldorado/eldorado-pc32.h>
#include <Generated/low_level_eldorado_pc32/lowlevel-eldorado-pc32-public-pch.h>
#include <Generated/high_level_eldorado_pc32/highlevel-eldorado-pc32-public-pch.h>
#endif
