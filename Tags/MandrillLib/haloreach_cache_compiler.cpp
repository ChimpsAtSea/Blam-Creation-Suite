#include "mandrilllib-private-pch.h"

#define align_value(value, alignment) (((value) + ((alignment) - 1)) & ~((alignment) - 1))

namespace cache_compiler
{
	constexpr tag k_cache_header_signature = 'head';
	constexpr tag k_cache_footer_signature = 'foot';

#pragma pack(push, 1)
	struct s_cache_file_header
	{
		tag header_signature;
		long file_version;
		long file_length;
		long file_compressed_length;
	};

	struct s_cache_file_info
	{
		uint64_t tags_header_address = 0;

		unsigned long tag_buffer_offset;
		unsigned long tag_buffer_size;

		char source_file[256] = "";
		char build[32] = "";

		e_scenario_type scenario_type = _scenario_type_none;
		e_scenario_load_type load_type = _scenario_load_none;

		unsigned char : 8;
		char tracked_build;
		unsigned char : 8;
		unsigned char : 8;

		unsigned long : 32;
		unsigned long : 32;

		unsigned long string_count;
		unsigned long string_table_length;
		unsigned long string_table_indices_offset;
		unsigned long string_table_offset;
		unsigned long string_ids_namespace_table_count;
		unsigned long string_ids_namespace_table_offset;

		gen3::e_cache_file_flags flags = {};

		time64_t timestamp;
		time64_t scenario_type_timestamps[4];

		char name[32];
		unsigned long __unknown1B4;
		char scenario_path[256];
		long minor_version;

		unsigned long file_count;
		unsigned long file_table_offset;
		unsigned long file_table_length;
		unsigned long file_table_indices_offset;

		unsigned long checksum;

		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;
		unsigned long : 32;

		unsigned long long virtual_base_address;
		unsigned long xdk_version;
		unsigned long : 32;

		s_basic_buffer64 tag_post_link_buffer = {};
		s_basic_buffer64 tag_language_dependent_read_only_buffer = {};
		s_basic_buffer64 tag_language_dependent_read_write_buffer = {};
		s_basic_buffer64 tag_language_neutral_read_write_buffer = {};
		s_basic_buffer64 tag_language_neutral_write_combined_buffer = {};
		s_basic_buffer64 tag_language_neutral_read_only_buffer = {};

		unsigned long SHA1_A[5];
		unsigned long SHA1_B[5];
		unsigned long SHA1_C[5];
		unsigned long RSA[64];

		unsigned long GUID[4];

		struct
		{
			long offset_masks[gen3::k_number_of_cache_file_sections];
			struct
			{
				long offset;
				long size;
			} sections[gen3::k_number_of_cache_file_sections];
		} section_table;

		int32_t guid[4];
	};

	struct s_cache_file_metadata
	{
		s_cache_file_header header;
		s_cache_file_info info;
		char _padding[0x9B10];
		tag footer;
	};

#pragma pack(pop)

	struct s_cache_file_tags_header
	{
		gen3::s_section<gen3::s_cache_file_tag_group> tag_groups;
		gen3::s_section<gen3::s_cache_file_tag_instance> tag_instances;
		gen3::s_section<gen3::s_cache_file_tag_global_instance> tag_global_instance;
		gen3::s_section<gen3::s_cache_file_tag_interop> tag_interop_table;
		long : 32;
		dword checksum;
		unsigned long tags_signature;
	};
	static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
	static_assert(k_cache_file_tags_header == 0x50);

	struct s_cache_file_tag_group
	{
		unsigned long group_tags[3];
		unsigned long name;
	};
	static_assert(sizeof(s_cache_file_tag_group) == 0x10);

	struct s_cache_file_tag_instance
	{
		uint16_t group_index;
		uint16_t identifier;
		uint32_t address;
	};
	static_assert(sizeof(s_cache_file_tag_instance) == 0x8);
}

using namespace cache_compiler;

