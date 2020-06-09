#include "mantlelib-private-pch.h"

c_mantle_tag_gui_tab::c_mantle_tag_gui_tab(c_cache_file& cache_file, c_tag_interface& tag_interface, c_mantle_gui_tab* parent_tab) : 
	c_mantle_gui_tab(tag_interface.get_name_with_group_id_cstr(), tag_interface.get_path_with_group_name_cstr()),
	tag_interface(tag_interface),
	cache_file(cache_file),
	parent_tab(parent_tab)
{
	if (v_tag_interface<blofeld::haloreach::s_bitmap_block_struct>* bitmap_tag_interface = dynamic_cast<decltype(bitmap_tag_interface)>(&tag_interface))
	{
		c_mantle_bitmap_gui_tab* mantle_bitmap_gui_tab = new c_mantle_bitmap_gui_tab(cache_file, this, *bitmap_tag_interface);
		ASSERT(mantle_bitmap_gui_tab != nullptr);
		add_tab(*mantle_bitmap_gui_tab);
	}

	const blofeld::s_tag_group* blofeld_reflection = tag_interface.get_blofeld_reflection_data();
	if (blofeld_reflection)
	{
		c_mantle_blofeld_tag_editor_gui_tab* blofeld_tag_editor_gui_tab = new c_mantle_blofeld_tag_editor_gui_tab(cache_file, this, tag_interface);
		ASSERT(blofeld_tag_editor_gui_tab != nullptr);
		add_tab(*blofeld_tag_editor_gui_tab);
	}
}

c_mantle_tag_gui_tab::~c_mantle_tag_gui_tab()
{
	for (c_imgui_dynamic_data* dynamic_data : imgui_dynamic_data)
	{
		delete dynamic_data;
	}
}

//void c_mantle_tag_gui_tab::copy_data_recursively(const s_reflection_structure_type_legacy& reflection_type, char* source, char* destination)
//{
//	// #TODO: Package up all of the tag data into a single packet
//	// #TODO: Patch the tag address table to make room for extra data
//
//	memcpy(destination, source, reflection_type.size_of_data);
//
//	for (size_t i = 0; i < reflection_type.members_count; i++)
//	{
//		const c_reflection_field_legacy& reflection_field = reflection_type.fields[i];
//		const s_reflection_structure_type_info_legacy& type_info = reflection_field.type_info;
//
//		if (!reflection_field.array_size)
//		{
//			if (type_info.legacy_reflection_type_category == _legacy_reflection_type_category_tag_block)
//			{
//				s_tag_block_legacy<>* tag_block = reinterpret_cast<s_tag_block_legacy<>*>(source + reflection_field.offset);
//				const s_reflection_tag_block_info_legacy& rs_reflection_tag_block_info_legacy = reflection_field.tag_block_info;
//				const s_reflection_structure_type_legacy* tag_block_reflection_type = rs_reflection_tag_block_info_legacy.reflection_type;
//
//				if (tag_block->count && tag_block->address)
//				{
//					char* pTagBlockDataSource = cache_file.get_tag_block_data<char>(*tag_block); // #TODO: Remove get_tag_block_data and replace with virtual tag interface/virtual tab block data access
//					char* pTagBlockDataDest = c_mantle_gui::get_tag_selection_address(tag_block->address);
//
//					if (IsBadReadPtr(pTagBlockDataSource, tag_block_reflection_type->size_of_data))
//					{
//						c_console::write_line_verbose("poke> warning: failed to poke memory address 0x%p (IsBadReadPtr pTagBlockDataSource) '%s'", pTagBlockDataSource, reflection_field.name);
//					}
//					else if(IsBadWritePtr(pTagBlockDataDest, tag_block_reflection_type->size_of_data))
//					{
//						c_console::write_line_verbose("poke> warning: failed to poke memory address 0x%p (IsBadWritePtr pTagBlockDataDest) '%s'", pTagBlockDataDest, reflection_field.name);
//					}
//					else
//					{
//						c_console::write_line_verbose("poke> pushed block '%s'", reflection_field.name);
//						for (uint32_t i = 0; i < tag_block->count; i++)
//						{
//							//memcpy(pTagBlockDest, pTagBlockDataSource, tag_block_reflection_type->m_size);
//							uint32_t offset = tag_block_reflection_type->size_of_data * i;
//							copy_data_recursively(*tag_block_reflection_type, pTagBlockDataSource + offset, pTagBlockDataDest + offset);
//						}
//					}
//				}
//			}
//		}
//	}
//}

void c_mantle_tag_gui_tab::send_to_game()
{
	char* pDest = static_cast<char*>(c_mantle_gui::get_tag_pointer(get_tag_interface().get_index()));
	if (pDest)
	{
		char* pSource = get_tag_interface().get_data();;

		//const s_reflection_structure_type_legacy* ps_reflection_structure_type_legacy = tag_interface.get_legacy_reflection_data();
		//copy_data_recursively(*ps_reflection_structure_type_legacy, pSource, pDest);

		c_console::write_line_verbose("Successfully poked tag '%s'", get_tag_interface().get_name_with_group_id_cstr());
	}
	else
	{
		c_console::write_line_verbose("Failed to poke tag '%s' as pDest was null", get_tag_interface().get_name_with_group_id_cstr());
	}

}

void c_mantle_tag_gui_tab::render_tab_contents_gui()
{
	if (child_tabs.empty())
	{
		ImGui::Text("No supported editors");
		return;
	}

	if (ImGui::BeginTabBar("##TagEditorTabs", ImGuiTabBarFlags_None)) // each tag
	{
		for (c_mantle_gui_tab* mantle_gui_tab : child_tabs)
		{
			mantle_gui_tab->render_gui(false);
		}

		ImGui::EndTabBar();
	}
}

void c_mantle_tag_gui_tab::RenderButtons()
{
	if (c_mantle_gui::is_game())
	{
		if (!is_selected) return;

		if (ImGui::Button("Push"))
		{
			send_to_game();
		}
	}
}
