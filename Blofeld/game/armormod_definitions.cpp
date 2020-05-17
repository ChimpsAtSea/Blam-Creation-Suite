#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(stealthFlagsDefs, 8)
	{
		OPTION("is invisible to X-ray"),
		OPTION("pings invisible on radar edge on foot#if enabled player will not ping on the radar gutter (circumference of radar) when on foot"),
		OPTION("pings invisible on radar edge if driving#if enabled player will not ping on the radar gutter (circumference of radar) when driving a vehicle"),
		OPTION("pings invisible on radar edge if in vehicle#if enabled player will not ping on the radar gutter (circumference of radar) when riding in a vehicle, in any seat"),
		OPTION("pings invisible on radar edge only for enemy team#if this is enabled, stealth player will only not ping for the enemy team"),
		OPTION("is invisible to turrets when camo is active"),
		OPTION("use mod ping frequency and duration#enabling this will use the values set below for the radar ping and frequency"),
		OPTION("disable footstep audio"),
	};

	TAG_GROUP_FROM_BLOCK(armormod_globals, ARMORMOD_GLOBALS_TAG, armormod_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(armormod_globals_block, 1, armormod_globals_struct_definition_struct_definition );

	TAG_BLOCK(aural_enhancement_audio_settings_block, 1)
	{
		FIELD( _field_real, "frequency#beeps per second" ),
		FIELD( _field_real, "duty cycle pct" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(armormod_globals_struct_definition)
{
		FIELD( _field_explanation, "explode on death" ),
		FIELD( _field_tag_reference, "projectile#spawned by Explode On Death armormod" ),
		FIELD( _field_explanation, "aural enhancement" ),
		FIELD( _field_tag_reference, "looping sound effect" ),
		FIELD( _field_real, "near threshold:world units#beyond this distance volume is attenuated, far audio settings are applied" ),
		FIELD( _field_real, "attenuation pct#how much to attenuate volume" ),
		FIELD( _field_block, "near audio settings", &aural_enhancement_audio_settings_block_block ),
		FIELD( _field_block, "far audio settings", &aural_enhancement_audio_settings_block_block ),
		FIELD( _field_explanation, "Enhanced HUD (battle awareness)" ),
		FIELD( _field_real, "range:world units" ),
		FIELD( _field_explanation, "Stealth" ),
		FIELD( _field_byte_flags, "flags", &stealthFlagsDefs ),
		FIELD( _field_pad, "agspad", 3 ),
		FIELD( _field_real, "stealth ping frequency:seconds#how often stealthed unit will ping" ),
		FIELD( _field_real, "stealth ping duration:seconds#length of ping" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

