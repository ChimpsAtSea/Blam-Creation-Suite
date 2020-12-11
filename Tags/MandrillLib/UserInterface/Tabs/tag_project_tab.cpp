#include "mandrilllib-private-pch.h"

using namespace DirectX;

c_tag_project_tab::c_tag_project_tab(const wchar_t* filepath, c_tag_project& tag_project, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Project", "Tag Project", &parent, false),
	tag_project(tag_project),
	user_interface(*search_parent_tab_type<c_mandrill_user_interface>()),
	project_filepath(filepath),
	search_buffer()
{
	
}

c_tag_project_tab::~c_tag_project_tab()
{

}

c_tag_project& c_tag_project_tab::get_tag_project() const
{
	return tag_project;
}

void c_tag_project_tab::open_tag_by_search_name(const char* tag_name)
{
	for (h_tag* tag : tag_project.tags)
	{
		bool is_match =
			_stricmp(tag_name, tag->tag_filepath.c_str()) == 0 ||
			_stricmp(tag_name, tag->tag_filename.c_str()) == 0;
		if (is_match)
		{
			open_tag_interface_tab(*tag);
			return;
		}
	}
}

c_high_level_tag_tab& c_tag_project_tab::open_tag_interface_tab(h_tag& tag)
{
	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		if (c_high_level_tag_tab* high_level_tag_tab = dynamic_cast<c_high_level_tag_tab*>(&tab))
		{
			if (&high_level_tag_tab->get_tag() == &tag)
			{
				next_selected_tab = high_level_tag_tab;
				return *high_level_tag_tab;
			}
		}
	}

	c_high_level_tag_tab* high_level_tag_tab = new c_high_level_tag_tab(tag_project, tag, *this);
	add_tab(*high_level_tag_tab);
	next_selected_tab = high_level_tag_tab;

	return *high_level_tag_tab;
}

void c_tag_project_tab::render_search_box()
{
	const char* search_reccomendation = "<search for tag>";
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImGui::Dummy({ 10.0f, 0.0f });
	ImGui::SameLine();
	ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - 75.0f);
	ImGuiInputTextFlags input_text_flags = 0;
	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImGui::InputText("##Search", search_buffer.str(), search_buffer.capacity(), input_text_flags);
	if (!ImGui::IsItemActive() && search_buffer.is_empty())
	{
		draw_list->AddText({ pos.x + 4.0f, pos.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(0.25)), search_reccomendation);
	}
	ImGui::SameLine();
	if (ImGui::Button(ICON_FA_TIMES))
	{
		search_buffer.clear();
	}
	ImGui::SameLine();
	ImGui::Dummy({ 10.0f, 0.0f });
}

void c_tag_project_tab::render_tags_list_search()
{
	for (h_tag* tag : tag_project.tags)
	{
		//const char* tag_path_group_id = tag_interface.get_path_with_group_id_cstr();
		//const char* tag_path_group_name = tag_interface.get_path_with_group_name_cstr();

		//const char* tag_display_with_group_name = user_interface.get_use_full_file_length_display()
		//	? tag_interface.get_path_with_group_name_cstr()
		//	: tag_interface.get_name_with_group_name_cstr();

		//if (!search_buffer.is_empty())
		//{
		//	if (strstr(tag_path_group_name, search_buffer.c_str()) == nullptr && strstr(tag_path_group_id, search_buffer.c_str()) == nullptr)
		//	{
		//		continue;
		//	}
		//}

		bool is_active = search_selected_tag_interface == tag;
		bool selectable_activated = ImGui::Selectable(tag->tag_filepath.c_str(), is_active, ImGuiSelectableFlags_AllowDoubleClick);

		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::Text(tag->tag_filepath.c_str());
			ImGui::EndTooltip();
		}
		if (selectable_activated && ImGui::IsMouseDoubleClicked((ImGuiMouseButton_Left)))
		{
			search_selected_tag_interface = tag;
			open_tag_interface_tab(*tag);
			search_selected_tag_interface = nullptr;
		}
	}
}

