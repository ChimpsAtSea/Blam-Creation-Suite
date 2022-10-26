#include "definitiontweaker-private-pch.h"

c_runtime_tag_field_definition::c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_field(_runtime_tag_definitions),
	field_type(),
	name(),
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
	field_id(),
	original_field(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_field_definition::c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_field_definition const& source) :
	c_blamtoozle_tag_field(_runtime_tag_definitions),
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
	field_id(source.field_id),
	original_field(source.original_field),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_field_definition::c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_field& field) :
	c_blamtoozle_tag_field(_runtime_tag_definitions),
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
	field_id(field.id),
	original_field(&field),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	if (field.old_names)
	{
		debug_point;
	}

	switch (field.field_type)
	{
	case blofeld::_field_long_block_flags:
	case blofeld::_field_word_block_flags:
	case blofeld::_field_byte_block_flags:
	case blofeld::_field_char_block_index:
	case blofeld::_field_short_block_index:
	case blofeld::_field_long_block_index:
	case blofeld::_field_block:
		ASSERT(field.block_definition != nullptr);
		block_definition = &runtime_tag_definitions.enqueue_tag_block_definition(*field.block_definition);
		break;
	case blofeld::_field_struct:
		ASSERT(field.struct_definition != nullptr);
		struct_definition = &runtime_tag_definitions.enqueue_tag_struct_definition(*field.struct_definition);
		break;
	case blofeld::_field_array:
		ASSERT(field.array_definition != nullptr);
		array_definition = &runtime_tag_definitions.enqueue_tag_array_definition(*field.array_definition);
		break;
		// case blofeld::_field_string_list:
	case blofeld::_field_char_enum:
	case blofeld::_field_short_enum:
	case blofeld::_field_long_enum:
	case blofeld::_field_long_flags:
	case blofeld::_field_word_flags:
	case blofeld::_field_byte_flags:
		ASSERT(field.string_list_definition != nullptr);
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

	for (const char** old_names_iterator = field.old_names; old_names_iterator && *old_names_iterator; old_names_iterator++)
	{
		const char* old_name = *old_names_iterator;
		if (*old_name)
		{
			old_names.push_back(old_name);
		}
	}
}

std::string const& c_runtime_tag_field_definition::get_raw_name()
{
	return name;
}

std::string const& c_runtime_tag_field_definition::get_name()
{
	return name;
}

std::string const& c_runtime_tag_field_definition::get_description()
{
	return description;
}

std::string const& c_runtime_tag_field_definition::get_units()
{
	return units;
}

std::string const& c_runtime_tag_field_definition::get_limits()
{
	return limits;
}

std::string const& c_runtime_tag_field_definition::get_limits_legacy()
{
	static std::string empty_string;
	return empty_string;
}

std::vector<std::string> const& c_runtime_tag_field_definition::get_old_names()
{
	return old_names;
}

blofeld::f_tag_field_flags c_runtime_tag_field_definition::get_field_flags()
{
	return flags;
}

blofeld::e_field c_runtime_tag_field_definition::get_field_type()
{
	return field_type;
}

uint32_t c_runtime_tag_field_definition::get_padding()
{
	return padding;
}

uint32_t c_runtime_tag_field_definition::get_skip_length()
{
	return length;
}

const char* c_runtime_tag_field_definition::get_explanation()
{
	return explanation.c_str();
}

blofeld::e_field_id c_runtime_tag_field_definition::get_field_id()
{
	return field_id;
}

c_blamtoozle_tag_block_definition* c_runtime_tag_field_definition::get_block_definition()
{
	return block_definition;
}

c_blamtoozle_tag_reference_definition* c_runtime_tag_field_definition::get_tag_reference_definition()
{
	return tag_reference_definition;
}

c_blamtoozle_tag_struct_definition* c_runtime_tag_field_definition::get_struct_definition()
{
	return struct_definition;
}

c_blamtoozle_tag_array_definition* c_runtime_tag_field_definition::get_array_definition()
{
	return array_definition;
}

c_blamtoozle_string_list_definition* c_runtime_tag_field_definition::get_string_list_definition()
{
	return string_list_definition;
}

c_blamtoozle_tag_resource_definition* c_runtime_tag_field_definition::get_tag_resource_definition()
{
	return tag_resource_definition;
}

c_blamtoozle_tag_data_definition* c_runtime_tag_field_definition::get_data_definition()
{
	return tag_data_definition;
}

c_blamtoozle_tag_api_interop_definition* c_runtime_tag_field_definition::get_api_interop_definition()
{
	return tag_interop_definition;
}

c_blamtoozle_tag_block_index_custom_search_definition* c_runtime_tag_field_definition::get_block_index_custom_search_definition()
{
	return block_index_custom_search_definition;
}

blofeld::s_tag_field_versioning const& c_runtime_tag_field_definition::get_tag_field_versioning()
{
	return versioning;
}

void c_runtime_tag_field_definition::restore()
{
	if (const blofeld::s_tag_field* original_field = this->original_field)
	{
		c_runtime_tag_definitions& runtime_tag_definitions = this->runtime_tag_definitions;
		this->~c_runtime_tag_field_definition();
		new(this) c_runtime_tag_field_definition(runtime_tag_definitions, *original_field);
	}
}
