#pragma once

class h_group :
	public h_type
{
public:
	h_group(s_engine_platform_build engine_platform_build, blofeld::s_tag_group const& tag_group);

	~h_group();

	BCS_SHARED h_tag& create_tag_instance(const char* filepath);
	BCS_SHARED void associate_tag_instance(h_tag& tag_instance);

	std::vector<h_tag*> tags;
	s_engine_platform_build const engine_platform_build;
	blofeld::s_tag_group const& tag_group;

protected:
	h_group(h_group const&) = default;
};
