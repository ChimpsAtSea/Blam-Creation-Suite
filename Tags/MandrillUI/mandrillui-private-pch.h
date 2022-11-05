#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <GraphicsLib\graphicslib-public-pch.h>
#include <DeviceCommunication\devicecommunication-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <TagValidate\tagvalidate-public-pch.h>
#include <TagFileSerialization\tagfileserialization-public-pch.h>
#include <MandrillLib\mandrilllib-public-pch.h>

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
