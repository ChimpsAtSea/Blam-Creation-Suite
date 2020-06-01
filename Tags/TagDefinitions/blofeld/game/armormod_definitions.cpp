#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(armormod_globals, ARMORMOD_GLOBALS_TAG, armormod_globals_block_block );

	TAG_BLOCK(aural_enhancement_audio_settings_block, 1)
	{
		{ _field_real, "frequency#beeps per second" },
		{ _field_real, "duty cycle pct" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(armormod_globals_block, 1, armormod_globals_struct_definition_struct_definition );

	TAG_STRUCT(armormod_globals_struct_definition)
	{
		{ _field_explanation, "explode on death", "" },
		{ _field_tag_reference, "projectile#spawned by Explode On Death armormod", &projectile_reference },
		{ _field_explanation, "aural enhancement", "" },
		{ _field_tag_reference, "looping sound effect", &sound_looping_reference },
		{ _field_real, "near threshold:world units#beyond this distance volume is attenuated, far audio settings are applied" },
		{ _field_real, "attenuation pct#how much to attenuate volume" },
		{ _field_block, "near audio settings", &aural_enhancement_audio_settings_block_block },
		{ _field_block, "far audio settings", &aural_enhancement_audio_settings_block_block },
		{ _field_explanation, "Enhanced HUD (battle awareness)", "" },
		{ _field_real, "range:world units" },
		{ _field_explanation, "Stealth", "" },
		{ _field_byte_flags, "flags", &stealthFlagsDefs },
		{ _field_pad, "agspad", 3 },
		{ _field_real, "stealth ping frequency:seconds#how often stealthed unit will ping" },
		{ _field_real, "stealth ping duration:seconds#length of ping" },
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

} // namespace blofeld

