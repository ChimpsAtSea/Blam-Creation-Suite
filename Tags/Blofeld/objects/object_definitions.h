#pragma once

namespace blofeld
{

	constexpr unsigned long OBJECT_TAG = 'obje';

	extern s_tag_group object_group;

	extern s_tag_struct_definition sidecarBlock_block_struct;
	extern s_tag_block_definition sidecarBlock_block;
	extern s_tag_struct_definition object_early_mover_obb_block_block_struct;
	extern s_tag_block_definition object_early_mover_obb_block_block;
	extern s_tag_struct_definition object_ai_properties_block_block_struct;
	extern s_tag_block_definition object_ai_properties_block_block;
	extern s_tag_struct_definition object_function_interpolation_block_block_struct;
	extern s_tag_block_definition object_function_interpolation_block_block;
	extern s_tag_struct_definition object_function_block_block_struct;
	extern s_tag_block_definition object_function_block_block;
	extern s_tag_struct_definition object_runtime_interpolator_functions_block_block_struct;
	extern s_tag_block_definition object_runtime_interpolator_functions_block_block;
	extern s_tag_struct_definition objectFunctionSwitchFunctionBlock_block_struct;
	extern s_tag_block_definition objectFunctionSwitchFunctionBlock_block;
	extern s_tag_struct_definition objectFunctionSwitchBlock_block_struct;
	extern s_tag_block_definition objectFunctionSwitchBlock_block;
	extern s_tag_struct_definition global_object_attachment_block_block_struct;
	extern s_tag_block_definition global_object_attachment_block_block;
	extern s_tag_struct_definition object_widget_block_block_struct;
	extern s_tag_block_definition object_widget_block_block;
	extern s_tag_struct_definition object_change_color_initial_permutation_block_struct;
	extern s_tag_block_definition object_change_color_initial_permutation_block;
	extern s_tag_struct_definition object_change_color_function_block_struct;
	extern s_tag_block_definition object_change_color_function_block;
	extern s_tag_struct_definition object_change_colors_block_struct;
	extern s_tag_block_definition object_change_colors_block;
	extern s_tag_struct_definition multiplayer_object_block_block_struct;
	extern s_tag_block_definition multiplayer_object_block_block;
	extern s_tag_struct_definition object_spawn_effects_block_block_struct;
	extern s_tag_block_definition object_spawn_effects_block_block;
	extern s_tag_block_definition object_block_block;

	extern s_tag_struct_definition object_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition object_abandonment_struct_struct_definition;

	extern const char* water_density_type_enum_strings[];
	extern s_string_list_definition water_density_type_enum;
	extern const char* global_object_change_color_enum_strings[];
	extern s_string_list_definition global_object_change_color_enum;
	extern const char* object_function_interpolation_mode_enum_strings[];
	extern s_string_list_definition object_function_interpolation_mode_enum;
	extern const char* object_function_flags_strings[];
	extern s_string_list_definition object_function_flags;
	extern const char* object_abandonment_flags_strings[];
	extern s_string_list_definition object_abandonment_flags;
	extern const char* object_attachment_flags_strings[];
	extern s_string_list_definition object_attachment_flags;
	extern const char* global_rgb_interpolation_flags_strings[];
	extern s_string_list_definition global_rgb_interpolation_flags;
	extern const char* multiplayer_object_flags_strings[];
	extern s_string_list_definition multiplayer_object_flags;
	extern const char* multiplayer_object_spawn_timer_types_strings[];
	extern s_string_list_definition multiplayer_object_spawn_timer_types;
	extern const char* teleporter_passability_flags_strings[];
	extern s_string_list_definition teleporter_passability_flags;
	extern const char* ai_size_enum_strings[];
	extern s_string_list_definition ai_size_enum;
	extern const char* ai_properties_flags_strings[];
	extern s_string_list_definition ai_properties_flags;
	extern const char* lightmap_shadow_mode_enum_strings[];
	extern s_string_list_definition lightmap_shadow_mode_enum;
	extern const char* sweetener_size_enum_strings[];
	extern s_string_list_definition sweetener_size_enum;
	extern const char* NavMeshCuttingOverrideEnum_strings[];
	extern s_string_list_definition NavMeshCuttingOverrideEnum;
	extern const char* BooleanOverrideEnum_strings[];
	extern s_string_list_definition BooleanOverrideEnum;
	extern const char* object_definition_flags_strings[];
	extern s_string_list_definition object_definition_flags;
	extern const char* object_definition_secondary_flags_strings[];
	extern s_string_list_definition object_definition_secondary_flags;

} // namespace blofeld

