#include "mantlelib-private-pch.h"



c_mantle_shader_gui_tab::c_mantle_shader_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tag, v_tag_interface<s_shader_definition>& shader_tag_interface) :
	c_mantle_gui_tab("Shader Editor", "Shader Editor"),
	cache_file(cache_file),
	parent_tag(parent_tag),
	shader_tag_interface(shader_tag_interface)
{

	allow_close = false;
}

c_mantle_shader_gui_tab::~c_mantle_shader_gui_tab()
{

}

void c_mantle_shader_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Shader Editor");

	v_tag_interface<s_render_method_definition_definition>* render_method_definition = tag_cast<s_render_method_definition_definition>(&shader_tag_interface.base_render_method_reference);

	if (render_method_definition == nullptr)
	{
		ImGui::Text("Failed to find render_method_definition");
		return;
	}

	uint32_t option_index = 0;
	for (s_shader_definition::s_unknown_definition& unknown : shader_tag_interface.__unknown1)
	{
		uint16_t option_value = unknown.__unknown0;

		if (option_value < render_method_definition->unknown_0_block.count)
		{
			s_render_method_definition_definition::s_unknown_0_definition& rmdf_unknown0 = render_method_definition->unknown_0_block[option_index];

			// #TODO: Generate code to make accessing a tag block virtual
			c_virtual_tag_block<s_render_method_definition_definition::s_unknown_0_definition::s_unknown_1_definition> unknown_1_block(cache_file, *render_method_definition, rmdf_unknown0.unknown_1_block);

			//s_render_method_definition_definition::s_unknown_0_definition::s_unknown_1_definition& unknown1 = rmdf_unknown0.unknown_1_block[option_value];
			s_render_method_definition_definition::s_unknown_0_definition::s_unknown_1_definition& unknown1 = unknown_1_block[option_value];

			const char* option_name = cache_file.string_id_to_cstr(rmdf_unknown0.__unknown0, "<failed to get option name>");
			const char* option_value = cache_file.string_id_to_cstr(unknown1.__unknown0, "<failed to get option value>");

			ImGui::Text("option_name %s", option_name);
			ImGui::Text("option_value %s", option_value);

		}
		else
		{
			ImGui::Text("rmdf option index out of range");
		}

		option_index++;
	}










}
