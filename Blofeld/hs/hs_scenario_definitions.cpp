#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(hsc, HSC_TAG, hs_source_files_block_block );

	TAG_BLOCK(hs_references_block, k_maximum_hs_references_per_context)
	{
		FIELD( _field_tag_reference, "reference*^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(hs_source_files_block, k_maximum_hs_source_files_per_context)
	{
		FIELD( _field_string, "name*" ),
		FIELD( _field_data, "source*" ),
		FIELD( _field_long_flags, "flags", &hs_source_file_flags ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(hs_script_parameters_block, k_maximum_hs_parameters_per_script)
	{
		FIELD( _field_string, "name^*" ),
		FIELD( _field_long_enum, "return type*", &hs_types_enum ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(hs_scripts_block, k_maximum_hs_scripts_per_context)
	{
		FIELD( _field_string_id, "name^*" ),
		FIELD( _field_enum, "script type*", &hs_script_types_enum ),
		FIELD( _field_word_flags, "script flags*", &scriptFlagsEnumDefinition ),
		FIELD( _field_long_enum, "return type*", &hs_types_enum ),
		FIELD( _field_long_integer, "root expression index*" ),
		FIELD( _field_long_integer, "locals stack space" ),
		FIELD( _field_block, "parameters", &hs_script_parameters_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(hs_globals_block, k_maximum_hs_globals_per_context)
	{
		FIELD( _field_string_id, "name*" ),
		FIELD( _field_long_enum, "type*", &hs_types_enum ),
		FIELD( _field_long_integer, "initialization expression index*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(HSInstancedVariablesBlock, k_maximum_hs_instanced_variables_per_context)
	{
		FIELD( _field_string_id, "name*" ),
		FIELD( _field_long_enum, "type*", &hs_types_enum ),
		FIELD( _field_long_integer, "initialization expression index*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(hs_unit_seat_block, k_maximum_hs_unit_seat_mappings)
	{
		FIELD( _field_long_integer, "unit definition tag index!" ),
		FIELD( _field_long_integer, "unit seats!" ),
		FIELD( _field_long_integer, "unit seats2!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(hs_syntax_datum_block, k_maximum_hs_syntax_nodes_per_context)
	{
		FIELD( _field_short_integer, "datum header~" ),
		FIELD( _field_short_integer, "script index/function index/constant type union" ),
		FIELD( _field_long_integer, "next node" ),
		FIELD( _field_long_integer, "source data" ),
		FIELD( _field_long_integer, "source offset location" ),
		FIELD( _field_long_enum, "node expression type", &hs_types_enum ),
		FIELD( _field_short_integer, "flags" ),
		FIELD( _field_short_integer, "source file index" ),
		FIELD( _field_long_integer, "source file offset" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(HSImportManifestEntryBlock, k_maximum_hs_scripts_per_context)
	{
		FIELD( _field_string_id, "script name*" ),
		FIELD( _field_long_integer, "argCount*" ),
		FIELD( _field_long_integer, "index!~" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(HSImportManifestBlock, 128)
	{
		FIELD( _field_tag, "callee tag*" ),
		FIELD( _field_block, "script table*", &HSImportManifestEntryBlock_block ),
		FIELD( _field_block, "variable table*", &HSImportManifestEntryBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(hs_script_types_enum, 6)
	{
		OPTION("startup"),
		OPTION("dormant"),
		OPTION("continuous"),
		OPTION("static"),
		OPTION("command_script"),
		OPTION("stub"),
	};

	TAG_ENUM(scriptFlagsEnumDefinition, 2)
	{
		OPTION("instanced"),
		OPTION("cinema"),
	};

	TAG_ENUM(hs_types_enum, 102)
	{
		OPTION("unparsed"),
		OPTION("special_form"),
		OPTION("function_name"),
		OPTION("passthrough"),
		OPTION("void"),
		OPTION("boolean"),
		OPTION("real"),
		OPTION("short"),
		OPTION("long"),
		OPTION("string"),
		OPTION("script"),
		OPTION("string_id"),
		OPTION("unit_seat_mapping"),
		OPTION("trigger_volume"),
		OPTION("sound_event"),
		OPTION("cutscene_flag"),
		OPTION("cutscene_camera_point"),
		OPTION("cutscene_title"),
		OPTION("cutscene_recording"),
		OPTION("device_group"),
		OPTION("ai"),
		OPTION("ai_command_list"),
		OPTION("ai_command_script"),
		OPTION("ai_behavior"),
		OPTION("ai_orders"),
		OPTION("ai_line"),
		OPTION("starting_profile"),
		OPTION("conversation"),
		OPTION("player"),
		OPTION("zone_set"),
		OPTION("designer_zone"),
		OPTION("point_reference"),
		OPTION("point_set_reference"),
		OPTION("style"),
		OPTION("object_list"),
		OPTION("folder"),
		OPTION("sound"),
		OPTION("effect"),
		OPTION("damage"),
		OPTION("looping_sound"),
		OPTION("animation_graph"),
		OPTION("damage_effect"),
		OPTION("object_definition"),
		OPTION("bitmap"),
		OPTION("shader"),
		OPTION("render_model"),
		OPTION("structure_definition"),
		OPTION("lightmap_definition"),
		OPTION("cinematic_definition"),
		OPTION("cinematic_scene_definition"),
		OPTION("cinematic_scene_data_definition"),
		OPTION("cinematic_transition_definition"),
		OPTION("bink_definition"),
		OPTION("cui_screen_definition"),
		OPTION("any_tag"),
		OPTION("any_tag_not_resolving"),
		OPTION("game_difficulty"),
		OPTION("team"),
		OPTION("mp_team"),
		OPTION("controller"),
		OPTION("button_preset"),
		OPTION("joystick_preset"),
		OPTION("player_color"),
		OPTION("player_model_choice"),
		OPTION("voice_output_setting"),
		OPTION("voice_mask"),
		OPTION("subtitle_setting"),
		OPTION("actor_type"),
		OPTION("model_state"),
		OPTION("event"),
		OPTION("character_physics"),
		OPTION("skull"),
		OPTION("firing_point_evaluator"),
		OPTION("damage_region"),
		OPTION("currency_type"),
		OPTION("delivery_method"),
		OPTION("wave_difficulty"),
		OPTION("firefight_goal"),
		OPTION("firefight_wave_type"),
		OPTION("font"),
		OPTION("text_justification"),
		OPTION("text_alignment"),
		OPTION("text_drop_shadow_type"),
		OPTION("havok_group"),
		OPTION("object"),
		OPTION("unit"),
		OPTION("vehicle"),
		OPTION("weapon"),
		OPTION("device"),
		OPTION("scenery"),
		OPTION("effect_scenery"),
		OPTION("object_name"),
		OPTION("unit_name"),
		OPTION("vehicle_name"),
		OPTION("weapon_name"),
		OPTION("device_name"),
		OPTION("scenery_name"),
		OPTION("effect_scenery_name"),
		OPTION("cinematic_lightprobe"),
		OPTION("animation_budget_reference"),
		OPTION("looping_sound_budget_reference"),
		OPTION("sound_budget_reference"),
	};

	TAG_ENUM(hs_source_file_flags, 3)
	{
		OPTION("generated at runtime"),
		OPTION("ai fragments"),
		OPTION("ai performances"),
	};

} // namespace blofeld

