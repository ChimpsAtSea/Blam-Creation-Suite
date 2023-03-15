#pragma once

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>
#include <shared\shared-public-pch.h>
#include <symbolsruntime\symbolsruntime-public-pch.h>
#include <tagframework\tagframework-public-pch.h>
#include <tagreflection\tagreflection-public-pch.h>

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1
#include "Halo1/halo1tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_STUBBS
#include "Stubbs/stubbstagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO2
#include "Halo2/halo2tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
#include "Halo3/halo3tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3ODST
#include "Halo3ODST/halo3odsttagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
#include "Eldorado/eldoradotagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOREACH
#include "HaloReach/haloreachtagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO4
#include "Halo4/halo4tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_GROUNDHOG
#include "Groundhog/groundhogtagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO5
#include "Halo5/halo5tagdefinitions-public-pch.h"
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALOINFINITE
#include "HaloInfinite/haloinfinitetagdefinitions-public-pch.h"
#endif

#include <platform\platform-exports-pch.h>
#include "tagdefinitions-public-pch.h"
