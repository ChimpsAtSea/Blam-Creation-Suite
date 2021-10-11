#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		survival_mode_globals_group,
		SURVIVAL_MODE_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		survival_mode_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		survival_mode_globals_block,
		"survival_mode_globals_block",
		1,
		survival_mode_globals_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		survival_mode_wave_templates_block,
		"survival_mode_wave_templates",
		k_global_wave_templates_count,
		survival_mode_wave_templates_struct);

	#define SURVIVAL_MODE_GLOBALS_STRUCT_DEFINITION_ID { 0x85E14A0F, 0xF0534FEA, 0x91B24C4D, 0x74E59924 }
	TAG_STRUCT(
		survival_mode_globals_struct_definition,
		"survival_mode_globals_struct_definition",
		"s_survival_mode_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SURVIVAL_MODE_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_real, "respawn time", "NO: Use game_engine_settings for this" },
		{ _field_tag_reference, "survival mode text", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "countdown sound", &global_sound_reference },
		{ _field_tag_reference, "respawn sound", &global_sound_reference },
		{ _field_tag_reference, "co-op spawning globals", &global_coop_spawning_globals_reference },
		{ _field_block, "wave templates", &survival_mode_wave_templates_block },
		{ _field_block, "state responses", &game_engine_status_response_block },
		{ _field_block, "team colors", &multiplayer_color_block$3_block },
		{ _field_terminator }
	};

	#define SURVIVAL_MODE_WAVE_TEMPLATES_STRUCT_ID { 0x844D5A8D, 0x3EF44ADE, 0xAB297183, 0x11A7ACC1 }
	TAG_STRUCT(
		survival_mode_wave_templates_struct,
		"survival_mode_wave_templates_struct",
		"s_survival_mode_wave_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SURVIVAL_MODE_WAVE_TEMPLATES_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "wave template", &wave_template_reference$2 },
		{ _field_terminator }
	};



} // namespace blofeld

