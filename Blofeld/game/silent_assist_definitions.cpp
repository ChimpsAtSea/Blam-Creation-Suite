#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(silentAssistLevelBlock, SilentAssistGlobals::k_maxSilentAssistLevel+1)
{
	FIELD( _field_real, "grenade damage" ),
	FIELD( _field_real, "grenade radius" ),
	FIELD( _field_real, "assist award bias#multiplier for attributed-damage during assist calculation" ),
	FIELD( _field_real, "weapon spread" ),
	FIELD( _field_real, "headshot aim assist{headshot magnetism}#increases autoaim for headshot weapons" ),
	FIELD( _field_real, "melee cone" ),
	FIELD( _field_real, "aim assist#unimplemented" ),
	FIELD( _field_explanation, "Level Change" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "SXIX", 3 ),
	FIELD( _field_long_integer, "kills to decrease level" ),
	FIELD( _field_long_integer, "deaths to increase level" ),
	FIELD( _field_terminator )
};

TAG_GROUP(silent_assist_globals, SILENT_ASSIST_GLOBALS_TAG)
{
	FIELD( _field_block, "levels", &silentAssistLevelBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

