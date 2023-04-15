#pragma once

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>
#include <shared\shared-public-pch.h>
#include <tagframework\tagframework-public-pch.h>
#include <tagreflection\tagreflection-public-pch.h>
#include <tagdefinitions\tagdefinitions-public-pch.h>

#define BCS_HIGH_LEVEL_NO_PROTOTYPES

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
#include <tagdefinitions/halo1_pc64_guerilla/halo1tagdefinitions-public-pch.h>
#include <tagcodegen/halo1_pc64_guerilla/halo1-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
#include <tagdefinitions/stubbs_pc64_cache_release/stubbstagdefinitions-public-pch.h>
#include <tagcodegen/stubbs_pc64_cache_release/stubbs-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
#include <tagdefinitions/halo2_pc64_guerilla/halo2tagdefinitions-public-pch.h>
#include <tagcodegen/halo2_pc64_guerilla/halo2-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include <tagdefinitions/halo3_pc64_guerilla/halo3tagdefinitions-public-pch.h>
#include <tagcodegen/halo3_pc64_guerilla/halo3-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
#include <tagdefinitions/halo3odst_pc64_guerilla/halo3odsttagdefinitions-public-pch.h>
#include <tagcodegen/halo3odst_pc64_guerilla/halo3odst-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include <tagdefinitions/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32.h>
#include <tagcodegen/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
#include <tagdefinitions/haloreach_pc64_sapien/haloreachtagdefinitions-public-pch.h>
#include <tagcodegen/haloreach_pc64_sapien/haloreach-pc64-public-pch.h>
#include <tagdefinitions/haloreach_xbox360_tag_test/haloreachtagdefinitions-public-pch.h>
#include <tagcodegen/haloreach_xbox360_tag_test/haloreach-xbox360-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
#include <tagdefinitions/halo4_pc64_sapien/halo4tagdefinitions-public-pch.h>
#include <tagcodegen/halo4_pc64_sapien/halo4-pc64-public-pch.h>
#include <tagdefinitions/halo4_xbox360_tag_test/halo4tagdefinitions-public-pch.h>
#include <tagcodegen/halo4_xbox360_tag_test/halo4-xbox360-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include <tagdefinitions/groundhog_pc64_sapien/groundhogtagdefinitions-public-pch.h>
#include <tagcodegen/groundhog_pc64_sapien/groundhog-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
#include <tagdefinitions/halo5_pc64_cache_release/halo5tagdefinitions-public-pch.h>
#include <tagcodegen/halo5_pc64_cache_release/halo5-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
#include <tagdefinitions/haloinfinite_pc64_cache_release/haloinfinitetagdefinitions-public-pch.h>
#include <tagcodegen/haloinfinite_pc64_cache_release/haloinfinite-pc64-public-pch.h>
#endif

#include <platform\platform-exports-pch.h>
#include "tagregistry-public-pch.h"