void c_tag_project_tab::render_tags_list_tree()
{
	for (h_group* group : tag_project.groups)
	{
		const uint32_t tag_interfaces_count = static_cast<uint32_t>(group->tags.size());

		const char* group_name = group->tag_group.name;
		const char* group_short_name = group->tag_group.group_tag_str.c_str();

		bool display_group = tag_interfaces_count > 0;

		if (!display_group) continue;


		bool tree_node_selected = ImGui::TreeNode(group_short_name, "%s - %s", group_name, group_short_name);
		if (tree_node_selected)
		{
			for (h_tag* tag : group->tags)
			{
				const char* tag_display_with_group_id = tag->tag_filepath.c_str();

				static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
				if (ImGui::TreeNodeEx(tag, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, "%s", tag_display_with_group_id))
				{
					if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
					{
						open_tag_interface_tab(*tag);
					}
				}
			}

			ImGui::TreePop();
		}
	}
}

void c_tag_project_tab::render_explorer_bar()
{
	ImGui::Dummy({ 0.0f, 10.0f });

	render_search_box();

	ImGui::Dummy({ 0.0f, 10.0f });
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 25, 8 });
	if (search_buffer.is_empty())
	{
		if (ImGui::BeginTabBar("##fileview"))
		{
			if (ImGui::BeginTabItem("Tags"))
			{
				ImGui::Dummy({ 0.0f, 1.0f });
				ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4, 4 });

				ImGui::BeginChild("left column", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar);

				render_tags_list_tree();

				ImGui::EndChild();

				ImGui::PopStyleVar();
				ImGui::EndTabItem();
			}


			ImGui::EndTabBar();
		}
	}
	else
	{
		ImGui::BeginChild("left column", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar);

		render_tags_list_search();

		ImGui::EndChild();

	}
	ImGui::PopStyleVar();
}

void c_tag_project_tab::render_impl()
{
	if (c_mandrill_user_interface::show_explorer_bar)
	{
		ImGui::Columns(2, "##navigation");
		ImGui::SetColumnOffset(1, c_mandrill_user_interface::explorer_bar_width);
		ImGui::Separator();
		{
			ImGui::BeginGroup();
			ImVec2 size = ImGui::GetContentRegionAvail();
			if (size.x < 200.0f)
			{
				size.x = 200.0f;
			}
			ImGui::BeginChild("left column", size, false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

			render_explorer_bar();

			ImGui::EndChild();
			ImGui::EndGroup();
		}
		if (ImGui::IsMouseDragging(ImGuiMouseButton_Left))
		{
			c_mandrill_user_interface::explorer_bar_width = ImGui::GetItemRectSize().x + 16.0f;
			c_settings::write_float(_settings_section_mandrill, c_mandrill_user_interface::k_explorer_bar_width, c_mandrill_user_interface::explorer_bar_width);
		}
		if (c_mandrill_user_interface::explorer_bar_width < 200.0f)
		{
			c_mandrill_user_interface::explorer_bar_width = 200.0f + 16.0f;
		}
		ImGui::NextColumn();
	}
	{
		ImGui::BeginGroup();
		ImGui::BeginChild("right column", {}, false);

		if (ImGui::BeginTabBar("##tagsview"))
		{
			c_mandrill_tab* select_tab = next_selected_tab;
			next_selected_tab = nullptr; // take a copy here as child render calls can set this value
			//for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
			// ###HACK This is super bad, but the memory is being resized during runtime.
			// this needs to be replaced with a thread safe linked list
			std::vector<c_mandrill_tab*> _children = children;
			for (c_mandrill_tab* tab : _children)
			{
				tab->render(tab == select_tab);
			}

			ImGui::EndTabBar();
		}

		ImGui::EndChild();
		ImGui::EndGroup();
		ImGui::Columns(1);
	}
}

void c_tag_project_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root_file && is_selected())
	{
		if (ImGui::MenuItem("Close Project"))
		{
			_is_open = false;
		}
		ImGui::Separator();

		ImGui::MenuItem("New Tag");
		ImGui::Separator();

		ImGui::MenuItem("Compile Cache File");
		ImGui::Separator();
	}
	if (menu_render_type == _menu_render_type_root && is_selected())
	{
		if (ImGui::BeginMenu("Project"))
		{
			for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
			{
				tab.render_menu_gui(_menu_render_type_child);
			}

			ImGui::EndMenu();
		}

		for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		{
			tab.render_menu_gui(_menu_render_type_root);
		}
	}
}

void c_tag_project_tab::render_file_dialogue_gui_impl()
{

}

void c_tag_project_tab::render_game_layer_impl()
{

}
