#include "mandrilllib-private-pch.h"

const TextEditor::LanguageDefinition& TextEditor::LanguageDefinition::HaloScript()
{
	static bool halo_script_language_inited = false;
	static LanguageDefinition halo_script_language;
	if (halo_script_language_inited) return halo_script_language;

	halo_script_language.mName = "HSC";

	halo_script_language.mCommentStart = ";*";
	halo_script_language.mCommentEnd = "*;";
	halo_script_language.mSingleLineComment = ";";

	halo_script_language.mCaseSensitive = true;
	halo_script_language.mAutoIndentation = true;

	static const char* const keywords[] = {
		"static", "global", "dormant", "TRUE", "FALSE"
	};
	for (const char* keyword : keywords)
	{
		halo_script_language.mKeywords.insert(keyword);
	}

	for (const c_hs_type_definition& type_definition : hs_type_definitions)
	{
		if (type_definition.flags & _hs_type_flag_enum)
		{
			for (uint32_t enum_index = 0; enum_index < type_definition.enums_count; enum_index++)
			{
				const c_hs_enum_value& hs_enum_value = type_definition.enums[enum_index];
				halo_script_language.mEnums.insert(hs_enum_value.name); // #TODO: Add description for the value
			}
		}

		halo_script_language.mKeywords.insert(type_definition.name);
	}

	for (const c_hs_function_definition& function_definition : hs_function_definitions)
	{
		const char* description = function_definition.documentation.c_str();
		const char* identifier = function_definition.name;

		Identifier id;
		id.mDeclaration = description ? description : "Built-in Function";
		halo_script_language.mIdentifiers.insert(std::make_pair(std::string(identifier), id));
	}

	for (const c_hs_global_definition& global_definition : hs_globals_definitions)
	{
		const char* description = nullptr; // #TODO
		const char* identifier = global_definition.name;

		Identifier id;
		id.mDeclaration = description ? description : "Halo Script Global";
		halo_script_language.mIdentifiers.insert(std::make_pair(std::string(identifier), id));

		halo_script_language.mPreprocIdentifiers.insert(std::make_pair(std::string(identifier), id));
	}

	//halo_script_language.mTokenRegexStringsPost.emplace_back( "(?:\\()([a-zA-Z_])*", PaletteIndex::PreprocIdentifier, 1 ); // #TODO: Grab results for this for matching
	halo_script_language.mTokenRegexStringsPre.emplace_back(";.*", PaletteIndex::Comment);
	halo_script_language.mTokenRegexStringsPost.emplace_back("[ \\t]*#[ \\t]*[a-zA-Z_]+", PaletteIndex::Preprocessor);
	halo_script_language.mTokenRegexStringsPost.emplace_back("L?\\\"(\\\\.|[^\\\"])*\\\"", PaletteIndex::String);
	halo_script_language.mTokenRegexStringsPost.emplace_back("\\'\\\\?[^\\']\\'", PaletteIndex::CharLiteral);
	halo_script_language.mTokenRegexStringsPost.emplace_back("([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fF]?)(?!([0-9])*([a-zA-Z_]))", PaletteIndex::Number);
	halo_script_language.mTokenRegexStringsPost.emplace_back("([+-]?[0-9]+[Uu]?[lL]?[lL]?)(?!([0-9])*([a-zA-Z_]))", PaletteIndex::Number);
	halo_script_language.mTokenRegexStringsPost.emplace_back("(0[0-7]+[Uu]?[lL]?[lL]?)(?!([0-9])*([a-zA-Z_]))", PaletteIndex::Number);
	halo_script_language.mTokenRegexStringsPost.emplace_back("(0[xX][0-9a-fA-F]+[uU]?[lL]?[lL]?)(?!([0-9])*([a-zA-Z_]))", PaletteIndex::Number);
	halo_script_language.mTokenRegexStringsPost.emplace_back("[a-zA-Z_][a-zA-Z0-9_]*", PaletteIndex::Identifier);
	halo_script_language.mTokenRegexStringsPost.emplace_back("[\\[\\]\\{\\}\\!\\%\\^\\&\\*\\(\\)\\-\\+\\=\\~\\|\\<\\>\\?\\/\\;\\,\\.]", PaletteIndex::Punctuation);


	return halo_script_language;
}

c_mandrill_halo_script_editor::c_mandrill_halo_script_editor(c_old_mandrill_cache_file_gui_tab& parent_tab, c_cache_file& cache_file) :
	c_old_mandrill_gui_tab("Script Editor", "Halo Script Editor"),
	parent_tab(parent_tab),
	cache_file(cache_file),
	source_code_editor(),
	source_code_editor_language(TextEditor::LanguageDefinition::HaloScript()),
	compiler_output(),
	show_compiler_output(c_command_line::has_command_line_arg("-showhscompileroutput"))
{
	source_code_editor.SetLanguageDefinition(source_code_editor_language);
	compiler_output.SetLanguageDefinition(TextEditor::LanguageDefinition::PlainText());

	std::string halo_script_file = c_command_line::get_command_line_arg("-haloscript");
	std::wstring halo_script_filew = { halo_script_file.begin(), halo_script_file.end() };
	if (!halo_script_file.empty())
	{
		const char* halo_script_source = filesystem_read_to_memory_legacy(halo_script_filew.c_str());
		if (halo_script_source)
		{
			source_code_editor.SetText(halo_script_source);
			delete[] halo_script_source;
		}
		else source_code_editor.SetText("Failed to open testing blamscript file");
	}

	compiler_output.SetReadOnly(true);
}

