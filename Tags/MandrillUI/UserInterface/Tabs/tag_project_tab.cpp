#include "mandrillui-private-pch.h"
#include "tag_project_tab.export_sounds.inl"

c_tag_project_tab::c_tag_project_tab(const wchar_t* filepath, c_tag_project& tag_project, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Project", "Tag Project", &parent, false),
	tag_project(tag_project),
	user_interface(*search_parent_tab_type<c_mandrill_user_interface>()),
	project_filepath(filepath),
	search_buffer(),
	file_browser(),
	show_export_sounds_file_dialogue(),
	sound_export_wav(),
	sound_export_xma()
{
	const char* tag_filepaths[128] = {};
	uint32_t num_tag_filepaths = _countof(tag_filepaths);
	if (BCS_SUCCEEDED(command_line_get_arguments("autotag", tag_filepaths, num_tag_filepaths)) && num_tag_filepaths > 0)
	{
		for (uint32_t tag_filepath_index = 0; tag_filepath_index < num_tag_filepaths; tag_filepath_index++)
		{
			const char* tag_filepath = tag_filepaths[tag_filepath_index];
			open_tag_by_search_name(tag_filepath);
		}
	}

	if (tag_project.engine_platform_build.engine_type == _engine_type_halo3)
	{
		bool export_wav = BCS_SUCCEEDED(command_line_has_argument_internal("autoexportsoundswav"));
		bool export_xma = BCS_SUCCEEDED(command_line_has_argument_internal("autoexportsoundsxma"));
		if (export_wav || export_xma)
		{
			export_sounds(L"", tag_project, export_wav, export_xma);
		}
	}

}

c_tag_project_tab::~c_tag_project_tab()
{
	delete& tag_project;
}

c_tag_project& c_tag_project_tab::get_tag_project() const
{
	return tag_project;
}

void c_tag_project_tab::open_tag_by_search_name(const char* tag_name)
{
	h_tag_instance* const* tag_instances = nullptr;
	uint32_t num_tag_instances = 0;
	if (BCS_SUCCEEDED(tag_project.get_tag_instances(tag_instances, num_tag_instances)))
	{
		for (uint32_t tag_instance_index = 0; tag_instance_index < num_tag_instances; tag_instance_index++)
		{
			h_tag_instance* tag = tag_instances[tag_instance_index];
			if (_stricmp(tag_name, tag->get_file_path()) == 0)
			{
				open_tag_interface_tab(*tag);
				return;
			}
		}
		for (uint32_t tag_instance_index = 0; tag_instance_index < num_tag_instances; tag_instance_index++)
		{
			h_tag_instance* tag = tag_instances[tag_instance_index];
			if (_stricmp(tag_name, tag->get_file_name()) == 0)
			{
				open_tag_interface_tab(*tag);
				return;
			}
		}
	}
}

c_high_level_tag_tab& c_tag_project_tab::open_tag_interface_tab(h_tag_instance& tag)
{
	for (c_mandrill_tab* tab : children)
	{
		if (c_high_level_tag_tab* high_level_tag_tab = dynamic_cast<c_high_level_tag_tab*>(tab))
		{
			if (&high_level_tag_tab->get_tag() == &tag)
			{
				next_selected_tab = high_level_tag_tab;
				return *high_level_tag_tab;
			}
		}
	}

	c_high_level_tag_tab* high_level_tag_tab = new() c_high_level_tag_tab(tag_project, tag, *this);
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
	if (!ImGui::IsItemActive() && search_buffer.empty())
	{
		draw_list->AddText({ pos.x + 4.0f, pos.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(0.25)), search_reccomendation);
	}
	ImGui::SameLine();
	if (ImGui::Button(ICON_FA_XMARK))
	{
		search_buffer.clear();
	}
	ImGui::SameLine();
	ImGui::Dummy({ 10.0f, 0.0f });
}

void c_tag_project_tab::render_tags_list_search()
{
	h_tag_instance* const* tag_instances = nullptr;
	uint32_t num_tag_instances = 0;
	if (BCS_SUCCEEDED(tag_project.get_tag_instances(tag_instances, num_tag_instances)))
	{
		for (uint32_t tag_instance_index = 0; tag_instance_index < num_tag_instances; tag_instance_index++)
		{
			h_tag_instance* tag = tag_instances[tag_instance_index];
			//const char* tag_path_group_id = tag_interface.get_path_with_group_id_cstr();
			//const char* tag_path_group_name = tag_interface.get_path_with_group_name_cstr();

			//const char* tag_display_with_group_name = user_interface.get_use_full_file_length_display()
			//	? tag_interface.get_path_with_group_name_cstr()
			//	: tag_interface.get_name_with_group_name_cstr();

			if (!search_buffer.empty())
			{
				if (strstr(tag->get_file_path(), search_buffer.c_str()) == nullptr)
				{
					continue;
				}
			}

			bool is_active = search_selected_tag_interface == tag;
			bool selectable_activated = ImGui::Selectable(tag->get_file_path(), is_active, ImGuiSelectableFlags_AllowDoubleClick);

			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				ImGui::Text(tag->get_file_path());
				ImGui::EndTooltip();
			}
			if (selectable_activated && ImGui::IsMouseDoubleClicked((ImGuiMouseButton_Left)))
			{
				search_selected_tag_interface = tag;
				open_tag_interface_tab(*tag);
				search_selected_tag_interface = nullptr;
			}
			if (ImGui::BeginPopupContextItem()) // <-- This is using IsItemHovered()
			{
				if (ImGui::MenuItem("Copy as path"))
				{
					clipboard_set_text(tag->get_file_path());
				}
				ImGui::EndPopup();
			}
		}
	}
}

