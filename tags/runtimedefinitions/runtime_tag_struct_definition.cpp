#include "runtimedefinitions-private-pch.h"

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_struct_definition(_runtime_tag_definitions),
	original_tag_struct_definition(nullptr),
	original_tag_persist_struct_definition(nullptr),
	pretty_name(),
	name(),
	type_name(),
	symbol_name(),
	runtime_flags(),
	memory_attributes(),
	persistent_identifier{ UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX },
	alignment_bits(),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	c_runtime_tag_field_definition& terminator_field_definition = runtime_tag_definitions.create_tag_field_definition();
	terminator_field_definition.field_type = blofeld::_field_terminator;
	fields.push_back(&terminator_field_definition);
}

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_struct_definition const& source) :
	c_blamtoozle_tag_struct_definition(_runtime_tag_definitions),
	original_tag_struct_definition(source.original_tag_struct_definition),
	original_tag_persist_struct_definition(source.original_tag_persist_struct_definition),
	pretty_name(source.pretty_name),
	name(source.name),
	type_name(source.type_name),
	symbol_name(source.symbol_name),
	runtime_flags(source.runtime_flags),
	memory_attributes(source.memory_attributes),
	persistent_identifier(source.persistent_identifier),
	alignment_bits(source.alignment_bits),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	for (t_blamtoozle_tag_field* tag_field : source.fields)
	{
		if (c_runtime_tag_field_definition* runtime_tag_field = dynamic_cast<c_runtime_tag_field_definition*>(tag_field))
		{
			c_runtime_tag_field_definition& tag_field_copy = _runtime_tag_definitions.duplicate_tag_field_definition(*runtime_tag_field);
			fields.push_back(&tag_field_copy);
		}
	}
}

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, s_engine_platform_build engine_platform_build, blofeld::s_tag_struct_definition const& tag_struct_definition) :
	c_blamtoozle_tag_struct_definition(_runtime_tag_definitions),
	original_tag_struct_definition(&tag_struct_definition),
	original_tag_persist_struct_definition(nullptr),
	pretty_name(tag_struct_definition.pretty_name),
	name(tag_struct_definition.name),
	type_name(tag_struct_definition.type_name),
	symbol_name(tag_struct_definition.symbol_name),
	runtime_flags(tag_struct_definition.runtime_flags),
	memory_attributes(tag_struct_definition.memory_attributes),
	persistent_identifier(tag_struct_definition.persistent_identifier),
	alignment_bits(tag_struct_definition.alignment_bits),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	for (blofeld::s_tag_field const* field = tag_struct_definition.fields; ; field++)
	{
		c_runtime_tag_field_definition& field_definition = runtime_tag_definitions.enqueue_tag_field_definition(engine_platform_build, *field);
		fields.push_back(&field_definition);
		if (field->field_type == blofeld::_field_terminator)
		{
			break;
		}
	}
}

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_struct_definition const& persist_struct_definition) :
	c_blamtoozle_tag_struct_definition(_runtime_tag_definitions),
	original_tag_struct_definition(nullptr),
	original_tag_persist_struct_definition(&persist_struct_definition),
	pretty_name(),
	name(),
	type_name(),
	symbol_name(),
	runtime_flags(),
	memory_attributes(),
	persistent_identifier{ UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX },
	alignment_bits(),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	persistent_identifier.identifier_part_0 = persist_struct_definition.unique_identifier.identifier_part_0;
	persistent_identifier.identifier_part_1 = persist_struct_definition.unique_identifier.identifier_part_1;
	persistent_identifier.identifier_part_2 = persist_struct_definition.unique_identifier.identifier_part_2;
	persistent_identifier.identifier_part_3 = persist_struct_definition.unique_identifier.identifier_part_3;

	const char* struct_name = tag_file_reader.get_string_by_string_character_index(persist_struct_definition.string_character_index);
	pretty_name = struct_name;
	name = struct_name;
	type_name = struct_name;
	symbol_name = struct_name;

	_runtime_tag_definitions.format_code_symbol_name(type_name);
	_runtime_tag_definitions.format_code_symbol_name(symbol_name);

	for (unsigned long field_index = persist_struct_definition.fields_start_index;; field_index++)
	{
		s_tag_persist_field& tag_persist_field = tag_file_reader.get_field_by_index(field_index);
		c_runtime_tag_field_definition& field_definition = _runtime_tag_definitions.enqueue_tag_field_definition(tag_file_reader, tag_persist_field);
		fields.push_back(&field_definition);
		if (field_definition.field_type == blofeld::_field_terminator)
		{
			break;
		}
	}
}

c_runtime_tag_struct_definition::~c_runtime_tag_struct_definition()
{
	for (t_blamtoozle_tag_field* field : fields)
	{
		delete field;
	}
	fields.clear();
}

void c_runtime_tag_struct_definition::restore(s_engine_platform_build engine_platform_build)
{
	if (const blofeld::s_tag_struct_definition* original_tag_struct_definition = this->original_tag_struct_definition)
	{
		c_runtime_tag_definitions& runtime_tag_definitions = this->runtime_tag_definitions;
		this->~c_runtime_tag_struct_definition();
		new(this) c_runtime_tag_struct_definition(runtime_tag_definitions, engine_platform_build, *original_tag_struct_definition);
	}
}

const char* c_runtime_tag_struct_definition::get_pretty_name()
{
	return pretty_name.c_str();
}

const char* c_runtime_tag_struct_definition::get_name()
{
	return name.c_str();
}

const char* c_runtime_tag_struct_definition::get_code_symbol_name()
{
	return symbol_name.c_str();
}

const char* c_runtime_tag_struct_definition::get_structure_type_name()
{
	return type_name.c_str();
}

uint32_t c_runtime_tag_struct_definition::get_alignment_bits()
{
	return alignment_bits;
}

const char* c_runtime_tag_struct_definition::get_file_path()
{
	if (original_tag_struct_definition)
	{
		return original_tag_struct_definition->filename;
	}
	return c_blamtoozle_tag_struct_definition::get_file_path();
}

int32_t c_runtime_tag_struct_definition::get_line_number()
{
	if (original_tag_struct_definition)
	{
		return original_tag_struct_definition->line;
	}
	return c_blamtoozle_tag_struct_definition::get_line_number();
}

blofeld::s_tag_persistent_identifier& c_runtime_tag_struct_definition::get_persistent_identifier()
{
	return persistent_identifier;
}

c_flags<blofeld::e_tag_field_set_bit> c_runtime_tag_struct_definition::get_field_set_bits()
{
	return runtime_flags;
}
