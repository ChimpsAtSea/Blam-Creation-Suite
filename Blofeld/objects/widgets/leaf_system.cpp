#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(leaf_type, k_maximum_leaf_type_definitions)
{
	{ _field_short_integer, "bitmap sprite index#assumes sequence 0. if no sprites uses full bitmap" },
	{ _field_pad, "UNAX", 2 },
	{ _field_real, "frequency" },
	{ _field_real, "mass" },
	{ _field_real_bounds, "geometry scale#default of 0 for both means 0.1" },
	{ _field_real, "flitteriness" },
	{ _field_real, "flitteriness swing arm length*" },
	{ _field_real, "flitteriness scale*" },
	{ _field_real, "flitteriness speed*" },
	{ _field_real, "flitteriness leaves phase*" },
	{ _field_real, "tumble scale" },
	{ _field_real, "rotation scale" },
	{ _field_real, "starting velocity" },
	{ _field_real_fraction_bounds, "air friction XY and Z" },
	{ _field_terminator },
};

TAG_GROUP(leaf_system, LEAF_SYSTEM_TAG)
{
	{ _field_long_flags, "flags!" },
	{ _field_string_id, "marker attach name" },
	{ _field_tag_reference, "bitmap sprite plate" },
	{ _field_real_bounds, "emission rate#seconds" },
	{ _field_real, "lifetime" },
	{ _field_real_bounds, "wind min/max#default 0,0" },
	{ _field_real, "wind scale" },
	{ _field_real, "time scale" },
	{ _field_real_bounds, "fade distance!#from maximum movement range (10+). default 0!" },
	{ _field_real, "emissions sphere radius" },
	{ _field_real, "movement cylinder radius" },
	{ _field_real, "fade in time!" },
	{ _field_real, "fade out time!" },
	{ _field_block, "leaf types", &leaf_type_block },
	{ _field_terminator },
};

} // namespace blofeld

