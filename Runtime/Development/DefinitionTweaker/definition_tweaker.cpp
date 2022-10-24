#include "definitiontweaker-private-pch.h"

template<typename t_enum, typename t_storage, const int k_number_of_bits>
static void imgui_checkbox_cflags(const char* name, c_flags<t_enum, t_storage, k_number_of_bits>& flags, t_enum bit)
{
	bool is_set = flags.test(bit);
	if (ImGui::Checkbox(name, &is_set))
	{
		flags.set(bit, is_set);
	}
}

static bool imgui_input_text_std_string(const char* name, std::string& string, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL)
{
	bool result;
	size_t buffer_size = string.size() + 2;
	if (buffer_size > 4096)
	{
		char* buffer = trivial_malloca(char, buffer_size);
		strcpy_s(buffer, buffer_size, string.c_str());
		if (result = ImGui::InputText(name, buffer, buffer_size, flags, callback, user_data))
		{
			string = buffer;
		}
		trivial_freea(buffer);
	}
	else
	{
		char* buffer = trivial_alloca(char, buffer_size);
		strcpy_s(buffer, buffer_size, string.c_str());
		if (result = ImGui::InputText(name, buffer, buffer_size, flags, callback, user_data))
		{
			string = buffer;
		}
	}
	return result;
}

static bool imgui_input_text_multiline_std_string(const char* name, std::string& string, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL)
{
	bool result;
	size_t buffer_size = string.size() + 2;
	if (buffer_size > 4096)
	{
		char* buffer = trivial_malloca(char, buffer_size);
		strcpy_s(buffer, buffer_size, string.c_str());
		if (result = ImGui::InputTextMultiline(name, buffer, buffer_size, size, flags, callback, user_data))
		{
			string = buffer;
		}
		trivial_freea(buffer);
	}
	else
	{
		char* buffer = trivial_alloca(char, buffer_size);
		strcpy_s(buffer, buffer_size, string.c_str());
		if (result = ImGui::InputTextMultiline(name, buffer, buffer_size, size, flags, callback, user_data))
		{
			string = buffer;
		}
	}
	return result;
}


static bool imgui_input_text_tag(const char* name, tag& inout_group_tag)
{
	bool result;

	char group_tag_buffer[sizeof(tag) + 1];
	tag& group_tag = *reinterpret_cast<tag*>(group_tag_buffer);
	group_tag = byteswap(inout_group_tag);
	for (char& character : group_tag_buffer)
	{
		if (character == 0)
		{
			character = '?';
		}
	}

	group_tag_buffer[4] = 0;
	if (ImGui::InputText("Group Tag", group_tag_buffer, _countof(group_tag_buffer)))
	{
		for (char& character : group_tag_buffer)
		{
			if (character == '?')
			{
				character = 0;
			}
		}
		inout_group_tag = byteswap(group_tag);
	}
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::Text("? is converted to \\0 characters");
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}

	return result;
}

static constexpr const char* binary_filepaths[k_num_binaries] =
{
	"tags.dat",
	"string_ids.dat",
	"video.dat",
	"audio.dat",
	"resources.dat",
	"textures.dat",
	"textures_b.dat",
};

c_definition_tweaker::c_definition_tweaker(c_window& _window, c_render_context& _window_render_context) :
	engine_platform_build{ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 },
	group_serialization_contexts(),
	serialization_contexts(),
	open_tag_indices(),
	num_missing_groups(),
	binary_data(),
	binary_data_size(),
	file_handles(),
	runtime_tag_definitions(),
	window(_window),
	window_render_context(_window_render_context),
	mandrill_theme_color_count(),
	mandrill_theme_var_count(),
	group_definition_search_buffer(),
	block_definition_search_buffer(),
	struct_definition_search_buffer(),
	array_definition_search_buffer(),
	string_list_definition_search_buffer(),
	reference_definition_search_buffer(),
	resource_definition_search_buffer(),
	interop_definition_search_buffer(),
	data_definition_search_buffer(),
	block_index_custom_search_definition_search_buffer(),
	open_group_definitions(),
	open_block_definitions(),
	open_struct_definitions(),
	open_array_definitions(),
	open_string_list_definitions(),
	open_reference_definitions(),
	open_resource_definitions(),
	open_interop_definitions(),
	open_data_definitions(),
	open_block_index_custom_search_definitions(),
	next_group_definition(),
	next_block_definition(),
	next_struct_definition(),
	next_array_definition(),
	next_string_list_definition(),
	next_reference_definition(),
	next_resource_definition(),
	next_interop_definition(),
	next_data_definition(),
	next_block_index_custom_search_definition(),
	name_edit_state_hack_definition_type(k_num_definition_types),
	name_edit_state_hack()
{


}

c_definition_tweaker::~c_definition_tweaker()
{

}

void c_definition_tweaker::init()
{
	const char* eldorado_directory;
	BCS_RESULT get_eldorado_directory_result = command_line_get_argument("eldoradodir", eldorado_directory);
	ASSERT(BCS_SUCCEEDED(get_eldorado_directory_result));

	for (unsigned int binary_filepath_index = 0; binary_filepath_index < _countof(binary_filepaths); binary_filepath_index++)
	{
		const char* binary_filepath = binary_filepaths[binary_filepath_index];
		size_t filepath_buffer_length = strlen(eldorado_directory) + strlen("\\maps\\") + strlen(binary_filepath) + 1;
		char* filepath = trivial_malloc(char, filepath_buffer_length);
		strcpy(filepath, eldorado_directory);
		strcat(filepath, "\\maps\\");
		strcat(filepath, binary_filepath);

		BCS_RESULT create_memory_mapped_file_result = create_memory_mapped_file(filepath, true, file_handles[binary_filepath_index]);
		ASSERT(BCS_SUCCEEDED(create_memory_mapped_file_result));

		if (binary_filepath_index == 0)
		{
			BCS_RESULT read_file_result = filesystem_read_file_to_memory(filepath, binary_data[binary_filepath_index], binary_data_size[binary_filepath_index]);
			ASSERT(BCS_SUCCEEDED(read_file_result));
		}
		else
		{
			s_memory_mapped_file_info file_info;
			BCS_RESULT get_memory_mapped_file_info_result = get_memory_mapped_file_info(file_handles[binary_filepath_index], file_info);
			ASSERT(BCS_SUCCEEDED(get_memory_mapped_file_info_result));

			binary_data[binary_filepath_index] = file_info.file_view_begin;
			binary_data_size[binary_filepath_index] = file_info.file_size;
		}
	}

	runtime_tag_definitions = new c_runtime_tag_definitions(engine_platform_build);

	parse_binary();
}

