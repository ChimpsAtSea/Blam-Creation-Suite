#include "runtimedefinitions-private-pch.h"

c_runtime_tag_field_definition::c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_field(_runtime_tag_definitions),
	original_field(),
	original_tag_persist_field(nullptr),
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
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_field_definition::c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_field_definition const& source) :
	c_blamtoozle_tag_field(_runtime_tag_definitions),
	original_field(source.original_field),
	original_tag_persist_field(nullptr),
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
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_field_definition::c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions, s_engine_platform_build engine_platform_build, blofeld::s_tag_field const& field) :
	c_blamtoozle_tag_field(_runtime_tag_definitions),
	original_field(&field),
	original_tag_persist_field(nullptr),
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
	field_id(field._field_id),
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
		if (field.block_definition != nullptr)
		{
			block_definition = &runtime_tag_definitions.enqueue_tag_block_definition(engine_platform_build, *field.block_definition);
		}
		break;
	case blofeld::_field_struct:
		if (field.struct_definition != nullptr)
		{
			struct_definition = &runtime_tag_definitions.enqueue_tag_struct_definition(engine_platform_build, *field.struct_definition);
		}
		break;
	case blofeld::_field_array:
		if (field.array_definition != nullptr)
		{
			array_definition = &runtime_tag_definitions.enqueue_tag_array_definition(engine_platform_build, *field.array_definition);
		}
		break;
	case blofeld::_field_char_enum:
	case blofeld::_field_short_enum:
	case blofeld::_field_long_enum:
	case blofeld::_field_long_flags:
	case blofeld::_field_word_flags:
	case blofeld::_field_byte_flags:
		if (field.string_list_definition != nullptr)
		{
			string_list_definition = &runtime_tag_definitions.enqueue_string_list_definition(engine_platform_build, *field.string_list_definition);
		}
		break;
	case blofeld::_field_tag_reference:
		if (field.tag_reference_definition != nullptr)
		{
			tag_reference_definition = &runtime_tag_definitions.enqueue_tag_reference_definition(engine_platform_build, *field.tag_reference_definition);
		}
		break;
	case blofeld::_field_pageable_resource:
		if (field.tag_resource_definition != nullptr)
		{
			tag_resource_definition = &runtime_tag_definitions.enqueue_tag_resource_definition(engine_platform_build, *field.tag_resource_definition);
		}
		break;
	case blofeld::_field_api_interop:
		if (field.tag_interop_definition != nullptr)
		{
			tag_interop_definition = &runtime_tag_definitions.enqueue_tag_api_interop_definition(engine_platform_build, *field.tag_interop_definition);
		}
		break;
	case blofeld::_field_data:
		if (field.tag_data_definition != nullptr)
		{
			tag_data_definition = &runtime_tag_definitions.enqueue_tag_data_definition(engine_platform_build, *field.tag_data_definition);
		}
		break;
	case blofeld::_field_char_block_index_custom_search:
	case blofeld::_field_short_block_index_custom_search:
	case blofeld::_field_long_block_index_custom_search:
		if (field.block_index_custom_search_definition != nullptr)
		{
			block_index_custom_search_definition = &runtime_tag_definitions.enqueue_block_index_custom_search_definition(engine_platform_build, *field.block_index_custom_search_definition);
		}
		break;
	case blofeld::_field_pad:
	case blofeld::_field_useless_pad:
		if (field.padding)
		{
			padding = field.padding;
		}
		break;
	case blofeld::_field_skip:
		if (field.length)
		{
			length = field.length;
		}
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

