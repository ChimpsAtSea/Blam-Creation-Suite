#pragma once

namespace blofeld
{



	constexpr unsigned long HSC_TAG = 'hsc*';
	extern s_tag_group hsc_group; // hs_source_files_block


	extern s_tag_block_definition hs_source_files_block;
	extern s_tag_struct_definition hs_source_files_block_struct_definition; // hs_source_files_block
	extern s_tag_block_definition hs_references_block;
	extern s_tag_struct_definition hs_references_block_struct_definition; // hs_references_block
	extern s_tag_block_definition hs_scripts_block;
	extern s_tag_struct_definition hs_scripts_block_struct_definition; // hs_scripts_block
	extern s_tag_block_definition hs_script_parameters_block;
	extern s_tag_struct_definition hs_script_parameters_block_struct_definition; // hs_script_parameters_block
	extern s_tag_block_definition hs_globals_block;
	extern s_tag_struct_definition hs_globals_block_struct_definition; // hs_globals_block
	extern s_tag_block_definition HSInstancedVariablesBlock_block;
	extern s_tag_struct_definition HSInstancedVariablesBlock_block_struct_definition; // HSInstancedVariablesBlock_block
	extern s_tag_block_definition hs_unit_seat_block;
	extern s_tag_struct_definition hs_unit_seat_block_struct_definition; // hs_unit_seat_block
	extern s_tag_block_definition hs_syntax_datum_block;
	extern s_tag_struct_definition hs_syntax_datum_block_struct_definition; // hs_syntax_datum_block
	extern s_tag_block_definition HSImportManifestBlock_block;
	extern s_tag_struct_definition HSImportManifestBlock_block_struct_definition; // HSImportManifestBlock_block
	extern s_tag_block_definition HSImportManifestEntryBlock_block;
	extern s_tag_struct_definition HSImportManifestEntryBlock_block_struct_definition; // HSImportManifestEntryBlock_block


	extern c_versioned_string_list hs_script_types_enum_strings;
	extern s_string_list_definition hs_script_types_enum;
	extern c_versioned_string_list scriptFlagsEnumDefinition_strings;
	extern s_string_list_definition scriptFlagsEnumDefinition;
	extern c_versioned_string_list hs_types_enum_strings;
	extern s_string_list_definition hs_types_enum;
	extern c_versioned_string_list hs_source_file_flags_strings;
	extern s_string_list_definition hs_source_file_flags;



} // namespace blofeld

