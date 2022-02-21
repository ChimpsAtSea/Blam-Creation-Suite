#include "blamboozlelib-private-pch.h"



template<> void byteswap_inplace(s_reach_tag_memory_attributes& value)
{
	byteswap_inplace(value.memory_type);
	byteswap_inplace(value.usage_flags);
}

template<> void byteswap_inplace(blofeld::s_tag_persistent_identifier& value)
{
	byteswap_inplace(value.identifier_part_0);
	byteswap_inplace(value.identifier_part_1);
	byteswap_inplace(value.identifier_part_2);
	byteswap_inplace(value.identifier_part_3);
}

template<> void byteswap_inplace(s_reach_x360_byte_swap_definition& value)
{
	byteswap_inplace(value.name);
	byteswap_inplace(value.size);
	byteswap_inplace(value.byte_swap_traits);
	byteswap_inplace(value.filepath);
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
	byteswap_inplace(value.pretty_name_address);
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.filepath_address);
	byteswap_inplace(value.line_number);
	byteswap_inplace(value.persistent_identifier);
	byteswap_inplace(value.fields_address);
	byteswap_inplace(value.structure_size);
	byteswap_inplace(value.size_string_address);
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

std::map<ptr32, c_reach_x360_tag_struct_definition*> c_reach_x360_tag_struct_definition::tag_struct_definitions;

c_reach_x360_tag_struct_definition::c_reach_x360_tag_struct_definition(const char* data, const s_reach_x360_tag_struct_definition& definition_header) :
	pretty_name(reach_x360_pa_to_pointer(data, definition_header.type.pretty_name_address)),
	name(reach_x360_pa_to_pointer(data, definition_header.type.name_address)),
	code_name(reach_x360_convert_to_code_name(name)),
	structure_size(definition_header.type.structure_size),
	alignment_bits(definition_header.type.alignment_bits),
	persistent_identifier(definition_header.type.persistent_identifier),
	struct_definitions{ { definition_header, c_reach_x360_tag_group_definition::current_group_traverse_hack } },
	fields()
{

	unsigned long existing_count = 0;
	for (auto& keyval : tag_struct_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}

	ptr32 fields_address = definition_header.type.fields_address;
	const s_reach_x360_tag_field* const field_definitions = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, fields_address);
	const s_reach_x360_tag_field* field_definition = field_definitions;
	ASSERT(field_definition);
	do
	{
		c_reach_x360_tag_field* field_wrapper = new c_reach_x360_tag_field(data, *field_definition);
		fields.push_back(field_wrapper);
	} while ((field_definition++)->field_type != _reach_x360_field_type_terminator);
}

c_reach_x360_tag_struct_definition::~c_reach_x360_tag_struct_definition()
{
	clear_fields();
}

void c_reach_x360_tag_struct_definition::handle_conflict(const char* data, const s_reach_x360_tag_struct_definition& conflicting_tag_struct_definition)
{
	clear_fields(); // clear fields, they will be rebuild

	// push the current definition header onto the back of the queue
	struct_definitions.insert(struct_definitions.end(), { conflicting_tag_struct_definition, c_reach_x360_tag_group_definition::current_group_traverse_hack });

	// make sure that we can compare with the original otherwise all hope is lost
	// and poor squaresome might have to rewrite the tag system again
	ASSERT(struct_definitions.front().first.runtime.original_fields == conflicting_tag_struct_definition.runtime.original_fields);
	ASSERT(struct_definitions.front().second != c_reach_x360_tag_group_definition::current_group_traverse_hack);

	// insert the original fields
	{
		ptr32 fields_address = conflicting_tag_struct_definition.runtime.original_fields;
		const s_reach_x360_tag_field* const field_definitions = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, fields_address);
		const s_reach_x360_tag_field* field_definition = field_definitions;
		ASSERT(field_definition);
		do
		{
			c_reach_x360_tag_field* field_wrapper = new c_reach_x360_tag_field(data, *field_definition);
			fields.push_back(field_wrapper);
		} while ((field_definition++)->field_type != _reach_x360_field_type_terminator);
	}
	unsigned long num_original_fields = static_cast<unsigned long>(fields.size());

	

	// insert bespoke field fixups
	for (auto& kv : struct_definitions)
	{
		const s_reach_x360_tag_struct_definition& definition_header = kv.first;
		c_reach_x360_tag_group_definition& tag_group_definition = *kv.second;

		unsigned long num_combined_fields = definition_header.runtime.num_combined_fields;
		unsigned long num_insert_fields = num_combined_fields - num_original_fields;

		ptr32 fields_address = definition_header.runtime.combined_fields;
		const s_reach_x360_tag_field* const field_definitions = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, fields_address);

		const s_reach_x360_tag_field* field_definition = field_definitions;
		ASSERT(field_definition);

		t_fields temp_fields;

		if (num_insert_fields > 0)
		{
			e_reach_x360_tag_field_combined_fixup_type fixup_type = _reach_x360_tag_field_combined_fixup_type_equal;
			{
				// #TODO: Is there a better way to automatically detect this?
				static const char* fixups[] =
				{
					"shader_contrail",
					"shader_particle"
					"shader_beam",
					"shader_decal",
					"shader_light_volume",
				};
				for (const char* fixup : fixups)
				{
					c_reach_x360_tag_field* field_wrapper = new c_reach_x360_tag_field(data, *field_definition);
					if (strcmp(tag_group_definition.name,  fixup) == 0)
					{
						fixup_type = _reach_x360_tag_field_combined_fixup_type_not_equal;
						break;
					}
				}
			}

			c_reach_x360_tag_field_combined_fixup* versioning_field_wrapper = new c_reach_x360_tag_field_combined_fixup(tag_group_definition, num_insert_fields, fixup_type);
			temp_fields.push_back(versioning_field_wrapper);

			// #TODO: This might be way more complicated than assuming that these fields are always at the front
			// but this fixup codepath is only required for a handful of tags
			for (unsigned long combined_field_index = 0; combined_field_index < num_insert_fields; combined_field_index++, field_definition++)
			{
				c_reach_x360_tag_field* field_wrapper = new c_reach_x360_tag_field(data, *field_definition);
				temp_fields.push_back(field_wrapper);
			}

			c_reach_x360_tag_field_dummy_space* dummy_space_wrapper = new c_reach_x360_tag_field_dummy_space();
			temp_fields.push_back(dummy_space_wrapper);
			
			fields.insert(fields.begin(), temp_fields.begin(), temp_fields.end());

		}

		debug_point;
	}



	ASSERT(fields.size() > 0);
	c_reach_x360_tag_field* last_field = dynamic_cast<c_reach_x360_tag_field*>(fields.back());
	ASSERT(last_field != nullptr);
	ASSERT(last_field->field_type == _reach_x360_field_type_terminator);

	debug_point;
}

