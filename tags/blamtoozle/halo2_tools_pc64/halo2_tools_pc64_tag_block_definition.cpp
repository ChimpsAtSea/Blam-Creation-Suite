#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo2_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo2_tools_pc64_tag_block_definition& value)
{
	byteswap_inplace(value.display_name_address);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.unknown);
	byteswap_inplace(value.max_count);
	byteswap_inplace(value.max_count_string_address);
	byteswap_inplace(value.versioning_structure_definitions_address);
	byteswap_inplace(value.versioning_structure_definitions_count);
	byteswap_inplace(value.structure_definition_address);
}

c_halo2_tools_pc64_tag_block_definition::c_halo2_tools_pc64_tag_block_definition(c_halo2_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_block_definition(_tag_definition_manager),
	definition_address(_definition_address),
	block_definition(tag_definition_manager.read_structure<s_halo2_tools_pc64_tag_block_definition>(_definition_address)),
	struct_definition(),
	display_name(tag_definition_manager.va_to_pointer(block_definition.display_name_address)),
	name(tag_definition_manager.va_to_pointer(block_definition.name_address)),
	code_symbol_name(),
	max_count_string(tag_definition_manager.va_to_pointer(block_definition.max_count_string_address))
{
	c_halo2_tools_pc64_tag_block_definition* previous_current_block_traverse_hack = tag_definition_manager.current_block_traverse_hack;
	tag_definition_manager.current_block_traverse_hack = this;

	struct_definition = &tag_definition_manager.eval_struct(block_definition.structure_definition_address);

	ptr32 versioning_structure_definition_address = block_definition.versioning_structure_definitions_address;


	c_halo2_tools_pc64_tag_struct_definition* previous_version_struct_definition = nullptr;
	for (uint32_t version_structure_index = 0; version_structure_index < block_definition.versioning_structure_definitions_count; version_structure_index++)
	{
		c_halo2_tools_pc64_tag_struct_definition& versioning_struct_definition = tag_definition_manager.eval_struct(versioning_structure_definition_address);
		versioning_struct_definition.structure_version = version_structure_index;
		versioning_struct_definition.previous_version_struct_definition = previous_version_struct_definition;
		versioning_struct_definitions.push_back(&versioning_struct_definition);
		versioning_structure_definition_address += sizeof(s_halo2_tools_pc64_tag_struct_definition);

		if (previous_version_struct_definition != nullptr)
		{
			previous_version_struct_definition->next_version_struct_definition = &versioning_struct_definition;
		}
		previous_version_struct_definition = &versioning_struct_definition;
	}

	make_code_symbol_name();

	tag_definition_manager.current_block_traverse_hack = previous_current_block_traverse_hack;
}

c_halo2_tools_pc64_tag_block_definition::~c_halo2_tools_pc64_tag_block_definition()
{

}

const char* c_halo2_tools_pc64_tag_block_definition::get_pretty_name()
{
	return display_name;
}

const char* c_halo2_tools_pc64_tag_block_definition::get_name()
{
	return name;
}

const char* c_halo2_tools_pc64_tag_block_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

uint32_t c_halo2_tools_pc64_tag_block_definition::get_max_count()
{
	return block_definition.max_count;
}

const char* c_halo2_tools_pc64_tag_block_definition::get_max_count_string()
{
	return max_count_string;
}

c_blamtoozle_tag_struct_definition& c_halo2_tools_pc64_tag_block_definition::get_struct_definition()
{
	ASSERT(struct_definition != nullptr);
	return *struct_definition;
}

void c_halo2_tools_pc64_tag_block_definition::associate_tag_group_definition(c_blamtoozle_tag_group_definition* tag_group_definition)
{
	c_blamtoozle_tag_block_definition::associate_tag_group_definition(tag_group_definition);
	make_code_symbol_name();
}

void c_halo2_tools_pc64_tag_block_definition::make_code_symbol_name()
{
	const char* source_string = name;
	size_t buffer_size = 0;
	buffer_size += strlen(source_string) + 1; // maximum string length of sizeof_string
	buffer_size += strlen("_group_block");
	char* buffer = new(_alloca(buffer_size)) char[buffer_size] {};
	strcpy_s(buffer, buffer_size, source_string);

	if (tag_group_definition != nullptr)
	{
		strcat_s(buffer, buffer_size, "_group_block");
	}
	else
	{
		strcat_s(buffer, buffer_size, "_block");
	}

	replace_trailing_extension(buffer, buffer_size, "_block_group_block", "_group_block");
	replace_trailing_extension(buffer, buffer_size, "_block_block", "_block");

	code_symbol_name = buffer;

	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}
