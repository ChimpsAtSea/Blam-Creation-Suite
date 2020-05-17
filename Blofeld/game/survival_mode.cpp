#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(survival_mode_globals, SURVIVAL_MODE_GLOBALS_TAG, survival_mode_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(survival_mode_globals_block, 1, survival_mode_globals_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(survival_mode_wave_templates, k_global_wave_templates_count, survival_mode_wave_templates_struct_struct_definition );

TAG_STRUCT(survival_mode_globals_struct_definition)
{
		FIELD( _field_real, "respawn time#NO: Use game_engine_settings for this" ),
		FIELD( _field_tag_reference, "survival mode text" ),
		FIELD( _field_tag_reference, "countdown sound" ),
		FIELD( _field_tag_reference, "respawn sound" ),
		FIELD( _field_tag_reference, "co-op spawning globals" ),
		FIELD( _field_block, "wave templates", &survival_mode_wave_templates_block ),
		FIELD( _field_block, "state responses", &game_engine_status_response_block_block ),
		FIELD( _field_block, "team colors", &multiplayer_color_block$3_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(survival_mode_wave_templates_struct)
{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_tag_reference, "wave template" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

