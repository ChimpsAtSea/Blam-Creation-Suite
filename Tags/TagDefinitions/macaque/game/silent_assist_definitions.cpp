#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		silent_assist_globals_group,
		SILENT_ASSIST_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		silent_assist_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		silent_assist_globals_block,
		"silent_assist_globals_block",
		1,
		silent_assist_globals_struct_definition);

	#define SILENTASSISTLEVELBLOCK_ID { 0x619E7799, 0x7B464079, 0x8BAFB0F0, 0xBC3CA08D }
	TAG_BLOCK(
		silentAssistLevelBlock_block,
		"silentAssistLevelBlock",
		SilentAssistGlobals::k_maxSilentAssistLevel+1,
		"SilentAssistLevel",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SILENTASSISTLEVELBLOCK_ID)
	{
		{ _field_real, "grenade damage" },
		{ _field_real, "grenade radius" },
		{ _field_real, "assist award bias", "multiplier for attributed-damage during assist calculation" },
		{ _field_real, "weapon spread" },
		{ _field_real, "headshot aim assist", "increases autoaim for headshot weapons" },
		{ _field_real, "melee cone" },
		{ _field_real, "aim assist", "unimplemented" },
		{ _field_explanation, "Level Change", "These fields show how many kills/deaths it takes to move between levels" },
		{ _field_byte_flags, "flags", &g_silentAssistFlags },
		FIELD_PAD("SXIX", nullptr, 3),
		{ _field_long_integer, "kills to decrease level" },
		{ _field_long_integer, "deaths to increase level" },
		{ _field_terminator }
	};

	#define SILENT_ASSIST_GLOBALS_STRUCT_DEFINITION_ID { 0xEE88DBE0, 0xD8AA47B3, 0x84A4C71C, 0x8844778E }
	TAG_STRUCT(
		silent_assist_globals_struct_definition,
		"silent_assist_globals_struct_definition",
		"SilentAssistGlobals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SILENT_ASSIST_GLOBALS_STRUCT_DEFINITION_ID)
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

} // namespace macaque

} // namespace blofeld