void c_tag_project_tab::render_tags_list_tree()
{
	h_tag_group* const* groups;
	uint32_t group_count;
	if (BCS_SUCCEEDED(tag_project.get_tag_groups(groups, group_count)))
	{
		for (uint32_t group_index = 0; group_index < group_count; group_index++)
		{
			h_tag_group* group = groups[group_index];
			const uint32_t tag_interfaces_count = static_cast<unsigned long>(group->tags.size());

			const char* group_name = group->blofeld_tag_group.name;
			const char* group_short_name = group->blofeld_tag_group.group_tag_short_string;

			bool display_group = tag_interfaces_count > 0;

			if (!display_group) continue;


			bool tree_node_selected = ImGui::TreeNode(group_short_name, "%s - %s", group_name, group_short_name);
			if (tree_node_selected)
			{
				for (h_tag_instance* tag : group->tags)
				{
					const char* tag_display_with_group_id = tag->get_file_path();

					static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
					if (ImGui::TreeNodeEx(tag, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, "%s", tag_display_with_group_id))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_tag_interface_tab(*tag);
						}
					}
					if (ImGui::BeginPopupContextItem()) // <-- This is using IsItemHovered()
					{
						if (ImGui::MenuItem("Copy as path"))
						{
							clipboard_set_text(tag->get_file_path());
						}
						ImGui::EndPopup();
					}
				}

				ImGui::TreePop();
			}
		}
	}
}

void c_tag_project_tab::render_explorer_bar()
{
	ImGui::Dummy({ 0.0f, 10.0f });

	render_search_box();

	ImGui::Dummy({ 0.0f, 10.0f });
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 25, 8 });
	if (search_buffer.empty())
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
	if (c_mandrill_user_interface::get_show_explorer_bar_setting())
	{
		ImGui::Columns(2, "##navigation");
		ImGui::SetColumnOffset(1, c_mandrill_user_interface::get_explorer_bar_width_setting());
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
			c_mandrill_user_interface::set_explorer_bar_width_setting(ImGui::GetItemRectSize().x + 16.0f);
			
		}
		if (c_mandrill_user_interface::get_explorer_bar_width_setting() < 200.0f)
		{
			c_mandrill_user_interface::set_explorer_bar_width_setting(200.0f + 16.0f);
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

bool c_tag_project_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
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

		if (tag_project.engine_platform_build.engine_type == _engine_type_halo3)
		{
			if (ImGui::MenuItem("Export Sounds"))
			{
				show_export_sounds_file_dialogue = true;
				sound_export_wav = true;
				sound_export_xma = true;
			}
			if (ImGui::MenuItem("Export Sounds (WAV only)"))
			{
				show_export_sounds_file_dialogue = true;
				sound_export_wav = true;
				sound_export_xma = false;
			}
			if (ImGui::MenuItem("Export Sounds (XMA only)"))
			{
				show_export_sounds_file_dialogue = true;
				sound_export_wav = false;
				sound_export_xma = true;
			}
		}


		ImGui::Separator();
	}
	if (menu_render_type == _menu_render_type_root && is_selected())
	{
		if (ImGui::BeginMenu("Project"))
		{
			for (c_mandrill_tab* tab : children)
			{
				tab->render_menu_gui(_menu_render_type_child);
			}

			ImGui::EndMenu();
		}

		for (c_mandrill_tab* tab : children)
		{
			tab->render_menu_gui(_menu_render_type_root);
		}
	}
	return true;
}

void c_tag_project_tab::render_file_dialogue_gui_impl()
{
	if (ImGui::BeginAsyncOpenFolderDialog(&file_browser, "Export Sounds Directory", show_export_sounds_file_dialogue))
	{
		if (ImGui::AsyncFileDialogIsValid())
		{
			const wchar_t* export_directory = ImGui::AsyncFileDialogGetFilepathWideChar();

			export_sounds(export_directory, tag_project, sound_export_wav, sound_export_xma);

			debug_point;
		}
		debug_point;

		ImGui::EndAsyncFileDialog();
	}
	show_export_sounds_file_dialogue = false;
}

void c_tag_project_tab::render_game_layer_impl()
{

}