c_haloreach_cache_compiler::c_haloreach_cache_compiler(c_tag_project& tag_project) :
	tag_project(tag_project),
	cache_file_metadata(*new s_cache_file_metadata()),
	tag_group_count(),
	tag_groups_buffer_size(),
	tag_groups_buffer(),
	tag_groups(),
	tag_data_buffer(),
	tag_data_data_size(),
	tag_data_buffer_size(),
	tag_data_entries(),
	tag_data_entry_count(),
	tag_instances_buffer(),
	tag_instances_buffer_size(),
	tag_instance_count(),
	tag_file_table_buffer(),
	tag_file_table_buffer_size(),
	tag_file_table_indices_buffer(),
	tag_file_table_indices_buffer_size(),
	tag_file_table_indices_count()
{

}

c_haloreach_cache_compiler::~c_haloreach_cache_compiler()
{
	delete& cache_file_metadata;
}

void write(const void* _buffer, size_t size, FILE* stream)
{
	const char* buffer = static_cast<const char*>(_buffer);
	size_t bytes_written = 0;
	while (bytes_written < size)
	{
		bytes_written += fwrite(buffer + bytes_written, 1, size - bytes_written, stream);
	}
}

uint32_t c_haloreach_cache_compiler::calculate_size(h_tag& tag)
{
	uint32_t tag_size = tag.get_low_level_type_size();
	calculate_object_memory_footprint(tag_size, tag);
	return tag_size;
}

void c_haloreach_cache_compiler::calculate_object_memory_footprint(uint32_t& memory_footprint, h_object& object)
{
	for (const blofeld::s_tag_field* const* field_pointer = object.get_blofeld_field_list(); *field_pointer != nullptr; field_pointer++)
	{
		const blofeld::s_tag_field& field = **field_pointer;

		switch (field.field_type)
		{
		case blofeld::_field_block:
		{
			h_block& block_storage = *static_cast<h_block*>(object.get_field_data(field));
			uint32_t type_size = block_storage.get_low_level_type_size();
			uint32_t block_data_size = type_size * block_storage.size();
			memory_footprint += align_value(block_data_size, block_memory_alignment);

			for (uint32_t object_index = 0; object_index < block_storage.size(); object_index++)
			{
				h_object& object = block_storage.get(object_index);
				calculate_object_memory_footprint(memory_footprint, object);
			}

			debug_point;
			break;
		}
		case blofeld::_field_data:
		{
			h_data& data_storage = *static_cast<h_data*>(object.get_field_data(field));
			uint32_t data_size = data_storage.size();
			memory_footprint += align_value(data_size, block_memory_alignment);
			debug_point;
			break;
		}
		case blofeld::_field_array:
		{
			h_enumerable& child_array = *static_cast<h_enumerable*>(object.get_field_data(field));

			for (uint32_t object_index = 0; object_index < child_array.size(); object_index++)
			{
				h_object& object = child_array.get(object_index);
				calculate_object_memory_footprint(memory_footprint, object);
			}

			debug_point;
			break;
		}
		case blofeld::_field_struct:
		{
			h_object& child_object = *static_cast<h_object*>(object.get_field_data(field));

			calculate_object_memory_footprint(memory_footprint, child_object);

			debug_point;
			break;
		}
		}
	}
}

uint16_t c_haloreach_cache_compiler::get_tag_index(const h_tag* tag) const
{
	if (tag == nullptr)
	{
		return ~0ui16;
	}

	for (uint32_t tag_index = 0; tag_index < tag_data_entry_count; tag_index++)
	{
		s_tag_data_entry& tag_data_entry = tag_data_entries[tag_index];

		if (&tag_data_entry.tag == tag)
		{
			return static_cast<uint16_t>(tag_data_entry.tag_file_table_index);
		}

		debug_point;
	}
	throw;
}

void c_haloreach_cache_compiler::compile_tag(const h_tag& tag, char* tag_data)
{
	char* tag_allocation_postion = tag_data;
	tag_allocation_postion += tag.get_low_level_type_size();
	compile_object(tag, tag_data, tag_allocation_postion);
}

