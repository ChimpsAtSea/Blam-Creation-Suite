#pragma once

class c_haloreach_cache_file;

class h_object;
class h_interop;
class c_string_id_manager;
class h_structured_buffer_container;

namespace cache_compiler
{
	struct s_cache_file_header;
	struct s_cache_file_info;
	struct s_cache_file_metadata;
	struct s_cache_file_tags_header;
	struct s_cache_file_tag_group;
	struct s_cache_file_tag_instance;
}


namespace cache_compiler
{
	constexpr tag k_cache_header_signature = 'head';
	constexpr tag k_cache_footer_signature = 'foot';

	enum e_cache_file_flags : uint32_t
	{
		_cache_file_flag_use_absolute_addressing = 1u << 0u,
	};

	enum e_cache_file_section_index
	{
		_cache_file_section_index_debug,
		_cache_file_section_index_resource,
		_cache_file_section_index_tags,
		_cache_file_section_index_localization,
		k_number_of_cache_file_sections
	};

#pragma pack(push, 1)
	struct s_cache_file_metadata
	{
		tag header_signature;
		long file_version;
		long file_length;
		long file_compressed_length;


		uint64_t tags_header_address = 0;

		unsigned long tag_buffer_offset;
		unsigned long tag_buffer_size;

		char source_file[256] = "";
		char build[32] = "";

		e_scenario_type scenario_type = _scenario_type_none;
		e_scenario_load_type load_type = _scenario_load_none;

		unsigned char __unknown0;
		char tracked_build;
		unsigned char __unknown1;
		unsigned char __unknown2;

		unsigned long __unknown3;
		unsigned long __unknown4;

		unsigned long string_count;
		unsigned long string_table_length;
		unsigned long string_table_indices_offset;
		unsigned long string_table_offset;
		unsigned long string_ids_namespace_table_count;
		unsigned long string_ids_namespace_table_offset;

		e_cache_file_flags flags = {};

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

		unsigned long __unknown5;
		unsigned long __unknown6;
		unsigned long __unknown7;
		unsigned long __unknown8;
		unsigned long __unknown9;
		unsigned long __unknown10;
		unsigned long __unknown11;
		unsigned long __unknown12;

		unsigned long long virtual_base_address;
		unsigned long xdk_version;
		unsigned long __unknown13;

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
			long offset_masks[k_number_of_cache_file_sections];
			struct
			{
				long offset;
				long size;
			} sections[k_number_of_cache_file_sections];
		} section_table;

		int32_t guid[4];


		char _padding[0x9B10];
		tag footer;
	};
	static_assert(sizeof(s_cache_file_metadata) == 40960);
	static constexpr size_t x = offsetof(s_cache_file_metadata, __unknown2);
	static constexpr size_t y = offsetof(s_cache_file_metadata, tag_post_link_buffer);
	static constexpr size_t z = offsetof(s_cache_file_metadata, section_table);

	// 1200

#pragma pack(pop)


	struct s_cache_file_tag_interop_type_fixup
	{
		dword page_address;
		long type_index;
	};
	static_assert(sizeof(s_cache_file_tag_interop_type_fixup) == 0x8);

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

	struct s_cache_file_tag_global_instance
	{
		uint32_t group_tag;
		uint16_t tag_index;
		uint16_t identifier;
	};
	static_assert(sizeof(s_cache_file_tag_global_instance) == 0x8);

	template <typename t_type>
	struct s_section
	{
		uint32_t count = 0;
		uint32_t post_count_signature = k_cache_file_tags_section_signature;
		qword address = 0;
	};

	struct s_cache_file_tags_header
	{
		s_section<s_cache_file_tag_group> tag_groups;
		s_section<s_cache_file_tag_instance> tag_instances;
		s_section<s_cache_file_tag_global_instance> tag_global_instance;
		s_section<s_cache_file_tag_interop_type_fixup> tag_interop_table;
		long : 32;
		dword checksum;
		unsigned long tags_signature;
	};
	static constexpr size_t k_cache_file_tags_header = sizeof(s_cache_file_tags_header);
	static_assert(k_cache_file_tags_header == 0x50);
}

enum e_tag_interop_type
{
	_tag_interop_type_d3d_vertex_buffer,
	_tag_interop_type_d3d_index_buffer,
	_tag_interop_type_d3d_texture,
	_tag_interop_type_d3d_texture_interleaved,
	_tag_interop_type_d3d_vertex_shader,
	_tag_interop_type_d3d_pixel_shader,
	_tag_interop_type_constant_buffer,
	_tag_interop_type_structured_buffer,
	k_num_interop_types
};

struct h_cache_file_tag_interop_vtable
{
	const char* name;
	uint32_t size;
	uint32_t alignment_bits;
};

extern h_cache_file_tag_interop_vtable d3d_vertex_buffer_interop_vtable;
extern h_cache_file_tag_interop_vtable d3d_index_buffer_interop_vtable;
extern h_cache_file_tag_interop_vtable d3d_texture_interop_vtable;
extern h_cache_file_tag_interop_vtable d3d_texture_interleaved_interop_vtable;
extern h_cache_file_tag_interop_vtable d3d_vertex_shader_interop_vtable;
extern h_cache_file_tag_interop_vtable d3d_pixel_shader_interop_vtable;
extern h_cache_file_tag_interop_vtable constant_buffer_interop_vtable;
extern h_cache_file_tag_interop_vtable structured_buffer_interop_vtable;
extern h_cache_file_tag_interop_vtable* cache_file_tag_interop_vtable[k_num_interop_types];

class c_interop_container
{
public:
	c_interop_container(e_tag_interop_type interop_type) :
		interop_type(interop_type),
		interop_vtable(cache_file_tag_interop_vtable[interop_type])
	{

	}

