#include "mandrilllib-private-pch.h"

c_tag_file_high_level_transplant::c_tag_file_high_level_transplant(const char* filepath)
{
	BCS_FAIL_THROW(filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size));
	ASSERT(tag_file_data_size > (sizeof(s_single_tag_file_header) + sizeof(tag)));
	header_data = static_cast<s_single_tag_file_header*>(tag_file_data);
	ASSERT(header_data->blam == 'BLAM');

	static constexpr tag k_tag_file_root_data_stream_tag = 'tag!';
	tag root_node_tag = *reinterpret_cast<tag*>(header_data + 1);
	ASSERT(root_node_tag == k_tag_file_root_data_stream_tag);

	engine_platform_build = { _engine_type_halo3 };

	c_stopwatch s;
	s.start();

	root_chunk = new c_tag_header_chunk(header_data + 1);
	tag_group_layout_chunk = root_chunk->find_first_chunk<c_tag_group_layout_chunk>();
	binary_data_chunk = root_chunk->find_first_chunk<c_binary_data_chunk>();

	ASSERT(tag_group_layout_chunk != nullptr);
	ASSERT(binary_data_chunk != nullptr);

	layout_reader = new c_single_tag_file_layout_reader(*tag_group_layout_chunk);

	reader = new c_single_tag_file_reader(
		*header_data,
		engine_platform_build,
		*layout_reader,
		*binary_data_chunk);

	s.stop();
	float ms = s.get_miliseconds();
	console_write_line("Processed chunks in %.2f ms", ms);

	//tag_group_layout_chunk->log(layout_reader->string_data_chunk);
	//binary_data_chunk->log(layout_reader->string_data_chunk);

	h_tag* high_level_tag;
	reader->parse_high_level_object(high_level_tag);
	debug_point;
}

c_tag_file_high_level_transplant::~c_tag_file_high_level_transplant()
{

}