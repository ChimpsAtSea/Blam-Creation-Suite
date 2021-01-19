#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		hsc_group,
		HSC_TAG,
		nullptr,
		INVALID_TAG,
		hs_source_files_block );

	#define HSC_STRUCT_DEFINITION_ID { 0xCB061583, 0x078C4130, 0xA21DDAC3, 0x5C721332 }
	TAG_BLOCK(
		hs_source_files_block,
		"hs_source_files_block",
		k_maximum_hs_source_files_per_context,
		"hs_source_file",
		HSC_STRUCT_DEFINITION_ID)
	{
		{ _field_string, "name*" },
		{ _field_data, "source*" },
		{ _field_long_flags, "flags", &hs_source_file_flags },
		{ _field_terminator }
	};

	#define HS_REFERENCES_BLOCK_ID { 0xD5081A5A, 0xAAAE49B0, 0xA3DD5C21, 0x984C1A8B }
	TAG_BLOCK(
		hs_references_block,
		"hs_references_block",
		k_maximum_hs_references_per_context,
		"s_tag_reference",
		HS_REFERENCES_BLOCK_ID)
	{
		{ _field_tag_reference, "reference*^", &hs_references_block_reference_reference },
		{ _field_terminator }
	};

	#define HS_SCRIPTS_BLOCK_ID { 0x743D2F82, 0xC7BE47E3, 0xA33C2E37, 0x4C93AE2F }
	TAG_BLOCK(
		hs_scripts_block,
		"hs_scripts_block",
		k_maximum_hs_scripts_per_context,
		"hs_script",
		HS_SCRIPTS_BLOCK_ID)
	{
		{ _field_string_id, "name^*" },
		{ _field_enum, "script type*", &hs_script_types_enum },
		{ _field_word_flags, "script flags*", &scriptFlagsEnumDefinition },
		{ _field_long_enum, "return type*", &hs_types_enum },
		{ _field_long_integer, "root expression index*" },
		{ _field_long_integer, "locals stack space" },
		{ _field_block, "parameters", &hs_script_parameters_block },
		{ _field_terminator }
	};

	#define HS_SCRIPT_PARAMETERS_BLOCK_ID { 0x9E0B1B9B, 0xC4DF453F, 0x9C5A8529, 0xFDAB8B17 }
	TAG_BLOCK(
		hs_script_parameters_block,
		"hs_script_parameters_block",
		k_maximum_hs_parameters_per_script,
		"hs_script_parameter",
		HS_SCRIPT_PARAMETERS_BLOCK_ID)
	{
		{ _field_string, "name^*" },
		{ _field_long_enum, "return type*", &hs_types_enum },
		{ _field_terminator }
	};

	#define HS_GLOBALS_BLOCK_ID { 0x0593352A, 0x7FDE40C1, 0x9FA69786, 0x35DEEEA1 }
	TAG_BLOCK(
		hs_globals_block,
		"hs_globals_block",
		k_maximum_hs_globals_per_context,
		"HSInternalGlobal",
		HS_GLOBALS_BLOCK_ID)
	{
		{ _field_string_id, "name*" },
		{ _field_long_enum, "type*", &hs_types_enum },
		{ _field_long_integer, "initialization expression index*" },
		{ _field_terminator }
	};

	#define HSINSTANCEDVARIABLESBLOCK_ID { 0x749A4FA9, 0xB61D40B2, 0xA9E4C656, 0x226722FB }
	TAG_BLOCK(
		HSInstancedVariablesBlock_block,
		"HSInstancedVariablesBlock",
		k_maximum_hs_instanced_variables_per_context,
		"HSInternalInstanced",
		HSINSTANCEDVARIABLESBLOCK_ID)
	{
		{ _field_string_id, "name*" },
		{ _field_long_enum, "type*", &hs_types_enum },
		{ _field_long_integer, "initialization expression index*" },
		{ _field_terminator }
	};

	#define HS_UNIT_SEAT_BLOCK_ID { 0x605A618D, 0x49FA4B10, 0x9715B7D2, 0xCC2A0947 }
	TAG_BLOCK(
		hs_unit_seat_block,
		"hs_unit_seat_block",
		k_maximum_hs_unit_seat_mappings,
		"s_hs_unit_seat_mapping",
		HS_UNIT_SEAT_BLOCK_ID)
	{
		{ _field_long_integer, "unit definition tag index!" },
		{ _field_long_integer, "unit seats!" },
		{ _field_long_integer, "unit seats2!" },
		{ _field_terminator }
	};

	#define HS_SYNTAX_DATUM_BLOCK_ID { 0x3B57A0DC, 0x8E8147C2, 0xADEB0323, 0x1D9501C3 }
	TAG_BLOCK(
		hs_syntax_datum_block,
		"hs_syntax_datum_block",
		k_maximum_hs_syntax_nodes_per_context,
		"HSSyntaxNode",
		HS_SYNTAX_DATUM_BLOCK_ID)
	{
		{ _field_short_integer, "datum header~" },
		{ _field_short_integer, "script index/function index/constant type union" },
		{ _field_long_integer, "next node" },
		{ _field_long_integer, "source data" },
		{ _field_long_integer, "source offset location" },
		{ _field_long_enum, "node expression type", &hs_types_enum },
		{ _field_short_integer, "flags" },
		{ _field_short_integer, "source file index" },
		{ _field_long_integer, "source file offset" },
		{ _field_terminator }
	};

	#define HSIMPORTMANIFESTBLOCK_ID { 0xCD668B7A, 0x34BB4A72, 0x8A0794E4, 0xB24C2B19 }
	TAG_BLOCK(
		HSImportManifestBlock_block,
		"HSImportManifestBlock",
		128,
		"HSImportManifest",
		HSIMPORTMANIFESTBLOCK_ID)
	{
		{ _field_tag, "callee tag*" },
		{ _field_block, "script table*", &HSImportManifestEntryBlock_block },
		{ _field_block, "variable table*", &HSImportManifestEntryBlock_block },
		{ _field_terminator }
	};

	#define HSIMPORTMANIFESTENTRYBLOCK_ID { 0x698CF2F7, 0x448A41ED, 0x9D009D70, 0x71DF846A }
	TAG_BLOCK(
		HSImportManifestEntryBlock_block,
		"HSImportManifestEntryBlock",
		k_maximum_hs_scripts_per_context,
		"HSImportManifestEntry",
		HSIMPORTMANIFESTENTRYBLOCK_ID)
	{
		{ _field_string_id, "script name*" },
		{ _field_long_integer, "argCount*" },
		{ _field_long_integer, "index!~" },
		{ _field_terminator }
	};

	STRINGS(hs_script_types_enum)
	{
		"startup",
		"dormant",
		"continuous",
		"static",
		"command_script",
		"stub"
	};
	STRING_LIST(hs_script_types_enum, hs_script_types_enum_strings, _countof(hs_script_types_enum_strings));

	STRINGS(scriptFlagsEnumDefinition)
	{
		"instanced",
		"cinema"
	};
	STRING_LIST(scriptFlagsEnumDefinition, scriptFlagsEnumDefinition_strings, _countof(scriptFlagsEnumDefinition_strings));

	STRINGS(hs_types_enum)
	{
		"unparsed",
		"special_form",
		"function_name",
		"passthrough",
		"void",
		"boolean",
		"real",
		"short",
		"long",
		"string",
		"script",
		"string_id",
		"unit_seat_mapping",
		"trigger_volume",
		"sound_event",
		"cutscene_flag",
		"cutscene_camera_point",
		"cutscene_title",
		"cutscene_recording",
		"device_group",
		"ai",
		"ai_command_list",
		"ai_command_script",
		"ai_behavior",
		"ai_orders",
		"ai_line",
		"starting_profile",
		"conversation",
		"player",
		"zone_set",
		"designer_zone",
		"point_reference",
		"point_set_reference",
		"style",
		"object_list",
		"folder",
		"sound",
		"effect",
		"damage",
		"looping_sound",
		"animation_graph",
		"damage_effect",
		"object_definition",
		"bitmap",
		"shader",
		"render_model",
		"structure_definition",
		"lightmap_definition",
		"cinematic_definition",
		"cinematic_scene_definition",
		"cinematic_scene_data_definition",
		"cinematic_transition_definition",
		"bink_definition",
		"cui_screen_definition",
		"any_tag",
		"any_tag_not_resolving",
		"game_difficulty",
		"team",
		"mp_team",
		"controller",
		"button_preset",
		"joystick_preset",
		"player_color",
		"player_model_choice",
		"voice_output_setting",
		"voice_mask",
		"subtitle_setting",
		"actor_type",
		"model_state",
		"event",
		"character_physics",
		"skull",
		"firing_point_evaluator",
		"damage_region",
		"currency_type",
		"delivery_method",
		"wave_difficulty",
		"firefight_goal",
		"firefight_wave_type",
		"font",
		"text_justification",
		"text_alignment",
		"text_drop_shadow_type",
		"havok_group",
		"object",
		"unit",
		"vehicle",
		"weapon",
		"device",
		"scenery",
		"effect_scenery",
		"object_name",
		"unit_name",
		"vehicle_name",
		"weapon_name",
		"device_name",
		"scenery_name",
		"effect_scenery_name",
		"cinematic_lightprobe",
		"animation_budget_reference",
		"looping_sound_budget_reference",
		"sound_budget_reference"
	};
	STRING_LIST(hs_types_enum, hs_types_enum_strings, _countof(hs_types_enum_strings));

	STRINGS(hs_source_file_flags)
	{
		"generated at runtime",
		"ai fragments",
		"ai performances"
	};
	STRING_LIST(hs_source_file_flags, hs_source_file_flags_strings, _countof(hs_source_file_flags_strings));

} // namespace macaque

} // namespace blofeld

