#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <SymbolsRuntime\symbolsruntime-public-pch.h>
#include <TagFramework\tagframework-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>

#define BCS_HIGH_LEVEL_NO_PROTOTYPES

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
#include "Halo1/halo1tagdefinitions-public-pch.h"
#include <Generated/high_level_halo1_pc64/highlevel-halo1-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
#include "Stubbs/stubbstagdefinitions-public-pch.h"
#include <Generated/high_level_stubbs_pc64/highlevel-stubbs-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_2
#include "Halo2/halo2tagdefinitions-public-pch.h"
#include <Generated/high_level_halo2_pc64/highlevel-halo2-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
#include "Halo3/halo3tagdefinitions-public-pch.h"
#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
#include "Halo3ODST/halo3odsttagdefinitions-public-pch.h"
#include <Generated/high_level_halo3odst_pc64/highlevel-halo3odst-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "Eldorado/eldoradotagdefinitions-public-pch.h"
#include <Generated/high_level_eldorado_pc32/highlevel-eldorado-pc32-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
#include "HaloReach/haloreachtagdefinitions-public-pch.h"
#include <Generated/high_level_haloreach_xbox360/highlevel-haloreach-xbox360-public-pch.h>
#include <Generated/high_level_haloreach_pc64/highlevel-haloreach-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
#include "Halo4/halo4tagdefinitions-public-pch.h"
#include <Generated/high_level_halo4_xbox360/highlevel-halo4-xbox360-public-pch.h>
#include <Generated/high_level_halo4_pc64/highlevel-halo4-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include "Groundhog/groundhogtagdefinitions-public-pch.h"
#include <Generated/high_level_groundhog_pc64/highlevel-groundhog-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
#include "Halo5/halo5tagdefinitions-public-pch.h"
#include <Generated/high_level_halo5_pc64/highlevel-halo5-pc64-public-pch.h>
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
#include "HaloInfinite/haloinfinitetagdefinitions-public-pch.h"
#include <Generated/high_level_haloinfinite_pc64/highlevel-haloinfinite-pc64-public-pch.h>
#endif

#include <Platform\platform-exports-pch.h>
#include "tagregistry-public-pch.h"
