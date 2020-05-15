#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(water_physics_hull_surface_definition, s_water_physics_model::k_maximum_hull_surfaces_count)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "pad0", 2 },
	{ _field_custom },
	{ _field_string_id, "marker name^" },
	{ _field_real, "radius" },
	{ _field_block, "drag", &water_physics_material_override_block },
	{ _field_terminator },
};

TAG_BLOCK(water_physics_material_override, k_maximum_material_types)
{
	{ _field_string_id, "material^" },
	{ _field_struct, "drag" },
	{ _field_terminator },
};

TAG_GROUP(water_physics_drag_properties, WATER_PHYSICS_DRAG_PROPERTIES_TAG)
{
	{ _field_struct, "drag" },
	{ _field_terminator },
};

} // namespace blofeld

