#pragma once

class c_tag_struct_definition_view
{
public:
	s_engine_platform_build const engine_platform_build;
	const blofeld::s_tag_group* tag_group;

	BCS_DEBUG_API c_tag_struct_definition_view(s_engine_platform_build engine_platform_build, const blofeld::s_tag_group* tag_group = nullptr);
	BCS_DEBUG_API ~c_tag_struct_definition_view();

	BCS_DEBUG_API const blofeld::s_tag_struct_definition** get_tag_struct_definitions();
	BCS_DEBUG_API unsigned long get_num_tag_struct_definitions();

protected:

	std::vector<const blofeld::s_tag_struct_definition*> structures;

	void populate_tag_struct_definitions();
	void populate_tag_struct_definitions_iter(const blofeld::s_tag_group& tag_group);
	static void populate_tag_struct_definitions_callback(const blofeld::s_tag_struct_definition& struct_definition, void* userdata_pointer);
};

