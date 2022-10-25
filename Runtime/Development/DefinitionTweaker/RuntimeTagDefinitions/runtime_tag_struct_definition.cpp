#include "definitiontweaker-private-pch.h"

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	pretty_name(),
	name(),
	struct_name(),
	runtime_flags(),
	memory_attributes(),
	persistent_identifier{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX},
	fields(),
	alignment_bits(),
	original_tag_struct_definition(),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_struct_definition const& source) :
	pretty_name(source.pretty_name),
	name(source.name),
	struct_name(source.struct_name),
	runtime_flags(source.runtime_flags),
	memory_attributes(source.memory_attributes),
	persistent_identifier(source.persistent_identifier),
	fields(source.fields),
	alignment_bits(source.alignment_bits),
	original_tag_struct_definition(source.original_tag_struct_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{

}

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_struct_definition& tag_struct_definition) :
	pretty_name(tag_struct_definition.pretty_name),
	name(tag_struct_definition.name),
	struct_name(tag_struct_definition.struct_name),
	runtime_flags(tag_struct_definition.runtime_flags),
	memory_attributes(tag_struct_definition.memory_attributes),
	persistent_identifier(tag_struct_definition.persistent_identifier),
	fields(),
	alignment_bits(tag_struct_definition.alignment_bits),
	original_tag_struct_definition(&tag_struct_definition),
	runtime_tag_definitions(_runtime_tag_definitions)
{
	for (const blofeld::s_tag_field* field = tag_struct_definition.fields; field->field_type != blofeld::_field_terminator; field++)
	{
		fields.push_back(new c_runtime_tag_field(runtime_tag_definitions, *field));
	}
}

c_runtime_tag_struct_definition::~c_runtime_tag_struct_definition()
{
	for (c_runtime_tag_field* field : fields)
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