c_mandrill_halo_script_editor::~c_mandrill_halo_script_editor()
{

}

void c_mandrill_halo_script_editor::render_tab_contents_gui()
{
	if (show_compiler_output)
	{
		if (source_code_editor.IsTextChanged())
		{
			source_code_error_markers.clear();

			std::string halo_script_file = c_command_line::get_command_line_arg("-haloscript");
			std::wstring halo_script_filew = { halo_script_file.begin(), halo_script_file.end() };
			if (!halo_script_file.empty())
			{
				size_t halo_script_source_size = 0;
				const char* halo_script_source = filesystem_read_to_memory_legacy(halo_script_filew.c_str());
				if (halo_script_source)
				{
					std::string editor_test = source_code_editor.GetText();

					std::vector<c_lisp_node*> lisp_root_nodes;
					std::vector<c_lisp_error> lisp_errors;
					e_lisp_error_type lisp_parse_result = c_lisp_node::parse(editor_test.c_str(), editor_test.size(), lisp_root_nodes, lisp_errors);

					std::stringstream error_stream;
					if (lisp_parse_result != _lisp_error_type_success)
					{
						error_stream << "Compilation errors...\n\n";
						for (const c_lisp_error& lisp_error : lisp_errors)
						{
							std::stringstream error_builder;
							error_builder << "(" << lisp_error.line_number << ", 0) : error L" << static_cast<uint32_t>(lisp_error.type) << " " << lisp_error.message;

							std::string error_string = error_builder.str();

							error_stream << error_string << "\n";
							source_code_error_markers[lisp_error.line_number] = error_string;

						}
						compiler_output.SetText(error_stream.str());
						error_stream << "\n\n";

						//if (new_source_code_error_markers.get(source_code_error_markers))
						//{
						//	source_code_editor.SetErrorMarkers(source_code_error_markers);
						//}
					}

					bool found_ast_errors = false;

					// check the AST for errors

					for (c_lisp_node* node : lisp_root_nodes)
					{
						switch (node->type)
						{
						case _lisp_node_type_variable:
						{
							// #TODO: Replace with the compiler output and errors

							source_code_error_markers[node->line_number] += "arguments are invalid in root space";
							found_ast_errors = true;
						}
						break;
						case _lisp_node_type_statement:
						{
							// #TODO: Replace with the compiler output and errors

							if (node->arguments.empty())
							{
								source_code_error_markers[node->line_number] += "empty statement";
								found_ast_errors = true;
							}
							else
							{
								c_lisp_node* first_argument = node->arguments.front();

								bool is_valid_keyword = false;
								is_valid_keyword |= first_argument->data == "script";
								is_valid_keyword |= first_argument->data == "global";

								if (!is_valid_keyword)
								{
									bool is_function_collision = false;
									for (const c_hs_function_definition& function_definition : hs_function_definitions)
									{
										if (first_argument->data == function_definition.name)
										{
											is_function_collision = true;
											break;
										}
									}

									bool is_type_collision = false;
									for (const c_hs_type_definition& type_definition : hs_type_definitions)
									{
										if (first_argument->data == type_definition.name)
										{
											is_type_collision = true;
											break;
										}
									}

									if (is_function_collision)
									{
										source_code_error_markers[first_argument->line_number] += "invalid function call at root";
										found_ast_errors = true;
									}
									else if (is_type_collision)
									{
										source_code_error_markers[first_argument->line_number] += "invalid type usage at root";
										found_ast_errors = true;
									}
									else if (!is_valid_keyword) // test known keywords
									{
										source_code_error_markers[first_argument->line_number] += "invalid opcode";
										found_ast_errors = true;
									}
								}
							}
						}
						break;
						case _lisp_node_type_uninitialized:
						case _lisp_node_type_comment:
						case _lisp_node_type_multi_line_comment:
						case _lisp_node_type_root:
							break;

						}
					}

					if (found_ast_errors)
					{
						error_stream << "found ast errors!\n\n";
						compiler_output.SetText("ast errors!");
					}
					else
					{
						compiler_output.SetText("success");
					}

					delete[] halo_script_source;
				}
				else compiler_output.SetText("Failed to open testing blamscript file");
			}
			else
			{
				compiler_output.SetText("please specify file using -haloscript:<filepath>");
			}

			source_code_editor.SetErrorMarkers(source_code_error_markers);
		}

		ImGui::Columns(2);
		source_code_editor.Render("Halo Script Editor");
		ImGui::NextColumn();
		compiler_output.Render("Halo Script Compiler");
		ImGui::Columns(1);
	}
	else
	{
		source_code_editor.Render("Halo Script Editor");
	}
}

void c_mandrill_halo_script_editor::render_tab_menu_gui()
{
	if (ImGui::BeginMenu("Script"))
	{
		if (ImGui::MenuItem(show_compiler_output ? "Hide Compiler Output" : "Show Compiler Output"))
		{
			show_compiler_output = !show_compiler_output;
		}

		ImGui::EndMenu();
	}
}
