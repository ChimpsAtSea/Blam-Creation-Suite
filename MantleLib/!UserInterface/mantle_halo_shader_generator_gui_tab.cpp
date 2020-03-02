#include "mantlelib-private-pch.h"


static TextEditor code_editor;
static TextEditor assembly_editor;
static TextEditor runtime_code_display;
static TextEditor::LanguageDefinition lang = TextEditor::LanguageDefinition::CPlusPlus();

c_mantle_halo_shader_generator_gui_tab::c_mantle_halo_shader_generator_gui_tab(const char* title, const char* description) :
	c_mantle_gui_tab(title, description)
{
	// set your own known preprocessor symbols...
	static const char* ppnames[] = { "NULL", "PM_REMOVE",
		"ZeroMemory", "DXGI_SWAP_EFFECT_DISCARD", "D3D_FEATURE_LEVEL", "D3D_DRIVER_TYPE_HARDWARE", "WINAPI","D3D11_SDK_VERSION", "assert" };
	// ... and their corresponding values
	static const char* ppvalues[] = {
		"#define NULL ((void*)0)",
		"#define PM_REMOVE (0x0001)",
		"Microsoft's own memory zapper function\n(which is a macro actually)\nvoid ZeroMemory(\n\t[in] PVOID  Destination,\n\t[in] SIZE_T Length\n); ",
		"enum DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_DISCARD = 0",
		"enum D3D_FEATURE_LEVEL",
		"enum D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE  = ( D3D_DRIVER_TYPE_UNKNOWN + 1 )",
		"#define WINAPI __stdcall",
		"#define D3D11_SDK_VERSION (7)",
		" #define assert(expression) (void)(                                                  \n"
		"    (!!(expression)) ||                                                              \n"
		"    (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \n"
		" )"
	};

	for (int i = 0; i < sizeof(ppnames) / sizeof(ppnames[0]); ++i)
	{
		TextEditor::Identifier id;
		id.mDeclaration = ppvalues[i];
		lang.mPreprocIdentifiers.insert(std::make_pair(std::string(ppnames[i]), id));
	}

	// set your own identifiers
	static const char* identifiers[] = {
		"HWND", "HRESULT", "LPRESULT","D3D11_RENDER_TARGET_VIEW_DESC", "DXGI_SWAP_CHAIN_DESC","MSG","LRESULT","WPARAM", "LPARAM","UINT","LPVOID",
		"ID3D11Device", "ID3D11DeviceContext", "ID3D11Buffer", "ID3D11Buffer", "ID3D10Blob", "ID3D11VertexShader", "ID3D11InputLayout", "ID3D11Buffer",
		"ID3D10Blob", "ID3D11PixelShader", "ID3D11SamplerState", "ID3D11ShaderResourceView", "ID3D11RasterizerState", "ID3D11BlendState", "ID3D11DepthStencilState",
		"IDXGISwapChain", "ID3D11RenderTargetView", "ID3D11Texture2D", "TextEditor" };
	static const char* idecls[] =
	{
		"typedef HWND_* HWND", "typedef long HRESULT", "typedef long* LPRESULT", "struct D3D11_RENDER_TARGET_VIEW_DESC", "struct DXGI_SWAP_CHAIN_DESC",
		"typedef tagMSG MSG\n * Message structure","typedef LONG_PTR LRESULT","WPARAM", "LPARAM","UINT","LPVOID",
		"ID3D11Device", "ID3D11DeviceContext", "ID3D11Buffer", "ID3D11Buffer", "ID3D10Blob", "ID3D11VertexShader", "ID3D11InputLayout", "ID3D11Buffer",
		"ID3D10Blob", "ID3D11PixelShader", "ID3D11SamplerState", "ID3D11ShaderResourceView", "ID3D11RasterizerState", "ID3D11BlendState", "ID3D11DepthStencilState",
		"IDXGISwapChain", "ID3D11RenderTargetView", "ID3D11Texture2D", "class TextEditor" };
	for (int i = 0; i < sizeof(identifiers) / sizeof(identifiers[0]); ++i)
	{
		TextEditor::Identifier id;
		id.mDeclaration = std::string(idecls[i]);
		lang.mIdentifiers.insert(std::make_pair(std::string(identifiers[i]), id));
	}
	code_editor.SetLanguageDefinition(lang);
	//editor.SetPalette(TextEditor::GetLightPalette());

	// error markers
	TextEditor::ErrorMarkers markers;
	markers.insert(std::make_pair<int, std::string>(6, "Example error here:\nInclude file not found: \"TextEditor.h\""));
	markers.insert(std::make_pair<int, std::string>(41, "Another example error"));
	code_editor.SetErrorMarkers(markers);

	const char* example_code = "\n\n"
		"float4 main() : COLOR\n"
		"{\n"
		"	return float4(1, 0, 0, 0);\n"
		"}\n";

	code_editor.SetText(example_code);

	compile_source();
}

