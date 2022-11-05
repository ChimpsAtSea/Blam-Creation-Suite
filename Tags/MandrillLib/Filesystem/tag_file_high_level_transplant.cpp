#include "mandrilllib-private-pch.h"

c_tag_file_high_level_transplant::c_tag_file_high_level_transplant(const char* filepath, s_engine_platform_build engine_platform_build) :
	tag_file_data(),
	tag_file_data_size(),
	high_level_tag_file_reader(),
	engine_platform_build(engine_platform_build)
{
	BCS_FAIL_THROW(filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size));
	ASSERT(tag_file_data_size > (sizeof(s_tag_file_header) + sizeof(tag)));

	c_stopwatch s;
	s.start();

	high_level_tag_file_reader = new() c_high_level_tag_file_reader(
		engine_platform_build,
		tag_file_data,
		nullptr,
		nullptr);

	s.stop();
	float ms = s.get_miliseconds();
	console_write_line("Processed chunks in %.2f ms", ms);
}

c_tag_file_high_level_transplant::~c_tag_file_high_level_transplant()
{

}

h_tag* c_tag_file_high_level_transplant::parse_tag()
{
	const blofeld::s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, high_level_tag_file_reader->header.group_tag);
	h_group* high_level_group = new() h_group(engine_platform_build, *tag_group);

	h_tag* high_level_tag;
	high_level_tag_file_reader->parse_high_level_object(high_level_tag);

	high_level_group->associate_tag_instance(*high_level_tag);

	return high_level_tag;
}
