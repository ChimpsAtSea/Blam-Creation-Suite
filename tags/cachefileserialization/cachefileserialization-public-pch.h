#pragma once

#include "base/rsa_signature.h"
#include "base/file_last_modification_date.h"
#include "base/network_http_request_hash.h"
#include "base/cache_file_header.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
#include "halo1\halo1_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
#endif
#if \
defined(BCS_BUILD_HIGH_LEVEL_HALO3) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO3ODST) || \
defined(BCS_BUILD_HIGH_LEVEL_ELDORADO) || \
defined(BCS_BUILD_HIGH_LEVEL_HALOREACH) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO4) || \
defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)
#include "gen3\gen3_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include "halo3\halo3_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "eldorado/cache_file_tag_instance.h"
#include "eldorado/cache_file_tags_header.h"
#include "eldorado/strings_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
#include "halo4/halo4_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
#include "haloinfinite\haloinfinite_cache_file_header.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
#endif
