#pragma once

#include <Platform\platform-public-pch.h>
#include <Versioning\versioning-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>
#include <GameFramework\gameframework-public-pch.h>

#include "blamboozlelib-public-pch.h"

// #TODO: Common
struct tag_group
{
	union
	{
		uint32_t value;
		char name[4];
	};
};

using btag_group = bigendian_type<tag_group>;

#include "halo5/halo5_forge.h"
#include "halo4/halo4.h"


