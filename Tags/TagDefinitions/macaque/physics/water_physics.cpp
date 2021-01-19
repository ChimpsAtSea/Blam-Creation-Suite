#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		water_physics_drag_properties_group,
		WATER_PHYSICS_DRAG_PROPERTIES_TAG,
		nullptr,
		INVALID_TAG,
		water_physics_drag_properties_block );

	TAG_BLOCK_FROM_STRUCT(
		water_physics_drag_properties_block,
		"water_physics_drag_properties_block",
		1,
		water_physics_drag_properties_struct_definition);

	#define WATER_PHYSICS_HULL_SURFACE_DEFINITION_BLOCK_ID { 0x201415C3, 0x124B45F8, 0xB7118F83, 0xA4AD5B50 }
	TAG_BLOCK(
		water_physics_hull_surface_definition_block,
		"water_physics_hull_surface_definition_block",
		s_water_physics_model::k_maximum_hull_surfaces_count,
		"s_water_physics_hull_surface_definition",
		WATER_PHYSICS_HULL_SURFACE_DEFINITION_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &water_physics_hull_surface_definition_flags },
		{ _field_pad, "pad0", 2 },
		FIELD_CUSTOM(nullptr, _custom_field_marker),
		{ _field_string_id, "marker name^" },
		{ _field_real, "radius" },
		{ _field_block, "drag", &water_physics_material_override_block },
		{ _field_terminator }
	};

	#define WATER_PHYSICS_MATERIAL_OVERRIDE_ID { 0x520E02BA, 0x236044FA, 0xA55378A7, 0xA40AF1D2 }
	TAG_BLOCK(
		water_physics_material_override_block,
		"water_physics_material_override",
		k_maximum_material_types,
		"s_water_physics_drag_override",
		WATER_PHYSICS_MATERIAL_OVERRIDE_ID)
	{
		{ _field_string_id, "material^" },
		{ _field_struct, "drag", &water_physics_drag_properties_struct },
		{ _field_terminator }
	};

	#define WATER_PHYSICS_DRAG_PROPERTIES_STRUCT_DEFINITION_ID { 0xAFDC9397, 0x8FD848DB, 0xB431C572, 0xB7A2BEF8 }
	TAG_STRUCT(
		water_physics_drag_properties_struct_definition,
		"water_physics_drag_properties_struct_definition",
		"s_water_physics_drag_properties",
		WATER_PHYSICS_DRAG_PROPERTIES_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "drag", &water_physics_drag_properties_struct },
		{ _field_terminator }
	};

	#define WATER_PHYSICS_DRAG_PROPERTIES_STRUCT_ID { 0xFCE5EAF2, 0x3E2D4059, 0x8C4C8BC2, 0x4F5683D6 }
	TAG_STRUCT(
		water_physics_drag_properties_struct,
		"water_physics_drag_properties_struct",
		"s_water_physics_drag_properties",
		WATER_PHYSICS_DRAG_PROPERTIES_STRUCT_ID)
	{
		FIELD_CUSTOM("Pressure", _custom_field_function_group_begin),
		{ _field_struct, "pressure", &physics_force_function_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("Suction", _custom_field_function_group_begin),
		{ _field_struct, "suction", &physics_force_function_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_real, "linear damping" },
		{ _field_real, "angular damping" },
		{ _field_terminator }
	};

	#define PHYSICS_FORCE_FUNCTION_STRUCT_ID { 0xC5E705F1, 0xAA0C4E01, 0x981B4053, 0x44CC22DC }
	TAG_STRUCT(
		physics_force_function_struct,
		"physics_force_function_struct",
		"s_physics_force_function",
		PHYSICS_FORCE_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "velocity to pressure", &mapping_function },
		{ _field_real, "max velocity:wu/s" },
		{ _field_terminator }
	};

	STRINGS(water_physics_hull_surface_definition_flags)
	{
		"works on land#drives on an extruded version of everything physical in your level",
		"effects only"
	};
	STRING_LIST(water_physics_hull_surface_definition_flags, water_physics_hull_surface_definition_flags_strings, _countof(water_physics_hull_surface_definition_flags_strings));

	TAG_REFERENCE(water_physics_drag_properties_reference, WATER_PHYSICS_DRAG_PROPERTIES_TAG);

} // namespace macaque

} // namespace blofeld

