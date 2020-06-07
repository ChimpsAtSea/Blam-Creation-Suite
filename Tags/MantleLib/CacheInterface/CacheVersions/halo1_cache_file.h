#pragma once

namespace halo1
{
	enum class e_cache_file_version : long
	{
		_invalid = 0,

		_halo_xbox = 5,
		_halo_pc = 7,
		_halo_2 = 8,
		_halo_3_beta = 9,
		_halo_3 = 11,
		_halo_reach = 12,
		_halo_online = 18,
		_halo_custom_edition = 609
	};

	enum class e_cache_file_type : short
	{
		_none = -1,

		_campaign,
		_multiplayer,
		_main_menu,
		_shared,
		_shared_campaign,
		_unknown5,
		_unknown6,

		k_number_of_cache_file_types
	};

	enum class e_cache_file_shared_type : short
	{
		_none = -1,
		_main_menu,
		_shared,
		_campaign,

		k_number_of_cache_file_shared_types
	};

	struct s_cache_file_header
	{
		unsigned long header_signature;                 // 'head'
		e_cache_file_version file_version;
		long file_length;
		long file_compressed_length;
		unsigned long tags_header_address;
		long tag_data_size;
		long memory_buffer_offset;
		long memory_buffer_size;
		char name[32];
		char build[32];
		e_cache_file_type scenario_type;
		e_cache_file_shared_type shared_type;
		unsigned long __unknown64;                      // unknown
		char __unknown68[1940];                         // unknown padding?
		unsigned long footer_signature;                 // 'foot'
	};

	struct datum_index
	{
		short index;
		short identifier;
	};

	struct s_cache_file_tag_instance
	{
		unsigned long group_tags[3];                    // group, parent, grandparent
		datum_index handle;                             // salt, index

		unsigned long name_address;                     // offset to string, ptr32_t<char> name
		unsigned long base_address;                     // offset to data, union { ptr32_t<void> base_address; long index_in_data_file };

		bool bool_in_data_file;
		char : 8;
		char : 8;
		char : 8;

		long : 32;
	};

	struct s_cache_file_tags_header
	{
		unsigned long tags_address;                     // ptr32_t<void>, 0x40448028, g_tags_address is 0x40448000
		long scenario_index;
		unsigned long checksum;
		long tag_count;
		long geometry_vertices_count;
		long geometry_vertices_offset;
		long geometry_indices_count;
		long geometry_indices_offset;
		long geometry_data_total_size;
		unsigned long signature;                        // 'tags'
	};
}

class c_halo1_cache_file : 
	public c_cache_file
{
	friend c_cache_file;
protected:
	c_halo1_cache_file(const std::wstring& map_filepath);
	virtual ~c_halo1_cache_file();

public:
	void uncompress();
	void load_map();
	virtual bool save_map() final;
	virtual bool is_loading() const final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;
	virtual uint32_t get_tag_count() const final;
	virtual uint32_t get_tag_group_count() const final;
	virtual uint32_t get_string_id_count() const final;
	virtual c_tag_interface* get_tag_interface(uint16_t tag_index) const final;
	virtual c_tag_interface* const* get_tag_interfaces() const final;
	virtual c_tag_interface* const* get_tag_interfaces_sorted_by_name_with_group_id() const final;
	virtual c_tag_interface* const* get_tag_interfaces_sorted_by_path_with_group_id() const final;
	virtual c_tag_group_interface* get_tag_group_interface(uint16_t group_index) const final;
	virtual c_tag_group_interface* get_group_interface_by_group_id(unsigned long tag_group) const final;
	virtual c_tag_group_interface* const* get_tag_group_interfaces() const final;
	virtual char* get_tag_data(s_tag_data& tag_data) const final;
	virtual char* get_tag_block_data(s_tag_block& tag_block) const final;
	virtual const char* get_string_id_by_index(uint32_t index) const final;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const final;
	virtual const char* get_tag_path(uint16_t tag_index) const final;
	virtual unsigned long get_tag_group_by_tag_index(uint32_t tag_index) const final;

	virtual const s_section_cache* get_section(uint32_t section_index) const final;
	const s_section_cache& get_section(e_haloreach_cache_file_section_index cache_file_section) const;
	inline const s_section_cache& get_debug_section() const { return get_section(_haloreach_cache_file_section_index_debug); };
	inline const s_section_cache& get_tags_section() const { return get_section(_haloreach_cache_file_section_index_tags); };
	inline const s_section_cache& get_resources_section() const { return get_section(_haloreach_cache_file_section_index_resource); };
	inline const s_section_cache& get_localization_section() const { return get_section(_haloreach_cache_file_section_index_localization); };	
	
	inline s_cache_file_tag_instance* get_internal_tag_instance(uint16_t tag_index) const
	{
		return static_cast<s_cache_file_tag_instance*>(get_internal_tag_instance_impl(tag_index));
	}
	inline s_cache_file_tag_group* get_internal_tag_group(uint32_t group_index) const
	{
		return static_cast<s_cache_file_tag_group*>(get_internal_tag_group_impl(group_index));
	}

protected:
	virtual void* get_internal_tag_instance_impl(uint16_t tag_index) const final;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const final;

protected:
	halo1::s_cache_file_header* header;
	halo1::s_cache_file_tags_header* tags_header;
	halo1::s_cache_file_tag_instance* tag_instances;
};

