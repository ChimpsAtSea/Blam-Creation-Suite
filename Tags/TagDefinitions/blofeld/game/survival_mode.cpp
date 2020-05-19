#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(survival_mode_globals, SURVIVAL_MODE_GLOBALS_TAG, survival_mode_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(survival_mode_wave_templates, k_global_wave_templates_count, survival_mode_wave_templates_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(survival_mode_globals_block, 1, survival_mode_globals_struct_definition_struct_definition );

	TAG_STRUCT(survival_mode_globals_struct_definition)
	{
		{ _field_real, "respawn time#NO: Use game_engine_settings for this" },
		{ _field_tag_reference, "survival mode text", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "countdown sound", &global_sound_reference },
		{ _field_tag_reference, "respawn sound", &global_sound_reference },
		{ _field_tag_reference, "co-op spawning globals", &global_coop_spawning_globals_reference },
		{ _field_block, "wave templates", &survival_mode_wave_templates_block },
		{ _field_block, "state responses", &game_engine_status_response_block_block },
		{ _field_block, "team colors", &multiplayer_color_block$3_block },
		{ _field_terminator }
	};

	TAG_STRUCT(survival_mode_wave_templates_struct)
	{
		{ _field_string_id, "name^" },
		{ _field_tag_reference, "wave template", &wave_template_reference$2 },
		{ _field_terminator }
	};

} // namespace blofeld

