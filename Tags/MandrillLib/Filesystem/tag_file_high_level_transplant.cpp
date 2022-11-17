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

BCS_RESULT c_tag_file_high_level_transplant::parse_tag(h_tag_instance*& high_level_tag)
{
	BCS_RESULT rs = BCS_S_OK;

	blofeld::s_tag_group const* tag_group;
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_get_tag_group_by_engine_platform_build(engine_platform_build, high_level_tag_file_reader->header.group_tag, tag_group)))
	{
		return rs;
	}

	h_tag_group* high_level_group = new() h_tag_group(engine_platform_build, *tag_group);

	high_level_tag_file_reader->parse_high_level_object(high_level_tag);

	//high_level_group->associate_tag_instance(*high_level_tag);

	return rs;
}
