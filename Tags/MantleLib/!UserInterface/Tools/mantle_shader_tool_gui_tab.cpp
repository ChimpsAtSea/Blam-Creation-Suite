#include "mantlelib-private-pch.h"

e_shader_profile c_mantle_shader_tool_gui_tab::accepted_shader_profiles[] =
{
	_shader_profile_ps_5_0,
	_shader_profile_ps_3_0
};

c_mantle_shader_tool_gui_tab::c_mantle_shader_tool_gui_tab(const char* title, const char* description, c_mantle_cache_file_gui_tab& parent_tab, c_cache_file& cache_file) :
	c_mantle_gui_tab(title, description),
	compile_source_thread_subroutine(&c_mantle_shader_tool_gui_tab::compile_source_subroutine, this),
	disassemble_runtime(&c_mantle_shader_tool_gui_tab::disassemble_runtime_subroutine, this),
	parent_tab(parent_tab),
	cache_file(cache_file),
	selected_render_method_definition_tag_interface(nullptr),
	selected_render_method_template_tag_interface(nullptr),
	use_durango_shader_disassembly(false),
	current_shader_profile(accepted_shader_profiles[0]),
	selected_text_editor(nullptr),
	selected_file_path(""),
	selected_language_name(""),
	source_code_editor_display(),
	preview_disassembly_display(),
	runtime_disassembly_display(),
	code_editor_language(TextEditor::LanguageDefinition::HLSL()),
	hlsl_assembly_language(TextEditor::LanguageDefinition::HLSL_Shader_Asm())
{
	// set your own known preprocessor symbols...
	static const char* shader_stage_function_name[] =
	{
		"calc_albedo_ps"
	};

	// ... and their corresponding values
	static const char* shader_stage_function_description[] = {
		"Albedo shader stage pixel shader function"
	};

	for (int i = 0; i < _countof(shader_stage_function_name); ++i)
	{
		TextEditor::Identifier id;
		id.mDeclaration = shader_stage_function_description[i];
		code_editor_language.mPreprocIdentifiers.insert(std::make_pair(std::string(shader_stage_function_name[i]), id));
	}

	source_code_editor_display.SetLanguageDefinition(code_editor_language);
	preview_disassembly_display.SetLanguageDefinition(hlsl_assembly_language);
	runtime_disassembly_display.SetLanguageDefinition(hlsl_assembly_language);

	//editor.SetPalette(TextEditor::GetLightPalette());

	// error markers
	TextEditor::ErrorMarkers markers;
	markers.insert(std::make_pair<int, std::string>(6, "Example error here:\nInclude file not found: \"TextEditor.h\""));
	markers.insert(std::make_pair<int, std::string>(41, "Another example error"));
	source_code_editor_display.SetErrorMarkers(markers);

	std::string filepath = c_command_line::get_command_line_arg("-shadertool") + "\\shader.hlsl";
	std::wstring wfilepath(filepath.begin(), filepath.end());
	const char* shader_code = filesystem_read_to_memory_legacy(wfilepath.c_str());
	if (shader_code)
	{
		source_code_editor_display.SetText(shader_code);
		delete shader_code;
	}

	compile_source();
	disassemble_runtime();
}

c_mantle_shader_tool_gui_tab::~c_mantle_shader_tool_gui_tab()
{

}

void c_mantle_shader_tool_gui_tab::render_source_code_editor_gui()
{
	source_code_editor_display.Render("code_editor");

	if (new_source_code_error_markers.get(source_code_error_markers))
	{
		source_code_editor_display.SetErrorMarkers(source_code_error_markers);
	}

	if (source_code_editor_display.IsTextChanged()) // #TODO: Make this async
	{
		compile_source();
	}
	ImGui::NextColumn();
}

