#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WATER_PHYSICS_HULL_SURFACE_DEFINITION_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &water_physics_hull_surface_definition_flags },
		FIELD_PAD_EX("pad0", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name", FIELD_FLAG_INDEX },
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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WATER_PHYSICS_MATERIAL_OVERRIDE_ID)
	{
		{ _field_string_id, "material", FIELD_FLAG_INDEX },
		{ _field_struct, "drag", &water_physics_drag_properties_struct },
		{ _field_terminator }
	};

	#define WATER_PHYSICS_DRAG_PROPERTIES_STRUCT_DEFINITION_ID { 0xAFDC9397, 0x8FD848DB, 0xB431C572, 0xB7A2BEF8 }
	TAG_STRUCT(
		water_physics_drag_properties_struct_definition,
		"water_physics_drag_properties_struct_definition",
		"s_water_physics_drag_properties",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WATER_PHYSICS_DRAG_PROPERTIES_STRUCT_ID)
	{
		FIELD_CUSTOM_EX("Pressure", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "pressure", &physics_force_function_struct },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("Suction", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "suction", &physics_force_function_struct },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_real, "linear damping" },
		{ _field_real, "angular damping" },
		{ _field_terminator }
	};

	#define PHYSICS_FORCE_FUNCTION_STRUCT_ID { 0xC5E705F1, 0xAA0C4E01, 0x981B4053, 0x44CC22DC }
	TAG_STRUCT(
		physics_force_function_struct,
		"physics_force_function_struct",
		"s_physics_force_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_FORCE_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "velocity to pressure", &mapping_function },
		{ _field_real, "max velocity", nullptr, "wu/s" },
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

