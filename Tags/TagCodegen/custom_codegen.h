#pragma once

enum e_custom_structure_codegen_mode
{
	_custom_structure_codegen_low_level_header,
	_custom_structure_codegen_low_level_byteswap,
	_custom_structure_codegen_high_level_header,
	_custom_structure_codegen_high_level_get_field_data_func,
	_custom_structure_codegen_high_level_ctor,
	_custom_structure_codegen_high_level_field_impl,
};

bool custom_structure_codegen(
	e_custom_structure_codegen_mode mode, 
	std::stringstream& s, 
	const char* tabs, 
	const c_blamlib_string_parser_v2* field_formatter,
	const blofeld::s_tag_struct_definition& struct_definition, 
	const blofeld::s_tag_field& field,
	const char* root_namespace);