void c_mantle_shader_tool_gui_tab::render_preview_disassembly()
{
	static std::string new_source_code_disassembly_storage;
	if (new_source_code_disassembly.get(new_source_code_disassembly_storage))
	{
		preview_disassembly_display.SetText(new_source_code_disassembly_storage.c_str());
		new_source_code_disassembly_storage.clear();
	}

	preview_disassembly_display.SetReadOnly(true);
	preview_disassembly_display.Render("preview_disassembly");
	ImGui::NextColumn();
}

void c_mantle_shader_tool_gui_tab::render_runtime_disassembly()
{
	static std::string new_runtime_disassembly_storage;
	if (new_runtime_disassembly.get(new_runtime_disassembly_storage))
	{
		runtime_disassembly_display.SetText(new_runtime_disassembly_storage.c_str());
		new_runtime_disassembly_storage.clear();
	}

	runtime_disassembly_display.SetReadOnly(true);
	runtime_disassembly_display.Render("runtime_disassembly");
	ImGui::NextColumn();
}

std::string c_mantle_shader_tool_gui_tab::disassemble_shader(const char* hlsl_bytecode_data, size_t hlsl_bytecode_size)
{
	if (hlsl_bytecode_data == nullptr) return "<hlsl_bytecode_data was nullptr>";
	if (hlsl_bytecode_size == 0) return "<hlsl_bytecode_size was 0>";

	ID3D10Blob* disassembly_blob = NULL;
	HRESULT d3d_disassemble_result = D3DDisassemble(hlsl_bytecode_data, hlsl_bytecode_size, 0, NULL, &disassembly_blob);

	if (FAILED(d3d_disassemble_result) && disassembly_blob != nullptr)
	{
		if (disassembly_blob) disassembly_blob->Release();
		return "<D3DDisassemble failure>";
	}
	else
	{
		std::string hlsl_disassembly = reinterpret_cast<char*>(disassembly_blob->GetBufferPointer());
		disassembly_blob->Release();
		return hlsl_disassembly;
	}
}

void c_mantle_shader_tool_gui_tab::render_shader_profile_selection_gui()
{
	if (ImGui::BeginCombo("Shader Profile", shader_profile_to_string(current_shader_profile)))
	{
		for (uint32_t accepted_profile_index = 0; accepted_profile_index < _countof(accepted_shader_profiles); accepted_profile_index++)
		{
			e_shader_profile current_accepted_shader_profile = accepted_shader_profiles[accepted_profile_index];
			if (ImGui::Selectable(shader_profile_to_string(current_accepted_shader_profile)))
			{
				current_shader_profile = current_accepted_shader_profile;
				compile_source();
			}
		}
		ImGui::EndCombo();
	}
}

void c_mantle_shader_tool_gui_tab::render_source_code_editor_configuration_header_column_gui()
{
	render_shader_profile_selection_gui();

	if (selected_render_method_template_tag_interface)
	{
		if (ImGui::Button("Populate from RMT2"))
		{
			v_tag_interface_legacy<s_render_method_definition_definition_legacy>* render_method_definition = dynamic_cast<decltype(render_method_definition)>(selected_render_method_definition_tag_interface);

			//for (s_render_method_definition_definition::s_option_definition& option : render_method_definition->options)
			//{
			//	const char* shader_option = render_method_definition->GetCacheFile().string_id_to_cstr(option.__unknown);

			//	write_line_verbose("shader_option: %s", shader_option);
			//}
		}
	}
	else
	{
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		ImGui::Button("Populate from RMT2");
		ImGui::PopItemFlag();
	}

	ImGui::NextColumn();
}

void c_mantle_shader_tool_gui_tab::render_preview_disassembly_configuration_header_column_gui()
{
	ImGui::NextColumn();
}

