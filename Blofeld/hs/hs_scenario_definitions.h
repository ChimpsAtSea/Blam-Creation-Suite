#pragma once

namespace blofeld
{

	constexpr unsigned long HSC_TAG = 'hsc*';

	extern s_tag_group hsc_group;

	extern s_tag_struct_definition hs_references_block_block_struct;
	extern s_tag_block_definition hs_references_block_block;
	extern s_tag_struct_definition hs_source_files_block_block_struct;
	extern s_tag_block_definition hs_source_files_block_block;
	extern s_tag_struct_definition hs_script_parameters_block_block_struct;
	extern s_tag_block_definition hs_script_parameters_block_block;
	extern s_tag_struct_definition hs_scripts_block_block_struct;
	extern s_tag_block_definition hs_scripts_block_block;
	extern s_tag_struct_definition hs_globals_block_block_struct;
	extern s_tag_block_definition hs_globals_block_block;
	extern s_tag_struct_definition HSInstancedVariablesBlock_block_struct;
	extern s_tag_block_definition HSInstancedVariablesBlock_block;
	extern s_tag_struct_definition hs_unit_seat_block_block_struct;
	extern s_tag_block_definition hs_unit_seat_block_block;
	extern s_tag_struct_definition hs_syntax_datum_block_block_struct;
	extern s_tag_block_definition hs_syntax_datum_block_block;
	extern s_tag_struct_definition HSImportManifestEntryBlock_block_struct;
	extern s_tag_block_definition HSImportManifestEntryBlock_block;
	extern s_tag_struct_definition HSImportManifestBlock_block_struct;
	extern s_tag_block_definition HSImportManifestBlock_block;



	extern const char* hs_script_types_enum_strings[];
	extern s_string_list_definition hs_script_types_enum;
	extern const char* scriptFlagsEnumDefinition_strings[];
	extern s_string_list_definition scriptFlagsEnumDefinition;
	extern const char* hs_types_enum_strings[];
	extern s_string_list_definition hs_types_enum;
	extern const char* hs_source_file_flags_strings[];
	extern s_string_list_definition hs_source_file_flags;

} // namespace blofeld

