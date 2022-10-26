#include "definitiontweaker-private-pch.h"

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	c_blamtoozle_tag_struct_definition(_runtime_tag_definitions),
	original_tag_struct_definition(),
	pretty_name(),
	name(),
	type_name(),
	symbol_name(),
	runtime_flags(),
	memory_attributes(),
	persistent_identifier{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX},
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

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_struct_definition& tag_struct_definition) :
	c_blamtoozle_tag_struct_definition(_runtime_tag_definitions),
	original_tag_struct_definition(&tag_struct_definition),
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
	for (const blofeld::s_tag_field* field = tag_struct_definition.fields; ; field++)
	{
		c_runtime_tag_field_definition& field_definition = runtime_tag_definitions.enqueue_tag_field_definition(*field);
		fields.push_back(&field_definition);
		if (field->field_type == blofeld::_field_terminator)
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

void c_runtime_tag_struct_definition::restore()
{
	if (const blofeld::s_tag_struct_definition* original_tag_struct_definition = this->original_tag_struct_definition)
	{
		c_runtime_tag_definitions& runtime_tag_definitions = this->runtime_tag_definitions;
		this->~c_runtime_tag_struct_definition();
		new(this) c_runtime_tag_struct_definition(runtime_tag_definitions, *original_tag_struct_definition);
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
