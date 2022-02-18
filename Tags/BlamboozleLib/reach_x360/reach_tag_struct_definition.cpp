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
	byteswap_inplace(value.unknown9C);
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
	struct_definitions{ definition_header },
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
	//if (pretty_name == "shader_particle_struct_definition")
	if (definition_header.runtime.original_fields && definition_header.runtime.combined_fields)
	{
		const s_reach_x360_tag_field* combined_fields = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, definition_header.runtime.combined_fields);
		const s_reach_x360_tag_field* original_fields = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, definition_header.runtime.original_fields);

		c_reach_x360_tag_field* afield_wrapper = new c_reach_x360_tag_field(data, *combined_fields);
		c_reach_x360_tag_field* bfield_wrapper = new c_reach_x360_tag_field(data, *original_fields);

		debug_point;
	}

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
	for (c_reach_x360_tag_field* field_wrapper : fields)
	{
		delete field_wrapper;
	}
}

void c_reach_x360_tag_struct_definition::handle_conflict(const char* data, const s_reach_x360_tag_struct_definition& definition_header)
{
	struct_definitions.push_back(definition_header);

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
