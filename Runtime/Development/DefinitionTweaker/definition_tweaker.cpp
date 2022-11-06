#include "definitiontweaker-private-pch.h"

define_float_setting(c_definition_tweaker, float, serialization_column_weight, _settings_section_tool, 0.4f);
define_float_setting(c_definition_tweaker, float, definitions_column_weight, _settings_section_tool, 0.6f);
define_float_setting(c_definition_tweaker, float, serialization_definition_list_column_weight, _settings_section_tool, 0.4f);
define_integer_setting(c_definition_tweaker, e_serialization_error_type, serialization_definition_list_mode, _settings_section_tool, _serialization_error_type_ok);
define_integer_setting(c_definition_tweaker, tag, serialization_definition_list_group, _settings_section_tool, blofeld::INVALID_TAG);

const char* definition_type_to_string[] =
{
	"Group",
	"Block",
	"Struct",
	"Array",
	"String List",
	"Reference",
	"Resource",
	"Interop",
	"Data",
	"Block Index Custom Search",
	"BAD"
};

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
	char buffer[16384];
	strcpy_s(buffer, _countof(buffer), string.c_str());
	if (result = ImGui::InputText(name, buffer, _countof(buffer), flags, callback, user_data))
	{
		string = buffer;
	}
	return result;
}

static bool imgui_input_text_multiline_std_string(const char* name, std::string& string, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL)
{
	bool result;
	char buffer[16384];
	strcpy_s(buffer, _countof(buffer), string.c_str());
	if (result = ImGui::InputTextMultiline(name, buffer, _countof(buffer), size, flags, callback, user_data))
	{
		string = buffer;
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
	if (result = ImGui::InputText("Group Tag", group_tag_buffer, _countof(group_tag_buffer)))
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
	groupless_serialization_contexts(),
	open_tag_indices(),
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
	field_definition_search_buffer(),
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
	open_field_definitions(),
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
	next_field_definition(),
	name_edit_state_hack_definition_type(k_num_definition_types),
	name_edit_state_hack(),
	selected_definition_type(k_num_definition_types),
	selected_target_definition(),
	next_selected_definition_tab_type(k_num_definition_types),
	context_event_type(_definition_tweaker_context_event_none),
	context_event_definition_type(),
	context_event_index(SIZE_MAX),
	context_event_pointer(nullptr),
	cache_file_tags_header(),
	tag_cache_offsets()
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

	runtime_tag_definitions = new() c_runtime_tag_definitions();
	runtime_tag_definitions->init_from_blofeld(engine_platform_build);

	parse_binary(blofeld::INVALID_TAG);
}

void c_definition_tweaker::cleanup()
{
	for (c_tag_serialization_context* serialization_context : groupless_serialization_contexts)
	{
		delete serialization_context;
	}
	groupless_serialization_contexts.clear();

	for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
	{
		delete group_serialization_context;
	}
	group_serialization_contexts.clear();
}

static void group_serialization_context_read(void* userdata, size_t thread_index)
{
	c_group_serialization_context* group_serialization_context = static_cast<decltype(group_serialization_context)>(userdata);
	BCS_RESULT rs = BCS_S_OK;
	do
	{
		rs = group_serialization_context->read();
	} while (rs == BCS_S_CONTINUE);
}

static void group_serialization_context_traverse(void* userdata, size_t thread_index)
{
	c_group_serialization_context* group_serialization_context = static_cast<decltype(group_serialization_context)>(userdata);
	BCS_RESULT rs = BCS_S_OK;
	do
	{
		rs = group_serialization_context->traverse();
	} while (rs == BCS_S_CONTINUE);
}

static void group_serialization_contexts_read(void* userdata, size_t thread_index)
{
	std::vector<c_group_serialization_context*> const& group_serialization_contexts = *static_cast<decltype(&group_serialization_contexts)>(userdata);
	for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
	{
		group_serialization_context_read(group_serialization_context, thread_index);
	}
}

static void group_serialization_contexts_traverse(void* userdata, size_t thread_index)
{
	std::vector<c_group_serialization_context*> const& group_serialization_contexts = *static_cast<decltype(&group_serialization_contexts)>(userdata);
	for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
	{
		group_serialization_context_traverse(group_serialization_context, thread_index);
	}
}

void c_definition_tweaker::parse_binary(tag specific_group)
{
	if (specific_group == blofeld::INVALID_TAG)
	{
		for (c_tag_serialization_context* serialization_context : groupless_serialization_contexts)
		{
			delete serialization_context;
		}
		groupless_serialization_contexts.clear();

		for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
		{
			delete group_serialization_context;
		}
		group_serialization_contexts.clear();

		cache_file_tags_header = static_cast<s_cache_file_tags_header*>(binary_data[_binary_tags]);
		tag_cache_offsets = reinterpret_cast<unsigned int*>(static_cast<char*>(binary_data[_binary_tags]) + cache_file_tags_header->tag_cache_offsets);

		for (c_runtime_tag_group_definition* tag_group : runtime_tag_definitions->tag_group_definitions)
		{
			c_group_serialization_context* group_serialization_context = new() c_group_serialization_context(*this, *tag_group);
			group_serialization_contexts.push_back(group_serialization_context);
		}

		parallel_invoke_threadcount(group_serialization_contexts_read, &group_serialization_contexts);
		parallel_invoke_threadcount(group_serialization_contexts_traverse, &group_serialization_contexts);

		//for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
		//{
		//	group_serialization_context->read();
		//}

		//for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
		//{
		//	group_serialization_context->traverse();
		//}

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
				if (current_group_serialization_context->runtime_tag_group_definition.group_tag == tag_header->group_tags[0])
				{
					group_serialization_context = current_group_serialization_context;
					break;
				}
			}
			if (group_serialization_context != nullptr)
			{
				continue;
			}

			c_tag_serialization_context* tag_serialization_context = new() c_tag_serialization_context(*this, engine_platform_build, tag_cache_offset_index, tag_data_start);
			groupless_serialization_contexts.push_back(tag_serialization_context);
		}

		for (c_tag_serialization_context* tag_serialization_context : groupless_serialization_contexts)
		{
			tag_serialization_context->read();
		}

		for (c_tag_serialization_context* tag_serialization_context : groupless_serialization_contexts)
		{
			tag_serialization_context->traverse();
		}
	}
	else
	{
		c_group_serialization_context* selected_group_serialization_context = nullptr;
		size_t selected_group_serialization_context_index = SIZE_MAX;
		for (size_t group_serialization_context_index = 0; group_serialization_context_index < group_serialization_contexts.size(); group_serialization_context_index++)
		{
			c_group_serialization_context* group_serialization_context = group_serialization_contexts[group_serialization_context_index];
			if (group_serialization_context->group_tag == specific_group)
			{
				selected_group_serialization_context_index = group_serialization_context_index;
				selected_group_serialization_context = group_serialization_context;
			}
		}
		if (selected_group_serialization_context)
		{
			if (c_runtime_tag_group_definition* runtime_tag_group_definition = runtime_tag_definitions->get_tag_group_by_group_tag(specific_group))
			{
				selected_group_serialization_context->~c_group_serialization_context();
				new(selected_group_serialization_context) c_group_serialization_context(*this, *runtime_tag_group_definition);

				parallel_invoke_threadcount(group_serialization_context_read, selected_group_serialization_context);
				parallel_invoke_threadcount(group_serialization_context_traverse, selected_group_serialization_context);
			}
			else
			{
				delete selected_group_serialization_context;
				group_serialization_contexts.erase(group_serialization_contexts.begin() + selected_group_serialization_context_index);
			}
		}
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

void c_definition_tweaker::render_missing_group_serialization_context_tree()
{
	if (groupless_serialization_contexts.empty() || serialization_definition_list_mode > _serialization_error_type_error)
	{
		return;
	}

	ImGui::PushID("<missing group>");

	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[_serialization_error_type_error]);
	static ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (ImGui::TreeNodeEx("<missing group>", flags))
	{
		for (c_tag_serialization_context* tag_serialization_context : groupless_serialization_contexts)
		{
			tag_serialization_context->render_tree();
		}
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();

	ImGui::PopID();
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
	// imgui_main_window_flags |= ImGuiWindowFlags_MenuBar;
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
		ImGui::SetNextItemWidth(-1.0f);
		ImVec2 selected_item_cursor_position = ImGui::GetCursorScreenPos();

		if (ImGui::BeginTable("##Viewport", 2, ImGuiTableFlags_Resizable))
		{
			ImGui::TableSetupColumn("Serialization", ImGuiTableColumnFlags_WidthStretch, c_definition_tweaker::get_serialization_column_weight_setting());
			ImGui::TableSetupColumn("Definitions", ImGuiTableColumnFlags_WidthStretch, c_definition_tweaker::get_definitions_column_weight_setting());

			ImGuiTable* table = ImGui::GetCurrentTable();
			if (c_definition_tweaker::get_serialization_column_weight_setting() != table->Columns[0].StretchWeight)
			{
				c_definition_tweaker::set_serialization_column_weight_setting(table->Columns[0].StretchWeight);
			}
			if (c_definition_tweaker::get_definitions_column_weight_setting() != table->Columns[1].StretchWeight)
			{
				c_definition_tweaker::set_definitions_column_weight_setting(table->Columns[1].StretchWeight);
			}

			selected_item_cursor_position.y = ImGui::GetCursorScreenPos().y;

			ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::BeginTabBar("##serialization"))
			{
				// ImGui::Text("%f", table->Columns[0].StretchWeight);
				// ImGui::Text("%f", table->Columns[1].StretchWeight);
				render_serialization_tab();

				//for (unsigned int open_tag_index : open_tag_indices)
				//{
				//	if (open_tag_index < serialization_contexts.size())
				//	{
				//		c_tag_serialization_context* serialization_context = serialization_contexts[open_tag_index];

				//		// #TODO:
				//	}
				//}

				ImGui::EndTabBar();
			}
			ImGui::TableNextColumn();
			if (ImGui::BeginTabBar("##definitions"))
			{
				selected_item_cursor_position.x = ImGui::GetCursorScreenPos().x;

				render_definitions_view(
					"Groups",
					_definition_type_group_definition,
					&c_definition_tweaker::render_group_definitions_list,
					&c_definition_tweaker::render_group_definitions_tabs);
				render_definitions_view(
					"Blocks",
					_definition_type_block_definition,
					&c_definition_tweaker::render_block_definitions_list,
					&c_definition_tweaker::render_block_definitions_tabs);
				render_definitions_view(
					"Structs",
					_definition_type_struct_definition,
					&c_definition_tweaker::render_struct_definitions_list,
					&c_definition_tweaker::render_struct_definitions_tabs);
				render_definitions_view(
					"Arrays",
					_definition_type_array_definition,
					&c_definition_tweaker::render_array_definitions_list,
					&c_definition_tweaker::render_array_definitions_tabs);
				render_definitions_view(
					"String Lists",
					_definition_type_string_list_definition,
					&c_definition_tweaker::render_string_list_definitions_list,
					&c_definition_tweaker::render_string_list_definitions_tabs);
				render_definitions_view(
					"References",
					_definition_type_reference_definition,
					&c_definition_tweaker::render_reference_definitions_list,
					&c_definition_tweaker::render_reference_definitions_tabs);
				render_definitions_view(
					"Resources",
					_definition_type_resource_definition,
					&c_definition_tweaker::render_resource_definitions_list,
					&c_definition_tweaker::render_resource_definitions_tabs);
				render_definitions_view(
					"Interops",
					_definition_type_interop_definition,
					&c_definition_tweaker::render_interop_definitions_list,
					&c_definition_tweaker::render_interop_definitions_tabs);
				render_definitions_view(
					"Datas",
					_definition_type_data_definition,
					&c_definition_tweaker::render_data_definitions_list,
					&c_definition_tweaker::render_data_definitions_tabs);
				render_definitions_view(
					"Block Index Search",
					_definition_type_block_index_custom_search_definition,
					&c_definition_tweaker::render_block_index_custom_search_definitions_list,
					&c_definition_tweaker::render_block_index_custom_search_definitions_tabs);
				render_definitions_view(
					"Fields",
					_definition_type_field_definition,
					&c_definition_tweaker::render_field_definitions_list,
					&c_definition_tweaker::render_field_definitions_tabs);

				ImGui::EndTabBar();
			}

			ImGui::EndTable();
		}

		if (selected_target_definition)
		{
			char definition_text_buffer[256] = { 0 };
#define selected_target_definition_helper(_definition_type, t_runtime_definition)							\
			if(selected_definition_type == _definition_type) snprintf(										\
				definition_text_buffer, 																	\
				_countof(definition_text_buffer), 															\
				"%s: %s", 																					\
				definition_type_to_string[selected_definition_type], 										\
				static_cast<t_runtime_definition*>(selected_target_definition)->name.c_str());

			selected_target_definition_helper(_definition_type_group_definition, c_runtime_tag_group_definition);
			selected_target_definition_helper(_definition_type_block_definition, c_runtime_tag_block_definition);
			selected_target_definition_helper(_definition_type_struct_definition, c_runtime_tag_struct_definition);
			selected_target_definition_helper(_definition_type_array_definition, c_runtime_tag_array_definition);
			selected_target_definition_helper(_definition_type_string_list_definition, c_runtime_string_list_definition);
			selected_target_definition_helper(_definition_type_reference_definition, c_runtime_tag_reference_definition);
			selected_target_definition_helper(_definition_type_resource_definition, c_runtime_tag_resource_definition);
			selected_target_definition_helper(_definition_type_interop_definition, c_runtime_tag_api_interop_definition);
			selected_target_definition_helper(_definition_type_data_definition, c_runtime_tag_data_definition);
			selected_target_definition_helper(_definition_type_block_index_custom_search_definition, c_runtime_tag_block_index_custom_search_definition);

#undef selected_target_definition_helper
			if (*definition_text_buffer)
			{
				selected_item_cursor_position.x += ImGui::CalcTextSize("Definitions ").x;
				ImDrawList* draw_list = ImGui::GetWindowDrawList();
				draw_list->AddText({ selected_item_cursor_position.x + 4.0f, selected_item_cursor_position.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_WARNING_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA)), definition_text_buffer);
			}
		}
	}
	ImGui::End();

	mandrill_theme_pop();

	handle_definition_context_menu();
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

