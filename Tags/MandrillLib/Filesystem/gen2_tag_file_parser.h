#pragma once

class c_gen2_pseudo_tag_data_chunk;
class c_gen2_tag_block_field_data_chunk;

enum e_tag_file_version
{
	_tag_file_version0,
	_tag_file_version1,
	_tag_file_version2,
	_tag_file_version3,
	_tag_file_version4,
};

enum e_tag_file_version_signature
{
	_tag_file_version_signature0 = 'blam',
	_tag_file_version_signature1 = 'ambl',
	_tag_file_version_signature2 = 'LAMB',
	_tag_file_version_signature3 = 'MLAB',
	_tag_file_version_signature4 = 'BLM!',
};

#define k_tag_block_field_set_definition 'tbfd'
#define k_tag_struct_field_set_definition 'tsdf'

class c_gen2_tag_file_parse_context
{
protected:
	c_gen2_tag_file_parse_context(
		const void* _tag_file_data,
		uint64_t _tag_file_data_size,
		s_engine_platform_build _engine_platform_build);
	c_gen2_tag_file_parse_context() = delete;
	c_gen2_tag_file_parse_context(c_gen2_tag_file_parse_context const&) = delete;
	c_gen2_tag_file_parse_context& operator=(c_gen2_tag_file_parse_context const&) = delete;

public:
	friend c_gen2_pseudo_tag_data_chunk;
	friend c_gen2_tag_block_field_data_chunk;

	BCS_SHARED static BCS_RESULT parse_gen2_tag_file_data(
		h_tag*& tag_prototype,
		const wchar_t* tag_file_path, 
		s_engine_platform_build engine_platform_build);
	BCS_SHARED static BCS_RESULT parse_gen2_tag_file_data(
		h_tag*& tag_prototype,
		const void* tag_file_data, 
		uint64_t tag_file_data_size, 
		s_engine_platform_build engine_platform_build);

protected:
	//BCS_RESULT calculate_tag_struct_definition_size(
	//	blofeld::s_tag_struct_definition const& struct_definition,
	//	s_engine_platform_build engine_platform_build,
	//	uint32_t& tag_struct_definition_size,
	//	uint32_t tag_struct_version) const;
	BCS_RESULT calculate_tag_struct_definition_size2(
		blofeld::s_tag_struct_definition const& tag_struct_definition,
		const char* struct_data_position,
		const char* struct_data_expected_end,
		const char* external_data_position,
		uint32_t& tag_struct_size,
		uint32_t& tag_struct_external_size,
		uint32_t tag_struct_version) const;
	BCS_RESULT calculate_tag_struct_definition_size_iterator(
		blofeld::s_tag_struct_definition const& tag_struct_definition,
		const char*& struct_data_position,
		const char* struct_data_expected_end,
		const char*& external_data_position,
		uint32_t tag_struct_version) const;
	BCS_RESULT traverse_tag_struct(
		const char*& struct_data_position,
		const char* struct_data_expected_end,
		const char*& external_data_position,
		h_prototype& prototype,
		uint32_t struct_version) const;
	BCS_RESULT traverse_tag_block(const char*& global_data_position, h_block& block) const;
	BCS_RESULT traverse_tag_group(h_tag& prototype) const;
	tag get_group_tag() const;
	template<typename t_element> t_element byteswap(t_element value) const { if (is_big_endian) { ::byteswap_inplace(value); } return value; }
	template<typename t_element> void byteswap_inplace(t_element& value) const { if (is_big_endian) { ::byteswap_inplace(value); } }

	bool is_big_endian : 1;
	bool is_little_endian : 1;

	e_tag_file_version tag_file_version;

	const char* tag_file_data_start;
	const char* tag_file_structure_data_start;
	const char* tag_file_data_end;

	s_engine_platform_build engine_platform_build;
	s_tag_file_header_v1 tag_file_header;
};