void c_mantle_shader_tool_gui_tab::render_runtime_disassembly_configuration_header_column_gui()
{
	constexpr float k_min_column_height = 120.0f;
	const float start_cursor_position_y = ImGui::GetCursorPosY();

	{
		// #TODO: What happens when this tab closes? This value needs to be fixed up

		//const char* cache_file_combo_text = selected_cache_file_tab ? selected_cache_file_tab->get_title() : "(select cache file)";
		//if (ImGui::BeginCombo("Cache File", cache_file_combo_text))
		//{
		//	if (ImGui::Selectable("(select cache file)", selected_cache_file_tab == nullptr))
		//	{
		//		selected_cache_file_tab = nullptr;
		//	}

		//	for (c_mantle_gui_tab* gui_tab : c_mantle_gui::get_tabs())
		//	{
		//		c_mantle_cache_file_gui_tab* cache_file_gui_tab = dynamic_cast<c_mantle_cache_file_gui_tab*>(gui_tab);
		//		if (cache_file_gui_tab == nullptr) continue;

		//		if (ImGui::Selectable(cache_file_gui_tab->get_title(), selected_cache_file_tab == cache_file_gui_tab))
		//		{
		//			selected_cache_file_tab = cache_file_gui_tab;
		//		}
		//	}

		//	ImGui::EndCombo();
		//}

		constexpr float k_shader_selection_type_button_width = 80.0f;
		//if (selected_render_method_template_tag_interface)
		//{
		//	//ImGui::SameLine(ImGui::GetContentRegionAvail().x - k_shader_selection_type_button_width);

		//	if (use_durango_shader_disassembly)
		//	{
		//		if (ImGui::Button("PC", ImVec2(k_shader_selection_type_button_width, 0)))
		//		{
		//			use_durango_shader_disassembly = false;
		//			disassemble_runtime();
		//		}
		//	}
		//	else
		//	{
		//		if (ImGui::Button("Xbox", ImVec2(k_shader_selection_type_button_width, 0)))
		//		{
		//			use_durango_shader_disassembly = true;
		//			disassemble_runtime();
		//		}
		//	}
		//}
		//else
		//{
		//	//ImGui::SameLine(ImGui::GetContentRegionAvail().x - k_shader_selection_type_button_width);
		//	ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		//	if (use_durango_shader_disassembly)
		//	{
		//		ImGui::Button("PC", ImVec2(k_shader_selection_type_button_width, 0));
		//	}
		//	else
		//	{
		//		ImGui::Button("Xbox", ImVec2(k_shader_selection_type_button_width, 0));
		//	}
		//	ImGui::PopItemFlag();
		//}

		//if (selected_cache_file_tab)
		{
			c_legacy_tag_group_interface* tag_group_interface = cache_file.get_group_interface_by_group_id(_legacy_tag_group_render_method_definition);
			c_render_method_definition_group_interface* render_method_definition_interface = dynamic_cast<c_render_method_definition_group_interface*>(tag_group_interface);
			DEBUG_ASSERT(render_method_definition_interface == tag_group_interface);
			const std::vector<c_tag_interface*>& tag_interfaces = render_method_definition_interface->get_tag_interfaces();

			const char* selected_render_method_definition_tag_interface_text = selected_render_method_definition_tag_interface ? selected_render_method_definition_tag_interface->get_name_cstr() : "(select render method definition)";
			if (render_method_definition_interface)
			{
				if (ImGui::BeginCombo("Definition", selected_render_method_definition_tag_interface_text))
				{
					for (c_tag_interface* render_method_definition_tag_interface : tag_interfaces)
					{
						DEBUG_ASSERT(render_method_definition_tag_interface->get_group_interface() == render_method_definition_interface);
						DEBUG_ASSERT(render_method_definition_interface->GetGroupMagic() == _legacy_tag_group_render_method_definition);

						if (ImGui::Selectable(render_method_definition_tag_interface->get_name_cstr(), selected_render_method_definition_tag_interface == render_method_definition_tag_interface))
						{
							selected_render_method_definition_tag_interface = render_method_definition_tag_interface;
							selected_render_method_template_tag_interface = nullptr;
							disassemble_runtime();
						}
					}

					ImGui::EndCombo();
				}
			}
			else ImGui::Text("Couldn't find Render Method Definition group!");
		}
		//else
		//{
		//	ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		//	if (ImGui::BeginCombo("Definition", ""))
		//	{
		//		ImGui::EndCombo();
		//	}
		//	ImGui::PopItemFlag();
		//}

		constexpr float k_goto_button_width = 80.0f;
		if (selected_render_method_definition_tag_interface)
		{
			ImGui::SameLine(ImGui::GetContentRegionAvail().x - k_goto_button_width);

			if (ImGui::Button("Goto", ImVec2(k_goto_button_width, 0)))
			{
				parent_tab.open_tag_interface_tab(*selected_render_method_definition_tag_interface);
			}
		}
		else
		{
			ImGui::SameLine(ImGui::GetContentRegionAvail().x - k_shader_selection_type_button_width);
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
			ImGui::Button("Goto", ImVec2(k_goto_button_width, 0));
			ImGui::PopItemFlag();
		}

		if (selected_render_method_definition_tag_interface)
		{
			// #TODO: This could do with some optimization by adding a subclass to c_tag_interface to store all of this information computed upfront

			c_legacy_tag_group_interface* tag_group_interface = cache_file.get_group_interface_by_group_id(_legacy_tag_group_render_method_definition);
			c_render_method_definition_group_interface* render_method_definition_interface = dynamic_cast<c_render_method_definition_group_interface*>(tag_group_interface);


			DEBUG_ASSERT(render_method_definition_interface->shader_definition_and_rmt2.find(selected_render_method_definition_tag_interface) != render_method_definition_interface->shader_definition_and_rmt2.end());
			std::vector<c_tag_interface*>& render_method_template_tags = render_method_definition_interface->shader_definition_and_rmt2[selected_render_method_definition_tag_interface];

			const char* selected_render_method_template_tag_interface_text = selected_render_method_template_tag_interface ? selected_render_method_template_tag_interface->get_name_cstr() : "(select render method template)";
			if (ImGui::BeginCombo("Template", selected_render_method_template_tag_interface_text))
			{
				for (c_tag_interface* render_method_template_tag_interface : render_method_template_tags)
				{
					DEBUG_ASSERT(render_method_template_tag_interface->get_group_interface()->GetGroupMagic() == _legacy_tag_group_render_method_template);

					if (ImGui::Selectable(render_method_template_tag_interface->get_name_cstr(), selected_render_method_template_tag_interface == render_method_template_tag_interface))
					{
						selected_render_method_template_tag_interface = render_method_template_tag_interface;
						disassemble_runtime();
					}
				}

				ImGui::EndCombo();
			}
		}
		else
		{
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
			if (ImGui::BeginCombo("Template", ""))
			{
				ImGui::EndCombo();
			}
			ImGui::PopItemFlag();
		}

		if (selected_render_method_template_tag_interface)
		{
			ImGui::SameLine(ImGui::GetContentRegionAvail().x - k_goto_button_width);

			if (ImGui::Button("Goto", ImVec2(k_goto_button_width, 0)))
			{
				parent_tab.open_tag_interface_tab(*selected_render_method_template_tag_interface);
			}
		}
		else
		{
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
			ImGui::SameLine(ImGui::GetContentRegionAvail().x - k_goto_button_width);
			ImGui::Button("Goto", ImVec2(k_goto_button_width, 0));
			ImGui::PopItemFlag();
		}
	}
	const float end_cursor_position_y = ImGui::GetCursorPosY();
	if (end_cursor_position_y < k_min_column_height)
	{
		ImGui::Dummy(ImVec2(0.0f, k_min_column_height - end_cursor_position_y));
	}
	ImGui::NextColumn();
}

