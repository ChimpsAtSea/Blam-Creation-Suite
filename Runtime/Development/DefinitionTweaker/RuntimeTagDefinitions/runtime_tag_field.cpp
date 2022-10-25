#include "definitiontweaker-private-pch.h"

c_runtime_tag_field::c_runtime_tag_field(c_runtime_tag_definitions& _runtime_tag_definitions) :
	field_type(),
	name("new field"),
	description(),
	units(),
	limits(),
	old_names(),
	flags(),
	block_definition(),
	struct_definition(),
	array_definition(),
	string_list_definition(),
	tag_reference_definition(),
	tag_resource_definition(),
	tag_interop_definition(),
	tag_data_definition(),
	block_index_custom_search_definition(),
	explanation(),
	padding(),
	length(),
	versioning(),
	custom_type(),
	original_field(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_field::c_runtime_tag_field(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_field const& source) :
	field_type(source.field_type),
	name(source.name),
	description(source.description),
	units(source.units),
	limits(source.limits),
	old_names(source.old_names),
	flags(source.flags),
	block_definition(source.block_definition),
	struct_definition(source.struct_definition),
	array_definition(source.array_definition),
	string_list_definition(source.string_list_definition),
	tag_reference_definition(source.tag_reference_definition),
	tag_resource_definition(source.tag_resource_definition),
	tag_interop_definition(source.tag_interop_definition),
	tag_data_definition(source.tag_data_definition),
	block_index_custom_search_definition(source.block_index_custom_search_definition),
	explanation(source.explanation),
	padding(source.padding),
	length(source.length),
	versioning(source.versioning),
	custom_type(source.custom_type),
	original_field(source.original_field),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_field::c_runtime_tag_field(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_field& field) :
	field_type(field.field_type),
	name(safe_string(field.name)),
	description(safe_string(field.description)),
	units(safe_string(field.units)),
	limits(safe_string(field.limits)),
	old_names(),
	flags(field.flags),
	block_definition(),
	struct_definition(),
	array_definition(),
	string_list_definition(),
	tag_reference_definition(),
	tag_resource_definition(),
	tag_interop_definition(),
	tag_data_definition(),
	block_index_custom_search_definition(),
	explanation(),
	padding(),
	length(),
	versioning(),
	custom_type(field.custom_type),
	original_field(&field),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	if (field.old_names)
	{
		debug_point;
	}

	switch (field.field_type)
	{
	case blofeld::_field_block:
		ASSERT(field.block_definition != nullptr);
		block_definition = &runtime_tag_definitions.enqueue_tag_block_definition(*field.block_definition);
		break;
	case blofeld::_field_struct:
		ASSERT(field.block_definition != nullptr);
		struct_definition = &runtime_tag_definitions.enqueue_tag_struct_definition(*field.struct_definition);
		break;
	case blofeld::_field_array:
		ASSERT(field.block_definition != nullptr);
		array_definition = &runtime_tag_definitions.enqueue_tag_array_definition(*field.array_definition);
		break;
		// case blofeld::_field_string_list:
	case blofeld::_field_char_enum:
	case blofeld::_field_short_enum:
	case blofeld::_field_long_enum:
	case blofeld::_field_long_flags:
	case blofeld::_field_word_flags:
	case blofeld::_field_byte_flags:
		ASSERT(field.block_definition != nullptr);
		string_list_definition = &runtime_tag_definitions.enqueue_string_list_definition(*field.string_list_definition);
		break;
	case blofeld::_field_tag_reference:
		ASSERT(field.tag_reference_definition != nullptr);
		tag_reference_definition = &runtime_tag_definitions.enqueue_tag_reference_definition(*field.tag_reference_definition);
		break;
	case blofeld::_field_pageable_resource:
		ASSERT(field.tag_resource_definition != nullptr);
		tag_resource_definition = &runtime_tag_definitions.enqueue_tag_resource_definition(*field.tag_resource_definition);
		break;
	case blofeld::_field_api_interop:
		ASSERT(field.tag_interop_definition != nullptr);
		tag_interop_definition = &runtime_tag_definitions.enqueue_tag_interop_definition(*field.tag_interop_definition);
		break;
	case blofeld::_field_data:
		ASSERT(field.tag_data_definition != nullptr);
		tag_data_definition = &runtime_tag_definitions.enqueue_tag_data_definition(*field.tag_data_definition);
		break;
		//case blofeld::_field_block_index_custom_search:
	case blofeld::_field_char_block_index_custom_search:
	case blofeld::_field_short_block_index_custom_search:
	case blofeld::_field_long_block_index_custom_search:
		ASSERT(field.block_index_custom_search_definition != nullptr);
		block_index_custom_search_definition = &runtime_tag_definitions.enqueue_block_index_custom_search_definition(*field.block_index_custom_search_definition);
		break;
	case blofeld::_field_pad:
	case blofeld::_field_useless_pad:
		ASSERT(field.padding);
		padding = field.padding;
		break;
	case blofeld::_field_skip:
		ASSERT(field.length);
		length = field.length;
		break;
	case blofeld::_field_explanation:
		if (field.explanation)
		{
			explanation = field.explanation;
		}
		break;
	case blofeld::_field_version:
		versioning = field.versioning;
		break;
	}
}
