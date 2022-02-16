#include "tagcodegen-private-pch.h"

bool custom_structure_codegen(
	e_custom_structure_codegen_mode mode,
	std::stringstream& s,
	const char* tabs,
	const c_blamlib_string_parser_v2* field_formatter,
	const blofeld::s_tag_struct_definition& struct_definition,
	const blofeld::s_tag_field& field,
	const char* namespace_name)
{
	if (field.name == nullptr)
	{
		return false;
	}

#define field_index (&field - struct_definition.fields)
#define CODEGEN_HELPER_STRUCT(blofeld_struct_ref) if (&struct_definition == &(blofeld_struct_ref))
#define CODEGEN_HELPER(target_mode, field_name, ...) if (mode == target_mode && strstr(field.name, field_name)) { __VA_ARGS__; return true; }

#define CODEGEN_HELPER_LOW_LEVEL(field_name, type, variable_name) \
	CODEGEN_HELPER(_custom_structure_codegen_low_level_header, field_name, { s << tabs << #type " " #variable_name ";" << std::endl; }) \
	CODEGEN_HELPER(_custom_structure_codegen_low_level_byteswap, field_name, { s << tabs << "byteswap_inplace(value." #variable_name ");" << std::endl; })

#define CODEGEN_HELPER_HIGH_LEVEL(field_name, type, variable_name) \
	CODEGEN_HELPER(_custom_structure_codegen_high_level_header, field_name, { s << tabs << "h_field<" << #type << ", h_" << struct_definition.name << ", " << field_index << "> " #variable_name ";" << std::endl; }) \
	CODEGEN_HELPER(_custom_structure_codegen_high_level_get_field_data_func, field_name, { s << tabs << "case " << field_index << ": return &" #variable_name ";" << std::endl; }) \
	CODEGEN_HELPER(_custom_structure_codegen_high_level_ctor, field_name, { s << tabs << ", " #variable_name "()" << std::endl; }) \
	CODEGEN_HELPER(_custom_structure_codegen_high_level_field_impl, field_name, { s << tabs << "h_field_func_impl(" #type ", blofeld::" << namespace_name << "::h_" << struct_definition.name << ", " << field_index << ", " #variable_name ");" << std::endl; })

	CODEGEN_HELPER_STRUCT(blofeld::cache_file_resource_fixup_location_block_struct_definition)
	{
		CODEGEN_HELPER_LOW_LEVEL("encoded fixup value", c_tag_resource_fixup, fixup);
		CODEGEN_HELPER_HIGH_LEVEL("encoded fixup value", c_tag_resource_fixup, fixup);
	}
	CODEGEN_HELPER_STRUCT(blofeld::cache_file_resource_data_block_struct_definition)
	{
		CODEGEN_HELPER_LOW_LEVEL("root fixup", c_tag_resource_fixup, root_fixup);
		CODEGEN_HELPER_HIGH_LEVEL("root fixup", c_tag_resource_fixup, root_fixup);
	}

#undef CODEGEN_HELPER_STRUCT
#undef CODEGEN_HELPER
#undef CODEGEN_HELPER_LOW_LEVEL
#undef CODEGEN_HELPER_HIGH_LEVEL
#undef field_index
	return false;
}