void c_mantle_shader_tool_gui_tab::render_text_editor_status_bar_gui()
{
	if (source_code_editor_display.IsFocused() || selected_text_editor == nullptr)
	{
		selected_text_editor = &source_code_editor_display;
		selected_file_path = "shader.hlsl";
		selected_language_name = source_code_editor_display.GetLanguageDefinition().mName.c_str();
	}
	if (preview_disassembly_display.IsFocused())
	{
		selected_text_editor = &preview_disassembly_display;
		selected_file_path = "assembly_editor.asm";
		selected_language_name = "ASM";
	}
	if (runtime_disassembly_display.IsFocused())
	{
		selected_text_editor = &runtime_disassembly_display;
		selected_file_path = "runtime_code_display.asm";
		selected_language_name = "ASM";
	}

	TextEditor::Coordinates cursor_position = selected_text_editor->GetCursorPosition();

	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10.0f);
	ImGui::Text(
		"%6d/%-6d %6d lines  | %s | %s | %s | %s",
		cursor_position.mLine + 1,
		cursor_position.mColumn + 1,
		selected_text_editor->GetTotalLines(),
		selected_text_editor->IsOverwrite() ? "Ovr" : "Ins",
		selected_text_editor->CanUndo() ? "*" : " ",
		selected_language_name, selected_file_path);
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 10.0f);
}

