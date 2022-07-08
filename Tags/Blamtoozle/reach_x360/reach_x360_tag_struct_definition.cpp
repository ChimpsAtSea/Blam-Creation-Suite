#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_reach_x360_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_reach_tag_memory_attributes& value)
{
	byteswap_inplace(value.memory_type);
	byteswap_inplace(value.usage_flags);
}

template<> void byteswap_inplace(s_reach_x360_byte_swap_definition& value)
{
	byteswap_inplace(value.name);
	byteswap_inplace(value.size);
	byteswap_inplace(value.byte_swap_traits);
	byteswap_inplace(value.file_path);
	byteswap_inplace(value.line);
	byteswap_inplace(value.signature);
	byteswap_inplace(value.unknown14);
}

template<> void byteswap_inplace(s_reach_x360_tag_struct_runtime& value)
{
	byteswap_inplace(value.original_fields);
	byteswap_inplace(value.byte_swap_definition);
	byteswap_inplace(value.structure_size);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.combined_fields);
	byteswap_inplace(value.cache_file_struct_size);
	byteswap_inplace(value.unknown98);
	byteswap_inplace(value.num_combined_fields);
	byteswap_inplace(value.unknownA0);
	byteswap_inplace(value.unique_index);
	byteswap_inplace(value.inlined_field_types);
	byteswap_inplace(value.unknown_field_types);
	byteswap_inplace(value.descendent_definition);
}

template<> void byteswap_inplace(s_reach_x360_tag_struct_legacy& value)
{
	byteswap_inplace(value.legacy_struct_tag);
	byteswap_inplace(value.unknown34);
	byteswap_inplace(value.unknown37);
	byteswap_inplace(value.legacy_version);
	byteswap_inplace(value.unknown40);
	byteswap_inplace(value.unknown44);
	byteswap_inplace(value.legacy_struct);
	byteswap_inplace(value.is_legacy_field_set);
	byteswap_inplace(value.padding4D);
	byteswap_inplace(value.padding4E);
	byteswap_inplace(value.padding4F);
}

template<> void byteswap_inplace(s_reach_x360_tag_struct_type& value)
{
	byteswap_inplace(value.display_name_address);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.file_path_address);
	byteswap_inplace(value.line_number);
	byteswap_inplace(value.persistent_identifier);
	byteswap_inplace(value.fields_address);
	byteswap_inplace(value.structure_size);
	byteswap_inplace(value.structure_size_string_address);
	byteswap_inplace(value.alignment_bits);
	byteswap_inplace(value.legacy);
}

template<> void byteswap_inplace(s_reach_x360_tag_struct_definition& value)
{
	byteswap_inplace(value.type);
	byteswap_inplace(value.struct_vtable);
	byteswap_inplace(value.unknown54);
	byteswap_inplace(value.exploded_struct_size);
	byteswap_inplace(value.unknown5C);
	byteswap_inplace(value.memory_attributes);
	byteswap_inplace(value.runtime);
	byteswap_inplace(value.unknownBC);
}

c_reach_x360_tag_struct_definition::c_reach_x360_tag_struct_definition(c_reach_x360_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_tag_struct_definition(_tag_definition_manager),
	definition_address(_definition_address),
	struct_definition(tag_definition_manager.read_structure<s_reach_x360_tag_struct_definition>(_definition_address)),
	display_name(tag_definition_manager.va_to_pointer(struct_definition.type.display_name_address)),
	name(tag_definition_manager.va_to_pointer(struct_definition.type.name_address)),
	file_path(tag_definition_manager.va_to_pointer(struct_definition.type.file_path_address)),
	structure_size_string(tag_definition_manager.va_to_pointer(struct_definition.type.structure_size_string_address)),
	code_symbol_name(name),
	code_type_name(),
	traversed_tag_group_definition(*c_reach_x360_tag_group_definition::current_group_traverse_hack)
{
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);

	bool is_runtime_flags_valid = struct_definition.runtime.flags.valid();
	ASSERT(is_runtime_flags_valid);

	ptr32 fields_address = struct_definition.type.fields_address;
	c_reach_x360_tag_field* tag_field = nullptr;
	do
	{
		tag_field = new() c_reach_x360_tag_field(tag_definition_manager, fields_address);
		fields.push_back(tag_field);
		fields_address += sizeof(s_reach_x360_tag_field);
	} while (tag_field->get_field_type() != blofeld::_field_terminator);
}

c_reach_x360_tag_struct_definition::~c_reach_x360_tag_struct_definition()
{

}

const char* c_reach_x360_tag_struct_definition::get_display_name()
{
	return display_name;
}

const char* c_reach_x360_tag_struct_definition::get_name()
{
	return name;
}

const char* c_reach_x360_tag_struct_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const char* c_reach_x360_tag_struct_definition::get_code_type_name()
{
	return code_type_name.c_str();
}

