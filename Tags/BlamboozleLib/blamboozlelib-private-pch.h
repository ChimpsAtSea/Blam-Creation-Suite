#pragma once

#include <Platform\platform-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>

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
#include "halo2/halo2.h"
#include "halo1/halo1.h"
