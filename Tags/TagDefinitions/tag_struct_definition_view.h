#pragma once

class c_tag_struct_definition_view
{
public:
	s_engine_platform_build const engine_platform_build;
	const blofeld::s_tag_group* tag_group;

	BCS_SHARED c_tag_struct_definition_view(s_engine_platform_build engine_platform_build, const blofeld::s_tag_group* tag_group = nullptr);
	BCS_SHARED ~c_tag_struct_definition_view();

	BCS_SHARED const blofeld::s_tag_struct_definition** get_tag_struct_definitions();
	BCS_SHARED uint32_t get_num_tag_struct_definitions();

protected:

	std::vector<const blofeld::s_tag_struct_definition*> structures;

	void populate_tag_struct_definitions();
	void populate_tag_struct_definitions_iter(const blofeld::s_tag_group& tag_group);
	static void populate_tag_struct_definitions_callback(const blofeld::s_tag_struct_definition& struct_definition, void* userdata_pointer);
};