void c_definition_tweaker::cleanup()
{
	num_missing_groups = 0;

	for (c_tag_serialization_context* serialization_context : serialization_contexts)
	{
		delete serialization_context;
	}
	serialization_contexts.clear();

	for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
	{
		delete group_serialization_context;
	}
	group_serialization_contexts.clear();
}

void c_definition_tweaker::parse_binary()
{
	cleanup();

	for (c_runtime_tag_group_definition* tag_group : runtime_tag_definitions->group_definitions)
	{
		c_group_serialization_context* group_serialization_context = new c_group_serialization_context(*tag_group);
		group_serialization_contexts.push_back(group_serialization_context);
	}

	s_cache_file_tags_header* cache_file_tags_header = static_cast<s_cache_file_tags_header*>(binary_data[_binary_tags]);
	unsigned int* tag_cache_offsets = reinterpret_cast<unsigned int*>(static_cast<char*>(binary_data[_binary_tags]) + cache_file_tags_header->tag_cache_offsets);

	for (unsigned int tag_cache_offset_index = 0; tag_cache_offset_index < cache_file_tags_header->tag_count; tag_cache_offset_index++)
	{
		unsigned int tag_cache_offset = tag_cache_offsets[tag_cache_offset_index];
		if (tag_cache_offset == 0)
		{
			debug_point;
			continue;
		}

		const char* tag_data_start = static_cast<char*>(binary_data[_binary_tags]) + tag_cache_offset;
		const s_cache_file_tag_instance* tag_header = reinterpret_cast<const s_cache_file_tag_instance*>(tag_data_start);


		c_group_serialization_context* group_serialization_context = nullptr;
		for (c_group_serialization_context* current_group_serialization_context : group_serialization_contexts)
		{
			if (current_group_serialization_context->tag_group.group_tag == tag_header->group_tags[0])
			{
				group_serialization_context = current_group_serialization_context;
				break;
			}
		}

		c_tag_serialization_context* tag_serialization_context = new c_tag_serialization_context(group_serialization_context, engine_platform_build, tag_data_start);

		if (group_serialization_context)
		{
			group_serialization_context->serialization_contexts.push_back(tag_serialization_context);
		}
		else
		{
			num_missing_groups++;
		}
		serialization_contexts.push_back(tag_serialization_context);

		unsigned long errors = tag_serialization_context->read();
		if (errors == 0)
		{
			errors = tag_serialization_context->traverse();
		}

		debug_point;
	}

	for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
	{
		group_serialization_context->post();
	}

	debug_point;
}

void c_definition_tweaker::deinit()
{
	cleanup();

	for (unsigned int binary_filepath_index = 0; binary_filepath_index < _countof(binary_filepaths); binary_filepath_index++)
	{
		if (binary_filepath_index == 0)
		{
			tracked_free(binary_data[binary_filepath_index]);
		}
		else
		{
			BCS_RESULT destroy_memory_mapped_file_result = destroy_memory_mapped_file(file_handles[binary_filepath_index]);
			ASSERT(BCS_SUCCEEDED(destroy_memory_mapped_file_result));
		}
	}

	delete runtime_tag_definitions;
}

ImVec4 colors[] =
{
	MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
	MANDRILL_THEME_WARNING_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
	MANDRILL_THEME_ERROR_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA),
};

void c_definition_tweaker::render_missing_group_serialization_context_tree()
{
	if (num_missing_groups)
	{
		ImGui::PushID("<missing group>");

		ImGui::PushStyleColor(ImGuiCol_Text, colors[_tag_serialization_state_error]);

		if (ImGui::TreeNode("<missing group>"))
		{
			for (c_tag_serialization_context* tag_serialization_context : serialization_contexts)
			{
				if (tag_serialization_context->group_serialization_context == nullptr)
				{
					render_tag_serialization_context_tree(tag_serialization_context);
				}
			}
			ImGui::TreePop();
		}

		ImGui::PopStyleColor();

		ImGui::PopID();
	}
}

void c_definition_tweaker::render_group_serialization_context_tree(c_group_serialization_context* group_serialization_context)
{
	if (!group_serialization_context->serialization_contexts.empty())
	{
		ImGui::PushID(group_serialization_context->tag_group.group_tag);

		ImGui::PushStyleColor(ImGuiCol_Text, colors[group_serialization_context->max_serialization_error_type]);

		if (ImGui::TreeNode("%s (%zu)", group_serialization_context->tag_group.name.c_str(), group_serialization_context->serialization_contexts.size()))
		{
			for (c_tag_serialization_context* tag_serialization_context : group_serialization_context->serialization_contexts)
			{
				render_tag_serialization_context_tree(tag_serialization_context);
			}

			ImGui::TreePop();
		}

		ImGui::PopStyleColor();

		ImGui::PopID();
	}
}

void c_definition_tweaker::render_tag_serialization_context_tree(c_tag_serialization_context* tag_serialization_context)
{
	ImGui::PushStyleColor(ImGuiCol_Text, colors[tag_serialization_context->max_serialization_error_type]);

	unsigned int group_tag_swapped = byteswap(tag_serialization_context->tag_header->group_tags[0]);

	static ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_OpenOnArrow |
		ImGuiTreeNodeFlags_OpenOnDoubleClick |
		ImGuiTreeNodeFlags_SpanAvailWidth |
		ImGuiTreeNodeFlags_Leaf |
		ImGuiTreeNodeFlags_NoTreePushOnOpen;
	if (ImGui::TreeNodeEx(tag_serialization_context, flags, "%.4s", &group_tag_swapped))
	{
		if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
		{
			debug_point;
		}
	}

	ImGui::PopStyleColor();
}


