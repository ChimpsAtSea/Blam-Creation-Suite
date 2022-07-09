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
	byteswap_inplace(value.legacy_struct_tag2);
	byteswap_inplace(value.unknown8);
	byteswap_inplace(value.legacy_version);
	byteswap_inplace(value.padding0);
	byteswap_inplace(value.unknown40);
	byteswap_inplace(value.unknown1);
	byteswap_inplace(value.unknown2);
	byteswap_inplace(value.legacy_struct);
	byteswap_inplace(value.is_legacy_field_set);
	byteswap_inplace(value.padding4D);
	byteswap_inplace(value.padding4E);
	byteswap_inplace(value.padding4F);
	byteswap_inplace(value.padding3);
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
	conflict_handled(false)
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
}

c_halo3_tools_pc64_tag_struct_definition::~c_halo3_tools_pc64_tag_struct_definition()
{

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
	return struct_definition.type.persistent_identifier;
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

void c_halo3_tools_pc64_tag_struct_definition::handle_conflict(const c_blamtoozle_tag_struct_definition& _conflicting_tag_struct_definition)
{
	const c_halo3_tools_pc64_tag_struct_definition& conflicting_tag_struct_definition = static_cast<const c_halo3_tools_pc64_tag_struct_definition&>(_conflicting_tag_struct_definition);
	ASSERT(conflict_handled == false);
	conflict_handled = true;

	clear_fields(); // clear fields, they will be rebuild

	// push the current definition header onto the back of the queue
	//struct_definitions.insert(struct_definitions.end(), { conflicting_tag_struct_definition, c_halo3_tools_pc64_tag_group_definition::current_group_traverse_hack });

	// make sure that we can compare with the original otherwise all hope is lost
	// and poor squaresome might have to rewrite the tag system again
	ASSERT(struct_definition.runtime.original_fields == conflicting_tag_struct_definition.struct_definition.runtime.original_fields);
	ASSERT(&traversed_tag_group_definition != &conflicting_tag_struct_definition.traversed_tag_group_definition);


	// insert the original fields from the conflicting definition

	t_fields original_fields;
	{
		ptr64 fields_address = struct_definition.type.fields_address;
		c_halo3_tools_pc64_tag_field* tag_field = nullptr;
		do
		{
			tag_field = new() c_halo3_tools_pc64_tag_field(tag_definition_manager, fields_address);
			if (tag_field->get_field_type() == blofeld::_field_terminator) break; // #NOTE: Exclude this terminator as there will be another
			original_fields.push_back(tag_field);
			fields_address += sizeof(s_halo3_tools_pc64_tag_field);
		} while (tag_field->get_field_type() != blofeld::_field_terminator);
	}

	t_fields conflicting_fields;
	{
		ptr64 fields_address = conflicting_tag_struct_definition.struct_definition.type.fields_address;
		c_halo3_tools_pc64_tag_field* tag_field = nullptr;
		do
		{
			tag_field = new() c_halo3_tools_pc64_tag_field(tag_definition_manager, fields_address);
			//if (tag_field->get_field_type() == blofeld::_field_terminator) break;
			conflicting_fields.push_back(tag_field);
			fields_address += sizeof(s_halo3_tools_pc64_tag_field);
		} while (tag_field->get_field_type() != blofeld::_field_terminator);
	}

	unsigned long num_original_fields = static_cast<unsigned long>(original_fields.size());
	fields.push_back(new() c_blamtoozle_tag_field_combined_fixup(traversed_tag_group_definition, num_original_fields, _blamtoozle_tag_field_combined_fixup_type_not_equal));
	fields.insert(fields.end(), original_fields.begin(), original_fields.end());

	fields.push_back(new() c_blamtoozle_tag_field_dummy_space());

	unsigned long num_conflicting_fields = static_cast<unsigned long>(conflicting_fields.size());
	fields.push_back(new() c_blamtoozle_tag_field_combined_fixup(conflicting_tag_struct_definition.traversed_tag_group_definition, num_conflicting_fields, _blamtoozle_tag_field_combined_fixup_type_equal));
	fields.insert(fields.end(), conflicting_fields.begin(), conflicting_fields.end());

	ASSERT(fields.size() > 0);
	c_halo3_tools_pc64_tag_field* last_field = dynamic_cast<c_halo3_tools_pc64_tag_field*>(fields.back());
	ASSERT(last_field != nullptr);
	ASSERT(last_field->field_type == blofeld::_field_terminator);

	
}
