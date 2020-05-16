#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(cui_logic, CUI_LOGIC_TAG, cui_logic_block_block );

TAG_GROUP_FROM_BLOCK(cui_screen, CUI_SCREEN_TAG, cui_screen_block_block );

TAG_GROUP_FROM_BLOCK(cui_static_data, CUI_STATIC_DATA_TAG, cui_static_data_block_block );

TAG_BLOCK_FROM_STRUCT(cui_logic_block, 1, cui_logic_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(cui_screen_block, 1, cui_screen_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(cui_static_data_block, 1, cui_static_data_struct_definition_struct_definition );

TAG_BLOCK(template_instantiation_block_definition, k_cui_max_component_count)
{
	FIELD( _field_tag_reference, "screen reference" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(component_definition, k_cui_max_component_count)
{
	FIELD( _field_string_id, "type" ),
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "parent" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_block_index, "template instantiation index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(component_index_block_definition, k_cui_max_component_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_short_block_index, "component definition index" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(overlay_definition, k_cui_max_overlay_count)
{
	FIELD( _field_string_id, "resolution" ),
	FIELD( _field_string_id, "theme" ),
	FIELD( _field_block, "components", &component_properties_definition_block ),
	FIELD( _field_block, "animations", &animation_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(component_properties_definition, k_cui_max_component_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_struct, "property values", &properties_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_long_value, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_integer, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_real_value, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_string_id_value, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(propertyComponentPtrValue, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "value" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_tag_reference_value, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_tag_reference, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_text_value, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_string, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_argb_color_value, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real_argb_color, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_definition, k_cui_max_animation_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real, "time base offset" ),
	FIELD( _field_real, "time exponential offset" ),
	FIELD( _field_char_enum, "animation input" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_block, "components", &animation_component_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_component_definition, k_cui_max_component_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_integer, "total milliseconds" ),
	FIELD( _field_block, "real properties", &animation_component_real_property_block ),
	FIELD( _field_block, "argb color properties", &animation_component_argb_color_property_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_component_real_property, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_enum, "composition" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_long_integer, "total milliseconds" ),
	FIELD( _field_block, "real keyframes", &animation_property_keyframe_real_value_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_property_keyframe_real_value, 8*k_kilo)
{
	FIELD( _field_long_integer, "duration:milliseconds#the amount of time from the previous keyframe to this keyframe" ),
	FIELD( _field_real, "value#the value when the current time is on this keyframe" ),
	FIELD( _field_struct, "transition function", &animation_scalar_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_component_argb_color_property, 8*k_kilo)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_enum, "composition" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_long_integer, "total milliseconds" ),
	FIELD( _field_block, "argb color keyframes", &animation_property_keyframe_argb_color_value_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_property_keyframe_argb_color_value, 8*k_kilo)
{
	FIELD( _field_long_integer, "duration:milliseconds#the amount of time from the previous keyframe to this keyframe" ),
	FIELD( _field_real_argb_color, "color#the value when the current time is on this keyframe" ),
	FIELD( _field_struct, "transition function", &animation_scalar_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(overlay_editor_only_definition, k_cui_max_overlay_count)
{
	FIELD( _field_string_id, "resolution" ),
	FIELD( _field_string_id, "theme" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_block, "components editor only", &component_editor_only_definition_block ),
	FIELD( _field_block, "animations editor only", &animation_editor_only_definition_block ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(component_editor_only_definition, k_cui_max_component_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "properties editor only", &property_editor_only_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_editor_only_definition, k_cui_max_property_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_editor_only_definition, k_cui_max_animation_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "components editor only", &component_editor_only_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(property_binding, k_cui_max_property_binding_count)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_enum, "conversion function" ),
	FIELD( _field_string_id, "source component name" ),
	FIELD( _field_string_id, "source property name" ),
	FIELD( _field_string_id, "target component name" ),
	FIELD( _field_string_id, "target property name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(binding_conversion_long_comparison_block_definition, k_cui_max_property_binding_count)
{
	FIELD( _field_string_id, "target component name" ),
	FIELD( _field_string_id, "target property name" ),
	FIELD( _field_char_enum, "comparison operator" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_long_integer, "comparison value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(static_data_table, 128)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "mock data for component#a component on this screen that gets replaced in simulation with this data table" ),
	FIELD( _field_struct, "static data", &static_data_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(static_data_column, 128)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_enum, "type" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(static_data_row, 256, properties_struct_struct_definition );

TAG_BLOCK(expression, 128)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_string, "expression text" ),
	FIELD( _field_block, "steps", &expression_step_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(expression_step, s_cui_expression_step_definition::k_maximum_step_count)
{
	FIELD( _field_char_enum, "step type^" ),
	FIELD( _field_char_enum, "operator" ),
	FIELD( _field_char_enum, "variable" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_real, "value&real value" ),
	FIELD( _field_string_id, "string id value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(encapsulatedProperties, k_cuiMaxEncapsulationCount)
{
	FIELD( _field_string_id, "encapsulation name^" ),
	FIELD( _field_block, "properties", &static_data_column_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(string_file_references, 16)
{
	FIELD( _field_tag_reference, "string list" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cui_logic_struct_definition)
{
	FIELD( _field_string_id, "logic name" ),
	FIELD( _field_tag_reference, "string list" ),
	FIELD( _field_struct, "system", &cui_system_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cui_screen_struct_definition)
{
	FIELD( _field_block, "string references", &string_file_references_block ),
	FIELD( _field_tag_reference, "logic" ),
	FIELD( _field_struct, "system", &cui_system_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cui_static_data_struct_definition)
{
	FIELD( _field_struct, "static data", &static_data_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cui_system)
{
	FIELD( _field_block, "template instantiations", &template_instantiation_block_definition_block ),
	FIELD( _field_block, "components", &component_definition_block ),
	FIELD( _field_block, "component indices", &component_index_block_definition_block ),
	FIELD( _field_block, "overlays", &overlay_definition_block ),
	FIELD( _field_block, "overlays editor only", &overlay_editor_only_definition_block ),
	FIELD( _field_block, "property bindings", &property_binding_block ),
	FIELD( _field_block, "binding conversion long comparisons", &binding_conversion_long_comparison_block_definition_block ),
	FIELD( _field_block, "static data tables", &static_data_table_block ),
	FIELD( _field_block, "expressions", &expression_block ),
	FIELD( _field_block, "encapsulated properties", &encapsulatedProperties_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(properties_struct)
{
	FIELD( _field_block, "long properties", &property_long_value_block ),
	FIELD( _field_block, "real properties", &property_real_value_block ),
	FIELD( _field_block, "string_id properties", &property_string_id_value_block ),
	FIELD( _field_block, "component ptr properties", &propertyComponentPtrValue_block ),
	FIELD( _field_block, "tag reference properties", &property_tag_reference_value_block ),
	FIELD( _field_block, "string properties", &property_text_value_block ),
	FIELD( _field_block, "argb color properties", &property_argb_color_value_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(animation_scalar_function)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "scalar function", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(static_data_struct)
{
	FIELD( _field_block, "columns", &static_data_column_block ),
	FIELD( _field_block, "rows", &static_data_row_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

