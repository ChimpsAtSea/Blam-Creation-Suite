#pragma once

namespace blofeld
{

	extern const char* water_physics_hull_surface_definition_flags_strings[];
	extern s_string_list_definition water_physics_hull_surface_definition_flags;

	constexpr unsigned long WATER_PHYSICS_DRAG_PROPERTIES_TAG = 'wpdp';

	extern s_tag_group water_physics_drag_properties_group;

	extern s_tag_block_definition water_physics_drag_properties_block_block;
	extern s_tag_struct water_physics_hull_surface_definition_block_block_struct;
	extern s_tag_block_definition water_physics_hull_surface_definition_block_block;
	extern s_tag_struct water_physics_material_override_block_struct;
	extern s_tag_block_definition water_physics_material_override_block;

	extern s_tag_struct water_physics_drag_properties_struct_definition_struct_definition; // tag group
	extern s_tag_struct water_physics_drag_properties_struct_struct_definition;
	extern s_tag_struct physics_force_function_struct_struct_definition;

} // namespace blofeld

