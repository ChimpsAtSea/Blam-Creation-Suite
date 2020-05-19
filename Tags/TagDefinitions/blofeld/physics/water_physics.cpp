#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(water_physics_drag_properties, WATER_PHYSICS_DRAG_PROPERTIES_TAG, water_physics_drag_properties_block_block );

	TAG_BLOCK(water_physics_material_override, k_maximum_material_types)
	{
		{ _field_string_id, "material^" },
		{ _field_struct, "drag", &water_physics_drag_properties_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(water_physics_hull_surface_definition_block, s_water_physics_model::k_maximum_hull_surfaces_count)
	{
		{ _field_word_flags, "flags", &water_physics_hull_surface_definition_flags },
		{ _field_pad, "pad0", 2 },
		{ _field_custom },
		{ _field_string_id, "marker name^" },
		{ _field_real, "radius" },
		{ _field_block, "drag", &water_physics_material_override_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(water_physics_drag_properties_block, 1, water_physics_drag_properties_struct_definition_struct_definition );

	TAG_STRUCT(water_physics_drag_properties_struct)
	{
		{ _field_custom, "Pressure" },
		{ _field_struct, "pressure", &physics_force_function_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "Suction" },
		{ _field_struct, "suction", &physics_force_function_struct_struct_definition },
		{ _field_custom },
		{ _field_real, "linear damping" },
		{ _field_real, "angular damping" },
		{ _field_terminator }
	};

	TAG_STRUCT(physics_force_function_struct)
	{
		{ _field_custom },
		{ _field_struct, "velocity to pressure", &mapping_function_struct_definition },
		{ _field_real, "max velocity:wu/s" },
		{ _field_terminator }
	};

	TAG_STRUCT(water_physics_drag_properties_struct_definition)
	{
		{ _field_struct, "drag", &water_physics_drag_properties_struct_struct_definition },
		{ _field_terminator }
	};

	STRINGS(water_physics_hull_surface_definition_flags)
	{
		"works on land#drives on an extruded version of everything physical in your level",
		"effects only"
	};
	STRING_LIST(water_physics_hull_surface_definition_flags, water_physics_hull_surface_definition_flags_strings, _countof(water_physics_hull_surface_definition_flags_strings));

	TAG_REFERENCE(water_physics_drag_properties_reference, WATER_PHYSICS_DRAG_PROPERTIES_TAG);

} // namespace blofeld

