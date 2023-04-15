#pragma once

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>
#include <shared\shared-public-pch.h>
#include <symbolsruntime\symbolsruntime-public-pch.h>
#include <tagframework\tagframework-public-pch.h>
#include <tagreflection\tagreflection-public-pch.h>

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
#include "halo1_pc64_guerilla/halo1tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
#include "stubbs_pc64_cache_release/stubbstagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
#include "halo2_pc64_guerilla/halo2tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include "halo3_pc64_guerilla/halo3tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
#include "halo3odst_pc64_guerilla/halo3odsttagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "eldorado_pc32_eldorado_1_106708_cert_ms23/eldoradotagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
#include "haloreach_pc64_sapien/haloreachtagdefinitions-public-pch.h"
#include "haloreach_xbox360_tag_test/haloreachtagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
#include "halo4_pc64_sapien/halo4tagdefinitions-public-pch.h"
#include "halo4_xbox360_tag_test/halo4tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include "groundhog_pc64_sapien/groundhogtagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
#include "halo5_pc64_cache_release/halo5tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
#include "haloinfinite_pc64_cache_release/haloinfinitetagdefinitions-public-pch.h"
#endif

#include <platform\platform-exports-pch.h>
#include "tagdefinitions-public-pch.h"
