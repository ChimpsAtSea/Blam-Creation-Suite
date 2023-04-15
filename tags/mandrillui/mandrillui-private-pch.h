#pragma once

#include <imgui.h>
#include <imgui_internal.h>

#include <platform/platform-public-pch.h>
#include <templatelibrary/templatelibrary-public-pch.h>
#include <shared/shared-public-pch.h>
#include <stringdefinitions/stringdefinitions-public-pch.h>
#include <cachefileserialization/cachefileserialization-public-pch.h>
#include <graphicslib/graphicslib-public-pch.h>
#include <devicecommunication/devicecommunication-public-pch.h>
#include <symbolslib/symbolslib-public-pch.h>
#include <tagframework/tagframework-public-pch.h>
#include <tagdefinitions/tagdefinitions-public-pch.h>
#include <tagreflection/tagreflection-public-pch.h>
#include <tagvalidate/tagvalidate-public-pch.h>
#include <tagfileserialization/tagfileserialization-public-pch.h>
#include <highlevelcachefileserialization/highlevelcachefileserialization-public-pch.h>

#include <platform/platform-exports-pch.h>

#include <mandrilllib/mandrilllib-public-pch.h>

//#if defined(BCS_BUILD_HIGH_LEVEL_HALO_1)
//#include <tagcodegen/halo1_pc64_guerilla/halo1_pc64_forward_declare.h>
//#endif
//#if defined(BCS_BUILD_HIGH_LEVEL_HALO_3)
//#include <tagcodegen/halo3_pc64_guerilla/halo3_pc64_forward_declare.h>
//#endif
//#if defined(BCS_BUILD_HIGH_LEVEL_HALO_REACH)
//#include <tagcodegen/haloreach_xbox360_tag_test/haloreach_xbox360_forward_declare.h>
//#endif
//#if defined(BCS_BUILD_HIGH_LEVEL_HALO_INFINITE)
//#include <tagcodegen/haloinfinite_pc64_cache_release/infinite_pc64_forward_declare.h>
//#endif

#include "mandrillui-public-pch.h"

#if defined(BCS_BUILD_HIGH_LEVEL_HALO1)
#include <tagdefinitions/halo1_pc64_guerilla/halo1tagdefinitions-public-pch.h>
#include <tagcodegen/halo1_pc64_guerilla/halo1-pc64-public-pch.h>
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALO3)
#include <tagdefinitions/halo3_pc64_guerilla/halo3tagdefinitions-public-pch.h>
#include <tagcodegen/halo3_pc64_guerilla/halo3-pc64-public-pch.h>
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALOREACH)
#include <tagdefinitions/haloreach_xbox360_tag_test/haloreachtagdefinitions-public-pch.h>
#include <tagcodegen/haloreach_xbox360_tag_test/haloreach-xbox360-public-pch.h>
#endif
#if defined(BCS_BUILD_HIGH_LEVEL_HALOINFINITE)
#include <tagdefinitions/haloinfinite_pc64_cache_release/haloinfinitetagdefinitions-public-pch.h>
#include <tagcodegen/haloinfinite_pc64_cache_release/haloinfinite-pc64-public-pch.h>
#endif
