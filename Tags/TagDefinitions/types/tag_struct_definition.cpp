#include "tagdefinitions-private-pch.h"

using namespace blofeld;

s_tag_struct_definition::s_tag_struct_definition(
	const char* pretty_name,
	const char* name,
	const char* struct_name,
	const char* filename,
	long const line,
	s_tag_persistent_identifier persistent_identifier,
	s_tag_field* fields,
	int alignment_bits
)
	: pretty_name(pretty_name)
	, name(name)
	, struct_name(struct_name)
	, filename(filename)
	, line(line)
	, runtime_flags()
	, memory_attributes()
	, persistent_identifier(persistent_identifier)
	, fields(fields)
	, alignment_bits(alignment_bits)
	, symbol()
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);

}

s_tag_struct_definition::s_tag_struct_definition(
	//#ifdef __INTELLISENSE__
	const char* pretty_name,
	const char* name,
	const char* struct_name,
	const char* filename,
	long const line,
	c_flags<e_tag_field_set_bit> runtime_flags,
	c_tag_memory_attributes memory_attributes,
	s_tag_persistent_identifier persistent_identifier,
	s_tag_field* fields,
	int alignment_bits
	//#else
	//const char(&pretty_name)[],
	//const char(&name)[],
	//const char(&struct_name)[],
	//const char(&filename)[],
	//long const line,
	//s_tag_persistent_identifier persistent_identifier,
	//s_tag_field(&fields)[],
	//int alignment_bits = 0
	//#endif
)
	: pretty_name(pretty_name)
	, name(name)
	, struct_name(struct_name)
	, filename(filename)
	, line(line)
	, runtime_flags(runtime_flags)
	, memory_attributes(memory_attributes)
	, persistent_identifier(persistent_identifier)
	, fields(fields)
	, alignment_bits(alignment_bits)
	, symbol()
{
	symbol_manager_get_public_symbol_by_pointer(this, symbol);

}