void c_definition_tweaker::render_group_definitions_list()
{
	if (ImGui::BeginChild("Groups"))
	{
		bool search_active = render_search_box(group_definition_search_buffer, _countof(group_definition_search_buffer));
		if (ImGui::Button("Create Group"))
		{
			c_runtime_tag_group_definition& group_definition = runtime_tag_definitions->create_tag_group_definition();
			open_type_tab(_definition_type_group_definition, &group_definition);
		}

		if (ImGui::BeginChild("GroupsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t group_event_index = SIZE_MAX;
			bool delete_group = false;
			bool duplicate_group = false;

			//for (c_runtime_tag_group_definition* group_definition : runtime_tag_definitions->group_definitions)
			for (size_t group_definition_index = 0; group_definition_index < runtime_tag_definitions->tag_group_definitions.size(); group_definition_index++)
			{
				c_runtime_tag_group_definition* group_definition = runtime_tag_definitions->tag_group_definitions[group_definition_index];

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
							open_type_tab(_definition_type_group_definition, group_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_group_definition, group_definition);
				}
				ImGui::PopID();
			}

			if (group_event_index != SIZE_MAX)
			{
				if (delete_group)
				{
					c_runtime_tag_group_definition* group_definition = runtime_tag_definitions->tag_group_definitions[group_event_index];
					runtime_tag_definitions->delete_tag_group_definition(*group_definition);
				}
				else if (duplicate_group)
				{
					c_runtime_tag_group_definition* old_group_definition = runtime_tag_definitions->tag_group_definitions[group_event_index];
					c_runtime_tag_group_definition& new_group_definition = runtime_tag_definitions->duplicate_tag_group_definition(*old_group_definition);
					open_group_definitions.insert(open_group_definitions.end(), &new_group_definition);
					new_group_definition.name += " (copy)";
					next_group_definition = &new_group_definition;
					runtime_tag_definitions->sort_tag_group_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_group_definitions_tabs()
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
					runtime_tag_definitions->sort_tag_group_definitions();
				}
				handle_name_edit_state_hack(_definition_type_group_definition);

				imgui_input_text_std_string("Symbol Name", group_definition->symbol_name);

				if (imgui_input_text_tag("Group Tag", group_definition->group_tag))
				{
					mark_modified();
				}

				ImGui::InputInt("Version", reinterpret_cast<int*>(&group_definition->version));

				if (selcted_type_assignment(_definition_type_block_definition, "Block", group_definition->block_definition))
				{
					group_definition->block_definition = &runtime_tag_definitions->create_tag_block_definition();
					group_definition->block_definition->pretty_name = group_definition->name + "_block";
					group_definition->block_definition->name = group_definition->name + "_block";
					group_definition->block_definition->symbol_name = group_definition->symbol_name + "_block";
					group_definition->block_definition->max_count = 1;
					group_definition->block_definition->max_count_string = "1";
					open_type_tab(_definition_type_block_definition, group_definition->block_definition);
				}
				if (selcted_type_assignment(_definition_type_group_definition, "Parent Group", group_definition->parent_tag_group))
				{
					group_definition->parent_tag_group = &runtime_tag_definitions->create_tag_group_definition();
					open_type_tab(_definition_type_group_definition, group_definition->parent_tag_group);
				}
			}
			ImGui::EndChild();
			ImGui::EndTabItem();
		}
		if (!open)
		{
			open_group_definitions.erase(group_definition);
		}
		ImGui::PopID();
	}
}

