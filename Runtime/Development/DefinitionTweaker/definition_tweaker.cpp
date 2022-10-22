#include "definitiontweaker-private-pch.h"

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
	structure_search_buffer(),
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
	next_block_index_custom_search_definition()
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

	if (ImGui::Begin("Definition Tweaker", nullptr, imgui_main_window_flags))
	{
		if (ImGui::BeginTabBar("##root"))
		{
			render_serialization_tab();
			render_definitions_tab();

			for (unsigned int open_tag_index : open_tag_indices)
			{
				if (open_tag_index < serialization_contexts.size())
				{
					c_tag_serialization_context* serialization_context = serialization_contexts[open_tag_index];


				}
			}

			ImGui::EndTabBar();
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

void c_definition_tweaker::render_definitions_tab()
{
	ImGui::ShowDemoWindow();

	if (ImGui::BeginTabItem("Structures"))
	{
		ImGui::Columns(2, "##navigation");
		ImGui::SetColumnOffset(1, 500.0f);
		{
			if (ImGui::BeginChild("Structures"))
			{
				bool search_active = render_search_box(structure_search_buffer, _countof(structure_search_buffer));
				if (ImGui::Button("Create Structure"))
				{
					c_runtime_tag_struct_definition& struct_definition = runtime_tag_definitions->create_tag_struct_definition();
					open_struct_definitions.insert(open_struct_definitions.end(), &struct_definition);
					next_struct_definition = &struct_definition;
				}

				if (ImGui::BeginChild("StructuresList", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar))
				{
					for (c_runtime_tag_struct_definition* struct_definition : runtime_tag_definitions->struct_definitions)
					{
						const char* structure_name = "<unnamed struct>";
						if (!struct_definition->name.empty())
						{
							structure_name = struct_definition->name.c_str();
						}
						if (!search_active || strstr(structure_name, structure_search_buffer))
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
						}
					}
					ImGui::EndChild();
				}
				ImGui::EndChild();
			}

		}
		ImGui::NextColumn();
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

							char pretty_name_buffer[256];
							char name_buffer[256];
							char struct_name_buffer[256];

							strcpy_s(pretty_name_buffer, struct_definition->pretty_name.c_str());
							strcpy_s(name_buffer, struct_definition->name.c_str());
							strcpy_s(struct_name_buffer, struct_definition->struct_name.c_str());

							if (ImGui::InputText("Pretty Name", pretty_name_buffer, _countof(pretty_name_buffer)))
							{
								struct_definition->pretty_name = pretty_name_buffer;
							}
							if (ImGui::InputText("Name", name_buffer, _countof(name_buffer)))
							{
								struct_definition->name = name_buffer;
							}
							if (ImGui::InputText("Structure Name", struct_name_buffer, _countof(struct_name_buffer)))
							{
								struct_definition->struct_name = struct_name_buffer;
							}

							if (ImGui::CollapsingHeader("Tag Field Set"))
							{
								bool tag_field_set_unknown0_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown0_bit);
								bool tag_field_set_unknown1_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown1_bit);
								bool tag_field_set_has_inlined_children_with_placement_new_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_has_inlined_children_with_placement_new_bit);
								bool tag_field_set_unknown3_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown3_bit);
								bool tag_field_set_unknown4_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown4_bit);
								bool tag_field_set_has_aggregate_types_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_has_aggregate_types_bit);
								bool tag_field_set_is_temporary_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_is_temporary_bit);
								bool tag_field_set_unknown7_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown7_bit);
								bool tag_field_set_unknown8_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown8_bit);
								bool tag_field_set_delete_recursively_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_delete_recursively_bit);
								bool tag_field_set_postprocess_recursively_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_postprocess_recursively_bit);
								bool tag_field_set_is_memcpyable_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_is_memcpyable_bit);
								bool tag_field_set_unknown12_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown12_bit);
								bool tag_field_set_has_resources_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_has_resources_bit);
								bool tag_field_set_unknown14_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown14_bit);
								bool tag_field_set_unknown15_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown15_bit);
								bool tag_field_set_has_level_specific_fields_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_has_level_specific_fields_bit);
								bool tag_field_set_can_memset_to_initialize_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_can_memset_to_initialize_bit);
								bool tag_field_set_unknown18_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_unknown18_bit);
								bool tag_field_set_exist_in_cache_build_set = struct_definition->runtime_flags.test(blofeld::_tag_field_set_exist_in_cache_build_bit);

								if (ImGui::Checkbox("unknown0", &tag_field_set_unknown0_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown0_bit, tag_field_set_unknown0_set);
								if (ImGui::Checkbox("unknown1", &tag_field_set_unknown1_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown1_bit, tag_field_set_unknown1_set);
								if (ImGui::Checkbox("has_inlined_children_with_placement_new", &tag_field_set_has_inlined_children_with_placement_new_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_has_inlined_children_with_placement_new_bit, tag_field_set_has_inlined_children_with_placement_new_set);
								if (ImGui::Checkbox("unknown3", &tag_field_set_unknown3_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown3_bit, tag_field_set_unknown3_set);
								if (ImGui::Checkbox("unknown4", &tag_field_set_unknown4_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown4_bit, tag_field_set_unknown4_set);
								if (ImGui::Checkbox("has_aggregate_types", &tag_field_set_has_aggregate_types_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_has_aggregate_types_bit, tag_field_set_has_aggregate_types_set);
								if (ImGui::Checkbox("is_temporary", &tag_field_set_is_temporary_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_is_temporary_bit, tag_field_set_is_temporary_set);
								if (ImGui::Checkbox("unknown7", &tag_field_set_unknown7_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown7_bit, tag_field_set_unknown7_set);
								if (ImGui::Checkbox("unknown8", &tag_field_set_unknown8_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown8_bit, tag_field_set_unknown8_set);
								if (ImGui::Checkbox("delete_recursively", &tag_field_set_delete_recursively_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_delete_recursively_bit, tag_field_set_delete_recursively_set);
								if (ImGui::Checkbox("postprocess_recursively", &tag_field_set_postprocess_recursively_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_postprocess_recursively_bit, tag_field_set_postprocess_recursively_set);
								if (ImGui::Checkbox("is_memcpyable", &tag_field_set_is_memcpyable_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_is_memcpyable_bit, tag_field_set_is_memcpyable_set);
								if (ImGui::Checkbox("unknown12", &tag_field_set_unknown12_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown12_bit, tag_field_set_unknown12_set);
								if (ImGui::Checkbox("has_resources", &tag_field_set_has_resources_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_has_resources_bit, tag_field_set_has_resources_set);
								if (ImGui::Checkbox("unknown14", &tag_field_set_unknown14_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown14_bit, tag_field_set_unknown14_set);
								if (ImGui::Checkbox("unknown15", &tag_field_set_unknown15_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown15_bit, tag_field_set_unknown15_set);
								if (ImGui::Checkbox("has_level_specific_fields", &tag_field_set_has_level_specific_fields_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_has_level_specific_fields_bit, tag_field_set_has_level_specific_fields_set);
								if (ImGui::Checkbox("can_memset_to_initialize", &tag_field_set_can_memset_to_initialize_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_can_memset_to_initialize_bit, tag_field_set_can_memset_to_initialize_set);
								if (ImGui::Checkbox("unknown18", &tag_field_set_unknown18_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_unknown18_bit, tag_field_set_unknown18_set);
								if (ImGui::Checkbox("exist_in_cache_build", &tag_field_set_exist_in_cache_build_set))
									struct_definition->runtime_flags.set(blofeld::_tag_field_set_exist_in_cache_build_bit, tag_field_set_exist_in_cache_build_set);

							}

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

								bool tag_memory_physical_set = struct_definition->memory_attributes.usage_flags.test(blofeld::_tag_memory_physical_bit);
								bool tag_memory_unknown1_set = struct_definition->memory_attributes.usage_flags.test(blofeld::_tag_memory_unknown1_bit);
								bool tag_memory_unknown2_set = struct_definition->memory_attributes.usage_flags.test(blofeld::_tag_memory_unknown2_bit);
								bool tag_memory_writeable_set = struct_definition->memory_attributes.usage_flags.test(blofeld::_tag_memory_writeable_bit);
								bool tag_memory_combined_set = struct_definition->memory_attributes.usage_flags.test(blofeld::_tag_memory_combined_bit);
								bool tag_memory_streaming_set = struct_definition->memory_attributes.usage_flags.test(blofeld::_tag_memory_streaming_bit);
								bool tag_memory_non_aliased_set = struct_definition->memory_attributes.usage_flags.test(blofeld::_tag_memory_non_aliased_bit);


								if (ImGui::Checkbox("tag_memory_physical_bit", &tag_memory_physical_set))
									struct_definition->memory_attributes.usage_flags.set(blofeld::_tag_memory_physical_bit, tag_memory_physical_set);
								if (ImGui::Checkbox("tag_memory_unknown1_bit", &tag_memory_unknown1_set))
									struct_definition->memory_attributes.usage_flags.set(blofeld::_tag_memory_unknown1_bit, tag_memory_unknown1_set);
								if (ImGui::Checkbox("tag_memory_unknown2_bit", &tag_memory_unknown2_set))
									struct_definition->memory_attributes.usage_flags.set(blofeld::_tag_memory_unknown2_bit, tag_memory_unknown2_set);
								if (ImGui::Checkbox("tag_memory_writeable_bit", &tag_memory_writeable_set))
									struct_definition->memory_attributes.usage_flags.set(blofeld::_tag_memory_writeable_bit, tag_memory_writeable_set);
								if (ImGui::Checkbox("tag_memory_combined_bit", &tag_memory_combined_set))
									struct_definition->memory_attributes.usage_flags.set(blofeld::_tag_memory_combined_bit, tag_memory_combined_set);
								if (ImGui::Checkbox("tag_memory_streaming_bit", &tag_memory_streaming_set))
									struct_definition->memory_attributes.usage_flags.set(blofeld::_tag_memory_streaming_bit, tag_memory_streaming_set);
								if (ImGui::Checkbox("tag_memory_non_aliased_bit", &tag_memory_non_aliased_set))
									struct_definition->memory_attributes.usage_flags.set(blofeld::_tag_memory_non_aliased_bit, tag_memory_non_aliased_set);
							}

							ImGui::InputInt4(
								"Persistent Identifier",
								reinterpret_cast<int*>(&struct_definition->persistent_identifier.identifier_part_0),
								ImGuiInputTextFlags_CharsHexadecimal);
							ImGui::InputInt("Alignment Bits", reinterpret_cast<int*>(&struct_definition->alignment_bits));

							std::vector<c_runtime_tag_field*> fields = struct_definition->fields;
							bool fields_changed = false;

							for (size_t field_index = 0; field_index < fields.size(); field_index++)
							{
								c_runtime_tag_field* field = fields[field_index];
								ImGui::PushID(field);

								//ImGui::BeginGroup();
								const char* field_name = "<unnamed>";
								if (!field->name.empty())
								{
									field_name = field->name.c_str();
								}
								ImGui::Selectable(field_name);
								//ImGui::EndGroup();

								if (ImGui::IsItemActive() && !ImGui::IsItemHovered())
								{
									int field_index_next = field_index + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
									if (field_index_next >= 0 && field_index_next < fields.size())
									{
										fields[field_index] = fields[field_index_next];
										fields[field_index_next] = field;
										fields_changed = true;
										ImGui::ResetMouseDragDelta();
									}
								}

								ImGui::PopID();
							}

							if (fields_changed)
							{
								struct_definition->fields = fields;
							}


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
