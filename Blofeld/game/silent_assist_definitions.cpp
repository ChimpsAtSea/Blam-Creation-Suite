#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(silentAssistLevelBlock, SilentAssistGlobals::k_maxSilentAssistLevel+1)
{
	{ _field_real, "grenade damage" },
	{ _field_real, "grenade radius" },
	{ _field_real, "assist award bias#multiplier for attributed-damage during assist calculation" },
	{ _field_real, "weapon spread" },
	{ _field_real, "headshot aim assist{headshot magnetism}#increases autoaim for headshot weapons" },
	{ _field_real, "melee cone" },
	{ _field_real, "aim assist#unimplemented" },
	{ _field_explanation, "Level Change" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "SXIX", 3 },
	{ _field_long_integer, "kills to decrease level" },
	{ _field_long_integer, "deaths to increase level" },
	{ _field_terminator },
};

TAG_GROUP(silent_assist_globals, SILENT_ASSIST_GLOBALS_TAG)
{
	{ _field_block, "levels", &silentAssistLevelBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

