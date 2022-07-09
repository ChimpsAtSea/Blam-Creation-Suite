#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo2_tools_pc32_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo2_tools_pc32_byte_swap_definition& value)
{
	byteswap_inplace(value.name);
	byteswap_inplace(value.size);
	byteswap_inplace(value.codes);
	byteswap_inplace(value.signature);
	byteswap_inplace(value.should_byteswap);
	byteswap_inplace(value.padding1);
	byteswap_inplace(value.padding2);
	byteswap_inplace(value.padding3);
}

template<> void byteswap_inplace(s_halo2_tools_pc32_tag_struct_runtime& value)
{
	byteswap_inplace(value.byte_swap_definition);
	byteswap_inplace(value.structure_size);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.combined_fields);
	byteswap_inplace(value.cache_file_struct_size);
	byteswap_inplace(value.num_combined_fields);
}

template<> void byteswap_inplace(s_halo2_tools_pc32_tag_struct_type& value)
{
	byteswap_inplace(value.fields_address);
	byteswap_inplace(value.unknown4);
	byteswap_inplace(value.upgrade_procedure);
	byteswap_inplace(value.unknown10);
	byteswap_inplace(value.unknown14);
	byteswap_inplace(value.structure_size);
	byteswap_inplace(value.alignment_bits);
	byteswap_inplace(value.unknown20);
	byteswap_inplace(value.original_fields);
	byteswap_inplace(value.structure_size_string_address);
}

template<> void byteswap_inplace(s_halo2_tools_pc32_tag_struct_definition& value)
{
	byteswap_inplace(value.type);
	byteswap_inplace(value.runtime);
}

template<> void byteswap_inplace(s_halo2_tools_pc32_tag_field_struct_definition& value)
{
	byteswap_inplace(value.name);
	byteswap_inplace(value.signature);
	byteswap_inplace(value.display_name);
	byteswap_inplace(value.block_definition_address);
}

c_halo2_tools_pc32_tag_struct_definition::c_halo2_tools_pc32_tag_struct_definition(c_halo2_tools_pc32_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_struct_definition(_tag_definition_manager),
	definition_address(_definition_address),
	struct_definition(tag_definition_manager.read_structure<s_halo2_tools_pc32_tag_struct_definition>(_definition_address)),
	display_name(),
	name(),
	structure_size_string(tag_definition_manager.va_to_pointer(struct_definition.type.structure_size_string_address)),
	code_symbol_name(name),
	code_type_name(),
	conflict_handled(false)
{
	generate_structure_names();

	tag_definition_manager.format_code_symbol_name_uid(code_type_name);
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);

	bool is_runtime_flags_valid = struct_definition.runtime.flags.valid();
	ASSERT(is_runtime_flags_valid);

	ptr32 fields_address = struct_definition.type.fields_address;
	c_halo2_tools_pc32_tag_field* tag_field = nullptr;
	do
	{
		tag_field = new() c_halo2_tools_pc32_tag_field(tag_definition_manager, fields_address);
		fields.push_back(tag_field);

		// array fixup
		if (tag_field->field_definition.field_type == _halo2_tools_pc32_field_array_start)
		{
			c_halo2_tools_pc32_tag_array_definition* array_definition = static_cast<c_halo2_tools_pc32_tag_array_definition*>(tag_field->get_array_definition());
			ASSERT(array_definition != nullptr);
			c_halo2_tools_pc32_tag_struct_definition& struct_definition = static_cast<c_halo2_tools_pc32_tag_struct_definition&>(array_definition->get_struct_definition());

			c_halo2_tools_pc32_tag_field* array_end_field = dynamic_cast<c_halo2_tools_pc32_tag_field*>(struct_definition.fields.back());
			ASSERT(array_end_field != nullptr);
			ASSERT(array_end_field->get_field_type() == blofeld::_field_terminator);

			fields_address = array_end_field->definition_address;

			
		}

		fields_address += sizeof(s_halo2_tools_pc32_tag_field);
	} while (tag_field->get_field_type() != blofeld::_field_terminator);
}

c_halo2_tools_pc32_tag_struct_definition::~c_halo2_tools_pc32_tag_struct_definition()
{

}

const char* c_halo2_tools_pc32_tag_struct_definition::get_display_name()
{
	return display_name.c_str();
}

const char* c_halo2_tools_pc32_tag_struct_definition::get_name()
{
	return name.c_str();
}

const char* c_halo2_tools_pc32_tag_struct_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const char* c_halo2_tools_pc32_tag_struct_definition::get_structure_type_name()
{
	return code_type_name.c_str();
}

unsigned long c_halo2_tools_pc32_tag_struct_definition::get_alignment_bits()
{
	return struct_definition.type.alignment_bits;
}

blofeld::s_tag_persistent_identifier& c_halo2_tools_pc32_tag_struct_definition::get_persistent_identifier()
{
	static blofeld::s_tag_persistent_identifier id;
	return id;
}

c_flags<blofeld::e_tag_field_set_bit> c_halo2_tools_pc32_tag_struct_definition::get_field_set_bits()
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

void c_halo2_tools_pc32_tag_struct_definition::generate_structure_names()
{
	if (const char* byteswap_name = tag_definition_manager.va_to_pointer(struct_definition.runtime.byte_swap_definition.name))
	{
		char* byteswap0 = strdup(byteswap_name);

		nuke_trailing_extension(byteswap0, "_byte_swap_definition");
		nuke_trailing_extension(byteswap0, "_fields");
		if (strstr(byteswap0, "_fields_v"))
		{
			for (char version_index = 0; version_index < 10; version_index++)
			{
				char extension[] = "_fields_v0";
				extension[_countof(extension) - 2] += version_index;
				char replacement[] = "_v0";
				replacement[_countof(replacement) - 2] += version_index;
				replace_trailing_extension(byteswap0, extension, replacement);
			}
		}

		display_name = byteswap0;
		name = byteswap0;
		name += "_struct_definition";
		code_symbol_name = name;

		untracked_free(byteswap0);
	}
	else
	{
		c_halo2_tools_pc32_tag_block_definition* tag_block_definition = tag_definition_manager.current_block_traverse_hack;
		ASSERT(tag_block_definition != nullptr);

		display_name = tag_block_definition->get_display_name();
		name = tag_block_definition->get_name();
		name += "_struct_definition";
		code_symbol_name = name;
	}


	if (const char* sizeof_string = tag_definition_manager.va_to_pointer(struct_definition.type.structure_size_string_address))
	{
		size_t buffer_size = 0;
		buffer_size += strlen(sizeof_string) + 1; // maximum string length of sizeof_string
		buffer_size += strlen("s_");
		char* buffer = new(alloca(buffer_size)) char[buffer_size] {};

		int elements_found;
		if (strstr(sizeof_string, "struct "))
		{
			elements_found = sscanf(sizeof_string, "sizeof(struct %[^)])", buffer);
		}
		else
		{
			elements_found = sscanf(sizeof_string, "sizeof(%[^)])", buffer);
		}
		if (elements_found > 0)
		{
			cleanup_code_symbol_name(buffer);

			code_type_name = buffer;
		}
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
