#pragma once

class h_tag_instance;

class h_tag_group
{
public:
	BCS_SHARED h_tag_group(s_engine_platform_build engine_platform_build, blofeld::s_tag_group const& tag_group);
	~h_tag_group();

	BCS_SHARED BCS_RESULT create_tag_instance(const char* relative_filepath_without_extension, h_tag_instance*& tag_instance);

	c_mutex mutex;
	std::vector<h_tag_instance*> tags;
	s_engine_platform_build const engine_platform_build;
	blofeld::s_tag_group const& tag_group;

protected:
	BCS_SHARED h_tag_group(h_tag_group const&) = default;
};
