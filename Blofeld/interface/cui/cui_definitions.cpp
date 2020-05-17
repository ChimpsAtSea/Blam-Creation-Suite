#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(propertyComponentPtrFlags, 1)
	{
		OPTION("source is in external system"),
	};

	TAG_ENUM(property_type, 9)
	{
		OPTION("boolean"),
		OPTION("long"),
		OPTION("real"),
		OPTION("string"),
		OPTION("component"),
		OPTION("tag reference"),
		OPTION("string id"),
		OPTION("argb color"),
		OPTION("emblem info"),
	};

	TAG_ENUM(property_binding_flags, 3)
	{
		OPTION("source is in external screen"),
		OPTION("source is in external system"),
		OPTION("target is in external system"),
	};

	TAG_ENUM(binding_conversion_function_enum_definition, 3)
	{
		OPTION("none"),
		OPTION("negate bool"),
		OPTION("compare long"),
	};

	TAG_ENUM(binding_conversion_comparison_operator_enum_definition, 6)
	{
		OPTION("equality"),
		OPTION("inequality"),
		OPTION("less than"),
		OPTION("less than or equal"),
		OPTION("greater than or equal"),
		OPTION("greater than"),
	};

	TAG_ENUM(animation_property_composition_type, 3)
	{
		OPTION("relative to current"),
		OPTION("absolute to screen"),
		OPTION("absolute to parent"),
	};

	TAG_ENUM(animation_property_flags, 1)
	{
		OPTION("loop"),
	};

	TAG_ENUM(animationInputType, 2)
	{
		OPTION("time"),
		OPTION("binding"),
	};

	TAG_ENUM(step_type, 4)
	{
		OPTION("operator"),
		OPTION("variable"),
		OPTION("real value"),
		OPTION("string id value"),
	};

	TAG_ENUM(step_operator, 15)
	{
		OPTION("add"),
		OPTION("subtract"),
		OPTION("multiply"),
		OPTION("divide"),
		OPTION("negate"),
		OPTION("not"),
		OPTION("less than"),
		OPTION("less than or equal to"),
		OPTION("greater than"),
		OPTION("greater than or equal to"),
		OPTION("equals"),
		OPTION("not equals"),
		OPTION("and"),
		OPTION("or"),
		OPTION("mod"),
	};

	TAG_ENUM(step_variable, 8)
	{
		OPTION("variable a"),
		OPTION("variable b"),
		OPTION("variable c"),
		OPTION("variable d"),
		OPTION("variable e"),
		OPTION("variable f"),
		OPTION("variable g"),
		OPTION("variable h"),
	};

	TAG_ENUM(component_definition_flags, 1)
	{
		OPTION("hidden to tools user"),
	};

	TAG_ENUM(editor_overlay_info_flags, 1)
	{
		OPTION("exclude overlay"),
	};

	TAG_ENUM(editor_property_info_flags, 1)
	{
		OPTION("default value"),
	};

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
		FIELD( _field_word_flags, "flags", &component_definition_flags ),
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
		FIELD( _field_byte_flags, "flags", &propertyComponentPtrFlags ),
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
		FIELD( _field_char_enum, "animation input", &animationInputType ),
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
		FIELD( _field_enum, "composition", &animation_property_composition_type ),
		FIELD( _field_byte_flags, "flags", &animation_property_flags ),
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
		FIELD( _field_enum, "composition", &animation_property_composition_type ),
		FIELD( _field_byte_flags, "flags", &animation_property_flags ),
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
		FIELD( _field_byte_flags, "flags", &editor_overlay_info_flags ),
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
		FIELD( _field_byte_flags, "flags", &editor_property_info_flags ),
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
		FIELD( _field_word_flags, "flags", &property_binding_flags ),
		FIELD( _field_enum, "conversion function", &binding_conversion_function_enum_definition ),
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
		FIELD( _field_char_enum, "comparison operator", &binding_conversion_comparison_operator_enum_definition ),
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
		FIELD( _field_enum, "type", &property_type ),
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
		FIELD( _field_char_enum, "step type^", &step_type ),
		FIELD( _field_char_enum, "operator", &step_operator ),
		FIELD( _field_char_enum, "variable", &step_variable ),
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

