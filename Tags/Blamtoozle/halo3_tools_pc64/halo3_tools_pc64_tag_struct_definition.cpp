#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo3_tools_pc64_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_memory_attributes& value)
{
	byteswap_inplace(value.memory_type);
	byteswap_inplace(value.usage_flags);
}

template<> void byteswap_inplace(s_halo3_tools_pc64_byte_swap_definition& value)
{
	byteswap_inplace(value.name);
	byteswap_inplace(value.size);
	byteswap_inplace(value.padding0);
	byteswap_inplace(value.codes);
	byteswap_inplace(value.filepath);
	byteswap_inplace(value.line);
	byteswap_inplace(value.signature);
	byteswap_inplace(value.should_byteswap);
	byteswap_inplace(value.padding1);
	byteswap_inplace(value.padding2);
	byteswap_inplace(value.padding3);
	byteswap_inplace(value.padding4);
}

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_struct_runtime& value)
{
	byteswap_inplace(value.original_fields);
	byteswap_inplace(value.byte_swap_definition);
	byteswap_inplace(value.structure_size);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.combined_fields);
	byteswap_inplace(value.cache_file_struct_size);
	byteswap_inplace(value.unknown0);
	byteswap_inplace(value.num_combined_fields);
	byteswap_inplace(value.unknown1);
	byteswap_inplace(value.unique_index);
	byteswap_inplace(value.inlined_field_types);
	byteswap_inplace(value.unknown_field_types);
	byteswap_inplace(value.padding);
	byteswap_inplace(value.descendent_definition);
}

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_struct_legacy& value)
{
	byteswap_inplace(value.legacy_struct_tag);
	byteswap_inplace(value.unknown34);
	byteswap_inplace(value.upgrade_function);
	byteswap_inplace(value.legacy_version);
	byteswap_inplace(value.unknown_struct);
	byteswap_inplace(value.legacy_version_count);
	byteswap_inplace(value.previous_version_struct);
	byteswap_inplace(value.is_legacy_field_set);
}

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_struct_type& value)
{
	byteswap_inplace(value.display_name_address);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.file_path_address);
	byteswap_inplace(value.line_number);
	byteswap_inplace(value.padding);
	byteswap_inplace(value.persistent_identifier);
	byteswap_inplace(value.fields_address);
	byteswap_inplace(value.structure_size);
	byteswap_inplace(value.padding2);
	byteswap_inplace(value.structure_size_string_address);
	byteswap_inplace(value.alignment_bits);
	byteswap_inplace(value.padding3);
	byteswap_inplace(value.legacy);
}

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_struct_definition& value)
{
	byteswap_inplace(value.type);
	byteswap_inplace(value.struct_vtable);
	byteswap_inplace(value.exploded_struct_size);
	byteswap_inplace(value.unknown5C);
	byteswap_inplace(value.memory_attributes);
	byteswap_inplace(value.runtime);
}

c_halo3_tools_pc64_tag_struct_definition::c_halo3_tools_pc64_tag_struct_definition(c_halo3_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr64 _definition_address) :
	c_blamtoozle_tag_struct_definition(_tag_definition_manager),
	definition_address(_definition_address),
	struct_definition(tag_definition_manager.read_structure<s_halo3_tools_pc64_tag_struct_definition>(_definition_address)),
	display_name(tag_definition_manager.va_to_pointer(struct_definition.type.display_name_address)),
	name(tag_definition_manager.va_to_pointer(struct_definition.type.name_address)),
	file_path(tag_definition_manager.va_to_pointer(struct_definition.type.file_path_address)),
	structure_size_string(tag_definition_manager.va_to_pointer(struct_definition.type.structure_size_string_address)),
	code_symbol_name(name),
	code_type_name(),
	traversed_tag_group_definition(*c_halo3_tools_pc64_tag_group_definition::current_group_traverse_hack),
	conflict_handled(false),
	previous_version_struct_definition(),
	next_version_struct_definition()
{
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);

	code_type_name = "s_";
	code_type_name += code_symbol_name;
	tag_definition_manager.format_structure_type_name(code_type_name);

	bool is_runtime_flags_valid = struct_definition.runtime.flags.valid();
	ASSERT(is_runtime_flags_valid);

	ptr64 fields_address = struct_definition.type.fields_address;
	c_halo3_tools_pc64_tag_field* tag_field = nullptr;
	do
	{
		tag_field = new() c_halo3_tools_pc64_tag_field(tag_definition_manager, fields_address);
		fields.push_back(tag_field);
		fields_address += sizeof(s_halo3_tools_pc64_tag_field);
	} while (tag_field->get_field_type() != blofeld::_field_terminator);

	if (struct_definition.type.legacy.previous_version_struct)
	{
		previous_version_struct_definition = &tag_definition_manager.eval_struct(struct_definition.type.legacy.previous_version_struct);
		previous_version_struct_definition->next_version_struct_definition = this;
		debug_point;
	}
}

