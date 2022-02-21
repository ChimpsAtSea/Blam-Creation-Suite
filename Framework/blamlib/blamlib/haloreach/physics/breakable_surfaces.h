#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_breakable_source_group_tag = 'bsdt';

/* ---------- types */

struct s_breakable_surface_definition
{
	real unknown00;
	real unknown04;
	real unknown08;
	real unknown0C;
	real unknown10;
	real unknown14;
	s_tag_reference effect;
	s_tag_reference sound;
	real unknown38;
	real unknown3C;
	real unknown40;
	real unknown44;
	s_tag_reference crack_bitmap;
	s_tag_reference hole_bitemap;
};
static_assert(sizeof(s_breakable_surface_definition) == 0x68);