	virtual uint32_t get_data_size() const = 0;
	e_tag_interop_type interop_type;
	h_cache_file_tag_interop_vtable* interop_vtable;
};

class c_haloreach_cache_compiler
{
public:
	c_haloreach_cache_compiler(c_tag_project& tag_project, c_haloreach_cache_file* cache_file);
	~c_haloreach_cache_compiler();
	uint32_t calculate_size(h_tag& tag);
	void calculate_object_memory_footprint(uint32_t& memory_footprint, h_object& object);
	uint16_t get_tag_index(const h_tag* tag) const;
	void compile_tag(const h_tag& tag, char* tag_data, uint32_t tag_data_size);
	void compile_object(const h_tag& tag, const h_object& object, char* tag_data, char*& tag_allocation_postion);
	void create_tag_groups();
	void init_tags();
	void create_tag_file_table();
	void pre_compile_tags();
	void compile_tags();
	void compile_string_ids();
	void compile_resources();
	void compile_tag_instances();
	void pre_compile_global_tag_instances();
	void compile_global_tag_instances();
	void pre_compile_interops();
	void compile_interops();


	void compile(const wchar_t* filepath);


protected:
	c_haloreach_cache_file* cache_file;

	static constexpr uint32_t page_address_offset_relative = 0x50000000ull;
	static constexpr uint32_t block_memory_alignment = 16;
	static constexpr uint32_t tag_memory_alignment = 16;

	uint32_t get_tag_pointer_relative_offset(const char* tag_data);
	uint32_t encode_page_offset(uint64_t virtual_address);
	uint64_t decode_page_offset(uint32_t page_offset);

	c_tag_project& tag_project;
	c_string_id_manager& string_id_manager;

	cache_compiler::s_cache_file_metadata& cache_file_metadata;
	std::vector<char> section_data[4];

	uint64_t virtual_base_address;

	// subsections
	uint32_t tags_section_begin_file_offset;
	uint32_t tags_section_tag_data_offset;
	uint32_t tags_section_tags_header_offset;
	uint32_t tags_section_tag_groups_offset;
	uint32_t tags_section_tag_instances_offset;
	uint32_t tags_section_tag_global_instances_offset;
	uint32_t tags_section_api_interop_fixups_offset;
	uint32_t tags_section_api_interop_data_offset;
	uint32_t tags_section_structured_buffer_interops_offset;

	uint32_t debug_section_file_table_offset;
	uint32_t debug_section_file_table_indices_offset;
	uint32_t debug_section_string_ids_offset;
	uint32_t debug_section_string_id_indices_offset;
	uint32_t debug_section_string_id_namespaces_offset;

	// tag groups

	uint32_t tag_group_count;
	uint32_t tag_groups_buffer_size;
	char* tag_groups_buffer;
	cache_compiler::s_cache_file_tag_group* tag_groups;

	// tag data

	char* tag_data_buffer;
	uint32_t tag_data_data_size;
	uint32_t tag_data_buffer_size;

	struct s_tag_data_entry
	{
		h_tag& tag;
		uint32_t tag_data_offset;
		uint32_t tag_data_size;
		char* tag_data;
		uint32_t tag_file_table_offset;
		uint32_t tag_file_table_index;
		uint32_t tag_file_table_datum_index;
		char* tag_file_table_entry;
		cache_compiler::s_cache_file_tag_group* tag_group;
		uint32_t tag_group_index;
		c_fixed_path path;
	};
	s_tag_data_entry* tag_data_entries;
	uint32_t tag_data_entry_count;

	// tag instances

	char* tag_instances_buffer;
	uint32_t tag_instances_data_size;
	uint32_t tag_instances_buffer_size;
	uint32_t tag_instance_count;

	// global tag instances

	char* tag_global_entries_buffer;
	uint32_t tag_global_entries_data_size;
	uint32_t tag_global_entries_buffer_size;
	uint32_t tag_global_entries_count;

	// api interops

	std::map<const h_interop*, uint32_t> interop_page_offsets;
	h_structured_buffer_container* effect_structured_buffer;
	h_structured_buffer_container* beam_structured_buffer;
	h_structured_buffer_container* contrail_structured_buffer;
	h_structured_buffer_container* light_volume_structured_buffer;
	std::vector<c_interop_container*> interop_containers;

	char* tag_api_interops_buffer;
	uint32_t tag_api_interops_data_size;
	uint32_t tag_api_interops_buffer_size;
	char* tag_api_interop_fixups_buffer;
	uint32_t tag_api_interop_fixups_data_size;
	uint32_t tag_api_interop_fixups_buffer_size;
	uint32_t tag_api_interops_count;

	// file table

	char* tag_file_table_buffer; 
	uint32_t tag_file_table_data_size;
	uint32_t tag_file_table_buffer_size;
	char* tag_file_table_indices_buffer;
	uint32_t tag_file_table_indices_buffer_size;
	uint32_t tag_file_table_indices_count;

	// resources

	char* resources_buffer;
	uint32_t resources_data_size;
	uint32_t resources_buffer_size;

	// localization

	char* localization_buffer;
	uint32_t localization_data_size;
	uint32_t localization_buffer_size;

	// string_ids

	uint32_t string_ids_count;
	char* string_ids_indices_buffer;
	uint32_t string_ids_indices_data_size;
	uint32_t string_ids_indices_buffer_size;

	char* string_ids_buffer;
	uint32_t string_ids_data_size;
	uint32_t string_ids_buffer_size;

	uint32_t string_id_namespace_count;
	char* string_id_namespaces_buffer;
	uint32_t string_id_namespaces_data_size;
	uint32_t string_id_namespaces_buffer_size;

};