void c_haloreach_cache_compiler::compile_object(const h_object& object, char* object_data, char*& tag_allocation_postion)
{
	using namespace blofeld;

	char* current_data_position = object_data;
	for (const blofeld::s_tag_field* const* field_pointer = object.get_blofeld_field_list(); *field_pointer != nullptr; field_pointer++)
	{
		const blofeld::s_tag_field& field = **field_pointer;

		const void* high_level_field_data = object.get_field_data(field);

		uint32_t field_size = get_blofeld_field_size(field, tag_project.engine_type, tag_project.platform_type, tag_project.build);

		if (high_level_field_data != nullptr)
		{
			switch (field.field_type)
			{
			case _field_string:
			case _field_long_string:
			case _field_char_integer:
			case _field_short_integer:
			case _field_long_integer:
			case _field_int64_integer:
			case _field_angle:
			case _field_long_flags:
			case _field_word_flags:
			case _field_byte_flags:
			case _field_point_2d:
			case _field_rectangle_2d:
			case _field_rgb_color:
			case _field_argb_color:
			case _field_real:
			case _field_real_fraction:
			case _field_real_point_2d:
			case _field_real_point_3d:
			case _field_real_vector_2d:
			case _field_real_vector_3d:
			case _field_real_quaternion:
			case _field_real_euler_angles_2d:
			case _field_real_euler_angles_3d:
			case _field_real_plane_2d:
			case _field_real_plane_3d:
			case _field_real_rgb_color:
			case _field_real_argb_color:
			case _field_real_hsv_color:
			case _field_real_ahsv_color:
			case _field_short_bounds:
			case _field_angle_bounds:
			case _field_real_bounds:
			case _field_real_fraction_bounds:
			{
				memcpy(current_data_position, high_level_field_data, field_size);
				break;
			}
			case _field_char_enum:
			{
				char data = *reinterpret_cast<const int32_t*>(high_level_field_data);
				memcpy(current_data_position, &data, sizeof(data));
				break;
			}
			case _field_enum:
			{
				short data = *reinterpret_cast<const int32_t*>(current_data_position);
				memcpy(current_data_position, &data, sizeof(data));
				break;
			}
			case _field_long_enum:
			{
				long data = *reinterpret_cast<const int32_t*>(current_data_position);
				memcpy(current_data_position, &data, sizeof(data));
				break;
			}
			case _field_old_string_id:
			case _field_string_id:
			{
				//if (const char* string_id_value = cache_file.get_string_id(*reinterpret_cast<const string_id*>(current_data_position)))
				//{
				//	c_fixed_string_2048& string_id_storage = *reinterpret_cast<decltype(&string_id_storage)>(high_level_field_data);
				//	string_id_storage = string_id_value;
				//}

				string_id& stringid = *reinterpret_cast<string_id*>(current_data_position);
				stringid = 0;

				break;
			}
			case _field_block:
			{
				s_tag_block& tag_block = *reinterpret_cast<decltype(&tag_block)>(current_data_position);
				const h_block& block_storage = *reinterpret_cast<decltype(&block_storage)>(high_level_field_data);

				if (block_storage.size() == 0)
				{
					tag_block.count = 0;
					tag_block.address = 0;
					tag_block.definition_address = 0;
				}
				else
				{
					uint32_t type_size = block_storage.get_low_level_type_size();
					uint32_t block_data_size = type_size * block_storage.size();

					char* const tag_block_data = tag_allocation_postion;
					tag_allocation_postion += align_value(block_data_size, block_memory_alignment);

					uint32_t relative_offset = get_tag_pointer_relative_offset(tag_block_data);
					uint32_t page_offset = encode_page_offset(relative_offset);

					tag_block.count = static_cast<uint32_t>(block_storage.size());
					tag_block.address = page_offset;
					tag_block.definition_address = 0;

					char* current_tag_block_data_position = tag_block_data;
					for (uint32_t block_index = 0; block_index < block_storage.size(); block_index++)
					{
						const h_object& block_object = block_storage.get(block_index);

						compile_object(block_object, current_tag_block_data_position, tag_allocation_postion);

						current_tag_block_data_position += type_size;
					}
				}

				break;
			}
			case _field_struct:
			{
				const h_object& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);
				compile_object(struct_storage, current_data_position, tag_allocation_postion);
				debug_point;
				break;
			}
			case _field_array:
			{
				const h_enumerable& array_storage = *reinterpret_cast<decltype(&array_storage)>(high_level_field_data);
				const char* raw_array_data_position = current_data_position;

				uint32_t const array_elements_count = array_storage.size();
				for (uint32_t array_index = 0; array_index < array_elements_count; array_index++)
				{
					const h_object& array_element_storage = array_storage[array_index];

					compile_object(array_element_storage, current_data_position, tag_allocation_postion);

					raw_array_data_position += field_size;
				}
				break;
			}
			case _field_tag_reference:
			{
				s_tag_reference& tag_reference = *reinterpret_cast<decltype(&tag_reference)>(current_data_position);
				const h_tag* const& tag_reference_storage = *reinterpret_cast<decltype(&tag_reference_storage)>(high_level_field_data);

				if (tag_reference_storage != nullptr)
				{
					tag_reference.group_tag = blofeld::INVALID_TAG;
					tag_reference.index = get_tag_index(tag_reference_storage);
					tag_reference.datum = 0; // #TODO
				}
				else
				{
					tag_reference.group_tag = blofeld::INVALID_TAG;
					tag_reference.index = ~0ui16;
					tag_reference.datum = ~0ui16;
				}
				tag_reference.name = 0;
				tag_reference.name_length = 0;
				break;
			}
			case _field_data:
			{
				s_tag_data& tag_data = *reinterpret_cast<decltype(&tag_data)>(current_data_position);
				const h_data& data_storage = *reinterpret_cast<decltype(&data_storage)>(high_level_field_data);

				if (data_storage.size() == 0)
				{
					tag_data.size = 0;
					tag_data.stream_flags = 0;
					tag_data.stream_offset = 0;
					tag_data.address = 0;
					tag_data.definition = 0;
				}
				else
				{
					uint32_t block_data_size = data_storage.size();

					char* const tag_data_data = tag_allocation_postion;
					tag_allocation_postion += align_value(block_data_size, block_memory_alignment);

					uint32_t relative_offset = get_tag_pointer_relative_offset(tag_data_data);
					uint32_t page_offset = encode_page_offset(relative_offset);

					tag_data.size = static_cast<uint32_t>(data_storage.size());
					tag_data.stream_flags = 0;
					tag_data.stream_offset = 0;
					tag_data.address = page_offset;
					tag_data.definition = 0;

					memcpy(tag_data_data, data_storage.data(), block_data_size);
				}

				break;
			}
			}
		}

		current_data_position += field_size;
	}
}

