#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(silent_assist_globals, SILENT_ASSIST_GLOBALS_TAG, silent_assist_globals_block_block );

	TAG_BLOCK(silentAssistLevelBlock, SilentAssistGlobals::k_maxSilentAssistLevel+1)
	{
		{ _field_real, "grenade damage" },
		{ _field_real, "grenade radius" },
		{ _field_real, "assist award bias#multiplier for attributed-damage during assist calculation" },
		{ _field_real, "weapon spread" },
		{ _field_real, "headshot aim assist{headshot magnetism}#increases autoaim for headshot weapons" },
		{ _field_real, "melee cone" },
		{ _field_real, "aim assist#unimplemented" },
		{ _field_explanation, "Level Change", "These fields show how many kills/deaths it takes to move between levels" },
		{ _field_byte_flags, "flags", &g_silentAssistFlags },
		{ _field_pad, "SXIX", 3 },
		{ _field_long_integer, "kills to decrease level" },
		{ _field_long_integer, "deaths to increase level" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(silent_assist_globals_block, 1, silent_assist_globals_struct_definition_struct_definition );

	TAG_STRUCT(silent_assist_globals_struct_definition)
	{
		{ _field_block, "levels", &silentAssistLevelBlock_block },
		{ _field_terminator }
	};

	STRINGS(g_silentAssistFlags)
	{
		"kills must be consecutive",
		"deaths must be consecutive"
	};
	STRING_LIST(g_silentAssistFlags, g_silentAssistFlags_strings, _countof(g_silentAssistFlags_strings));

} // namespace blofeld

