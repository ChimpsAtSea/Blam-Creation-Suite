#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo2_tools_pc64_tag_definition_manager&>(tag_definition_manager)

c_halo2_tools_pc64_tag_array_struct_definition::c_halo2_tools_pc64_tag_array_struct_definition(c_halo2_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_struct_definition(_tag_definition_manager),
	definition_address(_definition_address),
	display_name("array"),
	name("array"),
	code_symbol_name(name),
	code_type_name(),
	conflict_handled(false)
{
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);

	code_type_name = "s_";
	code_type_name += code_symbol_name;
	tag_definition_manager.format_structure_type_name(code_type_name);

	ptr32 fields_address = _definition_address;
	c_halo2_tools_pc64_tag_field* tag_field = nullptr;
	do
	{
		tag_field = new() c_halo2_tools_pc64_tag_field(tag_definition_manager, fields_address);
		fields.push_back(tag_field);
		fields_address += sizeof(s_halo2_tools_pc64_tag_field);
	} while (tag_field->get_field_type() != blofeld::_field_terminator);
}

c_halo2_tools_pc64_tag_array_struct_definition::~c_halo2_tools_pc64_tag_array_struct_definition()
{

}

const char* c_halo2_tools_pc64_tag_array_struct_definition::get_pretty_name()
{
	return display_name;
}

const char* c_halo2_tools_pc64_tag_array_struct_definition::get_name()
{
	return name;
}

const char* c_halo2_tools_pc64_tag_array_struct_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const char* c_halo2_tools_pc64_tag_array_struct_definition::get_structure_type_name()
{
	return code_type_name.c_str();
}

uint32_t c_halo2_tools_pc64_tag_array_struct_definition::get_alignment_bits()
{
	// #TODO: calculate this
	return 0;
	//return struct_definition.type.alignment_bits;
}

blofeld::s_tag_persistent_identifier& c_halo2_tools_pc64_tag_array_struct_definition::get_persistent_identifier()
{
	static blofeld::s_tag_persistent_identifier id;
	return id;
}

c_flags<blofeld::e_tag_field_set_bit> c_halo2_tools_pc64_tag_array_struct_definition::get_field_set_bits()
{
	c_flags<blofeld::e_tag_field_set_bit> result; // #TODO

	c_flags<blofeld::e_tag_field_set_bit> default_flags;
	default_flags.set(blofeld::_tag_field_set_unknown0_bit, true);
	default_flags.set(blofeld::_tag_field_set_unknown1_bit, true);
	default_flags.set(blofeld::_tag_field_set_has_aggregate_types_bit, true);
	default_flags.set(blofeld::_tag_field_set_delete_recursively_bit, true);
	default_flags.set(blofeld::_tag_field_set_postprocess_recursively_bit, true);

	return default_flags;
}
