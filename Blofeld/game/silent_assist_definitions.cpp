#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(silent_assist_globals, SILENT_ASSIST_GLOBALS_TAG, silent_assist_globals_block_block );

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
		FIELD( _field_byte_flags, "flags", &g_silentAssistFlags ),
		FIELD( _field_pad, "SXIX", 3 ),
		FIELD( _field_long_integer, "kills to decrease level" ),
		FIELD( _field_long_integer, "deaths to increase level" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(silent_assist_globals_block, 1, silent_assist_globals_struct_definition_struct_definition );

	TAG_STRUCT(silent_assist_globals_struct_definition)
	{
		FIELD( _field_block, "levels", &silentAssistLevelBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(g_silentAssistFlags, 2)
	{
		OPTION("kills must be consecutive"),
		OPTION("deaths must be consecutive"),
	};

} // namespace blofeld

