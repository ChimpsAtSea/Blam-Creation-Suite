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

#include <murmur3/murmur3.h>

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include <tagdefinitions/eldorado_pc32_eldorado_1_106708_cert_ms23/eldoradotagdefinitions-public-pch.h>
#include <tagcodegen/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32-public-pch.h>
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include <tagdefinitions/halo3_pc64_guerilla/halo3tagdefinitions-public-pch.h>
#include <tagcodegen/halo3_pc64_guerilla/halo3-pc64-public-pch.h>
#endif