void c_definition_tweaker::mandrill_theme_push()
{
#define push_color4_float(color, r, g, b, a) mandrill_theme_color_count++; ImGui::PushStyleColor(color, ImVec4(float(r), float(g), float(b), float(a)))
#define push_color3_float(color, r, g, b) push_color4_float(color, r, g, b, 1.0f)
#define push_color4(color, r, g, b, a) push_color4_float(color, float(r) / 255.0f, float(g) / 255.0f, float(b) / 255.0f, 1.0f)
#define push_color3(color, r, g, b) push_color4(color, r, g, b, 255)
#define push_color(color, value) mandrill_theme_color_count++; ImGui::PushStyleColor(color, value)
#define push_style(style, ...) mandrill_theme_var_count++; ImGui::PushStyleVar(style, __VA_ARGS__)

	mandrill_theme_color_count = 0;
	mandrill_theme_var_count = 0;

	push_color(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.78f));
	push_color(ImGuiCol_TextDisabled, MANDRILL_THEME_TEXT(0.28f));
	push_color(ImGuiCol_WindowBg, ImVec4(0.13f, 0.14f, 0.17f, 1.00f));
	push_color(ImGuiCol_ChildBg, MANDRILL_THEME_BG(0.15f));
	push_color(ImGuiCol_PopupBg, MANDRILL_THEME_BG(0.9f));
	push_color(ImGuiCol_Border, ImVec4(0.31f, 0.31f, 1.00f, 0.00f));
	push_color(ImGuiCol_BorderShadow, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
	push_color(ImGuiCol_FrameBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_FrameBgHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_FrameBgActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TitleBg, MANDRILL_THEME_LOW(1.00f));
	push_color(ImGuiCol_TitleBgActive, MANDRILL_THEME_HIGH(1.00f));
	push_color(ImGuiCol_TitleBgCollapsed, MANDRILL_THEME_BG(0.75f));
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_BG(0.47f));
	push_color(ImGuiCol_ScrollbarBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_ScrollbarGrab, ImVec4(0.09f, 0.15f, 0.16f, 1.00f));
	push_color(ImGuiCol_ScrollbarGrabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ScrollbarGrabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_CheckMark, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_SliderGrab, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_SliderGrabActive, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_Button, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_ButtonHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_ButtonActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_Header, MANDRILL_THEME_MED(0.76f));
	push_color(ImGuiCol_HeaderHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_HeaderActive, MANDRILL_THEME_HIGH(1.00f));
	//push_color(ImGuiCol_Column, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	//push_color(ImGuiCol_ColumnHovered, MANDRILL_THEME_MED(0.78f));
	//push_color(ImGuiCol_ColumnActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_ResizeGrip, ImVec4(0.47f, 0.77f, 0.83f, 0.04f));
	push_color(ImGuiCol_ResizeGripHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ResizeGripActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotLines, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotLinesHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotHistogram, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotHistogramHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TextSelectedBg, MANDRILL_THEME_MED(0.43f));
	//push_color(ImGuiCol_ModalWindowDarkening, MANDRILL_THEME_BG(0.73f));

	push_color(ImGuiCol_Tab, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	push_color(ImGuiCol_TabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_TabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TabUnfocused, MANDRILL_THEME_LOW(0.78f));


	//push_color3(ImGuiCol_WindowBg, 33, 33, 33);
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_MENU(1.0f));

	push_style(ImGuiStyleVar_WindowPadding, { 4, 8 });
	push_style(ImGuiStyleVar_ScrollbarSize, { 20 });
	push_style(ImGuiStyleVar_ItemInnerSpacing, { 5, 4 });

	push_style(ImGuiStyleVar_WindowRounding, { 0 });
	push_style(ImGuiStyleVar_ScrollbarRounding, { 0 });
	push_style(ImGuiStyleVar_TabRounding, { 0 });

#undef push_color4_float
#undef push_color3_float
#undef push_color4
#undef push_color3
#undef push_style
}

void c_definition_tweaker::mandrill_theme_pop()
{
	ImGui::PopStyleColor(mandrill_theme_color_count);
	ImGui::PopStyleVar(mandrill_theme_var_count);
}

void c_definition_tweaker::render_user_interface()
{
	mandrill_theme_push();

	float margin = 4.0f;

	ImGuiWindowFlags imgui_main_window_flags = 0;
	imgui_main_window_flags |= ImGuiWindowFlags_NoCollapse;
	imgui_main_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_main_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	imgui_main_window_flags |= ImGuiWindowFlags_NoTitleBar;
	imgui_main_window_flags |= ImGuiWindowFlags_NoMove;
	imgui_main_window_flags |= ImGuiWindowFlags_NoResize;
	imgui_main_window_flags |= ImGuiWindowFlags_NoScrollbar;

	ImVec2 main_window_position = { margin, margin };
	ImVec2 main_window_size =
	{
		window_render_context.get_width_float() - margin * 2.0f,
		window_render_context.get_height_float() - margin * 2.0f
	};


	ImGui::SetNextWindowPos(main_window_position, ImGuiCond_Always);
	ImGui::SetNextWindowSize(main_window_size, ImGuiCond_Always);

	//ImGui::ShowDemoWindow();

	if (ImGui::Begin("Definition Tweaker", nullptr, imgui_main_window_flags))
	{
		if (ImGui::BeginTable("Viewport", 2))
		{
			ImGui::TableSetupColumn("Serialization");
			ImGui::TableSetupColumn("Definitions");
			ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::BeginTabBar("##serialization"))
			{
				render_serialization_tab();

				for (unsigned int open_tag_index : open_tag_indices)
				{
					if (open_tag_index < serialization_contexts.size())
					{
						c_tag_serialization_context* serialization_context = serialization_contexts[open_tag_index];

						// #TODO:
					}
				}

				ImGui::EndTabBar();
			}
			ImGui::TableNextColumn();
			if (ImGui::BeginTabBar("##definitions"))
			{
				render_group_definitions_tab();
				render_block_definitions_tab();
				render_struct_definitions_tab();
				render_array_definitions_tab();
				render_string_list_definitions_tab();
				render_reference_definitions_tab();
				render_resource_definitions_tab();
				render_interop_definitions_tab();
				render_data_definitions_tab();
				render_block_index_custom_search_definitions_tab();

				ImGui::EndTabBar();
			}

			ImGui::EndTable();
		}

	}
	ImGui::End();

	mandrill_theme_pop();
}

bool c_definition_tweaker::render_search_box(char* search_buffer, unsigned int search_buffer_length, const char* default_text)
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImGui::Dummy({ 10.0f, 0.0f });
	ImGui::SameLine();
	ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - 75.0f);
	ImGuiInputTextFlags input_text_flags = 0;
	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImGui::InputText("##Search", search_buffer, search_buffer_length, input_text_flags);
	if (!ImGui::IsItemActive() && search_buffer[0] == 0)
	{
		draw_list->AddText({ pos.x + 4.0f, pos.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(0.25)), default_text);
	}
	ImGui::SameLine();
	if (ImGui::Button(ICON_FA_XMARK))
	{
		*search_buffer = 0;
	}
	ImGui::SameLine();
	ImGui::Dummy({ 10.0f, 0.0f });

	return *search_buffer != 0;
}

