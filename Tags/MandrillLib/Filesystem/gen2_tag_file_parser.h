#pragma once

class c_gen2_pseudo_tag_data_chunk;
class c_gen2_tag_block_field_data_chunk;

class c_gen2_tag_file_parse_context
{
protected:
	c_gen2_tag_file_parse_context(
		const void* _tag_file_data,
		unsigned long long _tag_file_data_size,
		s_engine_platform_build _engine_platform_build);
	c_gen2_tag_file_parse_context() = delete;
	c_gen2_tag_file_parse_context(c_gen2_tag_file_parse_context const&) = delete;
	c_gen2_tag_file_parse_context& operator=(c_gen2_tag_file_parse_context const&) = delete;

public:
	friend c_gen2_pseudo_tag_data_chunk;
	friend c_gen2_tag_block_field_data_chunk;

	static constexpr tag k_signature = 'BLM!';
	static constexpr tag k_signature2 = 'MLAB';
	static constexpr tag k_signature3 = 'LAMB';
	static constexpr tag k_signature4 = 'ambl';

	BCS_DEBUG_API static BCS_RESULT parse_gen2_tag_file_data(
		h_tag*& tag_prototype,
		const wchar_t* tag_file_path, 
		s_engine_platform_build engine_platform_build);
	BCS_DEBUG_API static BCS_RESULT parse_gen2_tag_file_data(
		h_tag*& tag_prototype,
		const void* tag_file_data, 
		unsigned long long tag_file_data_size, 
		s_engine_platform_build engine_platform_build);

protected:
	BCS_RESULT calculate_tag_struct_definition_size(
		const blofeld::s_tag_struct_definition& struct_definition,
		s_engine_platform_build engine_platform_build,
		unsigned long& tag_struct_definition_size,
		unsigned long tag_struct_version) const;
	BCS_RESULT calculate_tag_struct_definition_size2(
		const blofeld::s_tag_struct_definition& tag_struct_definition,
		const char* struct_data_position,
		const char* external_data_position,
		unsigned long& tag_struct_size,
		unsigned long& tag_struct_external_size,
		unsigned long tag_struct_version) const;
	BCS_RESULT calculate_tag_struct_definition_size_iterator(
		const blofeld::s_tag_struct_definition& tag_struct_definition,
		const char*& struct_data_position,
		const char*& external_data_position,
		unsigned long tag_struct_version) const;
	BCS_RESULT traverse_tag_struct(
		const char*& struct_data_position,
		const char*& external_data_position,
		h_prototype& prototype,
		unsigned long struct_version) const;
	BCS_RESULT traverse_tag_block(const char*& global_data_position, h_block& block) const;
	BCS_RESULT traverse_tag_group(h_tag& prototype) const;
	tag get_group_tag() const;
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
