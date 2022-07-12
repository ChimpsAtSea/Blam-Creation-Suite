#pragma once

struct s_single_tag_file_header_v1
{
	tag tag_id_unused;
	char tag_name_unused[32];
	tag group_tag;
	unsigned long crc32;
	unsigned long data_offset;
	unsigned long unused30;
	unsigned long unused34;
	unsigned short group_version;
	unsigned char unused3A;
	unsigned char unused3B;
	tag signature;
};
static constexpr size_t k_single_tag_file_header_h1 = sizeof(s_single_tag_file_header_v1);
static_assert(k_single_tag_file_header_h1 == 0x40);

struct c_gen1_tag_file_parse_context
{
protected:
	c_gen1_tag_file_parse_context(
		const void* _tag_file_data,
		unsigned long long _tag_file_data_size,
		s_engine_platform_build _engine_platform_build);
	c_gen1_tag_file_parse_context() = delete;
	c_gen1_tag_file_parse_context(c_gen1_tag_file_parse_context const&) = delete;
	c_gen1_tag_file_parse_context& operator=(c_gen1_tag_file_parse_context const&) = delete;

public:
	BCS_DEBUG_API static BCS_RESULT parse_gen1_tag_file_data(
		h_prototype*& tag_prototype, 
		const wchar_t* tag_file_path, 
		s_engine_platform_build engine_platform_build);
	BCS_DEBUG_API static BCS_RESULT parse_gen1_tag_file_data(
		h_prototype*& tag_prototype,
		const void* tag_file_data, 
		unsigned long long tag_file_data_size, 
		s_engine_platform_build engine_platform_build);

protected:
	BCS_RESULT traverse(h_prototype& prototype) const;
	tag get_group_tag() const;
	BCS_RESULT traverse_tag_struct_data(const char*& global_data_position, h_prototype& prototype) const;
	BCS_RESULT traverse_tag_external_data(const char*& global_data_position, h_prototype& prototype) const;
	template<typename t_element> t_element byteswap(t_element value) const { if (is_big_endian) { ::byteswap_inplace(value); } return value; }
	template<typename t_element> void byteswap_inplace(t_element& value) const { if (is_big_endian) { ::byteswap_inplace(value); } }

	bool is_big_endian : 1;
	bool is_little_endian : 1;

	const char* tag_file_data_start;
	const char* tag_file_structure_data_start;
	const char* tag_file_data_end;

	s_engine_platform_build engine_platform_build;
	s_single_tag_file_header_v1 tag_file_header;
};
