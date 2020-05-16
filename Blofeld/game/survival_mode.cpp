#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(survival_mode_globals_struct_definition)
{
	FIELD( _field_real, "respawn time#NO: Use game_engine_settings for this" ),
	FIELD( _field_tag_reference, "survival mode text" ),
	FIELD( _field_tag_reference, "countdown sound" ),
	FIELD( _field_tag_reference, "respawn sound" ),
	FIELD( _field_tag_reference, "co-op spawning globals" ),
	FIELD( _field_block, "wave templates", &survival_mode_wave_templates ),
	FIELD( _field_block, "state responses", &game_engine_status_response_block ),
	FIELD( _field_block, "team colors", &multiplayer_color_block$3 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(survival_mode_wave_templates_struct)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_tag_reference, "wave template" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(survival_mode_wave_templates, k_global_wave_templates_count, survival_mode_wave_templates_struct_struct_definition );

TAG_GROUP(survival_mode_globals_block, SURVIVAL_MODE_GLOBALS_TAG)
{
	FIELD( _field_real, "respawn time#NO: Use game_engine_settings for this" ),
	FIELD( _field_tag_reference, "survival mode text" ),
	FIELD( _field_tag_reference, "countdown sound" ),
	FIELD( _field_tag_reference, "respawn sound" ),
	FIELD( _field_tag_reference, "co-op spawning globals" ),
	FIELD( _field_block, "wave templates", &survival_mode_wave_templates ),
	FIELD( _field_block, "state responses", &game_engine_status_response_block ),
	FIELD( _field_block, "team colors", &multiplayer_color_block$3 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