unsigned long c_reach_x360_tag_struct_definition::get_structure_size()
{
	return struct_definition.type.structure_size;
}

const char* c_reach_x360_tag_struct_definition::get_structure_size_string()
{
	return structure_size_string;
}

unsigned long c_reach_x360_tag_struct_definition::get_alignment_bits()
{
	return struct_definition.type.alignment_bits;
}

const char* c_reach_x360_tag_struct_definition::get_file_path()
{
	return file_path;
}

long c_reach_x360_tag_struct_definition::get_line_number()
{
	return struct_definition.type.line_number;
}

blofeld::s_tag_persistent_identifier& c_reach_x360_tag_struct_definition::get_persistent_identifier()
{
	return struct_definition.type.persistent_identifier;
}
c_flags<blofeld::e_tag_field_set_bit> c_reach_x360_tag_struct_definition::get_field_set_bits()
{
	c_flags<blofeld::e_tag_field_set_bit> result;

	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown0))
	{
		result.set(blofeld::_tag_field_set_unknown0_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown1))
	{
		result.set(blofeld::_tag_field_set_unknown1_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_has_inlined_children_with_placement_new_bit))
	{
		result.set(blofeld::_tag_field_set_has_inlined_children_with_placement_new_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown3))
	{
		result.set(blofeld::_tag_field_set_unknown3_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown4))
	{
		result.set(blofeld::_tag_field_set_unknown4_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown5))
	{
		result.set(blofeld::_tag_field_set_unknown5_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_is_temporary_bit))
	{
		result.set(blofeld::_tag_field_set_is_temporary_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown7))
	{
		result.set(blofeld::_tag_field_set_unknown7_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown8))
	{
		result.set(blofeld::_tag_field_set_unknown8_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_delete_recursively_bit))
	{
		result.set(blofeld::_tag_field_set_delete_recursively_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_postprocess_recursively_bit))
	{
		result.set(blofeld::_tag_field_set_postprocess_recursively_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_is_memcpyable_bit))
	{
		result.set(blofeld::_tag_field_set_is_memcpyable_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown12))
	{
		result.set(blofeld::_tag_field_set_unknown12_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_has_resources))
	{
		result.set(blofeld::_tag_field_set_has_resources_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown14))
	{
		result.set(blofeld::_tag_field_set_unknown14_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown15))
	{
		result.set(blofeld::_tag_field_set_unknown15_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_has_level_specific_fields_bit))
	{
		result.set(blofeld::_tag_field_set_has_level_specific_fields_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_can_memset_to_initialize_bit))
	{
		result.set(blofeld::_tag_field_set_can_memset_to_initialize_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown18))
	{
		result.set(blofeld::_tag_field_set_unknown18_bit, true);
	}
	if (struct_definition.runtime.flags.test(_reach_tag_field_set_unknown19))
	{
		result.set(blofeld::_tag_field_set_unknown19_bit, true);
	}

	return result;
}
//
//void c_reach_x360_tag_struct_definition::handle_conflict(const char* data, const s_reach_x360_tag_struct_definition& conflicting_tag_struct_definition)
//{
//	clear_fields(); // clear fields, they will be rebuild
//
//	// push the current definition header onto the back of the queue
//	struct_definitions.insert(struct_definitions.end(), { conflicting_tag_struct_definition, c_reach_x360_tag_group_definition::current_group_traverse_hack });
//
//	// make sure that we can compare with the original otherwise all hope is lost
//	// and poor squaresome might have to rewrite the tag system again
//	ASSERT(struct_definitions.front().first.runtime.original_fields == conflicting_tag_struct_definition.runtime.original_fields);
//	ASSERT(struct_definitions.front().second != c_reach_x360_tag_group_definition::current_group_traverse_hack);
//
//	// insert the original fields
//	{
//		ptr32 fields_address = conflicting_tag_struct_definition.runtime.original_fields;
//		const s_reach_x360_tag_field* const field_definitions = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, fields_address);
//		const s_reach_x360_tag_field* field_definition = field_definitions;
//		ASSERT(field_definition);
//		do
//		{
//			c_reach_x360_tag_field* field_wrapper = new() c_reach_x360_tag_field(data, *field_definition);
//			fields.push_back(field_wrapper);
//		} while ((field_definition++)->field_type != _reach_x360_field_type_terminator);
//	}
//	unsigned long num_original_fields = static_cast<unsigned long>(fields.size());
//
//
//
//	// insert bespoke field fixups
//	for (auto& kv : struct_definitions)
//	{
//		const s_reach_x360_tag_struct_definition& definition_header = kv.first;
//		c_reach_x360_tag_group_definition& tag_group_definition = *kv.second;
//
//		unsigned long num_combined_fields = definition_header.runtime.num_combined_fields;
//		unsigned long num_insert_fields = num_combined_fields - num_original_fields;
//
//		ptr32 fields_address = definition_header.runtime.combined_fields;
//		const s_reach_x360_tag_field* const field_definitions = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, fields_address);
//
//		const s_reach_x360_tag_field* field_definition = field_definitions;
//		ASSERT(field_definition);
//
//		t_fields temp_fields;
//
//		if (num_insert_fields > 0)
//		{
//			e_reach_x360_tag_field_combined_fixup_type fixup_type = _reach_x360_tag_field_combined_fixup_type_equal;
//			{
//				// #TODO: Is there a better way to automatically detect this?
//				static const char* fixups[] =
//				{
//					"shader_contrail",
//					"shader_particle"
//					"shader_beam",
//					"shader_decal",
//					"shader_light_volume",
//				};
//				for (const char* fixup : fixups)
//				{
//					c_reach_x360_tag_field* field_wrapper = new() c_reach_x360_tag_field(data, *field_definition);
//					if (strcmp(tag_group_definition.name, fixup) == 0)
//					{
//						fixup_type = _reach_x360_tag_field_combined_fixup_type_not_equal;
//						break;
//					}
//				}
//			}
//
//			c_reach_x360_tag_field_combined_fixup* versioning_field_wrapper = new() c_reach_x360_tag_field_combined_fixup(tag_group_definition, num_insert_fields, fixup_type);
//			temp_fields.push_back(versioning_field_wrapper);
//
//			// #TODO: This might be way more complicated than assuming that these fields are always at the front
//			// but this fixup codepath is only required for a handful of tags
//			for (unsigned long combined_field_index = 0; combined_field_index < num_insert_fields; combined_field_index++, field_definition++)
//			{
//				c_reach_x360_tag_field* field_wrapper = new() c_reach_x360_tag_field(data, *field_definition);
//				temp_fields.push_back(field_wrapper);
//			}
//
//			c_reach_x360_tag_field_dummy_space* dummy_space_wrapper = new() c_reach_x360_tag_field_dummy_space();
//			temp_fields.push_back(dummy_space_wrapper);
//
//			fields.insert(fields.begin(), temp_fields.begin(), temp_fields.end());
//
//		}
//
//		debug_point;
//	}
//
//
//
//	ASSERT(fields.size() > 0);
//	c_reach_x360_tag_field* last_field = dynamic_cast<c_reach_x360_tag_field*>(fields.back());
//	ASSERT(last_field != nullptr);
//	ASSERT(last_field->field_type == _reach_x360_field_type_terminator);
//
//	debug_point;
//}
//
//c_reach_x360_tag_struct_definition* c_reach_x360_tag_struct_definition::reach_x360_get_tag_struct_definition(const char* data, ptr32 virtual_address)
//{
//	const s_reach_x360_tag_struct_definition* src_tag_struct_definition = reinterpret_cast<const s_reach_x360_tag_struct_definition*>(reach_x360_pa_to_pointer(data, virtual_address));
//	s_reach_x360_tag_struct_definition tag_struct_definition = byteswap(*src_tag_struct_definition);
//
//	c_reach_x360_tag_struct_definition* conflicting_tag_struct_definition = reach_x360_find_tag_struct_definition_by_persistent_id(tag_struct_definition.type.persistent_identifier);
//	c_reach_x360_tag_struct_definition* existing_tag_struct_definition = nullptr;
//
//	std::map<ptr32, c_reach_x360_tag_struct_definition*>::iterator tag_block_definition_iterator = tag_struct_definitions.find(virtual_address);
//	if (tag_block_definition_iterator != tag_struct_definitions.end())
//	{
//		existing_tag_struct_definition = tag_block_definition_iterator->second;
//	}
//
//	if (existing_tag_struct_definition == nullptr && conflicting_tag_struct_definition != nullptr) // struct already exists, found a conflict
//	{
//		console_write_line("Attempting to resolve duplicate structure conflict for '%s'", conflicting_tag_struct_definition->display_name.c_str());
//
//		conflicting_tag_struct_definition->handle_conflict(data, tag_struct_definition);
//
//		existing_tag_struct_definition = conflicting_tag_struct_definition;
//		tag_struct_definitions[virtual_address] = conflicting_tag_struct_definition;
//
//		return existing_tag_struct_definition;
//	}
//	else if (existing_tag_struct_definition != nullptr)
//	{
//		return existing_tag_struct_definition;
//	}
//	else
//	{
//		c_reach_x360_tag_struct_definition* tag_block_definition = reinterpret_cast<c_reach_x360_tag_struct_definition*>(new char[sizeof(c_reach_x360_tag_struct_definition)]);
//
//		tag_struct_definitions[virtual_address] = tag_block_definition;
//
//		tag_block_definition = new(tag_block_definition) c_reach_x360_tag_struct_definition(data, tag_struct_definition);
//
//		return tag_block_definition;
//	}
//}