class c_debug_string_manager
{
public:
	uint32_t commit_string(const char* value)
	{

	}
};

void c_haloreach_cache_compiler::create_tag_groups()
{
	TASK_TIMER(__FUNCTION__);

	using namespace blofeld;

	{
		for (s_tag_group_info** haloreach_tag_groups = blofeld::haloreach::haloreach_tag_groups; *haloreach_tag_groups; haloreach_tag_groups++)
		{
			tag_group_count++;
		}

		tag_groups_buffer_size = align_value(tag_group_count * sizeof(s_cache_file_tag_group), 0x1000);
		tag_groups_buffer = new char[tag_groups_buffer_size] {};
		tag_groups = new(tag_groups_buffer) s_cache_file_tag_group[tag_group_count]{};

		for (uint32_t i = 0; i < tag_group_count; i++)
		{
			s_tag_group_info& tag_group_info = *blofeld::haloreach::haloreach_tag_groups[i];
			s_cache_file_tag_group& tag_group = tag_groups[i];

			tag_group.group_tags[0] = tag_group_info.group_tag;
			tag_group.group_tags[1] = tag_group_info.parents[0] != nullptr ? tag_group_info.parents[0]->group_tag : blofeld::INVALID_TAG;
			tag_group.group_tags[2] = tag_group_info.parents[1] != nullptr ? tag_group_info.parents[1]->group_tag : blofeld::INVALID_TAG;

		}
	}
}