c_halo3_tools_pc64_tag_struct_definition::~c_halo3_tools_pc64_tag_struct_definition()
{

}

bool c_halo3_tools_pc64_tag_struct_definition::is_legacy_struct()
{
	return previous_version_struct_definition != nullptr || next_version_struct_definition != nullptr;
}

bool c_halo3_tools_pc64_tag_struct_definition::is_latest_structure_version()
{
	return next_version_struct_definition == nullptr;
}

c_blamtoozle_tag_struct_definition* c_halo3_tools_pc64_tag_struct_definition::get_previous_struct_definition()
{
	return previous_version_struct_definition;
}

c_blamtoozle_tag_struct_definition* c_halo3_tools_pc64_tag_struct_definition::get_next_struct_definition()
{
	return next_version_struct_definition;
}

c_blamtoozle_tag_struct_definition& c_halo3_tools_pc64_tag_struct_definition::get_latest_struct_definition()
{
	if (next_version_struct_definition)
	{
		return next_version_struct_definition->get_latest_struct_definition();
	}
	return *this;
}

unsigned long c_halo3_tools_pc64_tag_struct_definition::get_structure_version()
{
	return struct_definition.type.legacy.legacy_version;
}

const char* c_halo3_tools_pc64_tag_struct_definition::get_display_name()
{
	return display_name;
}

const char* c_halo3_tools_pc64_tag_struct_definition::get_name()
{
	return name;
}

const char* c_halo3_tools_pc64_tag_struct_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const char* c_halo3_tools_pc64_tag_struct_definition::get_structure_type_name()
{
	return code_type_name.c_str();
}

unsigned long c_halo3_tools_pc64_tag_struct_definition::get_alignment_bits()
{
	return struct_definition.type.alignment_bits;
}

blofeld::s_tag_persistent_identifier& c_halo3_tools_pc64_tag_struct_definition::get_persistent_identifier()
{
	c_halo3_tools_pc64_tag_struct_definition& latest_struct_definition = static_cast<c_halo3_tools_pc64_tag_struct_definition&>(get_latest_struct_definition());
	return latest_struct_definition.struct_definition.type.persistent_identifier;
}

c_flags<blofeld::e_tag_field_set_bit> c_halo3_tools_pc64_tag_struct_definition::get_field_set_bits()
{
	c_flags<blofeld::e_tag_field_set_bit> result;

	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown0))
	{
		result.set(blofeld::_tag_field_set_unknown0_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown1))
	{
		result.set(blofeld::_tag_field_set_unknown1_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_has_inlined_children_with_placement_new_bit))
	{
		result.set(blofeld::_tag_field_set_has_inlined_children_with_placement_new_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown3))
	{
		result.set(blofeld::_tag_field_set_unknown3_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown4))
	{
		result.set(blofeld::_tag_field_set_unknown4_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_has_aggregate_types))
	{
		result.set(blofeld::_tag_field_set_has_aggregate_types_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_is_temporary_bit))
	{
		result.set(blofeld::_tag_field_set_is_temporary_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown7))
	{
		result.set(blofeld::_tag_field_set_unknown7_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown8))
	{
		result.set(blofeld::_tag_field_set_unknown8_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_delete_recursively_bit))
	{
		result.set(blofeld::_tag_field_set_delete_recursively_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_postprocess_recursively_bit))
	{
		result.set(blofeld::_tag_field_set_postprocess_recursively_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_is_memcpyable_bit))
	{
		result.set(blofeld::_tag_field_set_is_memcpyable_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown12))
	{
		result.set(blofeld::_tag_field_set_unknown12_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_has_resources))
	{
		result.set(blofeld::_tag_field_set_has_resources_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown14))
	{
		result.set(blofeld::_tag_field_set_unknown14_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown15))
	{
		result.set(blofeld::_tag_field_set_unknown15_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_has_level_specific_fields_bit))
	{
		result.set(blofeld::_tag_field_set_has_level_specific_fields_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_can_memset_to_initialize_bit))
	{
		result.set(blofeld::_tag_field_set_can_memset_to_initialize_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_unknown18))
	{
		result.set(blofeld::_tag_field_set_unknown18_bit, true);
	}
	if (struct_definition.runtime.flags.test(_halo3_tools_pc64_tag_field_set_exist_in_cache_build))
	{
		result.set(blofeld::_tag_field_set_exist_in_cache_build_bit, true);
	}

	return result;
}

const char* c_halo3_tools_pc64_tag_struct_definition::get_file_path()
{
	return file_path;
}

long c_halo3_tools_pc64_tag_struct_definition::get_line_number()
{
	return struct_definition.type.line_number;
}
