#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(survival_mode_wave_templates, k_global_wave_templates_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_tag_reference, "wave template" ),
	FIELD( _field_terminator )
};

TAG_GROUP(survival_mode_globals, SURVIVAL_MODE_GLOBALS_TAG)
{
	FIELD( _field_real, "respawn time#NO: Use game_engine_settings for this" ),
	FIELD( _field_tag_reference, "survival mode text" ),
	FIELD( _field_tag_reference, "countdown sound" ),
	FIELD( _field_tag_reference, "respawn sound" ),
	FIELD( _field_tag_reference, "co-op spawning globals" ),
	FIELD( _field_block, "wave templates", &survival_mode_wave_templates_block ),
	FIELD( _field_block, "state responses", &game_engine_status_response_block ),
	FIELD( _field_block, "team colors", &multiplayer_color$2_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

