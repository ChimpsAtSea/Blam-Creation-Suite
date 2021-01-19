#include "tagdefinitions-private-pch.h"

blofeld::s_tag_struct_definition::s_tag_struct_definition(
	const char* pretty_name,
	const char* name,
	const char* struct_name,
	const char* filename,
//#ifdef __INTELLISENSE__
//	const char* pretty_name,
//	const char* name,
//	const char* struct_name,
//	const char* filename,
//#else
//	const char(&pretty_name)[],
//	const char(&name)[],
//	const char(&struct_name)[],
//	const char(&filename)[],
//#endif
	int32_t const line,
	s_tag_persistent_identifier persistent_identifier,
#ifndef __INTELLISENSE2__
	s_tag_field* fields,
#else
	s_tag_field(&fields)[],
#endif
	int alignment_bits
)
	: pretty_name(pretty_name)
	, name(name)
	, struct_name(struct_name)
	, filename(filename)
	, line(line)
	, persistent_identifier(persistent_identifier)
	, fields(fields)
	, alignment_bits(alignment_bits)
	, symbol(c_runtime_symbols::runtime().get_public_symbol_by_virtual_address(this))
{

}