c_reach_x360_tag_struct_definition* c_reach_x360_tag_struct_definition::reach_x360_get_tag_struct_definition(const char* data, ptr32 virtual_address)
{
	const s_reach_x360_tag_struct_definition* src_tag_struct_definition = reinterpret_cast<const s_reach_x360_tag_struct_definition*>(reach_x360_pa_to_pointer(data, virtual_address));
	s_reach_x360_tag_struct_definition tag_struct_definition = byteswap(*src_tag_struct_definition);

	c_reach_x360_tag_struct_definition* conflicting_tag_struct_definition = reach_x360_find_tag_struct_definition_by_persistent_id(tag_struct_definition.type.persistent_identifier);
	c_reach_x360_tag_struct_definition* existing_tag_struct_definition = nullptr;

	std::map<ptr32, c_reach_x360_tag_struct_definition*>::iterator tag_block_definition_iterator = tag_struct_definitions.find(virtual_address);
	if (tag_block_definition_iterator != tag_struct_definitions.end())
	{
		existing_tag_struct_definition = tag_block_definition_iterator->second;
	}

	if (existing_tag_struct_definition == nullptr && conflicting_tag_struct_definition != nullptr) // struct already exists, found a conflict
	{
		console_write_line("Attempting to resolve duplicate structure conflict for '%s'", conflicting_tag_struct_definition->pretty_name.c_str());

		conflicting_tag_struct_definition->handle_conflict(data, tag_struct_definition);

		existing_tag_struct_definition = conflicting_tag_struct_definition;
		tag_struct_definitions[virtual_address] = conflicting_tag_struct_definition;

		return existing_tag_struct_definition;
	}
	else if (existing_tag_struct_definition != nullptr)
	{
		return existing_tag_struct_definition;
	}
	else
	{
		c_reach_x360_tag_struct_definition* tag_block_definition = reinterpret_cast<c_reach_x360_tag_struct_definition*>(new char[sizeof(c_reach_x360_tag_struct_definition)]);

		tag_struct_definitions[virtual_address] = tag_block_definition;

		tag_block_definition = new(tag_block_definition) c_reach_x360_tag_struct_definition(data, tag_struct_definition);

		return tag_block_definition;
	}
}

c_reach_x360_tag_struct_definition* c_reach_x360_tag_struct_definition::reach_x360_find_tag_struct_definition_by_persistent_id(blofeld::s_tag_persistent_identifier persistent_identifier)
{
	for (auto& kv : tag_struct_definitions)
	{
		c_reach_x360_tag_struct_definition& tag_struct_definition = *kv.second;

		if (tag_struct_definition.persistent_identifier == persistent_identifier)
		{
			return &tag_struct_definition;
		}
	}

	return nullptr;
}

void c_reach_x360_tag_struct_definition::clear_fields()
{
	for (t_reach_x360_tag_field* field_wrapper : fields)
	{
		delete field_wrapper;
	}
	fields.clear();
}
