#pragma once

#define BCS_DEBUG_API
#include <Tags\TagDefinitions\types\field_id.h>
#undef BCS_DEBUG_API

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <DbgHelp.h>
#include <sstream> // #TODO: replace with custom string stream implementation
#include <set>

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <SymbolsRuntime\symbolsruntime-public-pch.h>

#include "endianness.h"

#include "blamboozlelib-public-pch.h"

#include "blamlib_string_parser.h"

// #TODO: Common
struct tag_group
{
	union
	{
		unsigned long value;
		char name[4];
	};
};

using btag_group = bigendian_type<tag_group>;

#include "infinite/infinite.h"
#include "halo5/halo5_forge.h"
#include "halo4/halo4.h"
#include "reach_x360/haloreach_x360.h"
#include "halo3/halo3.h"
#include "halo2/halo2.h"
#include "halo1/halo1.h"
