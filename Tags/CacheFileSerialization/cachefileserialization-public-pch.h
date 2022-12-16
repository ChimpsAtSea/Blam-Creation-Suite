#pragma once

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
#include "halo1\halo1_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
#endif
#if \
defined(BCS_BUILD_HIGH_LEVEL_HALO_3) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO_3_ODST) || \
defined(BCS_BUILD_HIGH_LEVEL_ELDORADO) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO_REACH) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO_4) || \
defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)
#include "gen3\gen3_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
#include "halo3\halo3_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "eldorado/cache_file_tag_instance.h"
#include "eldorado/cache_file_tags_header.h"
#include "eldorado/strings_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
#include "halo4/halo4_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
#include "haloinfinite\haloinfinite_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
#endif
