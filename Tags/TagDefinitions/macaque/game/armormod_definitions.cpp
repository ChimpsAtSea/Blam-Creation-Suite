#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		armormod_globals_group,
		ARMORMOD_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		armormod_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		armormod_globals_block,
		"armormod_globals_block",
		1,
		armormod_globals_struct_definition);

	#define AURAL_ENHANCEMENT_AUDIO_SETTINGS_BLOCK_ID { 0x6D429CC4, 0x18EA4C2D, 0x8C429766, 0xC595AEF5 }
	TAG_BLOCK(
		aural_enhancement_audio_settings_block,
		"aural_enhancement_audio_settings_block",
		1,
		"AuralEnhancementAudioSettings",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AURAL_ENHANCEMENT_AUDIO_SETTINGS_BLOCK_ID)
	{
		{ _field_real, "frequency", "beeps per second" },
		{ _field_real, "duty cycle pct" },
		{ _field_terminator }
	};

	#define ARMORMOD_GLOBALS_STRUCT_DEFINITION_ID { 0xBA3D69E0, 0x5E314FDE, 0x992D73B7, 0x0B75EB20 }
	TAG_STRUCT(
		armormod_globals_struct_definition,
		"armormod_globals_struct_definition",
		"ArmorModGlobals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ARMORMOD_GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("explode on death", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "projectile", "spawned by Explode On Death armormod", &projectile_reference },
		FIELD_EXPLANATION("aural enhancement", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "looping sound effect", &sound_looping_reference },
		{ _field_real, "near threshold", "beyond this distance volume is attenuated, far audio settings are applied", "world units" },
		{ _field_real, "attenuation pct", "how much to attenuate volume" },
		{ _field_block, "near audio settings", &aural_enhancement_audio_settings_block },
		{ _field_block, "far audio settings", &aural_enhancement_audio_settings_block },
		FIELD_EXPLANATION("Enhanced HUD (battle awareness)", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "range", nullptr, "world units" },
		FIELD_EXPLANATION("Stealth", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_byte_flags, "flags", &stealthFlagsDefs },
		FIELD_PAD("agspad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "stealth ping frequency", "how often stealthed unit will ping", "seconds" },
		{ _field_real, "stealth ping duration", "length of ping", "seconds" },
		{ _field_terminator }
	};

	STRINGS(stealthFlagsDefs)
	{
		"is invisible to X-ray",
		"pings invisible on radar edge on foot#if enabled player will not ping on the radar gutter (circumference of radar) when on foot",
		"pings invisible on radar edge if driving#if enabled player will not ping on the radar gutter (circumference of radar) when driving a vehicle",
		"pings invisible on radar edge if in vehicle#if enabled player will not ping on the radar gutter (circumference of radar) when riding in a vehicle, in any seat",
		"pings invisible on radar edge only for enemy team#if this is enabled, stealth player will only not ping for the enemy team",
		"is invisible to turrets when camo is active",
		"use mod ping frequency and duration#enabling this will use the values set below for the radar ping and frequency",
		"disable footstep audio"
	};
	STRING_LIST(stealthFlagsDefs, stealthFlagsDefs_strings, _countof(stealthFlagsDefs_strings));

} // namespace macaque

} // namespace blofeld

