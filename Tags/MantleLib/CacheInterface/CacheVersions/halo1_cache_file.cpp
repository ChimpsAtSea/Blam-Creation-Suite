#include "mantlelib-private-pch.h"

#include <zlib/zlib/zlib.h>
#pragma comment(lib, "zlib.lib")

struct s_halo1_compressed_map_header
{
	uint32_t count;
	uint32_t offsets[];
};

struct s_halo1_compressed_chunk_header
{
	uint32_t uncompressed_size;
	char data[];
};

c_halo1_cache_file::c_halo1_cache_file(const std::wstring& map_filepath) :
	c_cache_file(map_filepath)
{
	load_map();
}

c_halo1_cache_file::~c_halo1_cache_file()
{

}

void c_halo1_cache_file::uncompress()
{
	char* compressed_map_data = nullptr;
	bool read_map_successful = filesystem_read_file_to_memory(map_filepath.c_str(), &compressed_map_data);
	ASSERT(read_map_successful);

	s_halo1_compressed_map_header& compressed_header = *reinterpret_cast<s_halo1_compressed_map_header*>(compressed_map_data);

	size_t map_size = 0;
	for (uint32_t i = 0; i < compressed_header.count; i++)
	{
		uint32_t offset = compressed_header.offsets[i];
		s_halo1_compressed_chunk_header& compressed_chunk = *reinterpret_cast<s_halo1_compressed_chunk_header*>(compressed_map_data + offset);
		map_size += compressed_chunk.uncompressed_size;
	}

	virtual_memory_container.set_size(map_size);
	char* map_virtual_data = virtual_memory_container.get_data();
	char* map_data = filesystem_read_to_memory_legacy2(map_filepath.c_str(), map_virtual_data, &map_size);
	char* map_data_end = map_data + map_size;

	char* current_data_position = map_data; // #TODO: TBB Candidate, create array of data positions on stack
	for (uint32_t i = 0; i < compressed_header.count; i++)
	{
		uint32_t offset = compressed_header.offsets[i];
		s_halo1_compressed_chunk_header& compressed_chunk = *reinterpret_cast<s_halo1_compressed_chunk_header*>(compressed_map_data + offset);

		char* compressed_data = compressed_chunk.data;
		char* uncompressed_data = current_data_position;

		z_stream inflate_stream = {};
		inflate_stream.zalloc = Z_NULL;
		inflate_stream.zfree = Z_NULL;
		inflate_stream.opaque = Z_NULL;
		inflate_stream.avail_in = 0xFFFFFFFFu;
		inflate_stream.next_in = reinterpret_cast<Bytef*>(compressed_data);
		inflate_stream.avail_out = compressed_chunk.uncompressed_size;
		inflate_stream.next_out = reinterpret_cast<Bytef*>(uncompressed_data);

		int inflate_init_result = inflateInit(&inflate_stream);
		ASSERT(inflate_init_result >= Z_OK);
		int inflate_result = inflate(&inflate_stream, Z_FINISH);
		ASSERT(inflate_result >= Z_OK);
		int inflate_end_result = inflateEnd(&inflate_stream);
		ASSERT(inflate_end_result >= Z_OK);

		// UNCOMPRESS HERE!

		current_data_position += compressed_chunk.uncompressed_size;

		debug_point;
	}

	delete[] compressed_map_data;
}

void c_halo1_cache_file::load_map()
{
	uncompress();

	char* map_data = virtual_memory_container.get_data();

	header = reinterpret_cast<halo1::s_cache_file_header*>(map_data);
	tags_header = reinterpret_cast<halo1::s_cache_file_tags_header*>(map_data + header->tags_header_address);
	tag_instances = reinterpret_cast<halo1::s_cache_file_tag_instance*>(map_data + header->tags_header_address + convert_page_offset(tags_header->tags_address));

	for (uint32_t i = 0; i < tags_header->tag_count; i++)
	{
		halo1::s_cache_file_tag_instance& tag_instance = tag_instances[i];

		const char* name = map_data + header->tags_header_address + convert_page_offset(tag_instance.name_address);
		debug_point;
	}
}

bool c_halo1_cache_file::save_map()
{
	return false;
}

bool c_halo1_cache_file::is_loading() const
{
	return false;
}

uint64_t c_halo1_cache_file::get_base_virtual_address() const
{
	uint32_t virtual_address = tags_header->tags_address - sizeof(halo1::s_cache_file_tags_header);
	return virtual_address;
}

uint64_t c_halo1_cache_file::convert_page_offset(uint32_t page_offset) const
{
	return static_cast<uint64_t>(page_offset) - get_base_virtual_address();
}

uint32_t c_halo1_cache_file::get_tag_count() const
{
	return tags_header->tag_count;
}

uint32_t c_halo1_cache_file::get_tag_group_count() const
{
	return 0;
}

uint32_t c_halo1_cache_file::get_string_id_count() const
{
	return 0;
}

c_tag_interface* c_halo1_cache_file::get_tag_interface(uint16_t tag_index) const
{
	return nullptr;
}

c_tag_interface* const* c_halo1_cache_file::get_tag_interfaces() const
{
	return nullptr;
}

c_tag_interface* const* c_halo1_cache_file::get_tag_interfaces_sorted_by_name_with_group_id() const
{
	return nullptr;
}

c_tag_interface* const* c_halo1_cache_file::get_tag_interfaces_sorted_by_path_with_group_id() const
{
	return nullptr;
}

c_tag_group_interface* c_halo1_cache_file::get_tag_group_interface(uint16_t group_index) const
{
	return nullptr;
}

c_tag_group_interface* c_halo1_cache_file::get_group_interface_by_group_id(unsigned long tag_group) const
{
	return nullptr;
}

c_tag_group_interface* const* c_halo1_cache_file::get_tag_group_interfaces() const
{
	return nullptr;
}

char* c_halo1_cache_file::get_tag_data(s_tag_data& tag_data) const
{
	return nullptr;
}

char* c_halo1_cache_file::get_tag_block_data(s_tag_block& tag_block) const
{
	return nullptr;
}

const char* c_halo1_cache_file::get_string_id_by_index(uint32_t index) const
{
	return nullptr;
}

const char* c_halo1_cache_file::get_string_id(string_id const id, const char* const error_value /*= nullptr*/) const
{
	return nullptr;
}

const char* c_halo1_cache_file::get_tag_path(uint16_t tag_index) const
{
	return nullptr;
}

unsigned long c_halo1_cache_file::get_tag_group_by_tag_index(uint32_t tag_index) const
{
	return blofeld::INVALID_TAG;
}

const s_section_cache* c_halo1_cache_file::get_section(uint32_t section_index) const
{
	return nullptr;
}

const s_section_cache& c_halo1_cache_file::get_section(e_haloreach_cache_file_section_index cache_file_section) const
{
	return *get_section(0);
}

void* c_halo1_cache_file::get_internal_tag_instance_impl(uint16_t tag_index) const
{
	return nullptr;
}

void* c_halo1_cache_file::get_internal_tag_group_impl(uint32_t group_index) const
{
	return nullptr;
}
