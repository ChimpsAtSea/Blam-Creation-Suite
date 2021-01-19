#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long WATER_PHYSICS_DRAG_PROPERTIES_TAG = 'wpdp';
	extern s_tag_group water_physics_drag_properties_group; // water_physics_drag_properties_block


	extern s_tag_block_definition water_physics_drag_properties_block;
	extern s_tag_block_definition water_physics_hull_surface_definition_block;
	extern s_tag_struct_definition water_physics_hull_surface_definition_block_struct_definition; // water_physics_hull_surface_definition_block
	extern s_tag_block_definition water_physics_material_override_block;
	extern s_tag_struct_definition water_physics_material_override_block_struct_definition; // water_physics_material_override_block

	extern s_tag_struct_definition water_physics_drag_properties_struct_definition; // tag group
	extern s_tag_struct_definition water_physics_drag_properties_struct;
	extern s_tag_struct_definition physics_force_function_struct;

	extern c_versioned_string_list water_physics_hull_surface_definition_flags_strings;
	extern s_string_list_definition water_physics_hull_surface_definition_flags;

	extern s_tag_reference_definition water_physics_drag_properties_reference;

} // namespace macaque

} // namespace blofeld

