#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <SymbolsRuntime\symbolsruntime-public-pch.h>
#include <TagFramework\tagframework-public-pch.h>

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
#include "Halo1/halo1tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
#include "Stubbs/stubbstagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_2
#include "Halo2/halo2tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
#include "Halo3/halo3tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3_ODST
#include "Halo3ODST/halo3odsttagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "Eldorado/eldoradotagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_REACH
#include "HaloReach/haloreachtagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
#include "Halo4/halo4tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include "Groundhog/groundhogtagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_5
#include "Halo5/halo5tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
#include "HaloInfinite/haloinfinitetagdefinitions-public-pch.h"
#endif

#include <Platform\platform-exports-pch.h>
#include "tagdefinitions-public-pch.h"
