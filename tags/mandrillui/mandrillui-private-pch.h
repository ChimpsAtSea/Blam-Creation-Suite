#pragma once

#include <imgui.h>
#include <imgui_internal.h>

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>
#include <shared\shared-public-pch.h>
#include <stringdefinitions\stringdefinitions-public-pch.h>
#include <cachefileserialization\cachefileserialization-public-pch.h>
#include <graphicslib\graphicslib-public-pch.h>
#include <devicecommunication\devicecommunication-public-pch.h>
#include <symbolslib\symbolslib-public-pch.h>
#include <tagframework\tagframework-public-pch.h>
#include <tagdefinitions\tagdefinitions-public-pch.h>
#include <tagreflection\tagreflection-public-pch.h>
#include <tagvalidate\tagvalidate-public-pch.h>
#include <tagfileserialization\tagfileserialization-public-pch.h>
#include <highlevelcachefileserialization\highlevelcachefileserialization-public-pch.h>
#include <mandrilllib\mandrilllib-public-pch.h>

#if defined(BCS_BUILD_ENGINE_HALO_1)
#include <Generated/high_level_halo1_pc64/halo1_pc64_forward_declare.h>
#endif
#if defined(BCS_BUILD_ENGINE_HALO_3)
#include <Generated/high_level_halo3_pc64/halo3_pc64_forward_declare.h>
#endif
#if defined(BCS_BUILD_ENGINE_HALO_REACH)
#include <Generated/high_level_haloreach_xbox360/haloreach_xbox360_forward_declare.h>
#endif
#if defined(BCS_BUILD_ENGINE_HALO_INFINITE)
#include <Generated/high_level_infinite_pc64/infinite_pc64_forward_declare.h>
#endif

#include "mandrillui-public-pch.h"

#ifndef __INTELLISENSE__
#if defined(BCS_BUILD_ENGINE_HALO_1)
#include <Generated/high_level_halo1_pc64/highlevel-halo1-pc64-public-pch.h>
#endif
#if defined(BCS_BUILD_ENGINE_HALO_3)
#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>
#endif
#if defined(BCS_BUILD_ENGINE_HALO_REACH)
#include <Generated/high_level_haloreach_xbox360/highlevel-haloreach-xbox360-public-pch.h>
#endif
#if defined(BCS_BUILD_ENGINE_HALO_INFINITE)
#include <Generated/high_level_infinite_pc64/highlevel-infinite-pc64-public-pch.h>
#endif
#endif