c_mantle_halo_shader_generator_gui_tab::~c_mantle_halo_shader_generator_gui_tab()
{

}

void c_mantle_halo_shader_generator_gui_tab::render_in_game_gui()
{

}

void c_mantle_halo_shader_generator_gui_tab::render_contents(bool setSelected)
{
	check_source_update();

	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(get_title(), &m_isOpen, tabFlags))
	{
		TextEditor::Coordinates cpos = code_editor.GetCursorPosition();

		static TextEditor* current_text_editor = &code_editor;
		static const char* fake_file_path = "shader.hlsl";
		static const char* language_name = "HLSL";

		if (code_editor.IsFocused())
		{
			current_text_editor = &code_editor;
			fake_file_path = "shader.hlsl";
			language_name = "HLSL";
		}
		if (assembly_editor.IsFocused())
		{
			current_text_editor = &assembly_editor;
			fake_file_path = "assembly_editor.asm";
			language_name = "ps_3_0";
		}
		if (runtime_code_display.IsFocused())
		{
			current_text_editor = &runtime_code_display;
			fake_file_path = "runtime_code_display.asm";
			language_name = "ps_3_0";
		}


		ImGui::Columns(3);
		{ // col0

		}
		ImGui::NextColumn();
		{ // col1

		}
		ImGui::NextColumn();
		{ // col2
			// #TODO: What happens when this tab closes? This value needs to be fixed up

			static c_mantle_cache_file_gui_tab* selected_cache_file_tab = nullptr;
			const char* cache_file_combo_text = selected_cache_file_tab ? selected_cache_file_tab->get_title() : "(select cache file)";
			if (ImGui::BeginCombo("Cache File", cache_file_combo_text))
			{
				if (ImGui::Selectable("(select cache file)", selected_cache_file_tab == nullptr))
				{
					selected_cache_file_tab = nullptr;
				}

				for (c_mantle_gui_tab* gui_tab : c_mantle_gui::get_tabs())
				{
					c_mantle_cache_file_gui_tab* cache_file_gui_tab = dynamic_cast<c_mantle_cache_file_gui_tab*>(gui_tab);
					if (cache_file_gui_tab == nullptr) continue;

					if (ImGui::Selectable(cache_file_gui_tab->get_title(), selected_cache_file_tab == cache_file_gui_tab))
					{
						selected_cache_file_tab = cache_file_gui_tab;
					}
				}

				ImGui::EndCombo();
			}

			static c_tag_interface* selected_render_method_definition_tag_interface = nullptr;
			if (selected_cache_file_tab)
			{
				c_tag_group_interface* tag_group_interface = selected_cache_file_tab->get_cache_file()->GetGroupInterfaceByGroupID(_tag_group_render_method_definition);
				c_render_method_definition_group_interface* render_method_definition_interface = dynamic_cast<c_render_method_definition_group_interface*>(tag_group_interface);
				DEBUG_ASSERT(render_method_definition_interface == tag_group_interface);
				const std::vector<c_tag_interface*>& tag_interfaces = render_method_definition_interface->GetTagInterfaces();

				const char* selected_render_method_definition_tag_interface_text = selected_render_method_definition_tag_interface ? selected_render_method_definition_tag_interface->GetNameCStr() : "(select render method definition)";
				if (render_method_definition_interface)
				{
					if (ImGui::BeginCombo("Render Method Definition", selected_render_method_definition_tag_interface_text))
					{
						for (c_tag_interface* render_method_definition_tag_interface : tag_interfaces)
						{
							DEBUG_ASSERT(render_method_definition_tag_interface->GetGroupInterface() == render_method_definition_interface);
							DEBUG_ASSERT(render_method_definition_interface->GetGroupMagic() == _tag_group_render_method_definition);

							if (ImGui::Selectable(render_method_definition_tag_interface->GetNameCStr(), selected_render_method_definition_tag_interface == render_method_definition_tag_interface))
							{
								selected_render_method_definition_tag_interface = render_method_definition_tag_interface;
							}
						}

						ImGui::EndCombo();
					}
				}
				else ImGui::Text("Couldn't find Render Method Definition group!");
			}
			else
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
				if (ImGui::BeginCombo("Render Method Definition", ""))
				{
					ImGui::EndCombo();
				}ImGui::PopItemFlag();
			}

			static c_tag_interface* selected_render_method_template_tag_interface = nullptr;
			if (selected_render_method_definition_tag_interface)
			{
				// #TODO: This could do with some optimization by adding a subclass to c_tag_interface to store all of this information computed upfront

				c_tag_group_interface* tag_group_interface = selected_cache_file_tab->get_cache_file()->GetGroupInterfaceByGroupID(_tag_group_render_method_definition);
				c_render_method_definition_group_interface* render_method_definition_interface = dynamic_cast<c_render_method_definition_group_interface*>(tag_group_interface);


				DEBUG_ASSERT(render_method_definition_interface->shader_definition_and_rmt2.find(selected_render_method_definition_tag_interface) != render_method_definition_interface->shader_definition_and_rmt2.end());
				std::vector<c_tag_interface*>& render_method_template_tags = render_method_definition_interface->shader_definition_and_rmt2[selected_render_method_definition_tag_interface];

				const char* selected_render_method_template_tag_interface_text = selected_render_method_template_tag_interface ? selected_render_method_template_tag_interface->GetNameCStr() : "(select render method template)";
				if (ImGui::BeginCombo("Render Method Template", selected_render_method_template_tag_interface_text))
				{
					for (c_tag_interface* render_method_template_tag_interface : render_method_template_tags)
					{
						DEBUG_ASSERT(render_method_template_tag_interface->GetGroupInterface()->GetGroupMagic() == _tag_group_render_method_template);

						if (ImGui::Selectable(render_method_template_tag_interface->GetNameCStr(), selected_render_method_template_tag_interface == render_method_template_tag_interface))
						{
							selected_render_method_template_tag_interface = render_method_template_tag_interface;


							// disassemble game shader
							{
								s_render_method_template_definition* render_method_template = render_method_template_tag_interface->GetData<s_render_method_template_definition>();
								c_tag_interface* pixel_shader_tag_interface = render_method_template_tag_interface->GetCacheFile().GetTagInterface(render_method_template->pixel_shader_reference.index);
								s_pixel_shader_definition* pixel_shader = pixel_shader_tag_interface->GetData<s_pixel_shader_definition>();

								s_pixel_shader_definition::s_pixel_shader2_block_definition* pixel_shader2_block = render_method_template_tag_interface->GetCacheFile().GetTagBlockData(pixel_shader->pixel_shaders_block)+ 0;

								char buffer[1024]{};
								snprintf(buffer, 1023, "%s%i\n%s%i\n%s%i",
									"__unknown2_data_reference.size",
									pixel_shader2_block->__unknown2_data_reference.size,
									"__unknown3_data_reference.size",
									pixel_shader2_block->__unknown3_data_reference.size,
									"__unknown4_data_reference.size",
									pixel_shader2_block->__unknown4_data_reference.size
								);
								runtime_code_display.SetText(buffer);
							}
						}
					}

					ImGui::EndCombo();
				}
			}
			else
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
				if (ImGui::BeginCombo("Render Method Template", ""))
				{
					ImGui::EndCombo();
				}ImGui::PopItemFlag();
			}


		}
		ImGui::NextColumn();
		ImGui::Columns(1);
		{
			ImGui::Text(
				"%6d/%-6d %6d lines  | %s | %s | %s | %s",
				cpos.mLine + 1,
				cpos.mColumn + 1,
				current_text_editor->GetTotalLines(),
				current_text_editor->IsOverwrite() ? "Ovr" : "Ins",
				current_text_editor->CanUndo() ? "*" : " ",
				language_name, fake_file_path);
		}
		ImGui::Columns(3);
		{ // col0
			code_editor.Render("TextEditor");

			if (code_editor.IsTextChanged()) // #TODO: Make this async
			{
				compile_source();
			}
		}
		ImGui::NextColumn();
		{ // col1
			assembly_editor.SetReadOnly(true);
			assembly_editor.Render("TextEditor2");
		}
		ImGui::NextColumn();
		{ // col2
			runtime_code_display.SetReadOnly(true);
			runtime_code_display.Render("Runtime");
		}
		ImGui::NextColumn();
		ImGui::Columns(1);
		ImGui::EndTabItem();
	}
	ImGui::PopID();
}

