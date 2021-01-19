#pragma once

namespace blofeld
{

namespace macaque
{

	extern s_tag_block_definition materials_block;
	extern s_tag_struct_definition materials_block_struct_definition; // materials_block
	extern s_tag_block_definition object_type_drag_properties_block;
	extern s_tag_struct_definition object_type_drag_properties_block_struct_definition; // object_type_drag_properties_block
	extern s_tag_block_definition underwater_proxies_block;
	extern s_tag_struct_definition underwater_proxies_block_struct_definition; // underwater_proxies_block
	extern s_tag_block_definition runtime_materials_block;
	extern s_tag_struct_definition runtime_materials_block_struct_definition; // runtime_materials_block

	extern s_tag_struct_definition wet_proxies_struct;
	extern s_tag_struct_definition material_physics_properties_struct;
	extern s_tag_struct_definition materials_sweeteners_struct;

	extern c_versioned_string_list materials_sweeteners_inheritance_flags_strings;
	extern s_string_list_definition materials_sweeteners_inheritance_flags;
	extern c_versioned_string_list global_material_flags_definition_strings;
	extern s_string_list_definition global_material_flags_definition;

} // namespace macaque

} // namespace blofeld