void c_definition_tweaker::render_block_definitions_list()
{
	if (ImGui::BeginChild("Blocks"))
	{
		bool search_active = render_search_box(block_definition_search_buffer, _countof(block_definition_search_buffer));
		if (ImGui::Button("Create Block"))
		{
			c_runtime_tag_block_definition& block_definition = runtime_tag_definitions->create_tag_block_definition();
			open_type_tab(_definition_type_block_definition, &block_definition);
		}

		if (ImGui::BeginChild("BlocksList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t block_event_index = SIZE_MAX;
			bool delete_block = false;
			bool duplicate_block = false;

			//for (c_runtime_tag_block_definition* block_definition : runtime_tag_definitions->block_definitions)
			for (size_t block_definition_index = 0; block_definition_index < runtime_tag_definitions->tag_block_definitions.size(); block_definition_index++)
			{
				c_runtime_tag_block_definition* block_definition = runtime_tag_definitions->tag_block_definitions[block_definition_index];

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
							open_type_tab(_definition_type_block_definition, block_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_block_definition, block_definition);
				}
				ImGui::PopID();
			}

			if (block_event_index != SIZE_MAX)
			{
				if (delete_block)
				{
					c_runtime_tag_block_definition* block_definition = runtime_tag_definitions->tag_block_definitions[block_event_index];
					runtime_tag_definitions->delete_tag_block_definition(*block_definition);
				}
				else if (duplicate_block)
				{
					c_runtime_tag_block_definition* old_block_definition = runtime_tag_definitions->tag_block_definitions[block_event_index];
					c_runtime_tag_block_definition& new_block_definition = runtime_tag_definitions->duplicate_tag_block_definition(*old_block_definition);
					open_block_definitions.insert(open_block_definitions.end(), &new_block_definition);
					new_block_definition.name += " (copy)";
					next_block_definition = &new_block_definition;
					runtime_tag_definitions->sort_tag_block_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_block_definitions_tabs()
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
				imgui_input_text_std_string("Pretty Name", block_definition->pretty_name);

				if (imgui_input_text_std_string("Name", block_definition->name))
				{
					enqueue_name_edit_state_hack(_definition_type_block_definition, block_definition);
					runtime_tag_definitions->sort_tag_block_definitions();
				}
				handle_name_edit_state_hack(_definition_type_block_definition);

				imgui_input_text_std_string("Symbol Name", block_definition->symbol_name);

				unsigned long previous_count = block_definition->max_count;
				if (ImGui::InputScalar("Max Count", ImGuiDataType_U32, &block_definition->max_count))
				{
					unsigned long existing_string_count = strtoul(block_definition->max_count_string.c_str(), nullptr, 10);
					if (block_definition->max_count_string == "0" || (existing_string_count != 0 && existing_string_count == previous_count))
					{
						char buffer[32] = {};
						ultoa(block_definition->max_count, buffer, 10);
						block_definition->max_count_string = buffer;
					}
				}

				if (imgui_input_text_std_string("Max Count String", block_definition->max_count_string))
				{
					unsigned long max_count_from_string = strtoul(block_definition->max_count_string.c_str(), nullptr, 10);
					if (block_definition->max_count_string == "0" || max_count_from_string > 0)
					{
						block_definition->max_count = static_cast<unsigned int>(max_count_from_string);
					}
				}

				if (selcted_type_assignment(_definition_type_struct_definition, "Struct", block_definition->struct_definition))
				{
					block_definition->struct_definition = &runtime_tag_definitions->create_tag_struct_definition();
					block_definition->struct_definition->pretty_name = block_definition->name + "_struct";
					block_definition->struct_definition->name = block_definition->name + "_struct";
					block_definition->struct_definition->type_name = std::string("s_") + block_definition->struct_definition->name;
					block_definition->struct_definition->symbol_name = block_definition->symbol_name + "_struct";
					open_type_tab(_definition_type_struct_definition, block_definition->struct_definition);
				}
			}
			ImGui::EndChild();
			ImGui::EndTabItem();
		}
		if (!open)
		{
			open_block_definitions.erase(block_definition);
		}
		ImGui::PopID();
	}
}

void c_definition_tweaker::render_struct_definitions_list()
{
	if (ImGui::BeginChild("struct_definition_list"))
	{
		bool search_active = render_search_box(struct_definition_search_buffer, _countof(struct_definition_search_buffer));
		if (ImGui::Button("Create Structure"))
		{
			c_runtime_tag_struct_definition& struct_definition = runtime_tag_definitions->create_tag_struct_definition();
			open_type_tab(_definition_type_struct_definition, &struct_definition);
		}

		if (ImGui::BeginChild("StructuresList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t struct_event_index = SIZE_MAX;
			bool delete_struct = false;
			bool duplicate_struct = false;

			//for (c_runtime_tag_struct_definition* struct_definition : runtime_tag_definitions->struct_definitions)
			for (size_t structure_definition_index = 0; structure_definition_index < runtime_tag_definitions->tag_struct_definitions.size(); structure_definition_index++)
			{
				c_runtime_tag_struct_definition* struct_definition = runtime_tag_definitions->tag_struct_definitions[structure_definition_index];

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
							open_type_tab(_definition_type_struct_definition, struct_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_struct_definition, struct_definition);
				}
				ImGui::PopID();
			}

			if (struct_event_index != SIZE_MAX)
			{
				if (delete_struct)
				{
					c_runtime_tag_struct_definition* struct_definition = runtime_tag_definitions->tag_struct_definitions[struct_event_index];
					runtime_tag_definitions->delete_tag_struct_definition(*struct_definition);
				}
				else if (duplicate_struct)
				{
					c_runtime_tag_struct_definition* old_struct_definition = runtime_tag_definitions->tag_struct_definitions[struct_event_index];
					c_runtime_tag_struct_definition& new_struct_definition = runtime_tag_definitions->duplicate_tag_struct_definition(*old_struct_definition);
					open_struct_definitions.insert(open_struct_definitions.end(), &new_struct_definition);
					new_struct_definition.name += " (copy)";
					new_struct_definition.persistent_identifier = { UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX };
					next_struct_definition = &new_struct_definition;
					runtime_tag_definitions->sort_tag_struct_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_struct_definitions_tabs()
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


			}
			ImGui::EndChild();
			ImGui::EndTabItem();
		}
		if (!open)
		{
			open_struct_definitions.erase(struct_definition);
		}
		ImGui::PopID();
	}
}

void c_definition_tweaker::render_struct_definition(c_runtime_tag_struct_definition* struct_definition)
{
	ImGui::BeginGroup();

	imgui_input_text_std_string("Pretty Name", struct_definition->pretty_name);

	if (imgui_input_text_std_string("Name", struct_definition->name))
	{
		enqueue_name_edit_state_hack(_definition_type_struct_definition, struct_definition);
		runtime_tag_definitions->sort_tag_struct_definitions();
	}
	handle_name_edit_state_hack(_definition_type_struct_definition);

	imgui_input_text_std_string("Structure Name", struct_definition->type_name);

	imgui_input_text_std_string("Symbol Name", struct_definition->symbol_name);

	if (ImGui::InputScalarN("Persistent Identifier", ImGuiDataType_U32, &struct_definition->persistent_identifier, 4))
	{
		mark_modified();
	}

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
		ImGui::BeginDisabled();
		imgui_checkbox_cflags("mandrill_has_versioning", struct_definition->runtime_flags, blofeld::_tag_field_set_mandrill_has_versioning);
		ImGui::EndDisabled();
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
	bool fields_changed = false;
	if (ImGui::CollapsingHeader("Fields", ImGuiTreeNodeFlags_DefaultOpen))
	{
		std::vector<t_blamtoozle_tag_field*>& fields = struct_definition->fields;
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

		if (ImGui::BeginChild("FieldsList", child_size, false, ImGuiWindowFlags_HorizontalScrollbar))
		{
			ImGui::SetNextItemWidth(-1.0f);
			char buf[1] = { 0 };
			ImGui::InputText("text", buf, 1);
			if (ImGui::IsWindowHovered())
			{
				ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
			}

			ImVec2 cursor = ImGui::GetCursorPos();
			if (ImGui::BeginTable("FieldsTable", 5))
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
				//ImGui::TableSetupColumn("Units");
				//ImGui::TableSetupColumn("Limits");
				ImGui::TableSetupColumn("Ext", ImGuiTableColumnFlags_WidthFixed, 350);

				ImGui::TableHeadersRow();

				ImVec2* _cursor_start = trivial_alloca(ImVec2, fields.size());
				ImVec2* _cursor_end = trivial_alloca(ImVec2, fields.size());

				for (size_t field_index = 0; field_index < fields.size(); field_index++)
				{
					t_blamtoozle_tag_field* blamtoozle_field = fields[field_index];
					if (c_runtime_tag_field_definition* field = dynamic_cast<c_runtime_tag_field_definition*>(blamtoozle_field))
					{
						ImGui::PushID(field);


						ImGui::BeginGroup();
						ImGui::TableNextRow();
						ImGui::TableNextColumn();
						_cursor_start[field_index] = ImGui::GetCursorPos();
						if (field->field_type == blofeld::_field_version)
						{
							ImGui::Text("VERSION");
						}
						else
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
									if (field_index_next >= 0 && field_index_next < fields.size())
									{
										fields.erase(fields.begin() + field_index);
										fields.insert(fields.begin() + field_index_next, field);
										ImGui::ResetMouseDragDelta();
										fields_changed = true;
									}
								}
							}
						}
						ImGui::TableNextColumn();
						if (field->field_type == blofeld::_field_version)
						{
							ImGui::Text("VERSION");
						}
						else
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
										fields_changed = true;
									}
								}
								ImGui::EndCombo();
							}
						}
						if (field->field_type == blofeld::_field_version)
						{
							ImGui::TableNextColumn();
							ImGui::Text("VERSION");
							ImGui::TableNextColumn();
							ImGui::Text("VERSION");
						}
						else
						{
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
							//string_edit("units", field->units, false, "units", row_height);
							//string_edit("limits", field->limits, false, "limits", row_height);
						}

						ImGui::TableNextColumn();
						{
							switch (field->field_type)
							{
							case blofeld::_field_block:
								if (selcted_type_assignment(_definition_type_block_definition, "", field->block_definition))
								{
									field->block_definition = &runtime_tag_definitions->create_tag_block_definition();
									open_type_tab(_definition_type_block_definition, field->block_definition);
								}
								break;
							case blofeld::_field_struct:
								if (selcted_type_assignment(_definition_type_struct_definition, "", field->struct_definition))
								{
									field->struct_definition = &runtime_tag_definitions->create_tag_struct_definition();
									open_type_tab(_definition_type_struct_definition, field->struct_definition);
								}
								break;
							case blofeld::_field_array:
								if (selcted_type_assignment(_definition_type_array_definition, "", field->array_definition))
								{
									field->array_definition = &runtime_tag_definitions->create_tag_array_definition();
									open_type_tab(_definition_type_array_definition, field->array_definition);
								}
								break;
							case blofeld::_field_char_enum:
							case blofeld::_field_short_enum:
							case blofeld::_field_long_enum:
							case blofeld::_field_long_flags:
							case blofeld::_field_word_flags:
							case blofeld::_field_byte_flags:
								if (selcted_type_assignment(_definition_type_string_list_definition, "", field->string_list_definition))
								{
									field->string_list_definition = &runtime_tag_definitions->create_string_list_definition();
									open_type_tab(_definition_type_string_list_definition, field->string_list_definition);
								}
								break;
							case blofeld::_field_tag_reference:
								if (selcted_type_assignment(_definition_type_reference_definition, "", field->tag_reference_definition))
								{
									field->tag_reference_definition = &runtime_tag_definitions->create_tag_reference_definition();
									open_type_tab(_definition_type_reference_definition, field->tag_reference_definition);
								}
								break;
							case blofeld::_field_data:
								if (selcted_type_assignment(_definition_type_data_definition, "", field->tag_data_definition))
								{
									field->tag_data_definition = &runtime_tag_definitions->create_tag_data_definition();
									open_type_tab(_definition_type_data_definition, field->tag_data_definition);
								}
								break;
							case blofeld::_field_pageable_resource:
								if (selcted_type_assignment(_definition_type_resource_definition, "", field->tag_resource_definition))
								{
									field->tag_resource_definition = &runtime_tag_definitions->create_tag_resource_definition();
									open_type_tab(_definition_type_resource_definition, field->tag_resource_definition);
								}
								break;
							case blofeld::_field_api_interop:
								if (selcted_type_assignment(_definition_type_interop_definition, "", field->tag_interop_definition))
								{
									field->tag_interop_definition = &runtime_tag_definitions->create_tag_api_interop_definition();
									open_type_tab(_definition_type_interop_definition, field->tag_interop_definition);
								}
								break;
							case blofeld::_field_char_block_index_custom_search:
							case blofeld::_field_short_block_index_custom_search:
							case blofeld::_field_long_block_index_custom_search:
								if (selcted_type_assignment(_definition_type_interop_definition, "", field->block_index_custom_search_definition))
								{
									field->block_index_custom_search_definition = &runtime_tag_definitions->create_block_index_custom_search_definition();
									open_type_tab(_definition_type_interop_definition, field->block_index_custom_search_definition);
								}
								break;
							case blofeld::_field_skip:
								ImGui::InputScalar("Length", ImGuiDataType_U32, &field->length);
								break;
							case blofeld::_field_pad:
							case blofeld::_field_useless_pad:
								ImGui::InputScalar("Padding", ImGuiDataType_U32, &field->padding);
								break;
							}
						}

						ImGui::EndGroup();

						_cursor_end[field_index] = ImGui::GetCursorPos();
						ImVec2 x = ImGui::GetContentRegionMax();
						_cursor_end[field_index].x = x.x;
						ImVec2 y = ImGui::GetWindowContentRegionMax();
						ImGui::PopID();

					}
				}
				ImGui::EndTable();

				ImVec2 cursor2 = ImGui::GetCursorPos();
				ImGui::SetCursorPos(cursor);
				for (size_t field_index = 0; field_index < fields.size(); field_index++)
				{
					if (c_runtime_tag_field_definition* field = dynamic_cast<c_runtime_tag_field_definition*>(fields[field_index]))
					{
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
							if (const blofeld::s_tag_field* original_field = field->original_field)
							{
								if (ImGui::MenuItem("Restore Original"))
								{
									field->restore(engine_platform_build);
								}
							}
							ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
							if (ImGui::MenuItem("Open in tab"))
							{
								open_type_tab(_definition_type_field_definition, field);
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
				}
				ImGui::SetCursorPos(cursor2);

			}
		}
		ImGui::EndChild();

		if (field_event_index != UINT_MAX)
		{
			if (delete_field)
			{
				t_blamtoozle_tag_field* blamtoozle_tag_field = fields[field_event_index];
				if (c_runtime_tag_field_definition* runtime_tag_field = dynamic_cast<c_runtime_tag_field_definition*>(blamtoozle_tag_field))
				{
					open_field_definitions.erase(dynamic_cast<c_runtime_tag_field_definition*>(runtime_tag_field));
					fields.erase(fields.begin() + field_event_index);
					runtime_tag_definitions->delete_tag_field_definition(*runtime_tag_field);
					fields_changed = true;
				}
			}
			else
			{
				c_runtime_tag_field_definition* field = nullptr;
				if (duplicate_field)
				{
					if (c_runtime_tag_field_definition* source_field = dynamic_cast<c_runtime_tag_field_definition*>(fields[field_event_index]))
					{
						field = &runtime_tag_definitions->duplicate_tag_field_definition(*source_field);
						field->name += " (copy)";
						field_event_index++;
						fields_changed = true;
					}
				}
				else
				{
					field = &runtime_tag_definitions->create_tag_field_definition();
					fields.insert(fields.begin() + field_event_index, field);
					fields_changed = true;
				}
			}
		}
	}
	if (fields_changed)
	{
		bool is_versioned = false;

		std::vector<t_blamtoozle_tag_field*>& fields = struct_definition->fields;
		for (t_blamtoozle_tag_field* blamtoozle_field : fields)
		{
			if (c_runtime_tag_field_definition* runtime_field = dynamic_cast<c_runtime_tag_field_definition*>(blamtoozle_field))
			{
				if (runtime_field->field_type == blofeld::_field_version)
				{
					is_versioned = true;
					break;
				}
			}
		}

		struct_definition->runtime_flags.set(blofeld::_tag_field_set_mandrill_has_versioning, is_versioned);
	}
}

