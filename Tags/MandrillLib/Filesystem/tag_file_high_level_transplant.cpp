#include "mandrilllib-private-pch.h"

c_tag_file_high_level_transplant::c_tag_file_high_level_transplant(const char* filepath, s_engine_platform_build engine_platform_build) :
	tag_file_data(),
	tag_file_data_size(),
	header_data(),
	layout_reader(),
	reader(),
	engine_platform_build(engine_platform_build)
{
	BCS_FAIL_THROW(filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size));
	ASSERT(tag_file_data_size > (sizeof(s_single_tag_file_header) + sizeof(tag)));
	header_data = static_cast<s_single_tag_file_header*>(tag_file_data);
	ASSERT(header_data->blam == 'BLAM');

	static constexpr tag k_tag_file_root_data_stream_tag = 'tag!';
	tag root_node_tag = *reinterpret_cast<tag*>(header_data + 1);
	bool is_little_endian_tag = root_node_tag == k_tag_file_root_data_stream_tag;
	bool is_big_endian_tag = byteswap(root_node_tag) == k_tag_file_root_data_stream_tag;
	ASSERT(is_little_endian_tag || is_big_endian_tag);

	c_stopwatch s;
	s.start();

	layout_reader = new() c_single_tag_file_layout_reader(*header_data, header_data);

	reader = new() c_single_tag_file_reader(
		*header_data,
		engine_platform_build,
		is_big_endian_tag,
		*layout_reader,
		*layout_reader->binary_data_chunk,
		nullptr,
		nullptr);

	s.stop();
	float ms = s.get_miliseconds();
	console_write_line("Processed chunks in %.2f ms", ms);

	//tag_group_layout_chunk->log(layout_reader->string_data_chunk);
	//binary_data_chunk->log(layout_reader->string_data_chunk);


	debug_point;
}

c_tag_file_high_level_transplant::~c_tag_file_high_level_transplant()
{

}

h_tag* c_tag_file_high_level_transplant::parse_tag()
{
	const blofeld::s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build.engine_type, header_data->group_tag);
	h_group* high_level_group = new() h_group(engine_platform_build, *tag_group);

	h_tag* high_level_tag;
	reader->parse_high_level_object(high_level_tag);
	debug_point;

	high_level_group->associate_tag_instance(*high_level_tag);

	return high_level_tag;
}