void c_haloreach_cache_compiler::init_tags()
{
	TASK_TIMER(__FUNCTION__);

	tag_data_entry_count = static_cast<uint32_t>(tag_project.tags.size());
	tag_data_entries = reinterpret_cast<s_tag_data_entry*>(new char[sizeof(s_tag_data_entry) * tag_data_entry_count]{});

	uint32_t file_index = 0;
	for (h_tag* tag : tag_project.tags)
	{
		uint32_t tag_data_size = calculate_size(*tag);
		ASSERT((tag_data_size % 4) == 0);

		uint32_t tag_group_index = ~0u;
		for (uint32_t _tag_group_index = 0; _tag_group_index < tag_group_count; _tag_group_index++)
		{
			if (tag_groups[_tag_group_index].group_tags[0] == tag->group->tag_group.group_tag) // #TODO: this is kinda crazy?
			{
				tag_group_index = _tag_group_index;
			}
		}
		ASSERT(tag_group_index != ~0u);

		s_tag_data_entry& data_entry = *new(tag_data_entries + file_index) s_tag_data_entry
		{
			*tag,
			tag_data_data_size,
			tag_data_size,
			nullptr,
			tag_file_table_data_size,
			file_index,
			nullptr,
			tag_group_index,
			tag->tag_filepath
		};

		PathRemoveExtensionA(data_entry.path.data);

		tag_file_table_data_size += data_entry.path.size() + 1;
		tag_data_data_size += tag_data_size;
		file_index++;
	}
}

void c_haloreach_cache_compiler::create_tag_file_table()
{
	TASK_TIMER(__FUNCTION__);

	tag_file_table_buffer_size = align_value(tag_file_table_data_size, 0x1000);
	tag_file_table_buffer = new char[tag_file_table_buffer_size] {};

	tag_file_table_indices_count = static_cast<uint32_t>(tag_project.tags.size());
	tag_file_table_indices_buffer_size = align_value(tag_file_table_indices_count * sizeof(uint32_t), 0x1000);
	tag_file_table_indices_buffer = new char[tag_file_table_indices_buffer_size] {};
	uint32_t* tag_file_table_indices = new(tag_file_table_indices_buffer) uint32_t[tag_file_table_indices_count]{};

	for (uint32_t tag_index = 0; tag_index < tag_data_entry_count; tag_index++)
	{
		s_tag_data_entry& tag_data_entry = tag_data_entries[tag_index];

		tag_data_entry.tag_file_table_entry = tag_file_table_buffer + tag_data_entry.tag_file_table_offset;
		tag_file_table_indices[tag_data_entry.tag_file_table_index] = tag_data_entry.tag_file_table_offset;
		strcpy(tag_data_entry.tag_file_table_entry, tag_data_entry.path.data);

		debug_point;
	}
}

void c_haloreach_cache_compiler::compile_tags()
{
	TASK_TIMER(__FUNCTION__);

	tag_data_buffer_size = align_value(tag_data_data_size, 0x1000);
	tag_data_buffer = new char[tag_data_buffer_size] {};

	tag_instance_count = static_cast<uint32_t>(tag_project.tags.size());
	tag_instances_buffer_size = tag_instance_count * sizeof(s_cache_file_tag_instance);
	tag_instances_buffer = new char[tag_instances_buffer_size] {};

	for (uint32_t tag_index = 0; tag_index < tag_data_entry_count; tag_index++)
	{
		s_tag_data_entry& tag_data_entry = tag_data_entries[tag_index];

		tag_data_entry.tag_data = tag_data_buffer + tag_data_entry.tag_data_offset;

		compile_tag(tag_data_entry.tag, tag_data_entry.tag_data); // #TODO: multithread?

		debug_point;
	}
}