void c_definition_tweaker::render_group_definitions_tab()
{
	if (ImGui::BeginTabItem("Groups"))
	{
		if (ImGui::BeginTable("##navigation", 2))
		{
			ImGui::TableSetupColumn("List");
			ImGui::TableSetupColumn("Definitions");
			//ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			{
				if (ImGui::BeginChild("Groups"))
				{
					bool search_active = render_search_box(group_definition_search_buffer, _countof(group_definition_search_buffer));
					if (ImGui::Button("Create Group"))
					{
						c_runtime_tag_group_definition& group_definition = runtime_tag_definitions->create_tag_group_definition();
						open_group_definitions.insert(open_group_definitions.end(), &group_definition);
						next_group_definition = &group_definition;
					}

					if (ImGui::BeginChild("GroupsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
					{
						size_t group_event_index = SIZE_MAX;
						bool delete_group = false;
						bool duplicate_group = false;

						//for (c_runtime_tag_group_definition* group_definition : runtime_tag_definitions->group_definitions)
						for (size_t group_definition_index = 0; group_definition_index < runtime_tag_definitions->group_definitions.size(); group_definition_index++)
						{
							c_runtime_tag_group_definition* group_definition = runtime_tag_definitions->group_definitions[group_definition_index];

							ImGui::PushID(group_definition);

							const char* group_name = "<unnamed group>";
							if (!group_definition->name.empty())
							{
								group_name = group_definition->name.c_str();
							}
							if (!search_active || strstr(group_name, group_definition_search_buffer))
							{
								if (ImGui::TreeNodeEx(group_name, ImGuiTreeNodeFlags_Leaf))
								{
									if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
									{
										open_group_definitions.insert(open_group_definitions.end(), group_definition);
										next_group_definition = group_definition;
									}
									ImGui::TreePop();
								}
								if (ImGui::BeginPopupContextItem("##groupcontextmenu"))
								{
									if (ImGui::MenuItem("Duplicate"))
									{
										group_event_index = group_definition_index;
										duplicate_group = true;
									}
									ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
									if (ImGui::MenuItem("Delete"))
									{
										group_event_index = group_definition_index;
										delete_group = true;
									}
									ImGui::EndPopup();
								}
							}
							ImGui::PopID();
						}

						if (group_event_index != SIZE_MAX)
						{
							if (delete_group)
							{
								c_runtime_tag_group_definition* group_definition = runtime_tag_definitions->group_definitions[group_event_index];
								runtime_tag_definitions->group_definitions.erase(runtime_tag_definitions->group_definitions.begin() + group_event_index);
								delete group_definition;
							}
							else if (duplicate_group)
							{
								c_runtime_tag_group_definition* old_group_definition = runtime_tag_definitions->group_definitions[group_event_index];
								c_runtime_tag_group_definition& new_group_definition = runtime_tag_definitions->duplicate_tag_group_definition(*old_group_definition);
								open_group_definitions.insert(open_group_definitions.end(), &new_group_definition);
								new_group_definition.name += " (copy)";
								next_group_definition = &new_group_definition;
							}
						}

						ImGui::EndChild();
					}
					ImGui::EndChild();
				}

			}
			ImGui::TableNextColumn();
			{

				if (ImGui::BeginTabBar("##openitems"))
				{
					auto open_group_definitions_copy = open_group_definitions;
					for (c_runtime_tag_group_definition* group_definition : open_group_definitions_copy)
					{
						ImGui::PushID(group_definition);

						const char* group_name = "unnamed group";
						if (!group_definition->name.empty())
						{
							group_name = group_definition->name.c_str();
						}

						bool open = true;
						ImGuiTabItemFlags flags = ImGuiTabItemFlags_None;
						if (next_group_definition == group_definition)
						{
							flags = flags | ImGuiTabItemFlags_SetSelected;
							next_group_definition = nullptr;
						}
						if (ImGui::BeginTabItem(group_name, &open, flags))
						{
							if (ImGui::BeginChild("GroupsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
							{
								if (imgui_input_text_std_string("Name", group_definition->name))
								{
									enqueue_name_edit_state_hack(_definition_type_group_definition, group_definition);
								}
								handle_name_edit_state_hack(_definition_type_group_definition);

								imgui_input_text_std_string("Symbol Name", group_definition->symbol_name);

								imgui_input_text_tag("Group Tag", group_definition->group_tag);

								ImGui::InputInt("Version", reinterpret_cast<int*>(&group_definition->version));

								ImGui::Text("Block Definition: BLOCK DEFINITION TODO");
								ImGui::Text("Parent Group Definition: GROUP DEFINITION TODO");

								ImGui::EndChild();
							}
							ImGui::EndTabItem();
						}
						if (!open)
						{
							open_group_definitions.erase(group_definition);
						}
						ImGui::PopID();
					}

					ImGui::EndTabBar();
				}
			}

			ImGui::EndTable();
		}
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_block_definitions_tab()
{
	if (ImGui::BeginTabItem("Blocks"))
	{
		if (ImGui::BeginTable("##navigation", 2))
		{
			ImGui::TableSetupColumn("List");
			ImGui::TableSetupColumn("Definitions");
			//ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			{
				if (ImGui::BeginChild("Blocks"))
				{
					bool search_active = render_search_box(block_definition_search_buffer, _countof(block_definition_search_buffer));
					if (ImGui::Button("Create Block"))
					{
						c_runtime_tag_block_definition& block_definition = runtime_tag_definitions->create_tag_block_definition();
						open_block_definitions.insert(open_block_definitions.end(), &block_definition);
						next_block_definition = &block_definition;
					}

					if (ImGui::BeginChild("BlocksList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
					{
						size_t block_event_index = SIZE_MAX;
						bool delete_block = false;
						bool duplicate_block = false;

						//for (c_runtime_tag_block_definition* block_definition : runtime_tag_definitions->block_definitions)
						for (size_t block_definition_index = 0; block_definition_index < runtime_tag_definitions->block_definitions.size(); block_definition_index++)
						{
							c_runtime_tag_block_definition* block_definition = runtime_tag_definitions->block_definitions[block_definition_index];

							ImGui::PushID(block_definition);

							const char* block_name = "<unnamed block>";
							if (!block_definition->name.empty())
							{
								block_name = block_definition->name.c_str();
							}
							if (!search_active || strstr(block_name, block_definition_search_buffer))
							{
								if (ImGui::TreeNodeEx(block_name, ImGuiTreeNodeFlags_Leaf))
								{
									if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
									{
										open_block_definitions.insert(open_block_definitions.end(), block_definition);
										next_block_definition = block_definition;
									}
									ImGui::TreePop();
								}
								if (ImGui::BeginPopupContextItem("##blockcontextmenu"))
								{
									if (ImGui::MenuItem("Duplicate"))
									{
										block_event_index = block_definition_index;
										duplicate_block = true;
									}
									ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
									if (ImGui::MenuItem("Delete"))
									{
										block_event_index = block_definition_index;
										delete_block = true;
									}
									ImGui::EndPopup();
								}
							}
							ImGui::PopID();
						}

						if (block_event_index != SIZE_MAX)
						{
							if (delete_block)
							{
								c_runtime_tag_block_definition* block_definition = runtime_tag_definitions->block_definitions[block_event_index];
								runtime_tag_definitions->block_definitions.erase(runtime_tag_definitions->block_definitions.begin() + block_event_index);
								delete block_definition;
							}
							else if (duplicate_block)
							{
								c_runtime_tag_block_definition* old_block_definition = runtime_tag_definitions->block_definitions[block_event_index];
								c_runtime_tag_block_definition& new_block_definition = runtime_tag_definitions->duplicate_tag_block_definition(*old_block_definition);
								open_block_definitions.insert(open_block_definitions.end(), &new_block_definition);
								new_block_definition.name += " (copy)";
								next_block_definition = &new_block_definition;
							}
						}

						ImGui::EndChild();
					}
					ImGui::EndChild();
				}

			}
			ImGui::TableNextColumn();
			{

				if (ImGui::BeginTabBar("##openitems"))
				{
					auto open_block_definitions_copy = open_block_definitions;
					for (c_runtime_tag_block_definition* block_definition : open_block_definitions_copy)
					{
						ImGui::PushID(block_definition);

						const char* block_name = "unnamed block";
						if (!block_definition->name.empty())
						{
							block_name = block_definition->name.c_str();
						}

						bool open = true;
						ImGuiTabItemFlags flags = ImGuiTabItemFlags_None;
						if (block_definition == next_block_definition)
						{
							flags = flags | ImGuiTabItemFlags_SetSelected;
							next_block_definition = nullptr;
						}
						if (ImGui::BeginTabItem(block_name, &open, flags))
						{
							if (ImGui::BeginChild("BlocksList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
							{
								imgui_input_text_std_string("Display Name", block_definition->display_name);

								if (imgui_input_text_std_string("Name", block_definition->name))
								{
									enqueue_name_edit_state_hack(_definition_type_block_definition, block_definition);
								}
								handle_name_edit_state_hack(_definition_type_block_definition);

								imgui_input_text_std_string("Symbol Name", block_definition->symbol_name);

								ImGui::InputInt("Max Count", reinterpret_cast<int*>(&block_definition->max_count));

								imgui_input_text_std_string("Max Count String", block_definition->max_count_string);

								ImGui::Text("Struct Definition: STRUCT DEFINITION TODO");

								ImGui::EndChild();
							}
							ImGui::EndTabItem();
						}
						if (!open)
						{
							open_block_definitions.erase(block_definition);
						}
						ImGui::PopID();
					}

					ImGui::EndTabBar();
				}
			}

			ImGui::EndTable();
		}
		ImGui::EndTabItem();
	}
}
void c_definition_tweaker::render_struct_definitions_tab()
{
	if (ImGui::BeginTabItem("Structures"))
	{
		if (ImGui::BeginTable("##navigation", 2))
		{
			ImGui::TableSetupColumn("List");
			ImGui::TableSetupColumn("Definitions");
			//ImGui::TableHeadersRow();
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			render_struct_definition_list();
			ImGui::TableNextColumn();
			render_struct_definition_tabs();
			ImGui::EndTable();
		}
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_struct_definition_list()
{
	if (ImGui::BeginChild("struct_definition_list"))
	{
		bool search_active = render_search_box(struct_definition_search_buffer, _countof(struct_definition_search_buffer));
		if (ImGui::Button("Create Structure"))
		{
			c_runtime_tag_struct_definition& struct_definition = runtime_tag_definitions->create_tag_struct_definition();
			open_struct_definitions.insert(open_struct_definitions.end(), &struct_definition);
			next_struct_definition = &struct_definition;
		}

		if (ImGui::BeginChild("StructuresList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t struct_event_index = SIZE_MAX;
			bool delete_struct = false;
			bool duplicate_struct = false;

			//for (c_runtime_tag_struct_definition* struct_definition : runtime_tag_definitions->struct_definitions)
			for (size_t structure_definition_index = 0; structure_definition_index < runtime_tag_definitions->struct_definitions.size(); structure_definition_index++)
			{
				c_runtime_tag_struct_definition* struct_definition = runtime_tag_definitions->struct_definitions[structure_definition_index];

				ImGui::PushID(struct_definition);

				const char* structure_name = "<unnamed struct>";
				if (!struct_definition->name.empty())
				{
					structure_name = struct_definition->name.c_str();
				}
				if (!search_active || strstr(structure_name, struct_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(structure_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_struct_definitions.insert(open_struct_definitions.end(), struct_definition);
							next_struct_definition = struct_definition;
						}
						ImGui::TreePop();
					}
					if (ImGui::BeginPopupContextItem("##structurecontextmenu"))
					{
						if (ImGui::MenuItem("Duplicate"))
						{
							struct_event_index = structure_definition_index;
							duplicate_struct = true;
						}
						ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
						if (ImGui::MenuItem("Delete"))
						{
							struct_event_index = structure_definition_index;
							delete_struct = true;
						}
						ImGui::EndPopup();
					}
				}
				ImGui::PopID();
			}

			if (struct_event_index != SIZE_MAX)
			{
				if (delete_struct)
				{
					c_runtime_tag_struct_definition* struct_definition = runtime_tag_definitions->struct_definitions[struct_event_index];
					runtime_tag_definitions->struct_definitions.erase(runtime_tag_definitions->struct_definitions.begin() + struct_event_index);
					delete struct_definition;
				}
				else if (duplicate_struct)
				{
					c_runtime_tag_struct_definition* old_struct_definition = runtime_tag_definitions->struct_definitions[struct_event_index];
					c_runtime_tag_struct_definition& new_struct_definition = runtime_tag_definitions->duplicate_tag_struct_definition(*old_struct_definition);
					open_struct_definitions.insert(open_struct_definitions.end(), &new_struct_definition);
					new_struct_definition.name += " (copy)";
					next_struct_definition = &new_struct_definition;
				}
			}

			ImGui::EndChild();
		}
		ImGui::EndChild();
	}
}

void c_definition_tweaker::render_struct_definition_tabs()
{
	if (ImGui::BeginTabBar("##openitems"))
	{
		auto open_struct_definitions_copy = open_struct_definitions;
		for (c_runtime_tag_struct_definition* struct_definition : open_struct_definitions_copy)
		{
			ImGui::PushID(struct_definition);

			const char* structure_name = "unnamed struct";
			if (!struct_definition->name.empty())
			{
				structure_name = struct_definition->name.c_str();
			}

			bool open = true;
			ImGuiTabItemFlags flags = ImGuiTabItemFlags_None;
			if (struct_definition == next_struct_definition)
			{
				flags = flags | ImGuiTabItemFlags_SetSelected;
				next_struct_definition = nullptr;
			}
			if (ImGui::BeginTabItem(structure_name, &open, flags))
			{
				if (ImGui::BeginChild("StructuresList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
				{
					render_struct_definition(struct_definition);


					ImGui::EndChild();
				}
				ImGui::EndTabItem();
			}
			if (!open)
			{
				open_struct_definitions.erase(struct_definition);
			}
			ImGui::PopID();
		}

		ImGui::EndTabBar();
	}
}

void c_definition_tweaker::render_struct_definition(c_runtime_tag_struct_definition* struct_definition)
{
	ImGui::BeginGroup();

	imgui_input_text_std_string("Pretty Name", struct_definition->pretty_name);

	if (imgui_input_text_std_string("Name", struct_definition->name))
	{
		enqueue_name_edit_state_hack(_definition_type_struct_definition, struct_definition);
	}
	handle_name_edit_state_hack(_definition_type_struct_definition);

	imgui_input_text_std_string("Structure Name", struct_definition->struct_name);

	ImGui::InputInt4(
		"Persistent Identifier",
		reinterpret_cast<int*>(&struct_definition->persistent_identifier.identifier_part_0),
		ImGuiInputTextFlags_CharsHexadecimal);

	render_struct_definition_tag_field_set(struct_definition);

	render_struct_definition_memory_attributes(struct_definition);

	ImGui::EndGroup();
	ImVec2 group_size = ImGui::GetItemRectSize();
	render_struct_definition_fields(struct_definition, group_size.x);
}

void c_definition_tweaker::render_struct_definition_tag_field_set(c_runtime_tag_struct_definition* struct_definition)
{
	if (ImGui::CollapsingHeader("Tag Field Set"))
	{
		imgui_checkbox_cflags("unknown0", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown0_bit);
		imgui_checkbox_cflags("unknown1", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown1_bit);
		imgui_checkbox_cflags("has_inlined_children_with_placement_new", struct_definition->runtime_flags, blofeld::_tag_field_set_has_inlined_children_with_placement_new_bit);
		imgui_checkbox_cflags("unknown3", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown3_bit);
		imgui_checkbox_cflags("unknown4", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown4_bit);
		imgui_checkbox_cflags("has_aggregate_types", struct_definition->runtime_flags, blofeld::_tag_field_set_has_aggregate_types_bit);
		imgui_checkbox_cflags("is_temporary", struct_definition->runtime_flags, blofeld::_tag_field_set_is_temporary_bit);
		imgui_checkbox_cflags("unknown7", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown7_bit);
		imgui_checkbox_cflags("unknown8", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown8_bit);
		imgui_checkbox_cflags("delete_recursively", struct_definition->runtime_flags, blofeld::_tag_field_set_delete_recursively_bit);
		imgui_checkbox_cflags("postprocess_recursively", struct_definition->runtime_flags, blofeld::_tag_field_set_postprocess_recursively_bit);
		imgui_checkbox_cflags("is_memcpyable", struct_definition->runtime_flags, blofeld::_tag_field_set_is_memcpyable_bit);
		imgui_checkbox_cflags("unknown12", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown12_bit);
		imgui_checkbox_cflags("has_resources", struct_definition->runtime_flags, blofeld::_tag_field_set_has_resources_bit);
		imgui_checkbox_cflags("unknown14", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown14_bit);
		imgui_checkbox_cflags("unknown15", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown15_bit);
		imgui_checkbox_cflags("has_level_specific_fields", struct_definition->runtime_flags, blofeld::_tag_field_set_has_level_specific_fields_bit);
		imgui_checkbox_cflags("can_memset_to_initialize", struct_definition->runtime_flags, blofeld::_tag_field_set_can_memset_to_initialize_bit);
		imgui_checkbox_cflags("unknown18", struct_definition->runtime_flags, blofeld::_tag_field_set_unknown18_bit);
		imgui_checkbox_cflags("exist_in_cache_build", struct_definition->runtime_flags, blofeld::_tag_field_set_exist_in_cache_build_bit);
	}
}

void c_definition_tweaker::render_struct_definition_memory_attributes(c_runtime_tag_struct_definition* struct_definition)
{
	if (ImGui::CollapsingHeader("Memory Attributes"))
	{
		static constexpr const char* tag_memory_to_string[blofeld::k_num_tag_memory_type] =
		{
			"_tag_memory_default",
			"_tag_memory_node",
		};
		const char* memory_type_string = tag_memory_to_string[struct_definition->memory_attributes.memory_type];
		if (ImGui::BeginCombo("##combo_type", memory_type_string, ImGuiComboFlags_HeightLargest))
		{
			for (unsigned int tag_memory_type = 0; tag_memory_type < blofeld::k_num_tag_memory_type; tag_memory_type++)
			{
				memory_type_string = tag_memory_to_string[tag_memory_type];
				if (ImGui::Selectable(memory_type_string))
				{
					struct_definition->memory_attributes.memory_type = static_cast<blofeld::e_tag_memory_allocation_type>(tag_memory_type);
				}
			}
			ImGui::EndCombo();
		}

		imgui_checkbox_cflags("physical", struct_definition->memory_attributes.usage_flags, blofeld::_tag_memory_physical_bit);
		imgui_checkbox_cflags("unknown1", struct_definition->memory_attributes.usage_flags, blofeld::_tag_memory_unknown1_bit);
		imgui_checkbox_cflags("unknown2", struct_definition->memory_attributes.usage_flags, blofeld::_tag_memory_unknown2_bit);
		imgui_checkbox_cflags("writeable", struct_definition->memory_attributes.usage_flags, blofeld::_tag_memory_writeable_bit);
		imgui_checkbox_cflags("combined", struct_definition->memory_attributes.usage_flags, blofeld::_tag_memory_combined_bit);
		imgui_checkbox_cflags("streaming", struct_definition->memory_attributes.usage_flags, blofeld::_tag_memory_streaming_bit);
		imgui_checkbox_cflags("non_aliased", struct_definition->memory_attributes.usage_flags, blofeld::_tag_memory_non_aliased_bit);

		ImGui::InputInt("Alignment Bits", reinterpret_cast<int*>(&struct_definition->alignment_bits));
	}
}

void c_definition_tweaker::render_struct_definition_fields(c_runtime_tag_struct_definition* struct_definition, float max_size)
{
	if (ImGui::CollapsingHeader("Fields", ImGuiTreeNodeFlags_DefaultOpen))
	{
		bool fields_changes = false;

		std::vector<c_runtime_tag_field*>& fields = struct_definition->fields;
		unsigned long field_event_index = UINT_MAX;
		bool duplicate_field = false;
		bool delete_field = false;
		if (ImGui::Button("Add Field"))
		{
			field_event_index = 0;
		}
		ImVec2 content_region_avail = ImGui::GetContentRegionAvail();
		ImVec2 cursor_screen_position = ImGui::GetCursorScreenPos();
		ImVec2 mouse_position = ImGui::GetMousePos();
		ImVec2 child_size = { __max(max_size, content_region_avail.x), content_region_avail.y };

		//if (ImGui::BeginChild("FieldsList", content_region_avail, false, ImGuiWindowFlags_HorizontalScrollbar))
		if (ImGui::BeginChild("FieldsList", child_size))
		{
			ImGui::SetNextItemWidth(-1.0f);
			char buf[1] = { 0 };
			ImGui::InputText("text", buf, 1);
			ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);

			ImVec2 cursor = ImGui::GetCursorPos();
			if (ImGui::BeginTable("FieldsTable", 7))
			{

				ImVec2 fa_bars_size = ImGui::CalcTextSize(ICON_FA_BARS);
				ImGuiStyle& imgui_style = ImGui::GetStyle();

				float row_height = 32.0f;
				float drag_column_width = fa_bars_size.x + imgui_style.FramePadding.x * 2.0f + imgui_style.ColumnsMinSpacing;
				float type_column_width = 150.0f;

				ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, drag_column_width);
				ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, type_column_width);
				ImGui::TableSetupColumn("Name");
				ImGui::TableSetupColumn("Description");
				ImGui::TableSetupColumn("Units");
				ImGui::TableSetupColumn("Limits");
				ImGui::TableSetupColumn("Ext");

				ImGui::TableHeadersRow();

				ImVec2* _cursor_start = trivial_alloca(ImVec2, fields.size());
				ImVec2* _cursor_end = trivial_alloca(ImVec2, fields.size());

				for (size_t field_index = 0; field_index < fields.size(); field_index++)
				{
					c_runtime_tag_field* field = fields[field_index];
					ImGui::PushID(field);


					ImGui::BeginGroup();
					ImGui::TableNextRow();
					ImGui::TableNextColumn();
					_cursor_start[field_index] = ImGui::GetCursorPos();
					{

						const char* field_type_name = "<bad type>";
						if (BCS_FAILED(blofeld::field_to_string(field->field_type, field_type_name)))
						{
							field_type_name = "<bad type>";
						}
						ImVec2 current_pos = ImGui::GetCursorPos();
						ImVec2 current_screen_pos = ImGui::GetCursorScreenPos();
						ImGui::Selectable(ICON_FA_BARS, false, 0, { drag_column_width, row_height });
						bool is_active = ImGui::IsItemActive();
						bool is_hovered = ImGui::IsItemHovered();
						ImVec2 item_size = ImGui::GetItemRectSize();
						if (is_active || is_hovered)
						{
							if (ImGui::IsMouseDown(ImGuiMouseButton_Left))
							{
								ImGui::SetCursorPos(current_pos);
								ImGui::Selectable(ICON_FA_BARS, true, ImGuiSelectableFlags_SpanAllColumns, { 0.0, row_height });
								is_active |= ImGui::IsItemActive();
								is_hovered |= ImGui::IsItemHovered();
								item_size = ImGui::GetItemRectSize();
								ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeNS);
							}
							else
							{
								ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
							}
						}
						if (is_active && !is_hovered)
						{
							float distance_below = current_screen_pos.y - mouse_position.y;
							float distance_above = mouse_position.y - (current_screen_pos.y + item_size.y);
							bool is_below = distance_below > 0.0f;
							bool is_above = distance_above > 0.0f;
							if (is_above || is_below)
							{
								int field_index_next = field_index + (is_below ? -__max(1, distance_below / item_size.y) : __max(1, distance_above / item_size.y));
								field_index_next == __clamp(field_index_next, -1, fields.size());
								if (field_index_next >= 0 && field_index_next < fields.size())
								{
									fields.erase(fields.begin() + field_index);
									fields.insert(fields.begin() + field_index_next, field);
									ImGui::ResetMouseDragDelta();
									fields_changes = true;
								}
							}
						}
					}
					ImGui::TableNextColumn();
					{
						const char* field_type_name = "<bad type>";
						if (BCS_FAILED(blofeld::field_to_tagfile_field_type(field->field_type, field_type_name)))
						{
							field_type_name = "<bad type>";
						}

						ImGui::SetNextItemWidth(-1.0f);
						if (ImGui::BeginCombo("##combo_type", field_type_name, ImGuiComboFlags_HeightLargest | ImGuiComboFlags_PopupAlignLeft))
						{
							for (unsigned int field_type = 0; field_type < blofeld::k_number_of_blofeld_field_types; field_type++)
							{
								ASSERT(BCS_SUCCEEDED(blofeld::field_to_tagfile_field_type(static_cast<blofeld::e_field>(field_type), field_type_name)));
								if (ImGui::Selectable(field_type_name))
								{
									field->field_type = static_cast<blofeld::e_field>(field_type);
								}
							}
							ImGui::EndCombo();
						}
					}
					auto string_edit = [](const char* id, std::string& string, bool multi_line, const char* _default, float row_height)
					{
						ImGui::TableNextColumn();
						{
							ImGui::PushID(id);

							ImGui::SetNextItemWidth(-1.0f);
							ImVec2 cursor_position = ImGui::GetCursorScreenPos();
							if (multi_line)
							{
								imgui_input_text_multiline_std_string(id, string, { 0.0f, row_height });
							}
							else
							{
								imgui_input_text_std_string(id, string);
							}
							if (!ImGui::IsItemActive() && string.empty())
							{
								ImDrawList* draw_list = ImGui::GetWindowDrawList();
								draw_list->AddText({ cursor_position.x + 4.0f, cursor_position.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(0.25)), _default);
							}

							ImGui::PopID();
						}
					};
					string_edit("name", field->name, false, "name", row_height);
					string_edit("description", field->description, true, "description", row_height);
					string_edit("units", field->units, false, "units", row_height);
					string_edit("limits", field->limits, false, "limits", row_height);
					ImGui::TableNextColumn();

					ImGui::EndGroup();

					_cursor_end[field_index] = ImGui::GetCursorPos();
					ImVec2 x = ImGui::GetContentRegionMax();
					_cursor_end[field_index].x = x.x;
					ImVec2 y = ImGui::GetWindowContentRegionMax();
					ImGui::PopID();
				}
				ImGui::EndTable();

				ImVec2 cursor2 = ImGui::GetCursorPos();
				ImGui::SetCursorPos(cursor);
				for (size_t field_index = 0; field_index < fields.size(); field_index++)
				{
					c_runtime_tag_field* field = fields[field_index];
					ImGui::PushID(field);

					ImVec2& cursor_start = _cursor_start[field_index];
					ImVec2& cursor_end = _cursor_end[field_index];

					ImGui::SetCursorPos(cursor_start);

					// make everything transparent
					for (int imgui_color_index = 0; imgui_color_index < ImGuiCol_COUNT; imgui_color_index++)
					{
						ImGui::PushStyleColor(imgui_color_index, {});
					}
					ImGui::Selectable("", false, ImGuiSelectableFlags_AllowItemOverlap, { cursor_end.x - cursor_start.x, cursor_end.y - cursor_start.y });
					ImGui::PopStyleColor(ImGuiCol_COUNT);

					if (ImGui::BeginPopupContextItem("adwdawaef"))
					{
						if (ImGui::MenuItem("Duplicate"))
						{
							field_event_index = field_index;
							duplicate_field = true;
						}
						if (ImGui::MenuItem("Add Field Before"))
						{
							field_event_index = field_index;
						}
						if (ImGui::MenuItem("Add Field After"))
						{
							field_event_index = field_index + 1;
						}
						if (field->original_field && ImGui::MenuItem("Restore Original"))
						{
							const blofeld::s_tag_field& original_field = *field->original_field;
							c_runtime_tag_definitions& runtime_tag_definitions = field->runtime_tag_definitions;

							field->~c_runtime_tag_field();
							new(field) c_runtime_tag_field(runtime_tag_definitions, original_field);
						}
						ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);

						if (ImGui::MenuItem("Delete"))
						{
							field_event_index = field_index;
							delete_field = true;
						}

						ImGui::EndPopup();
					}
					ImGui::PopID();
				}
				ImGui::SetCursorPos(cursor2);

			}
			ImGui::EndChild();
		}

		if (field_event_index != UINT_MAX)
		{
			if (delete_field)
			{
				c_runtime_tag_field* field = fields[field_event_index];
				fields.erase(fields.begin() + field_event_index);
				delete field;
			}
			else
			{
				c_runtime_tag_field* field = nullptr;
				if (duplicate_field)
				{
					c_runtime_tag_field* source_field = fields[field_event_index];
					field = new c_runtime_tag_field(*runtime_tag_definitions, *source_field);
					field->name += " (copy)";
					field_event_index++;
				}
				else
				{
					field = new c_runtime_tag_field(*runtime_tag_definitions);
				}
				fields_changes = true;
				fields.insert(fields.begin() + field_event_index, field);
			}
		}
	}
}

void c_definition_tweaker::render_array_definitions_tab()
{
	if (ImGui::BeginTabItem("Arrays"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_string_list_definitions_tab()
{
	if (ImGui::BeginTabItem("String Lists"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_reference_definitions_tab()
{
	if (ImGui::BeginTabItem("References"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_resource_definitions_tab()
{
	if (ImGui::BeginTabItem("Resources"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_interop_definitions_tab()
{
	if (ImGui::BeginTabItem("Interops"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_data_definitions_tab()
{
	if (ImGui::BeginTabItem("Datas"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_block_index_custom_search_definitions_tab()
{
	if (ImGui::BeginTabItem("Block Index"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_serialization_tab()
{
	if (ImGui::BeginTabItem("Serialization"))
	{
		if (ImGui::BeginChild("Serialization Contexts"))
		{
			if (ImGui::Button("Refresh"))
			{
				parse_binary();
			}

			//ImGui::BeginChild("left column", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar);

			render_missing_group_serialization_context_tree();

			for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
			{
				render_group_serialization_context_tree(group_serialization_context);
			}


			ImGui::EndChild();
		}
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::enqueue_name_edit_state_hack(e_definition_type definition_type, void* target_definition)
{
	ImGuiContext* g = ImGui::GetCurrentContext();

	name_edit_state_hack = g->InputTextState.Stb;
	name_edit_state_hack_definition_type = definition_type;
	name_edit_state_hack_ticks = 3;

	switch (definition_type)
	{
	case _definition_type_group_definition:
		next_group_definition = static_cast<decltype(next_group_definition)>(target_definition);
		break;
	case _definition_type_block_definition:
		next_block_definition = static_cast<decltype(next_block_definition)>(target_definition);
		break;
	case _definition_type_struct_definition:
		next_struct_definition = static_cast<decltype(next_struct_definition)>(target_definition);
		break;
	case _definition_type_array_definition:
		next_array_definition = static_cast<decltype(next_array_definition)>(target_definition);
		break;
	case _definition_type_string_list_definition:
		next_string_list_definition = static_cast<decltype(next_string_list_definition)>(target_definition);
		break;
	case _definition_type_reference_definition:
		next_reference_definition = static_cast<decltype(next_reference_definition)>(target_definition);
		break;
	case _definition_type_resource_definition:
		next_resource_definition = static_cast<decltype(next_resource_definition)>(target_definition);
		break;
	case _definition_type_interop_definition:
		next_interop_definition = static_cast<decltype(next_interop_definition)>(target_definition);
		break;
	case _definition_type_data_definition:
		next_data_definition = static_cast<decltype(next_data_definition)>(target_definition);
		break;
	case _definition_type_block_index_custom_search_definition:
		next_block_index_custom_search_definition = static_cast<decltype(next_block_index_custom_search_definition)>(target_definition);
		break;
	}

}

void c_definition_tweaker::handle_name_edit_state_hack(e_definition_type definition_type)
{
	if (name_edit_state_hack_definition_type == definition_type)
	{
		if (name_edit_state_hack_ticks > 0)
		{
			ImGuiContext* g = ImGui::GetCurrentContext();
			ImGuiWindow* window = ImGui::GetCurrentWindow();

			ImGui::SetNavWindow(window);
			ImGuiScrollFlags scroll_flags = window->Appearing ? ImGuiScrollFlags_KeepVisibleEdgeX | ImGuiScrollFlags_AlwaysCenterY : ImGuiScrollFlags_KeepVisibleEdgeX | ImGuiScrollFlags_KeepVisibleEdgeY;
			ImGui::NavMoveRequestSubmit(ImGuiDir_None, ImGuiDir_Up, ImGuiNavMoveFlags_Tabbing | ImGuiNavMoveFlags_FocusApi, scroll_flags); // FIXME-NAV: Once we refactor tabbing, add LegacyApi flag to not activate non-inputable.
			ImGui::NavMoveRequestResolveWithLastItem(&g->NavMoveResultLocal);

			g->InputTextState.Stb.cursor = name_edit_state_hack.cursor;
			g->InputTextState.Stb.select_start = name_edit_state_hack.select_start;
			g->InputTextState.Stb.select_end = name_edit_state_hack.select_end;
			g->InputTextState.Stb.insert_mode = name_edit_state_hack.insert_mode;

			name_edit_state_hack_ticks--;
		}
		else
		{
			name_edit_state_hack_definition_type = k_num_definition_types;
		}
	}
}
