#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(aural_enhancement_audio_settings, 1)
{
	FIELD( _field_real, "frequency#beeps per second" ),
	FIELD( _field_real, "duty cycle pct" ),
	FIELD( _field_terminator )
};

TAG_GROUP(armormod_globals, ARMORMOD_GLOBALS_TAG)
{
	FIELD( _field_explanation, "explode on death" ),
	FIELD( _field_tag_reference, "projectile#spawned by Explode On Death armormod" ),
	FIELD( _field_explanation, "aural enhancement" ),
	FIELD( _field_tag_reference, "looping sound effect" ),
	FIELD( _field_real, "near threshold:world units#beyond this distance volume is attenuated, far audio settings are applied" ),
	FIELD( _field_real, "attenuation pct#how much to attenuate volume" ),
	FIELD( _field_block, "near audio settings", &aural_enhancement_audio_settings_block ),
	FIELD( _field_block, "far audio settings", &aural_enhancement_audio_settings_block ),
	FIELD( _field_explanation, "Enhanced HUD (battle awareness)" ),
	FIELD( _field_real, "range:world units" ),
	FIELD( _field_explanation, "Stealth" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "agspad", 3 ),
	FIELD( _field_real, "stealth ping frequency:seconds#how often stealthed unit will ping" ),
	FIELD( _field_real, "stealth ping duration:seconds#length of ping" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