void c_haloreach_cache_compiler::compile(const wchar_t* filepath DEBUG_ONLY(, c_haloreach_cache_file* cache_file))
{
	using namespace blofeld;

#define push_to_vector(vector, data, size) \
	vector.insert(vector.end(), reinterpret_cast<const char*>(data), reinterpret_cast<const char*>(data) + (size))

	create_tag_groups();
	init_tags();
	create_tag_file_table();
	compile_tags();

	debug_point;



	blofeld::haloreach::h_scenario_struct_definition* scenario = dynamic_cast<decltype(scenario)>(tag_project.tags[8]);
	DEBUG_ASSERT(scenario != nullptr);

	uint32_t tags_header_buffer_size = align_value(sizeof(s_cache_file_tags_header), 0x1000);
	char* tags_header_buffer = new char[tags_header_buffer_size] {};
	s_cache_file_tags_header& tags_header = *reinterpret_cast<s_cache_file_tags_header*>(tags_header_buffer);


	uint32_t tags_section_file_offset = 0;

	struct s_section_info
	{
		uint32_t section_file_offset;
		uint32_t section_offset_from_header;
		uint32_t section_size;
	};
	s_section_info section_infos[gen3::k_number_of_cache_file_sections] = {};

	uint32_t tags_section_tag_data_offset;
	uint32_t tags_section_tags_header_offset;
	uint32_t tags_section_tag_groups_offset;
	uint32_t tags_section_tag_instances_offset;
	uint32_t debug_section_file_table_offset;
	uint32_t debug_section_file_table_indices_offset;

	{
		uint32_t total_cache_file_data = sizeof(s_cache_file_metadata);
		uint32_t total_section_data = 0;

		for (uint32_t i = 0; i < gen3::k_number_of_cache_file_sections; i++)
		{
			switch (i)
			{
			case gen3::_cache_file_section_index_resource:
			{
				break;
			}
			case gen3::_cache_file_section_index_localization:
			{
				break;
			}
			case gen3::_cache_file_section_index_tags:
			{
#define get_tag_section_virtual_address(offset) (virtual_base_address + (offset - tags_section_base))

				uint32_t tags_section_base = total_cache_file_data;
				tags_section_tag_data_offset = tags_section_base;
				tags_section_tags_header_offset = tags_section_tag_data_offset + tag_data_buffer_size;
				tags_section_tag_groups_offset = tags_section_tags_header_offset + tags_header_buffer_size;
				tags_section_tag_instances_offset = tags_section_tag_groups_offset + tag_groups_buffer_size;
				uint32_t tags_section_unused_next_offset = tags_section_tag_instances_offset + tag_instances_buffer_size;

				tags_header.checksum = 'poop';

				tags_header.tag_instances.count = tag_instance_count;
				tags_header.tag_instances.address = get_tag_section_virtual_address(tags_section_tag_instances_offset);

				{
					s_cache_file_tag_instance* tag_instances = new(tag_instances_buffer) s_cache_file_tag_instance[tag_instance_count]{};
					for (uint32_t tag_index = 0; tag_index < tag_data_entry_count; tag_index++)
					{
						s_tag_data_entry& tag_data_entry = tag_data_entries[tag_index];

						uint32_t instance_index = tag_data_entry.tag_file_table_index;
						s_cache_file_tag_instance& tag_instance = tag_instances[instance_index];
						tag_instance.identifier = static_cast<uint16_t>(instance_index + 0xe175u);
						tag_instance.address = encode_page_offset(tag_data_entry.tag_data_offset);
						tag_instance.group_index = tag_data_entry.tag_group_index;

						uint32_t reconstructed_address = decode_page_offset(tag_instance.address);
						DEBUG_ASSERT(reconstructed_address == tag_data_entry.tag_data_offset);

						debug_point;
					}
				}


				tags_header.tag_groups.count = tag_group_count;
				tags_header.tag_groups.address = get_tag_section_virtual_address(tags_section_tag_groups_offset);

				cache_file_metadata.info.tag_buffer_offset = tags_section_tag_data_offset;
				cache_file_metadata.info.tag_buffer_size = tag_data_data_size;

				section_data[i].insert(section_data[i].end(), tag_data_buffer, tag_data_buffer + tag_data_buffer_size);
				section_data[i].insert(section_data[i].end(), tags_header_buffer, tags_header_buffer + tags_header_buffer_size);
				section_data[i].insert(section_data[i].end(), tag_groups_buffer, tag_groups_buffer + tag_groups_buffer_size);
				section_data[i].insert(section_data[i].end(), tag_instances_buffer, tag_instances_buffer + tag_instances_buffer_size);

				break;
			}
			case gen3::_cache_file_section_index_debug:
			{
				debug_section_file_table_offset = total_cache_file_data;
				debug_section_file_table_indices_offset = debug_section_file_table_offset + tag_file_table_buffer_size;
				uint32_t debug_section_unused_next_offset = debug_section_file_table_indices_offset + tag_file_table_indices_buffer_size;

				cache_file_metadata.info.file_count = tag_file_table_indices_count;
				cache_file_metadata.info.file_table_offset = debug_section_file_table_offset;
				cache_file_metadata.info.file_table_length = tag_file_table_buffer_size;
				cache_file_metadata.info.file_table_indices_offset = debug_section_file_table_indices_offset;

				section_data[i].insert(section_data[i].end(), tag_file_table_buffer, tag_file_table_buffer + tag_file_table_buffer_size);
				section_data[i].insert(section_data[i].end(), tag_file_table_indices_buffer, tag_file_table_indices_buffer + tag_file_table_indices_buffer_size);

				break;
			}
			}

			uint32_t section_size = static_cast<uint32_t>(section_data[i].size());

			section_infos[i].section_file_offset = total_cache_file_data;
			section_infos[i].section_offset_from_header = total_cache_file_data;
			section_infos[i].section_size = section_size;

			total_section_data += section_size;
			total_cache_file_data += section_size;
		}
	}

	{
		memset(&cache_file_metadata._padding, 0, sizeof(cache_file_metadata._padding));
		cache_file_metadata.footer = k_cache_footer_signature;
	}
	{
		cache_file_metadata.info.scenario_type = _scenario_type_multiplayer;

		//time_t now = time(NULL);
		//struct tm* t = localtime(&now);
		//strftime(info.build, sizeof(info.build), "Mandrill - %b %d %Y %T", t);
		strcpy(cache_file_metadata.info.build, "Oct 15 2020 18:23:50");

		c_fixed_path name = scenario->tag_filename;
		PathRemoveExtensionA(name.data);
		c_fixed_path scenario_path = scenario->tag_filepath;
		PathRemoveExtensionA(scenario_path.data);
		snprintf(cache_file_metadata.info.name, sizeof(cache_file_metadata.info.name), "%s", name.c_str());
		snprintf(cache_file_metadata.info.scenario_path, sizeof(cache_file_metadata.info.scenario_path), "%s", scenario_path.c_str());

		cache_file_metadata.info.virtual_base_address = 0x00000001cb780000; // taken from 20_sword_slayer

		cache_file_metadata.info.tags_header_address = cache_file_metadata.info.virtual_base_address + (tags_section_tags_header_offset - tags_section_tag_data_offset);
	}
	{
		cache_file_metadata.header.header_signature = k_cache_header_signature;
		cache_file_metadata.header.file_version = 13;
		cache_file_metadata.header.file_length = sizeof(cache_file_metadata);
		cache_file_metadata.header.file_compressed_length = 0;

		for (uint32_t i = 0; i < gen3::k_number_of_cache_file_sections; i++)
		{
			cache_file_metadata.header.file_length += cache_file_metadata.info.section_table.sections[i].size;
		}

		for (uint32_t i = 0; i < gen3::k_number_of_cache_file_sections; i++)
		{
			s_section_info& section_info = section_infos[i];

			cache_file_metadata.info.section_table.sections[i].offset = section_info.section_offset_from_header;
			cache_file_metadata.info.section_table.sections[i].size = section_info.section_size;
			cache_file_metadata.info.section_table.offset_masks[i] = 0;
		}
	}

	FILE* file = _wfopen(filepath, L"wb");
	write(&cache_file_metadata, sizeof(cache_file_metadata), file);
	for (uint32_t i = 0; i < gen3::k_number_of_cache_file_sections; i++)
	{
		write(section_data[i].data(), section_data[i].size(), file);
	}
	fclose(file);

}

uint32_t c_haloreach_cache_compiler::get_tag_pointer_relative_offset(const char* tag_data)
{
	uint32_t relative_offset = static_cast<uint32_t>(tag_data - tag_data_buffer);
	return relative_offset;
}

uint32_t c_haloreach_cache_compiler::encode_page_offset(uint64_t virtual_address)
{
	return static_cast<uint32_t>(((virtual_address)+(virtual_base_address - page_address_offset_relative)) / 4ull);
}

uint64_t c_haloreach_cache_compiler::decode_page_offset(uint32_t page_offset)
{
	return (static_cast<uint64_t>(page_offset) * 4ull) - (virtual_base_address - page_address_offset_relative);
}
