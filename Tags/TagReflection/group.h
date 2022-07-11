#pragma once

class h_group :
	public h_type
{
public:
	h_group(s_engine_platform_build engine_platform_build, const blofeld::s_tag_group& tag_group);

	~h_group();

	BCS_DEBUG_API h_tag& create_tag_instance(const char* filepath);
	BCS_DEBUG_API void associate_tag_instance(h_tag& tag_instance);

	std::vector<h_tag*> tags;
	s_engine_platform_build const engine_platform_build;
	const blofeld::s_tag_group& tag_group;

protected:
	h_group(h_group const&) = default;
};
