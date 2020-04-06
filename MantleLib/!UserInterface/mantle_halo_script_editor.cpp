#include "mantlelib-private-pch.h"

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

c_mantle_halo_script_editor::c_mantle_halo_script_editor(c_mantle_cache_file_gui_tab& parent_tab, c_cache_file& cache_file) :
	c_mantle_gui_tab("Script Editor", "Halo Script Editor"),
	parent_tab(parent_tab),
	cache_file(cache_file),
	source_code_editor(),
	source_code_editor_language(TextEditor::LanguageDefinition::HaloScript())
{
	source_code_editor.SetLanguageDefinition(source_code_editor_language);

	std::string halo_script_file = c_command_line::get_command_line_arg("-haloscript");
	std::wstring halo_script_filew = { halo_script_file.begin(), halo_script_file.end() };
	if (!halo_script_file.empty())
	{
		std::string halo_script_source = FileSystemReadToMemory(halo_script_filew.c_str());
		source_code_editor.SetText(halo_script_source);
	}
}

c_mantle_halo_script_editor::~c_mantle_halo_script_editor()
{

}

void c_mantle_halo_script_editor::render_tab_contents_gui()
{
	source_code_editor.Render("Halo Script Editor");
}

void c_mantle_halo_script_editor::render_tab_menu_gui()
{
	if (ImGui::BeginMenu("Script"))
	{
		

		ImGui::EndMenu();
	}
}
