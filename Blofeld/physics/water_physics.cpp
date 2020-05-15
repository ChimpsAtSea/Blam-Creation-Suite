#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(water_physics_hull_surface_definition, s_water_physics_model::k_maximum_hull_surfaces_count)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name^" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_block, "drag", &water_physics_material_override_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(water_physics_material_override, k_maximum_material_types)
{
	FIELD( _field_string_id, "material^" ),
	FIELD( _field_struct, "drag" ),
	FIELD( _field_terminator )
};

TAG_GROUP(water_physics_drag_properties, WATER_PHYSICS_DRAG_PROPERTIES_TAG)
{
	FIELD( _field_struct, "drag" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