void c_mantle_halo_shader_generator_gui_tab::check_source_update()
{
	if (source_needs_updating)
	{
		if (!is_currently_updating)
		{
			source_needs_updating = false;
			is_currently_updating = true;

			tbb::task::enqueue(*lambda_task([=]()
				{
					compile_source(true);
				}
			));

		}
	}

	if (has_updated_results)
	{
		has_updated_results = false;

		// process updated results
		update_display();
	}
}

void c_mantle_halo_shader_generator_gui_tab::compile_source(bool is_worker_thread)
{
	if (!is_worker_thread)
	{
		source_needs_updating = true;
		new_compile_source_text = code_editor.GetText();
		return;
	}

	write_line_verbose("text changed!");

	error_markers.clear();

	std::vector< D3D_SHADER_MACRO> macros;
	macros.resize(1);

	const char* fake_file_path = "shader.hlsl";

	ID3D10Blob* code_blob = NULL;
	ID3D10Blob* error_blob = NULL;
	HRESULT d3d_compile_result = D3DCompile(new_compile_source_text.c_str(), new_compile_source_text.size(), fake_file_path, macros.data(), NULL, "main", "ps_3_0", 0, 0, &code_blob, &error_blob);

	if (code_blob == nullptr | FAILED(d3d_compile_result))
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
					size_t end_of_filename_position = current_line.find('(');
					size_t middle_of_brackets = current_line.find(',', end_of_filename_position);
					size_t end_of_brackets_position = current_line.find(')', end_of_filename_position);
					size_t start_of_error_string = current_line.find(": error ", end_of_brackets_position);

					std::string filename_str = current_line.substr(0, end_of_filename_position);
					std::string brackets_str = current_line.substr(end_of_filename_position, end_of_brackets_position - end_of_filename_position + 1);
					std::string line_number_str = current_line.substr(end_of_filename_position + 1, middle_of_brackets - end_of_filename_position - 1);
					std::string error_string_str = current_line.substr(start_of_error_string + 8);

					int line_number = atoi(line_number_str.c_str());


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
			new_assembly_editor_text = "Failed to disassemble shader";
			// #TODO: Provide error details
		}
		else
		{
			write_line_verbose("shader disassembled!");

			const char* hlsl_disassembly = reinterpret_cast<char*>(disassembly_blob->GetBufferPointer());
			new_assembly_editor_text = hlsl_disassembly;
		}

		if (disassembly_blob) disassembly_blob->Release();
		code_blob->Release();
	}
	else
	{
		// Something went wrong... There was no error but no shader code...
		new_assembly_editor_text = "";

		write_line_verbose("shader ded!");
	}

	is_currently_updating = false;
	has_updated_results = true;
}

void c_mantle_halo_shader_generator_gui_tab::update_display()
{
	assembly_editor.SetText(new_assembly_editor_text.c_str());
	code_editor.SetErrorMarkers(error_markers);
}
