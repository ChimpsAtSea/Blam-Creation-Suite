#include "mantlelib-private-pch.h"



c_mantle_shader_halogram_gui_tab::c_mantle_shader_halogram_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, v_tag_interface_legacy<s_shader_halogram_definition_legacy>& shader_tag_interface) :
	c_mantle_gui_tab("Shader Halogram Editor", "Shader Halogram Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	shader_tag_interface(shader_tag_interface)
{

	allow_close = false;
}

c_mantle_shader_halogram_gui_tab::~c_mantle_shader_halogram_gui_tab()
{

}

void c_mantle_shader_halogram_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Shader Editor");

	v_tag_interface_legacy<s_render_method_definition_definition_legacy>* render_method_definition = tag_cast<s_render_method_definition_definition_legacy>(&shader_tag_interface.base_render_method_reference);

	if (render_method_definition == nullptr)
	{
		ImGui::Text("Failed to find render_method_definition");
		return;
	}


	s_shader_halogram_definition_legacy::s_shader_properties_definition_legacy& shader_properties = shader_tag_interface.shader_properties_block[0];
	
	uint32_t option_index = 0;
	uint32_t shader_map_index = 0;
	for (s_shader_halogram_definition_legacy::s_unknown_definition_legacy& unknown : shader_tag_interface.__unknown1)
	{
		uint16_t option_value = unknown.__unknown0;

		if (option_value < render_method_definition->unknown_0_block.count)
		{
			s_render_method_definition_definition_legacy::s_unknown_0_definition_legacy& rmdf_unknown0 = render_method_definition->unknown_0_block[option_index];

			// #TODO: Generate code to make accessing a tag block virtual
			c_virtual_tag_block<s_render_method_definition_definition_legacy::s_unknown_0_definition_legacy::s_unknown_1_definition_legacy> unknown_1_block(cache_file, *render_method_definition, rmdf_unknown0.unknown_1_block);

			//s_render_method_definition_definition::s_unknown_0_definition::s_unknown_1_definition& unknown1 = rmdf_unknown0.unknown_1_block[option_value];
			s_render_method_definition_definition_legacy::s_unknown_0_definition_legacy::s_unknown_1_definition_legacy& unknown1 = unknown_1_block[option_value];

			const char* option_name = cache_file.string_id_to_cstr(rmdf_unknown0.__unknown0, "<failed to get option name>");
			const char* option_value = cache_file.string_id_to_cstr(unknown1.__unknown0, "<failed to get option value>");

			c_tag_interface* rmop_interface = cache_file.get_tag_interface(unknown1.__unknown1.index); // #TODO block virtual interface
			v_tag_interface_legacy<s_render_method_option_definition_legacy>* rmop = tag_cast<s_render_method_option_definition_legacy>(rmop_interface);

			char buffer[256]{};
			snprintf(buffer, 255, "%s: %s", option_name, option_value);
			if (rmop && ImGui::CollapsingHeader(buffer, ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap))
			{
				ImGui::Text("---------- shader maps ------------");

				for (s_render_method_option_definition_legacy::s_unknown_0_definition_legacy& option : rmop->unknown_0_block)
				{
					c_tag_interface* rmop_default_bitm_interface = cache_file.get_tag_interface(option.__unknown4.index); // #TODO block virtual interface
					v_tag_interface_legacy<s_bitmap_definition_legacy>* rmop_default_bitm = tag_cast<s_bitmap_definition_legacy>(rmop_default_bitm_interface);

					if (rmop_default_bitm != nullptr)
					{
						// render_tagref_gui_legacy(&option.__unknown4, bitmap_name, cache_file);
#undef auto

						//c_cache_file& cache_file, c_tag_interface& tag_interface, s_tag_block_legacy<t_value>& tag_block

						c_virtual_tag_block<s_shader_halogram_definition_legacy::s_shader_properties_definition_legacy::s_shader_maps_definition_legacy> shader_map_block(cache_file, shader_tag_interface, shader_properties.shader_maps_block);


						s_shader_halogram_definition_legacy::s_shader_properties_definition_legacy::s_shader_maps_definition_legacy& shader_map = shader_map_block[(size_t)shader_map_index];

						const char* bitmap_name = cache_file.string_id_to_cstr(option.__unknown0);

						ImGui::Text("bitmap: %s", bitmap_name);

						render_tagref_gui_legacy(&shader_map.bitmap_reference, bitmap_name, cache_file);

						shader_map_index++;
					}
				}
			}

		}
		else
		{
			ImGui::Text("rmdf option index out of range");
		}

		ImGui::Text("");

		option_index++;
	}











}
