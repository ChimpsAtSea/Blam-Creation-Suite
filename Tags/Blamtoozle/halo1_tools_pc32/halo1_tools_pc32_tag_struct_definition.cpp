#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo1_tools_pc32_tag_definition_manager&>(tag_definition_manager)

c_halo1_tools_pc32_tag_struct_definition::c_halo1_tools_pc32_tag_struct_definition(c_halo1_tools_pc32_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_struct_definition(_tag_definition_manager),
	definition_address(_definition_address),
	block_definition(tag_definition_manager.read_structure<s_halo1_tools_pc32_tag_block_definition>(_definition_address)),
	display_name(),
	name(),
	code_symbol_name(name),
	code_type_name(),
	conflict_handled(false)
{
	generate_structure_names();

	tag_definition_manager.format_code_symbol_name_uid(code_type_name);
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);

	ptr32 fields_address = block_definition.fields_address;
	c_halo1_tools_pc32_tag_field* tag_field = nullptr;
	do
	{
		tag_field = new() c_halo1_tools_pc32_tag_field(tag_definition_manager, fields_address);
		fields.push_back(tag_field);

		// array fixup
		if (tag_field->field_definition.field_type == _halo1_tools_pc32_field_array_start)
		{
			c_halo1_tools_pc32_tag_array_definition* array_definition = static_cast<c_halo1_tools_pc32_tag_array_definition*>(tag_field->get_array_definition());
			ASSERT(array_definition != nullptr);
			c_halo1_tools_pc32_tag_struct_definition& struct_definition = static_cast<c_halo1_tools_pc32_tag_struct_definition&>(array_definition->get_struct_definition());

			c_halo1_tools_pc32_tag_field* array_end_field = dynamic_cast<c_halo1_tools_pc32_tag_field*>(struct_definition.fields.back());
			ASSERT(array_end_field != nullptr);
			ASSERT(array_end_field->get_field_type() == blofeld::_field_terminator);

			fields_address = array_end_field->definition_address;
		}

		fields_address += sizeof(s_halo1_tools_pc32_tag_field);
	} while (tag_field->get_field_type() != blofeld::_field_terminator);
}

c_halo1_tools_pc32_tag_struct_definition::~c_halo1_tools_pc32_tag_struct_definition()
{

}

const char* c_halo1_tools_pc32_tag_struct_definition::get_display_name()
{
	return display_name.c_str();
}

const char* c_halo1_tools_pc32_tag_struct_definition::get_name()
{
	return name.c_str();
}

const char* c_halo1_tools_pc32_tag_struct_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const char* c_halo1_tools_pc32_tag_struct_definition::get_structure_type_name()
{
	return code_type_name.c_str();
}

unsigned long c_halo1_tools_pc32_tag_struct_definition::get_alignment_bits()
{
	return 0;
}

blofeld::s_tag_persistent_identifier& c_halo1_tools_pc32_tag_struct_definition::get_persistent_identifier()
{
	static blofeld::s_tag_persistent_identifier id;
	return id;
}

c_flags<blofeld::e_tag_field_set_bit> c_halo1_tools_pc32_tag_struct_definition::get_field_set_bits()
{
	c_flags<blofeld::e_tag_field_set_bit> result;

	// #TODO: populate flags

	c_flags<blofeld::e_tag_field_set_bit> default_flags;
	default_flags.set(blofeld::_tag_field_set_unknown0_bit, true);
	default_flags.set(blofeld::_tag_field_set_unknown1_bit, true);
	default_flags.set(blofeld::_tag_field_set_unknown5_bit, true);
	default_flags.set(blofeld::_tag_field_set_delete_recursively_bit, true);
	default_flags.set(blofeld::_tag_field_set_postprocess_recursively_bit, true);

	return default_flags;
}

void c_halo1_tools_pc32_tag_struct_definition::generate_structure_names()
{
	{
		c_halo1_tools_pc32_tag_block_definition* tag_block_definition = tag_definition_manager.current_block_traverse_hack;
		ASSERT(tag_block_definition != nullptr);

		display_name = tag_block_definition->get_display_name();
		name = tag_block_definition->get_name();
		name += "_struct_definition";
		code_symbol_name = name;
	}

	if (code_type_name.empty())
	{
		const char* source_string = code_symbol_name.c_str();
		size_t buffer_size = 0;
		buffer_size += strlen(source_string) + 1; // maximum string length of source_string
		buffer_size += strlen("s_");
		char* buffer = new(alloca(buffer_size)) char[buffer_size] {};
		strcpy(buffer, source_string);

		cleanup_code_symbol_name(buffer);

		code_type_name = buffer;
	}
}