void c_definition_tweaker::render_array_definitions_list()
{
	if (ImGui::BeginChild("Arrays"))
	{
		bool search_active = render_search_box(array_definition_search_buffer, _countof(array_definition_search_buffer));
		if (ImGui::Button("Create Array"))
		{
			c_runtime_tag_array_definition& array_definition = runtime_tag_definitions->create_tag_array_definition();
			open_type_tab(_definition_type_array_definition, &array_definition);
		}

		if (ImGui::BeginChild("ArraysList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t array_event_index = SIZE_MAX;
			bool delete_array = false;
			bool duplicate_array = false;

			//for (c_runtime_tag_array_definition* array_definition : runtime_tag_definitions->array_definitions)
			for (size_t array_definition_index = 0; array_definition_index < runtime_tag_definitions->tag_array_definitions.size(); array_definition_index++)
			{
				c_runtime_tag_array_definition* array_definition = runtime_tag_definitions->tag_array_definitions[array_definition_index];

				ImGui::PushID(array_definition);

				const char* array_name = "<unnamed array>";
				if (!array_definition->name.empty())
				{
					array_name = array_definition->name.c_str();
				}
				if (!search_active || strstr(array_name, array_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(array_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_array_definition, array_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_array_definition, array_definition);
				}
				ImGui::PopID();
			}

			if (array_event_index != SIZE_MAX)
			{
				if (delete_array)
				{
					c_runtime_tag_array_definition* array_definition = runtime_tag_definitions->tag_array_definitions[array_event_index];
					runtime_tag_definitions->delete_tag_array_definition(*array_definition);
				}
				else if (duplicate_array)
				{
					c_runtime_tag_array_definition* old_array_definition = runtime_tag_definitions->tag_array_definitions[array_event_index];
					c_runtime_tag_array_definition& new_array_definition = runtime_tag_definitions->duplicate_tag_array_definition(*old_array_definition);
					open_array_definitions.insert(open_array_definitions.end(), &new_array_definition);
					new_array_definition.name += " (copy)";
					next_array_definition = &new_array_definition;
					runtime_tag_definitions->sort_tag_array_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_array_definitions_tabs()
{
	auto open_array_definitions_copy = open_array_definitions;
	for (c_runtime_tag_array_definition* array_definition : open_array_definitions_copy)
	{
		ImGui::PushID(array_definition);

		const char* array_name = "unnamed array";
		if (!array_definition->name.empty())
		{
			array_name = array_definition->name.c_str();
		}

		bool open = true;
		ImGuiTabItemFlags flags = ImGuiTabItemFlags_None;
		if (next_array_definition == array_definition)
		{
			flags = flags | ImGuiTabItemFlags_SetSelected;
			next_array_definition = nullptr;
		}
		if (ImGui::BeginTabItem(array_name, &open, flags))
		{
			if (ImGui::BeginChild("ArraysList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
			{
				imgui_input_text_std_string("Pretty Name", array_definition->pretty_name);

				if (imgui_input_text_std_string("Name", array_definition->name))
				{
					enqueue_name_edit_state_hack(_definition_type_array_definition, array_definition);
					runtime_tag_definitions->sort_tag_array_definitions();
				}
				handle_name_edit_state_hack(_definition_type_array_definition);

				imgui_input_text_std_string("Symbol Name", array_definition->symbol_name);

				unsigned long previous_count = array_definition->element_count;
				if (ImGui::InputScalar("Element Count", ImGuiDataType_U32, &array_definition->element_count))
				{
					unsigned long existing_string_count = strtoul(array_definition->element_count_string.c_str(), nullptr, 10);
					if ((existing_string_count != 0 && existing_string_count == previous_count) || array_definition->element_count_string.empty() || array_definition->element_count_string == "0")
					{
						char buffer[32] = {};
						ultoa(array_definition->element_count, buffer, 10);
						array_definition->element_count_string = buffer;
					}
				}

				if (imgui_input_text_std_string("Element Count String", array_definition->element_count_string))
				{
					unsigned long max_count_from_string = strtoul(array_definition->element_count_string.c_str(), nullptr, 10);
					if (max_count_from_string > 0 || array_definition->element_count_string == "0" || array_definition->element_count_string.empty())
					{
						array_definition->element_count = static_cast<unsigned int>(max_count_from_string);
					}
				}
				if (selcted_type_assignment(_definition_type_struct_definition, "Struct", array_definition->struct_definition))
				{
					array_definition->struct_definition = &runtime_tag_definitions->create_tag_struct_definition();
					array_definition->struct_definition->pretty_name = array_definition->name + "_struct";
					array_definition->struct_definition->name = array_definition->name + "_struct";
					array_definition->struct_definition->symbol_name = array_definition->symbol_name + "_struct";
					open_type_tab(_definition_type_struct_definition, array_definition->struct_definition);
				}
			}
			ImGui::EndChild();
			ImGui::EndTabItem();
		}
		if (!open)
		{
			open_array_definitions.erase(array_definition);
		}
		ImGui::PopID();
	}
}

void c_definition_tweaker::render_string_list_definitions_list()
{
	if (ImGui::BeginChild("String Lists"))
	{
		bool search_active = render_search_box(string_list_definition_search_buffer, _countof(string_list_definition_search_buffer));
		if (ImGui::Button("Create String List"))
		{
			c_runtime_string_list_definition& string_list_definition = runtime_tag_definitions->create_string_list_definition();
			open_type_tab(_definition_type_string_list_definition, &string_list_definition);
		}

		if (ImGui::BeginChild("String ListsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t string_list_event_index = SIZE_MAX;
			bool delete_string_list = false;
			bool duplicate_string_list = false;

			//for (c_runtime_tag_string_list_definition* string_list_definition : runtime_tag_definitions->string_list_definitions)
			for (size_t string_list_definition_index = 0; string_list_definition_index < runtime_tag_definitions->tag_string_list_definitions.size(); string_list_definition_index++)
			{
				c_runtime_string_list_definition* string_list_definition = runtime_tag_definitions->tag_string_list_definitions[string_list_definition_index];

				ImGui::PushID(string_list_definition);

				const char* string_list_name = "<unnamed string_list>";
				if (!string_list_definition->name.empty())
				{
					string_list_name = string_list_definition->name.c_str();
				}
				if (!search_active || strstr(string_list_name, string_list_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(string_list_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_string_list_definition, string_list_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_string_list_definition, string_list_definition);
				}
				ImGui::PopID();
			}

			if (string_list_event_index != SIZE_MAX)
			{
				if (delete_string_list)
				{
					c_runtime_string_list_definition* string_list_definition = runtime_tag_definitions->tag_string_list_definitions[string_list_event_index];
					runtime_tag_definitions->delete_string_list_definition(*string_list_definition);
				}
				else if (duplicate_string_list)
				{
					c_runtime_string_list_definition* old_string_list_definition = runtime_tag_definitions->tag_string_list_definitions[string_list_event_index];
					c_runtime_string_list_definition& new_string_list_definition = runtime_tag_definitions->duplicate_string_list_definition(*old_string_list_definition);
					open_string_list_definitions.insert(open_string_list_definitions.end(), &new_string_list_definition);
					new_string_list_definition.name += " (copy)";
					next_string_list_definition = &new_string_list_definition;
					runtime_tag_definitions->sort_string_list_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_string_list_definitions_tabs()
{
	auto open_string_list_definitions_copy = open_string_list_definitions;
	for (c_runtime_string_list_definition* string_list_definition : open_string_list_definitions_copy)
	{
		ImGui::PushID(string_list_definition);

		const char* string_list_name = "unnamed string_list";
		if (!string_list_definition->name.empty())
		{
			string_list_name = string_list_definition->name.c_str();
		}

		bool open = true;
		ImGuiTabItemFlags flags = ImGuiTabItemFlags_None;
		if (next_string_list_definition == string_list_definition)
		{
			flags = flags | ImGuiTabItemFlags_SetSelected;
			next_string_list_definition = nullptr;
		}
		if (ImGui::BeginTabItem(string_list_name, &open, flags))
		{
			if (ImGui::BeginChild("string_listsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
			{
				if (imgui_input_text_std_string("Name", string_list_definition->name))
				{
					enqueue_name_edit_state_hack(_definition_type_string_list_definition, string_list_definition);
					runtime_tag_definitions->sort_string_list_definitions();
				}
				handle_name_edit_state_hack(_definition_type_string_list_definition);

				imgui_input_text_std_string("Symbol Name", string_list_definition->symbol_name);

				ImGui::Text("Count: %zu", string_list_definition->options.size());

				size_t delete_index = SIZE_MAX;
				if (ImGui::BeginTable("##options", 3))
				{
					ImGui::TableSetupColumn("##index", ImGuiTableColumnFlags_WidthFixed, 26.0f);
					ImGui::TableSetupColumn("##value", ImGuiTableColumnFlags_None, -1.0f);
					ImGui::TableSetupColumn("##buttons", ImGuiTableColumnFlags_None, -1.0f);

					for (size_t option_index = 0; option_index < string_list_definition->options.size(); option_index++)
					{
						ImGui::PushID(option_index);

						ImGui::TableNextRow();
						ImGui::TableNextColumn();
						{
							ImGui::Text("%zu", option_index);
						}
						ImGui::TableNextColumn();
						{
							std::string& option = string_list_definition->options[option_index];
							imgui_input_text_std_string("", option);
						}
						ImGui::TableNextColumn();
						if (ImGui::Button("Delete"))
						{
							delete_index = option_index;
						}

						ImGui::PopID();
					}

					//ImGui::BeginDisabled(string_list_definition->options.size() >= 32);
					{
						ImGui::TableNextRow();
						ImGui::TableNextColumn();
						{

						}
						ImGui::TableNextColumn();
						if (ImGui::Button("Add"))
						{
							string_list_definition->options.emplace_back();
						}
					}
					//ImGui::EndDisabled();

					ImGui::EndTable();
				}

				if (delete_index != SIZE_MAX)
				{
					string_list_definition->options.erase(string_list_definition->options.begin() + delete_index);
				}
			}
			ImGui::EndChild();
			ImGui::EndTabItem();
		}
		if (!open)
		{
			open_string_list_definitions.erase(string_list_definition);
		}
		ImGui::PopID();
	}
}

void c_definition_tweaker::render_reference_definitions_list()
{
	if (ImGui::BeginChild("References"))
	{
		bool search_active = render_search_box(reference_definition_search_buffer, _countof(reference_definition_search_buffer));
		if (ImGui::Button("Create Reference"))
		{
			c_runtime_tag_reference_definition& reference_definition = runtime_tag_definitions->create_tag_reference_definition();
			open_type_tab(_definition_type_reference_definition, &reference_definition);
		}

		if (ImGui::BeginChild("ReferencesList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t reference_event_index = SIZE_MAX;
			bool delete_reference = false;
			bool duplicate_reference = false;

			//for (c_runtime_tag_reference_definition* reference_definition : runtime_tag_definitions->reference_definitions)
			for (size_t reference_definition_index = 0; reference_definition_index < runtime_tag_definitions->tag_reference_definitions.size(); reference_definition_index++)
			{
				c_runtime_tag_reference_definition* reference_definition = runtime_tag_definitions->tag_reference_definitions[reference_definition_index];

				ImGui::PushID(reference_definition);

				const char* reference_name = "<unnamed reference>";
				if (!reference_definition->name.empty())
				{
					reference_name = reference_definition->name.c_str();
				}
				if (!search_active || strstr(reference_name, reference_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(reference_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_reference_definition, reference_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_reference_definition, reference_definition);
				}
				ImGui::PopID();
			}

			if (reference_event_index != SIZE_MAX)
			{
				if (delete_reference)
				{
					c_runtime_tag_reference_definition* reference_definition = runtime_tag_definitions->tag_reference_definitions[reference_event_index];
					runtime_tag_definitions->delete_tag_reference_definition(*reference_definition);
				}
				else if (duplicate_reference)
				{
					c_runtime_tag_reference_definition* old_reference_definition = runtime_tag_definitions->tag_reference_definitions[reference_event_index];
					c_runtime_tag_reference_definition& new_reference_definition = runtime_tag_definitions->duplicate_tag_reference_definition(*old_reference_definition);
					open_reference_definitions.insert(open_reference_definitions.end(), &new_reference_definition);
					new_reference_definition.name += " (copy)";
					next_reference_definition = &new_reference_definition;
					runtime_tag_definitions->sort_tag_reference_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_reference_definitions_tabs()
{
	if (ImGui::BeginTabItem("References"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_resource_definitions_list()
{
	if (ImGui::BeginChild("Resources"))
	{
		bool search_active = render_search_box(resource_definition_search_buffer, _countof(resource_definition_search_buffer));
		if (ImGui::Button("Create Resource"))
		{
			c_runtime_tag_resource_definition& resource_definition = runtime_tag_definitions->create_tag_resource_definition();
			open_type_tab(_definition_type_resource_definition, &resource_definition);
		}

		if (ImGui::BeginChild("ResourcesList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t resource_event_index = SIZE_MAX;
			bool delete_resource = false;
			bool duplicate_resource = false;

			//for (c_runtime_tag_resource_definition* resource_definition : runtime_tag_definitions->resource_definitions)
			for (size_t resource_definition_index = 0; resource_definition_index < runtime_tag_definitions->tag_resource_definitions.size(); resource_definition_index++)
			{
				c_runtime_tag_resource_definition* resource_definition = runtime_tag_definitions->tag_resource_definitions[resource_definition_index];

				ImGui::PushID(resource_definition);

				const char* resource_name = "<unnamed resource>";
				if (!resource_definition->name.empty())
				{
					resource_name = resource_definition->name.c_str();
				}
				if (!search_active || strstr(resource_name, resource_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(resource_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_resource_definition, resource_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_resource_definition, resource_definition);
				}
				ImGui::PopID();
			}

			if (resource_event_index != SIZE_MAX)
			{
				if (delete_resource)
				{
					c_runtime_tag_resource_definition* resource_definition = runtime_tag_definitions->tag_resource_definitions[resource_event_index];
					runtime_tag_definitions->delete_tag_resource_definition(*resource_definition);
				}
				else if (duplicate_resource)
				{
					c_runtime_tag_resource_definition* old_resource_definition = runtime_tag_definitions->tag_resource_definitions[resource_event_index];
					c_runtime_tag_resource_definition& new_resource_definition = runtime_tag_definitions->duplicate_tag_resource_definition(*old_resource_definition);
					open_resource_definitions.insert(open_resource_definitions.end(), &new_resource_definition);
					new_resource_definition.name += " (copy)";
					next_resource_definition = &new_resource_definition;
					runtime_tag_definitions->sort_tag_resource_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_resource_definitions_tabs()
{
	if (ImGui::BeginTabItem("Resources"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_interop_definitions_list()
{
	if (ImGui::BeginChild("interops"))
	{
		bool search_active = render_search_box(interop_definition_search_buffer, _countof(interop_definition_search_buffer));
		if (ImGui::Button("Create interop"))
		{
			c_runtime_tag_api_interop_definition& interop_definition = runtime_tag_definitions->create_tag_api_interop_definition();
			open_type_tab(_definition_type_interop_definition, &interop_definition);
		}

		if (ImGui::BeginChild("interopsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t interop_event_index = SIZE_MAX;
			bool delete_interop = false;
			bool duplicate_interop = false;

			//for (c_runtime_tag_interop_definition* interop_definition : runtime_tag_definitions->interop_definitions)
			for (size_t interop_definition_index = 0; interop_definition_index < runtime_tag_definitions->tag_api_interop_definitions.size(); interop_definition_index++)
			{
				c_runtime_tag_api_interop_definition* interop_definition = runtime_tag_definitions->tag_api_interop_definitions[interop_definition_index];

				ImGui::PushID(interop_definition);

				const char* interop_name = "<unnamed interop>";
				if (!interop_definition->name.empty())
				{
					interop_name = interop_definition->name.c_str();
				}
				if (!search_active || strstr(interop_name, interop_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(interop_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_interop_definition, interop_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_interop_definition, interop_definition);
				}
				ImGui::PopID();
			}

			if (interop_event_index != SIZE_MAX)
			{
				if (delete_interop)
				{
					c_runtime_tag_api_interop_definition* interop_definition = runtime_tag_definitions->tag_api_interop_definitions[interop_event_index];
					runtime_tag_definitions->delete_tag_api_interop_definition(*interop_definition);
				}
				else if (duplicate_interop)
				{
					c_runtime_tag_api_interop_definition* old_interop_definition = runtime_tag_definitions->tag_api_interop_definitions[interop_event_index];
					c_runtime_tag_api_interop_definition& new_interop_definition = runtime_tag_definitions->duplicate_tag_api_interop_definition(*old_interop_definition);
					open_interop_definitions.insert(open_interop_definitions.end(), &new_interop_definition);
					new_interop_definition.name += " (copy)";
					next_interop_definition = &new_interop_definition;
					runtime_tag_definitions->sort_tag_api_interop_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_interop_definitions_tabs()
{
	if (ImGui::BeginTabItem("Interops"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_data_definitions_list()
{
	if (ImGui::BeginChild("Datas"))
	{
		bool search_active = render_search_box(data_definition_search_buffer, _countof(data_definition_search_buffer));
		if (ImGui::Button("Create Data"))
		{
			c_runtime_tag_data_definition& data_definition = runtime_tag_definitions->create_tag_data_definition();
			open_type_tab(_definition_type_data_definition, &data_definition);
		}

		if (ImGui::BeginChild("DatasList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t data_event_index = SIZE_MAX;
			bool delete_data = false;
			bool duplicate_data = false;

			//for (c_runtime_tag_data_definition* data_definition : runtime_tag_definitions->data_definitions)
			for (size_t data_definition_index = 0; data_definition_index < runtime_tag_definitions->tag_data_definitions.size(); data_definition_index++)
			{
				c_runtime_tag_data_definition* data_definition = runtime_tag_definitions->tag_data_definitions[data_definition_index];

				ImGui::PushID(data_definition);

				const char* data_name = "<unnamed data>";
				if (!data_definition->name.empty())
				{
					data_name = data_definition->name.c_str();
				}
				if (!search_active || strstr(data_name, data_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(data_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_data_definition, data_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_data_definition, data_definition);
				}
				ImGui::PopID();
			}

			if (data_event_index != SIZE_MAX)
			{
				if (delete_data)
				{
					c_runtime_tag_data_definition* data_definition = runtime_tag_definitions->tag_data_definitions[data_event_index];
					runtime_tag_definitions->delete_tag_data_definition(*data_definition);
				}
				else if (duplicate_data)
				{
					c_runtime_tag_data_definition* old_data_definition = runtime_tag_definitions->tag_data_definitions[data_event_index];
					c_runtime_tag_data_definition& new_data_definition = runtime_tag_definitions->duplicate_tag_data_definition(*old_data_definition);
					open_data_definitions.insert(open_data_definitions.end(), &new_data_definition);
					new_data_definition.name += " (copy)";
					next_data_definition = &new_data_definition;
					runtime_tag_definitions->sort_tag_data_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_data_definitions_tabs()
{
	if (ImGui::BeginTabItem("Datas"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_block_index_custom_search_definitions_list()
{
	if (ImGui::BeginChild("Block Index Custom Searchs"))
	{
		bool search_active = render_search_box(block_index_custom_search_definition_search_buffer, _countof(block_index_custom_search_definition_search_buffer));
		if (ImGui::Button("Create Block Index Custom Search"))
		{
			c_runtime_tag_block_index_custom_search_definition& block_index_custom_search_definition = runtime_tag_definitions->create_block_index_custom_search_definition();
			open_type_tab(_definition_type_block_index_custom_search_definition, &block_index_custom_search_definition);
		}

		if (ImGui::BeginChild("Block Index Custom SearchsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t block_index_custom_search_event_index = SIZE_MAX;
			bool delete_block_index_custom_search = false;
			bool duplicate_block_index_custom_search = false;

			//for (c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition : runtime_tag_definitions->block_index_custom_search_definitions)
			for (size_t block_index_custom_search_definition_index = 0; block_index_custom_search_definition_index < runtime_tag_definitions->tag_block_index_custom_search_definitions.size(); block_index_custom_search_definition_index++)
			{
				c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition = runtime_tag_definitions->tag_block_index_custom_search_definitions[block_index_custom_search_definition_index];

				ImGui::PushID(block_index_custom_search_definition);

				const char* block_index_custom_search_name = "<unnamed block_index_custom_search>";
				if (!block_index_custom_search_definition->name.empty())
				{
					block_index_custom_search_name = block_index_custom_search_definition->name.c_str();
				}
				if (!search_active || strstr(block_index_custom_search_name, block_index_custom_search_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(block_index_custom_search_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_block_index_custom_search_definition, block_index_custom_search_definition);
						}
						ImGui::TreePop();
					}
					render_definition_context_menu(_definition_type_block_index_custom_search_definition, block_index_custom_search_definition);
				}
				ImGui::PopID();
			}

			if (block_index_custom_search_event_index != SIZE_MAX)
			{
				if (delete_block_index_custom_search)
				{
					c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition = runtime_tag_definitions->tag_block_index_custom_search_definitions[block_index_custom_search_event_index];
					runtime_tag_definitions->tag_block_index_custom_search_definitions.erase(runtime_tag_definitions->tag_block_index_custom_search_definitions.begin() + block_index_custom_search_event_index);
					delete block_index_custom_search_definition;
				}
				else if (duplicate_block_index_custom_search)
				{
					c_runtime_tag_block_index_custom_search_definition* old_block_index_custom_search_definition = runtime_tag_definitions->tag_block_index_custom_search_definitions[block_index_custom_search_event_index];
					c_runtime_tag_block_index_custom_search_definition& new_block_index_custom_search_definition = runtime_tag_definitions->duplicate_block_index_custom_search_definition(*old_block_index_custom_search_definition);
					open_block_index_custom_search_definitions.insert(open_block_index_custom_search_definitions.end(), &new_block_index_custom_search_definition);
					new_block_index_custom_search_definition.name += " (copy)";
					next_block_index_custom_search_definition = &new_block_index_custom_search_definition;
					runtime_tag_definitions->sort_block_index_custom_search_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}
void c_definition_tweaker::render_block_index_custom_search_definitions_tabs()
{
	if (ImGui::BeginTabItem("Block Index"))
	{
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::render_field_definitions_list()
{
	if (ImGui::BeginChild("Fields"))
	{
		bool search_active = render_search_box(field_definition_search_buffer, _countof(field_definition_search_buffer));
		if (ImGui::Button("Create Field"))
		{
			c_runtime_tag_field_definition& field_definition = runtime_tag_definitions->create_tag_field_definition();
			open_type_tab(_definition_type_field_definition, &field_definition);
		}

		if (ImGui::BeginChild("FieldsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
		{
			size_t field_event_index = SIZE_MAX;
			bool delete_field = false;
			bool duplicate_field = false;

			//for (c_runtime_tag_field_definition* field_definition : runtime_tag_definitions->field_definitions)
			for (size_t field_definition_index = 0; field_definition_index < runtime_tag_definitions->tag_field_definitions.size(); field_definition_index++)
			{
				c_runtime_tag_field_definition* field_definition = runtime_tag_definitions->tag_field_definitions[field_definition_index];

				ImGui::PushID(field_definition);

				const char* field_name = "<unnamed field>";
				if (!field_definition->name.empty())
				{
					field_name = field_definition->name.c_str();
				}
				if (!search_active || strstr(field_name, field_definition_search_buffer))
				{
					if (ImGui::TreeNodeEx(field_name, ImGuiTreeNodeFlags_Leaf))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_type_tab(_definition_type_field_definition, field_definition);
						}
						ImGui::TreePop();
					}
					//render_definition_context_menu(_definition_type_field_definition, field_definition);
				}
				ImGui::PopID();
			}

			if (field_event_index != SIZE_MAX)
			{
				if (delete_field)
				{
					c_runtime_tag_field_definition* field_definition = runtime_tag_definitions->tag_field_definitions[field_event_index];
					runtime_tag_definitions->delete_tag_field_definition(*field_definition);
				}
				else if (duplicate_field)
				{
					c_runtime_tag_field_definition* old_field_definition = runtime_tag_definitions->tag_field_definitions[field_event_index];
					c_runtime_tag_field_definition& new_field_definition = runtime_tag_definitions->duplicate_tag_field_definition(*old_field_definition);
					open_field_definitions.insert(open_field_definitions.end(), &new_field_definition);
					new_field_definition.name += " (copy)";
					next_field_definition = &new_field_definition;
					// runtime_tag_definitions->sort_tag_field_definitions();
				}
			}

		}
		ImGui::EndChild();
	}
	ImGui::EndChild();
}

void c_definition_tweaker::render_field_definitions_tabs()
{
	auto open_field_definitions_copy = open_field_definitions;
	for (c_runtime_tag_field_definition* field_definition : open_field_definitions_copy)
	{
		ImGui::PushID(field_definition);

		const char* field_name = "unnamed field";
		if (!field_definition->name.empty())
		{
			field_name = field_definition->name.c_str();
		}

		bool open = true;
		ImGuiTabItemFlags flags = ImGuiTabItemFlags_None;
		if (field_definition == next_field_definition)
		{
			flags = flags | ImGuiTabItemFlags_SetSelected;
			next_field_definition = nullptr;
		}
		if (ImGui::BeginTabItem(field_name, &open, flags))
		{
			if (ImGui::BeginChild("FieldsList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
			{
				if (imgui_input_text_std_string("Name", field_definition->name))
				{
					enqueue_name_edit_state_hack(_definition_type_field_definition, field_definition);
					// runtime_tag_definitions->sort_tag_field_definitions();
				}
				handle_name_edit_state_hack(_definition_type_field_definition);

				imgui_input_text_multiline_std_string("Description", field_definition->description);

				{
					switch (field_definition->field_type)
					{
					case blofeld::_field_block:
						if (selcted_type_assignment(_definition_type_block_definition, "", field_definition->block_definition))
						{
							field_definition->block_definition = &runtime_tag_definitions->create_tag_block_definition();
							open_type_tab(_definition_type_block_definition, field_definition->block_definition);
						}
						break;
					case blofeld::_field_struct:
						if (selcted_type_assignment(_definition_type_struct_definition, "", field_definition->struct_definition))
						{
							field_definition->struct_definition = &runtime_tag_definitions->create_tag_struct_definition();
							open_type_tab(_definition_type_struct_definition, field_definition->struct_definition);
						}
						break;
					case blofeld::_field_array:
						if (selcted_type_assignment(_definition_type_array_definition, "", field_definition->array_definition))
						{
							field_definition->array_definition = &runtime_tag_definitions->create_tag_array_definition();
							open_type_tab(_definition_type_array_definition, field_definition->array_definition);
						}
						break;
					case blofeld::_field_char_enum:
					case blofeld::_field_short_enum:
					case blofeld::_field_long_enum:
					case blofeld::_field_long_flags:
					case blofeld::_field_word_flags:
					case blofeld::_field_byte_flags:
						if (selcted_type_assignment(_definition_type_string_list_definition, "", field_definition->string_list_definition))
						{
							field_definition->string_list_definition = &runtime_tag_definitions->create_string_list_definition();
							open_type_tab(_definition_type_string_list_definition, field_definition->string_list_definition);
						}
						break;
					case blofeld::_field_tag_reference:
						if (selcted_type_assignment(_definition_type_reference_definition, "", field_definition->tag_reference_definition))
						{
							field_definition->tag_reference_definition = &runtime_tag_definitions->create_tag_reference_definition();
							open_type_tab(_definition_type_reference_definition, field_definition->tag_reference_definition);
						}
						break;
					case blofeld::_field_data:
						if (selcted_type_assignment(_definition_type_data_definition, "", field_definition->tag_data_definition))
						{
							field_definition->tag_data_definition = &runtime_tag_definitions->create_tag_data_definition();
							open_type_tab(_definition_type_data_definition, field_definition->tag_data_definition);
						}
						break;
					case blofeld::_field_pageable_resource:
						if (selcted_type_assignment(_definition_type_resource_definition, "", field_definition->tag_resource_definition))
						{
							field_definition->tag_resource_definition = &runtime_tag_definitions->create_tag_resource_definition();
							open_type_tab(_definition_type_resource_definition, field_definition->tag_resource_definition);
						}
						break;
					case blofeld::_field_api_interop:
						if (selcted_type_assignment(_definition_type_interop_definition, "", field_definition->tag_interop_definition))
						{
							field_definition->tag_interop_definition = &runtime_tag_definitions->create_tag_api_interop_definition();
							open_type_tab(_definition_type_interop_definition, field_definition->tag_interop_definition);
						}
						break;
					case blofeld::_field_char_block_index_custom_search:
					case blofeld::_field_short_block_index_custom_search:
					case blofeld::_field_long_block_index_custom_search:
						if (selcted_type_assignment(_definition_type_interop_definition, "", field_definition->block_index_custom_search_definition))
						{
							field_definition->block_index_custom_search_definition = &runtime_tag_definitions->create_block_index_custom_search_definition();
							open_type_tab(_definition_type_interop_definition, field_definition->block_index_custom_search_definition);
						}
						break;
					case blofeld::_field_skip:
						ImGui::InputScalar("Length", ImGuiDataType_U32, &field_definition->length);
						break;
					case blofeld::_field_pad:
					case blofeld::_field_useless_pad:
						ImGui::InputScalar("Padding", ImGuiDataType_U32, &field_definition->padding);
						break;
					}
				}

			}
			ImGui::EndChild();
			ImGui::EndTabItem();
		}
		if (!open)
		{
			open_field_definitions.erase(field_definition);
		}
		ImGui::PopID();
	}
}

void c_definition_tweaker::render_serialization_tab()
{
	if (ImGui::BeginTabItem("Serialization"))
	{
		if (ImGui::Button("Refresh"))
		{
			parse_binary(serialization_definition_list_group);
		}
		ImGui::SameLine();
		if (ImGui::Button("Export"))
		{
			const wchar_t* tag_definitions_output_directory = nullptr;
			const wchar_t* tag_groups_output_directory = nullptr;
			if (BCS_SUCCEEDED(command_line_get_argument(L"tag-definitions-output-directory", tag_definitions_output_directory)))
			{
				if (BCS_SUCCEEDED(command_line_get_argument(L"tag-groups-output-directory", tag_groups_output_directory)))
				{
					const char* engine_namespace = nullptr;
					const char* platform_namespace = nullptr;
					ASSERT(BCS_SUCCEEDED(get_engine_type_namespace(engine_platform_build.engine_type, engine_namespace)));
					ASSERT(BCS_SUCCEEDED(get_platform_type_namespace(engine_platform_build.platform_type, platform_namespace)));
					blamtoozle_generate_source(
						*runtime_tag_definitions,
						tag_definitions_output_directory,
						tag_groups_output_directory,
						engine_namespace,
						platform_namespace,
						nullptr);
				}
			}
		}
		ImGui::SameLine();

		ImGui::SetNextItemWidth(-1.0f);
		if (ImGui::BeginTable("##selection", 2))
		{
			ImGui::TableSetupColumn("##error", ImGuiTableColumnFlags_WidthStretch, 0.5f);
			ImGui::TableSetupColumn("##error", ImGuiTableColumnFlags_WidthStretch, 0.5f);

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			{
				constexpr const char* serialization_error_to_string[k_num_serialization_error_types]
				{
					"All",
					"Warning",
					"Error",
					"Block",
					"Data"
				};

				const char* serialization_mode = "<bad>";
				if (serialization_definition_list_mode < _countof(serialization_error_to_string))
				{
					serialization_mode = serialization_error_to_string[serialization_definition_list_mode];
				}

				ImGui::SetNextItemWidth(-1.0f);
				if (ImGui::BeginCombo("Error", serialization_mode, ImGuiComboFlags_HeightLargest | ImGuiComboFlags_PopupAlignLeft))
				{
					for (unsigned int serialization_error_type = 0; serialization_error_type < k_num_serialization_error_types; serialization_error_type++)
					{
						serialization_mode = "<bad>";
						if (serialization_error_type < _countof(serialization_error_to_string))
						{
							serialization_mode = serialization_error_to_string[serialization_error_type];
						}

						if (ImGui::Selectable(serialization_mode))
						{
							set_serialization_definition_list_mode_setting(static_cast<e_serialization_error_type>(serialization_error_type));
						}
					}
					ImGui::EndCombo();
				}
			}
			ImGui::TableNextColumn();
			{
				const char* tag_group_name = "All";
				if (serialization_definition_list_group != blofeld::INVALID_TAG)
				{
					c_group_serialization_context* selected_group_serialization_context = nullptr;
					for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
					{
						if (group_serialization_context->group_tag == serialization_definition_list_group)
						{
							selected_group_serialization_context = group_serialization_context;
							tag_group_name = group_serialization_context->name.c_str();
							break;
						}
					}
					if (selected_group_serialization_context == nullptr)
					{
						set_serialization_definition_list_group_setting(blofeld::INVALID_TAG);
					}
				}

				ImGui::SetNextItemWidth(-1.0f);
				if (ImGui::BeginCombo("Group", tag_group_name, ImGuiComboFlags_HeightLargest | ImGuiComboFlags_PopupAlignLeft))
				{
					if (ImGui::Selectable("All"))
					{
						set_serialization_definition_list_group_setting(blofeld::INVALID_TAG);
					}

					for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
					{
						tag_group_name = group_serialization_context->name.c_str();

						if (ImGui::Selectable(tag_group_name))
						{
							set_serialization_definition_list_group_setting(group_serialization_context->group_tag);
						}
					}

					ImGui::EndCombo();
				}
			}

			ImGui::EndTable();
		}

		if (ImGui::BeginChild("Serialization Contexts", {}, false, ImGuiWindowFlags_HorizontalScrollbar))
		{
			render_missing_group_serialization_context_tree();

			for (c_group_serialization_context* group_serialization_context : group_serialization_contexts)
			{
				if (group_serialization_context->max_serialization_error_type >= serialization_definition_list_mode)
				{
					group_serialization_context->render_tree();
				}
			}
		}
		ImGui::EndChild();
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::enqueue_name_edit_state_hack(e_definition_type definition_type, void* target_definition)
{
	ImGuiContext* g = ImGui::GetCurrentContext();

	name_edit_state_hack = g->InputTextState;
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
	case _definition_type_field_definition:
		next_field_definition = static_cast<decltype(next_field_definition)>(target_definition);
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

			g->InputTextState.ScrollX = name_edit_state_hack.ScrollX;
			g->InputTextState.Stb.cursor = name_edit_state_hack.Stb.cursor;
			g->InputTextState.Stb.select_start = name_edit_state_hack.Stb.select_start;
			g->InputTextState.Stb.select_end = name_edit_state_hack.Stb.select_end;
			g->InputTextState.Stb.insert_mode = name_edit_state_hack.Stb.insert_mode;

			name_edit_state_hack_ticks--;
		}
		else
		{
			name_edit_state_hack_definition_type = k_num_definition_types;
		}
	}
}

void c_definition_tweaker::mark_modified()
{

}

void c_definition_tweaker::select_type(e_definition_type definition_type, void* target_definition)
{
	bool deselect = definition_type == k_num_definition_types && target_definition != nullptr && selected_target_definition == target_definition;
	if (definition_type != k_num_definition_types || deselect)
	{
		selected_definition_type = definition_type;
		selected_target_definition = target_definition;
	}
}

template<typename t_runtime_definition>
bool c_definition_tweaker::selcted_type_assignment(e_definition_type definition_type, const char* variable_name, t_runtime_definition*& variable)
{
	bool result = false;

	ImGui::PushID(definition_type);
	ImGui::PushID(static_cast<const void*>(variable_name));

	const char* definition_name = "<unassigned>";
	if (variable)
	{
		definition_name = variable->name.c_str();
	}

	bool use_table = false;
	if (variable_name)
	{
		if (use_table = ImGui::BeginTable("Type Assignment", 2))
		{
			ImGui::TableSetupColumn("Name");
			ImGui::TableSetupColumn("Buttons", ImGuiTableColumnFlags_WidthFixed, 130);
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (*variable_name)
			{
				ImGui::Text("%s: %s", variable_name, definition_name);
			}
			else
			{
				ImGui::Text("%s", definition_name);
			}
			ImGui::TableNextColumn();
		}
	}
	{
		//char button_buffer[256];
		//snprintf(button_buffer, 256, "Assign %s", definition_type_to_string[definition_type]);
		//if (ImGui::Button(button_buffer))
		ImGui::BeginDisabled(selected_definition_type != definition_type);
		if (ImGui::Button("Assign"))
		{
			variable = *reinterpret_cast<decltype(&variable)>(&selected_target_definition);
		}
		ImGui::EndDisabled();
		//ImGui::BeginDisabled(variable == nullptr);
		//if (ImGui::Button("Goto"))
		//{
		//	open_type_tab(definition_type, variable);
		//}
		//ImGui::EndDisabled();
		ImGui::SameLine();
		if (variable == nullptr)
		{
			result = ImGui::Button("Create");
		}
		else if (ImGui::Button("Goto"))
		{
			open_type_tab(definition_type, variable);
		}
	}
	if (use_table)
	{
		ImGui::EndTable();
	}

	ImGui::PopID();
	ImGui::PopID();

	return result;
}

void* c_definition_tweaker::duplicate_type(e_definition_type definition_type, void* target_definition)
{
	switch (definition_type)
	{
	case _definition_type_group_definition:
		if (c_runtime_tag_group_definition* old_tag_group_definition = static_cast<c_runtime_tag_group_definition*>(context_event_pointer))
		{
			if (runtime_tag_definitions->is_tag_group_definition_valid(old_tag_group_definition))
			{
				c_runtime_tag_group_definition& new_tag_group_definition = runtime_tag_definitions->duplicate_tag_group_definition(*old_tag_group_definition);
				open_group_definitions.insert(open_group_definitions.end(), &new_tag_group_definition);
				new_tag_group_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_group_definition);
				runtime_tag_definitions->sort_tag_group_definitions();
				return &new_tag_group_definition;
			}
		}
		break;
	case _definition_type_block_definition:
		if (c_runtime_tag_block_definition* old_tag_block_definition = static_cast<decltype(old_tag_block_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_block_definition_valid(old_tag_block_definition))
			{
				c_runtime_tag_block_definition& new_tag_block_definition = runtime_tag_definitions->duplicate_tag_block_definition(*old_tag_block_definition);
				open_block_definitions.insert(open_block_definitions.end(), &new_tag_block_definition);
				new_tag_block_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_block_definition);
				runtime_tag_definitions->sort_tag_block_definitions();
				return &new_tag_block_definition;
			}
		}
		break;
	case _definition_type_struct_definition:
		if (c_runtime_tag_struct_definition* old_tag_struct_definition = static_cast<decltype(old_tag_struct_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_struct_definition_valid(old_tag_struct_definition))
			{
				c_runtime_tag_struct_definition& new_tag_struct_definition = runtime_tag_definitions->duplicate_tag_struct_definition(*old_tag_struct_definition);
				open_struct_definitions.insert(open_struct_definitions.end(), &new_tag_struct_definition);
				new_tag_struct_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_struct_definition);
				runtime_tag_definitions->sort_tag_struct_definitions();
				return &new_tag_struct_definition;
			}
		}
		break;
	case _definition_type_array_definition:
		if (c_runtime_tag_array_definition* old_tag_array_definition = static_cast<decltype(old_tag_array_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_array_definition_valid(old_tag_array_definition))
			{
				c_runtime_tag_array_definition& new_tag_array_definition = runtime_tag_definitions->duplicate_tag_array_definition(*old_tag_array_definition);
				open_array_definitions.insert(open_array_definitions.end(), &new_tag_array_definition);
				new_tag_array_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_array_definition);
				runtime_tag_definitions->sort_tag_array_definitions();
				return &new_tag_array_definition;
			}
		}
		break;
	case _definition_type_string_list_definition:
		if (c_runtime_string_list_definition* old_string_list_definition = static_cast<decltype(old_string_list_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_string_list_definition_valid(old_string_list_definition))
			{
				c_runtime_string_list_definition& new_string_list_definition = runtime_tag_definitions->duplicate_string_list_definition(*old_string_list_definition);
				open_string_list_definitions.insert(open_string_list_definitions.end(), &new_string_list_definition);
				new_string_list_definition.name += " (copy)";
				open_type_tab(definition_type, &new_string_list_definition);
				runtime_tag_definitions->sort_string_list_definitions();
				return &new_string_list_definition;
			}
		}
		break;
	case _definition_type_reference_definition:
		if (c_runtime_tag_reference_definition* old_tag_reference_definition = static_cast<decltype(old_tag_reference_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_reference_definition_valid(old_tag_reference_definition))
			{
				c_runtime_tag_reference_definition& new_tag_reference_definition = runtime_tag_definitions->duplicate_tag_reference_definition(*old_tag_reference_definition);
				open_reference_definitions.insert(open_reference_definitions.end(), &new_tag_reference_definition);
				new_tag_reference_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_reference_definition);
				runtime_tag_definitions->sort_tag_reference_definitions();
				return &new_tag_reference_definition;
			}
		}
		break;
	case _definition_type_resource_definition:
		if (c_runtime_tag_resource_definition* old_tag_resource_definition = static_cast<decltype(old_tag_resource_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_resource_definition_valid(old_tag_resource_definition))
			{
				c_runtime_tag_resource_definition& new_tag_resource_definition = runtime_tag_definitions->duplicate_tag_resource_definition(*old_tag_resource_definition);
				open_resource_definitions.insert(open_resource_definitions.end(), &new_tag_resource_definition);
				new_tag_resource_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_resource_definition);
				runtime_tag_definitions->sort_tag_resource_definitions();
				return &new_tag_resource_definition;
			}
		}
		break;
	case _definition_type_interop_definition:
		if (c_runtime_tag_api_interop_definition* old_tag_api_interop_definition = static_cast<decltype(old_tag_api_interop_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_api_interop_definition_valid(old_tag_api_interop_definition))
			{
				c_runtime_tag_api_interop_definition& new_tag_api_interop_definition = runtime_tag_definitions->duplicate_tag_api_interop_definition(*old_tag_api_interop_definition);
				open_interop_definitions.insert(open_interop_definitions.end(), &new_tag_api_interop_definition);
				new_tag_api_interop_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_api_interop_definition);
				runtime_tag_definitions->sort_tag_api_interop_definitions();
				return &new_tag_api_interop_definition;
			}
		}
		break;
	case _definition_type_data_definition:
		if (c_runtime_tag_data_definition* old_tag_data_definition = static_cast<decltype(old_tag_data_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_data_definition_valid(old_tag_data_definition))
			{
				;
				c_runtime_tag_data_definition& new_tag_data_definition = runtime_tag_definitions->duplicate_tag_data_definition(*old_tag_data_definition);
				open_data_definitions.insert(open_data_definitions.end(), &new_tag_data_definition);
				new_tag_data_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_data_definition);
				runtime_tag_definitions->sort_tag_data_definitions();
				return &new_tag_data_definition;
			}
		}
		break;
	case _definition_type_block_index_custom_search_definition:
		if (c_runtime_tag_block_index_custom_search_definition* old_block_index_custom_search_definition = static_cast<decltype(old_block_index_custom_search_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_block_index_custom_search_definition_valid(old_block_index_custom_search_definition))
			{
				c_runtime_tag_block_index_custom_search_definition& new_block_index_custom_search_definition = runtime_tag_definitions->duplicate_block_index_custom_search_definition(*old_block_index_custom_search_definition);
				open_block_index_custom_search_definitions.insert(open_block_index_custom_search_definitions.end(), &new_block_index_custom_search_definition);
				new_block_index_custom_search_definition.name += " (copy)";
				open_type_tab(definition_type, &new_block_index_custom_search_definition);
				runtime_tag_definitions->sort_block_index_custom_search_definitions();
				return &new_block_index_custom_search_definition;
			}
		}
		break;
	case _definition_type_field_definition:
		if (c_runtime_tag_field_definition* old_tag_field_definition = static_cast<decltype(old_tag_field_definition)>(target_definition))
		{
			if (runtime_tag_definitions->is_tag_field_definition_valid(old_tag_field_definition))
			{
				c_runtime_tag_field_definition& new_tag_field_definition = runtime_tag_definitions->duplicate_tag_field_definition(*old_tag_field_definition);
				open_field_definitions.insert(open_field_definitions.end(), &new_tag_field_definition);
				new_tag_field_definition.name += " (copy)";
				open_type_tab(definition_type, &new_tag_field_definition);
				// runtime_tag_definitions->sort_tag_field_definitions();
			}
		}
		break;
	}
	return nullptr;
}

bool c_definition_tweaker::is_definition_type_valid(e_definition_type definition_type, void* target_definition)
{
	switch (definition_type)
	{
	case _definition_type_group_definition:
		if (c_runtime_tag_api_interop_definition* old_interop_definition = static_cast<c_runtime_tag_api_interop_definition*>(context_event_pointer))
		{
			return runtime_tag_definitions->is_tag_api_interop_definition_valid(old_interop_definition);
		}
		break;
	case _definition_type_block_definition:
		if (c_runtime_tag_block_definition* old_tag_block_definition = static_cast<decltype(old_tag_block_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_block_definition_valid(old_tag_block_definition);
		}
		break;
	case _definition_type_struct_definition:
		if (c_runtime_tag_struct_definition* old_tag_struct_definition = static_cast<decltype(old_tag_struct_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_struct_definition_valid(old_tag_struct_definition);
		}
		break;
	case _definition_type_array_definition:
		if (c_runtime_tag_array_definition* old_tag_array_definition = static_cast<decltype(old_tag_array_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_array_definition_valid(old_tag_array_definition);
		}
		break;
	case _definition_type_string_list_definition:
		if (c_runtime_string_list_definition* old_string_list_definition = static_cast<decltype(old_string_list_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_string_list_definition_valid(old_string_list_definition);
		}
		break;
	case _definition_type_reference_definition:
		if (c_runtime_tag_reference_definition* old_tag_reference_definition = static_cast<decltype(old_tag_reference_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_reference_definition_valid(old_tag_reference_definition);
		}
		break;
	case _definition_type_resource_definition:
		if (c_runtime_tag_resource_definition* old_tag_resource_definition = static_cast<decltype(old_tag_resource_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_resource_definition_valid(old_tag_resource_definition);
		}
		break;
	case _definition_type_interop_definition:
		if (c_runtime_tag_api_interop_definition* old_tag_api_interop_definition = static_cast<decltype(old_tag_api_interop_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_api_interop_definition_valid(old_tag_api_interop_definition);
		}
		break;
	case _definition_type_data_definition:
		if (c_runtime_tag_data_definition* old_tag_data_definition = static_cast<decltype(old_tag_data_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_data_definition_valid(old_tag_data_definition);
		}
		break;
	case _definition_type_block_index_custom_search_definition:
		if (c_runtime_tag_block_index_custom_search_definition* old_block_index_custom_search_definition = static_cast<decltype(old_block_index_custom_search_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_block_index_custom_search_definition_valid(old_block_index_custom_search_definition);
		}
		break;
	case _definition_type_field_definition:
		if (c_runtime_tag_field_definition* old_tag_field_definition = static_cast<decltype(old_tag_field_definition)>(target_definition))
		{
			return runtime_tag_definitions->is_tag_field_definition_valid(old_tag_field_definition);
		}
		break;
	}
	return false;
}

void c_definition_tweaker::open_type_tab(e_definition_type definition_type, void* target_definition)
{
	next_selected_definition_tab_type = definition_type;

#define open_target_definition_helper(_definition_type, t_runtime_definition, open_definitions, next_definition) \
	if (definition_type == _definition_type) \
	{ \
		open_definitions.insert(open_definitions.end(), static_cast<t_runtime_definition*>(target_definition)); \
		next_definition = static_cast<t_runtime_definition*>(target_definition); \
	}

	open_target_definition_helper(_definition_type_group_definition, c_runtime_tag_group_definition, open_group_definitions, next_group_definition);
	open_target_definition_helper(_definition_type_block_definition, c_runtime_tag_block_definition, open_block_definitions, next_block_definition);
	open_target_definition_helper(_definition_type_struct_definition, c_runtime_tag_struct_definition, open_struct_definitions, next_struct_definition);
	open_target_definition_helper(_definition_type_array_definition, c_runtime_tag_array_definition, open_array_definitions, next_array_definition);
	open_target_definition_helper(_definition_type_string_list_definition, c_runtime_string_list_definition, open_string_list_definitions, next_string_list_definition);
	open_target_definition_helper(_definition_type_reference_definition, c_runtime_tag_reference_definition, open_reference_definitions, next_reference_definition);
	open_target_definition_helper(_definition_type_resource_definition, c_runtime_tag_resource_definition, open_resource_definitions, next_resource_definition);
	open_target_definition_helper(_definition_type_interop_definition, c_runtime_tag_api_interop_definition, open_interop_definitions, next_interop_definition);
	open_target_definition_helper(_definition_type_data_definition, c_runtime_tag_data_definition, open_data_definitions, next_data_definition);
	open_target_definition_helper(_definition_type_block_index_custom_search_definition, c_runtime_tag_block_index_custom_search_definition, open_block_index_custom_search_definitions, next_block_index_custom_search_definition);
	open_target_definition_helper(_definition_type_field_definition, c_runtime_tag_field_definition, open_field_definitions, next_field_definition);

#undef open_target_definition_helper
}

void c_definition_tweaker::render_definitions_view(const char* id, e_definition_type definition_type, void (c_definition_tweaker::* render_list)(), void (c_definition_tweaker::* render_tabs)())
{
	ImGuiTabItemFlags flags = 0;
	if (next_selected_definition_tab_type == definition_type)
	{
		flags = flags | ImGuiTabItemFlags_SetSelected;
		next_selected_definition_tab_type = k_num_definition_types;
	}
	if (ImGui::BeginTabItem(id, nullptr, flags))
	{
		if (ImGui::BeginTable("##navigation", 2, ImGuiTableFlags_Resizable))
		{
			setup_definitions_view_columns();
			//ImGui::TableHeadersRow();
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			(this->*render_list)();
			ImGui::TableNextColumn();
			if (ImGui::BeginTabBar("##openitems"))
			{
				(this->*render_tabs)();
				ImGui::EndTabBar();
			}

			ImGui::EndTable();
		}
		ImGui::EndTabItem();
	}
}

void c_definition_tweaker::setup_definitions_view_columns()
{
	ImGuiTable* table = ImGui::GetCurrentTable();
	ImGuiTableColumn& list_column = table->Columns[0];
	ImGuiTableColumn& definition_column = table->Columns[1];
	if (!ImGui::IsMouseDragging(ImGuiMouseButton_Left) && table->MinColumnWidth && c_definition_tweaker::get_serialization_definition_list_column_weight_setting() != list_column.StretchWeight)
	{
		if (list_column.InitStretchWeightOrWidth != -1.0f)
		{
			table->IsInitializing = table->IsSettingsDirty = table->IsResetAllRequest = true;

			float list_weight = c_definition_tweaker::get_serialization_definition_list_column_weight_setting();
			float definition_weight = 1.0f - c_definition_tweaker::get_serialization_definition_list_column_weight_setting();

			list_weight = __clamp(list_weight, 0.0f, 1.0f);
			definition_weight = __clamp(definition_weight, 0.0f, 1.0f);

			ImGui::TableSetupColumn("List", ImGuiTableColumnFlags_WidthStretch, list_weight);
			ImGui::TableSetupColumn("Definitions", ImGuiTableColumnFlags_WidthStretch, definition_weight);

			list_column.StretchWeight = list_weight;
			definition_column.StretchWeight = definition_weight;
		}
	}
	else
	{
		{
			float list_weight = c_definition_tweaker::get_serialization_definition_list_column_weight_setting();
			float definition_weight = 1.0f - c_definition_tweaker::get_serialization_definition_list_column_weight_setting();

			list_weight = __clamp(list_weight, 0.0f, 1.0f);
			definition_weight = __clamp(definition_weight, 0.0f, 1.0f);

			ImGui::TableSetupColumn("List", ImGuiTableColumnFlags_WidthStretch, list_weight);
			ImGui::TableSetupColumn("Definitions", ImGuiTableColumnFlags_WidthStretch, definition_weight);
		}
		if (c_definition_tweaker::get_serialization_definition_list_column_weight_setting() != list_column.StretchWeight && list_column.WidthRequest != table->MinColumnWidth)
		{
			if (list_column.StretchWeight >= 0.0f)
			{
				float list_weight = list_column.StretchWeight;
				float definition_weight = definition_column.StretchWeight;
				float weight_total = list_weight + definition_weight;
				list_weight /= weight_total;
				definition_weight /= weight_total;

				list_weight = __clamp(list_weight, 0.0f, 1.0f);
				definition_weight = __clamp(definition_weight, 0.0f, 1.0f);

				c_definition_tweaker::set_serialization_definition_list_column_weight_setting(list_weight);
			}
		}
	}
}

void c_definition_tweaker::context_menu_event(e_definition_tweaker_context_event event_type, e_definition_type definition_type, size_t index, void* pointer)
{
	context_event_type = event_type;
	context_event_definition_type = definition_type;
	context_event_index = index;
	context_event_pointer = pointer;
}

void c_definition_tweaker::render_definition_context_menu(e_definition_type definition_type, void* definition)
{
	c_runtime_tag_group_definition* group_definition = static_cast<decltype(group_definition)>(definition);
	if (ImGui::BeginPopupContextItem("##contextmenu"))
	{
		if (ImGui::MenuItem("Open"))
		{
			context_menu_event(_definition_tweaker_context_event_open, definition_type, SIZE_MAX, definition);
		}
		if (ImGui::MenuItem("Select Type"))
		{
			context_menu_event(_definition_tweaker_context_event_select, definition_type, SIZE_MAX, definition);
		}
		if (ImGui::MenuItem("Duplicate"))
		{
			context_menu_event(_definition_tweaker_context_event_duplicate, definition_type, SIZE_MAX, definition);
		}
		ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
		if (ImGui::MenuItem("Delete"))
		{
			context_menu_event(_definition_tweaker_context_event_delete, definition_type, SIZE_MAX, definition);
		}
		ImGui::EndPopup();
	}
}

void c_definition_tweaker::handle_definition_context_menu()
{
	if (context_event_type == _definition_tweaker_context_event_none)
	{
		return;
	}

	switch (context_event_type)
	{
	case _definition_tweaker_context_event_select:
		select_type(context_event_definition_type, context_event_pointer);
		break;
	case _definition_tweaker_context_event_delete:
		select_type(context_event_definition_type, context_event_pointer);
		break;
	case _definition_tweaker_context_event_duplicate:
		duplicate_type(context_event_definition_type, context_event_pointer);
		break;
	case _definition_tweaker_context_event_open:
		open_type_tab(context_event_definition_type, context_event_pointer);
		break;
	}

	context_event_type = _definition_tweaker_context_event_none;
}
