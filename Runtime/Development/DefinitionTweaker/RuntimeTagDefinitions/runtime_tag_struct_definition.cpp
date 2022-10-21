#include "definitiontweaker-private-pch.h"

c_runtime_tag_struct_definition::c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions) :
	pretty_name(),
	name(),
	struct_name(),
	runtime_flags(),
	memory_attributes(),
	persistent_identifier(),
	fields(),
	alignment_bits(),
	original_tag_struct_definition(),
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
