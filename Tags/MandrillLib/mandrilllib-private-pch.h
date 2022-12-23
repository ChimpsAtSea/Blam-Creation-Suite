#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <StringDefinitions\stringdefinitions-public-pch.h>
#include <CacheFileSerialization\cachefileserialization-public-pch.h>
#include <GraphicsLib\graphicslib-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <TagFramework\tagframework-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <TagValidate\tagvalidate-public-pch.h>
#include <TagFileSerialization\tagfileserialization-public-pch.h>
#include <HighLevelCacheFileSerialization\highlevelcachefileserialization-public-pch.h>

#include <Platform\platform-exports-pch.h>
#include "mandrilllib-public-pch.h"

#define ZLIB_CONST
#include <zlib/zlib.h>
#include <oozle/oozle.h>

#include <murmur3/murmur3.h>

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
#include <TagDefinitions/Halo3/halo3-tools-pc64.h>
#include <Generated/low_level_halo3_pc64/lowlevel-halo3-pc64-public-pch.h>
#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
#endif