c_runtime_tag_field_definition::c_runtime_tag_field_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_field const& tag_persist_field) :
	c_blamtoozle_tag_field(_runtime_tag_definitions),
	original_field(nullptr),
	original_tag_persist_field(&tag_persist_field),
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
	runtime_tag_definitions(_runtime_tag_definitions)
{
	name = tag_file_reader.get_string_by_string_character_index(tag_persist_field.string_character_index);
	field_type = tag_file_reader.get_blofeld_type_by_field_type_index(tag_persist_field.field_type_index);

	switch (field_type)
	{
	case blofeld::_field_long_block_flags:
	case blofeld::_field_word_block_flags:
	case blofeld::_field_byte_block_flags:
	case blofeld::_field_char_block_index:
	case blofeld::_field_short_block_index:
	case blofeld::_field_long_block_index:
	case blofeld::_field_block:
		if (tag_persist_field.metadata < tag_file_reader.block_definition_by_index_count)
		{
			s_tag_persist_block_definition& tag_persist_block_definition = tag_file_reader.get_block_definition_by_index(tag_persist_field.metadata);
			block_definition = &runtime_tag_definitions.enqueue_tag_block_definition(tag_file_reader, tag_persist_block_definition);
		}
		break;
	case blofeld::_field_struct:
		if (tag_persist_field.metadata < tag_file_reader.struct_definition_by_index_count)
		{
			s_tag_persist_struct_definition& tag_persist_struct_definition = tag_file_reader.get_struct_definition_by_index(tag_persist_field.metadata);
			struct_definition = &runtime_tag_definitions.enqueue_tag_struct_definition(tag_file_reader, tag_persist_struct_definition);
		}
		break;
	case blofeld::_field_array:
		if (tag_persist_field.metadata < tag_file_reader.array_definition_by_index_count)
		{
			s_tag_persist_array_definition& tag_persist_array_definition = tag_file_reader.get_array_definition_by_index(tag_persist_field.metadata);
			array_definition = &runtime_tag_definitions.enqueue_tag_array_definition(tag_file_reader, tag_persist_array_definition);
		}
		break;
	case blofeld::_field_char_enum:
	case blofeld::_field_short_enum:
	case blofeld::_field_long_enum:
	case blofeld::_field_long_flags:
	case blofeld::_field_word_flags:
	case blofeld::_field_byte_flags:
		if (tag_persist_field.metadata < tag_file_reader.string_list_by_index_count)
		{
			s_tag_persist_string_list& tag_persist_string_list = tag_file_reader.get_string_list_by_index(tag_persist_field.metadata);
			string_list_definition = &runtime_tag_definitions.enqueue_string_list_definition(tag_file_reader, tag_persist_string_list);
		}
		break;
	case blofeld::_field_tag_reference:
		tag_reference_definition = &runtime_tag_definitions.enqueue_tag_reference_definition(tag_file_reader);
		break;
	case blofeld::_field_pageable_resource:
		if (tag_persist_field.metadata < tag_file_reader.resource_definition_by_index_count)
		{
			s_tag_persist_resource_definition& tag_persist_resource_definition = tag_file_reader.get_resource_definition_by_index(tag_persist_field.metadata);
			tag_resource_definition = &runtime_tag_definitions.enqueue_tag_resource_definition(tag_file_reader, tag_persist_resource_definition);
		}
		break;
	case blofeld::_field_api_interop:
		if (tag_persist_field.metadata < tag_file_reader.interop_definition_by_index_count)
		{
			s_tag_persist_interop_definition& tag_persist_interop_definition = tag_file_reader.get_interop_definition_by_index(tag_persist_field.metadata);
			tag_interop_definition = &runtime_tag_definitions.enqueue_tag_api_interop_definition(tag_file_reader, tag_persist_interop_definition);
		}
		break;
	case blofeld::_field_data:
		if (tag_persist_field.metadata < tag_file_reader.data_definition_by_index_count)
		{
			s_tag_persist_string_character_index& tag_persist_string_character_index = tag_file_reader.get_data_definition_by_index(tag_persist_field.metadata);
			tag_data_definition = &runtime_tag_definitions.enqueue_tag_data_definition(tag_file_reader, tag_persist_string_character_index);
		}
		break;
	case blofeld::_field_char_block_index_custom_search:
	case blofeld::_field_short_block_index_custom_search:
	case blofeld::_field_long_block_index_custom_search:
		if (tag_persist_field.metadata < tag_file_reader.custom_block_index_search_name_by_index_count)
		{
			s_tag_persist_string_character_index& tag_persist_string_character_index = tag_file_reader.get_custom_block_index_search_by_index(tag_persist_field.metadata);
			block_index_custom_search_definition = &runtime_tag_definitions.enqueue_block_index_custom_search_definition(tag_file_reader, tag_persist_string_character_index);
		}
		break;
	case blofeld::_field_pad:
	case blofeld::_field_useless_pad:
		ASSERT(tag_persist_field.metadata);
		padding = tag_persist_field.metadata;
		break;
	case blofeld::_field_skip:
		ASSERT(tag_persist_field.metadata);
		length = tag_persist_field.metadata;
		break;
	}
}

c_runtime_tag_field_definition::~c_runtime_tag_field_definition()
{

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

bool c_runtime_tag_field_definition::get_tag_field_attributed_definition(blofeld::e_tag_field_attributed_definition& out_tag_field_attributed_definition)
{
	blofeld::e_tag_field_attributed_definition tag_field_attributed_definition = static_cast<blofeld::e_tag_field_attributed_definition>(field_id);
	if (const char* tag_field_attributed_definition_string = blofeld::tag_field_attributed_definition_to_string(tag_field_attributed_definition))
	{
		out_tag_field_attributed_definition = tag_field_attributed_definition;
		return true;
	}
	return false;
}

bool c_runtime_tag_field_definition::get_tag_field_custom_type(blofeld::e_tag_field_custom_type& out_tag_field_custom_type)
{
	blofeld::e_tag_field_custom_type tag_field_custom_type = static_cast<blofeld::e_tag_field_custom_type>(field_id);
	if (const char* tag_field_custom_type_string = blofeld::tag_field_custom_type_to_string(tag_field_custom_type))
	{
		out_tag_field_custom_type = tag_field_custom_type;
		return true;
	}
	return false;
}

bool c_runtime_tag_field_definition::get_tag_field_id(blofeld::e_field_id& out_field_id)
{
	blofeld::e_field_id tag_field_id = static_cast<blofeld::e_field_id>(field_id);
	if (const char* tag_field_id_string = blofeld::field_id_to_string(tag_field_id))
	{
		out_field_id = tag_field_id;
		return true;
	}
	return false;
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

void c_runtime_tag_field_definition::restore(s_engine_platform_build engine_platform_build)
{
	if (blofeld::s_tag_field const* original_field = this->original_field)
	{
		c_runtime_tag_definitions& runtime_tag_definitions = this->runtime_tag_definitions;
		this->~c_runtime_tag_field_definition();
		new(this) c_runtime_tag_field_definition(runtime_tag_definitions, engine_platform_build, *original_field);
	}
}
