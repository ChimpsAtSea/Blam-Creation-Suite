#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(water_physics_drag_properties, WATER_PHYSICS_DRAG_PROPERTIES_TAG, water_physics_drag_properties_block_block );

	TAG_BLOCK(water_physics_material_override, k_maximum_material_types)
	{
		FIELD( _field_string_id, "material^" ),
		FIELD( _field_struct, "drag", &water_physics_drag_properties_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(water_physics_hull_surface_definition_block, s_water_physics_model::k_maximum_hull_surfaces_count)
	{
		FIELD( _field_word_flags, "flags", &water_physics_hull_surface_definition_flags ),
		FIELD( _field_pad, "pad0", 2 ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name^" ),
		FIELD( _field_real, "radius" ),
		FIELD( _field_block, "drag", &water_physics_material_override_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(water_physics_drag_properties_block, 1, water_physics_drag_properties_struct_definition_struct_definition );

	TAG_STRUCT(water_physics_drag_properties_struct)
	{
		FIELD( _field_custom, "Pressure" ),
		FIELD( _field_struct, "pressure", &physics_force_function_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Suction" ),
		FIELD( _field_struct, "suction", &physics_force_function_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_real, "linear damping" ),
		FIELD( _field_real, "angular damping" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(physics_force_function_struct)
	{
		FIELD( _field_custom ),
		FIELD( _field_struct, "velocity to pressure", &mapping_function_struct_definition ),
		FIELD( _field_real, "max velocity:wu/s" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(water_physics_drag_properties_struct_definition)
	{
		FIELD( _field_struct, "drag", &water_physics_drag_properties_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(water_physics_hull_surface_definition_flags, 2)
	{
		OPTION("works on land#drives on an extruded version of everything physical in your level"),
		OPTION("effects only"),
	};

} // namespace blofeld