void c_mantle_shader_tool_gui_tab::render_tab_contents_gui()
{
	ImGui::Columns(3);
	render_source_code_editor_configuration_header_column_gui(); // column 0
	render_preview_disassembly_configuration_header_column_gui(); // column 1
	render_runtime_disassembly_configuration_header_column_gui(); // column 2

	ImGui::Columns(1);
	ImGui::SameLine();
	ImGui::SetCursorPosX(0);
	render_text_editor_status_bar_gui();
	ImGui::Dummy(ImVec2(0.0f, 3.0f));

	ImGui::Columns(3);

	render_source_code_editor_gui();
	render_preview_disassembly();
	render_runtime_disassembly();

	ImGui::Columns(1);
}

void c_mantle_shader_tool_gui_tab::compile_source()
{
	source_code = source_code_editor_display.GetText();
	compile_source_thread_subroutine();
}

void c_mantle_shader_tool_gui_tab::compile_source_subroutine() const
{
	std::string new_source_code;
	if (!source_code.get(new_source_code))
	{
		return;
	}

	TextEditor::ErrorMarkers error_markers;

	std::vector< D3D_SHADER_MACRO> macros;
	macros.resize(1);

	const char* fake_file_path = "shader.hlsl";
	const char* shader_profile_string = shader_profile_to_string(current_shader_profile);

	ID3D10Blob* code_blob = NULL;
	ID3D10Blob* error_blob = NULL;
	HRESULT d3d_compile_result = D3DCompile(new_source_code.c_str(), new_source_code.size(), fake_file_path, macros.data(), NULL, "main", shader_profile_string, 0, 0, &code_blob, &error_blob);

	if (code_blob == nullptr || FAILED(d3d_compile_result))
	{
		if (error_blob)
		{
			const char* error_string = reinterpret_cast<char*>(error_blob->GetBufferPointer());

			if (error_string != nullptr)
			{
				std::stringstream stream(error_string);
				std::string current_line;


				while (std::getline(stream, current_line, '\n'))
				{
					int line_number = 1;
					size_t start_of_error_string = current_line.find("error ");
					std::string error_string_str;
					if (start_of_error_string != 0)
					{
						size_t end_of_filename_position = current_line.find('(');
						size_t middle_of_brackets = current_line.find(',', end_of_filename_position);
						size_t end_of_brackets_position = current_line.find(')', end_of_filename_position);
						start_of_error_string = current_line.find(": error ", end_of_brackets_position);

						std::string filename_str = current_line.substr(0, end_of_filename_position);
						std::string brackets_str = current_line.substr(end_of_filename_position, end_of_brackets_position - end_of_filename_position + 1);
						std::string line_number_str = current_line.substr(end_of_filename_position + 1, middle_of_brackets - end_of_filename_position - 1);

						error_string_str = current_line.substr(start_of_error_string + 8);
						line_number = atoi(line_number_str.c_str());
					}
					else
					{
						error_string_str = current_line.substr(6);
					}

					decltype(error_markers)::iterator markers_iterator = error_markers.find(line_number);
					if (markers_iterator != error_markers.end())
					{
						markers_iterator->second += "\n";
						markers_iterator->second += error_string_str.c_str();
					}
					else
					{
						error_markers.emplace(static_cast<int>(line_number), error_string_str.c_str());
					}

					write_line_verbose(current_line.c_str());
				}
			}

			write_line_verbose("errors!");
			write_line_verbose(error_string);

			new_source_code_disassembly = error_string;

			error_blob->Release();
		}
		else
		{
			write_line_verbose("no errors!");
		}

		if (code_blob)
		{
			code_blob->Release();
		}

	}
	else if (code_blob)
	{
		write_line_verbose("shader compiled!");

		SIZE_T hlsl_bytecode_size = code_blob->GetBufferSize();
		const char* hlsl_bytecode = reinterpret_cast<char*>(code_blob->GetBufferPointer());

		ID3D10Blob* disassembly_blob = NULL;
		HRESULT d3d_disassemble_result = D3DDisassemble(hlsl_bytecode, hlsl_bytecode_size, 0, NULL, &disassembly_blob);

		if (FAILED(d3d_disassemble_result) && disassembly_blob != nullptr)
		{
			new_source_code_disassembly = "Failed to disassemble shader";
			// #TODO: Provide error details
		}
		else
		{
			write_line_verbose("shader disassembled!");

			const char* hlsl_disassembly = reinterpret_cast<char*>(disassembly_blob->GetBufferPointer());
			new_source_code_disassembly = hlsl_disassembly;
		}

		if (disassembly_blob) disassembly_blob->Release();
		code_blob->Release();
	}
	else
	{
		// Something went wrong... There was no error but no shader code...
		new_source_code_disassembly = "";

		write_line_verbose("shader ded!");
	}

	new_source_code_error_markers = error_markers;
}

