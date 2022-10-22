#include "definitiontweaker-private-pch.h"

c_tag_struct_serialization_context::c_tag_struct_serialization_context(
	c_tag_serialization_context& _serialization_context,
	const blofeld::s_tag_struct_definition& _struct_definition,
	unsigned int _expected_struct_size) :
	serialization_context(_serialization_context),
	expected_struct_size(_expected_struct_size),
	struct_size(),
	struct_definition(_struct_definition),
	field_serialization_contexts(),
	serialization_errors()
{

}

c_tag_struct_serialization_context::~c_tag_struct_serialization_context()
{
	for (auto field_serialization_context : field_serialization_contexts)
	{
		delete field_serialization_context;
	}

	for (auto seralization_error : serialization_errors)
	{
		delete seralization_error;
	}
}

unsigned int c_tag_struct_serialization_context::read()
{
	unsigned int num_errors = 0;

	debug_point;

	return num_errors;
}

unsigned int c_tag_struct_serialization_context::traverse()
{
	unsigned int num_errors = 0;

	debug_point;

	return num_errors;
}