void c_mantle_shader_tool_gui_tab::disassemble_runtime_subroutine() const
{
	if (selected_render_method_template_tag_interface)
	{
		s_render_method_template_definition_legacy* render_method_template = selected_render_method_template_tag_interface->get_data<s_render_method_template_definition_legacy>();
		c_tag_interface* pixel_shader_tag_interface = cache_file.get_tag_interface(render_method_template->pixel_shader_reference.index);
		s_pixel_shader_definition_legacy* pixel_shader = pixel_shader_tag_interface->get_data<s_pixel_shader_definition_legacy>();

		// #TODO: Remove GetTagBlockData and replace with virtual tag interface/virtual tab block data access
		s_pixel_shader_definition_legacy::s_pixel_shaders_definition_legacy* pixel_shader2_block = cache_file.GetTagBlockData(pixel_shader->pixel_shaders_block) + 0;

		std::string disassemble_shader_result;
		if (use_durango_shader_disassembly)
		{
			size_t __unknown4_data_reference_size = pixel_shader2_block->__unknown3.size;
			char* __unknown4_data_reference_data = cache_file.get_data_reference_data(pixel_shader2_block->__unknown3);
			disassemble_shader_result = disassemble_shader(__unknown4_data_reference_data, __unknown4_data_reference_size);
		}
		else
		{
			size_t __unknown3_data_reference_size = pixel_shader2_block->__unknown2.size;
			char* __unknown3_data_reference_data = cache_file.get_data_reference_data(pixel_shader2_block->__unknown2);
			disassemble_shader_result = disassemble_shader(__unknown3_data_reference_data, __unknown3_data_reference_size);
		}

		new_runtime_disassembly = disassemble_shader_result;
	}
	else
	{
		new_runtime_disassembly = "";
	}
}
