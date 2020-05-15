#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(aural_enhancement_audio_settings, 1)
{
	{ _field_real, "frequency#beeps per second" },
	{ _field_real, "duty cycle pct" },
	{ _field_terminator },
};

TAG_GROUP(armormod_globals, ARMORMOD_GLOBALS_TAG)
{
	{ _field_explanation, "explode on death" },
	{ _field_tag_reference, "projectile#spawned by Explode On Death armormod" },
	{ _field_explanation, "aural enhancement" },
	{ _field_tag_reference, "looping sound effect" },
	{ _field_real, "near threshold:world units#beyond this distance volume is attenuated, far audio settings are applied" },
	{ _field_real, "attenuation pct#how much to attenuate volume" },
	{ _field_block, "near audio settings", &aural_enhancement_audio_settings_block },
	{ _field_block, "far audio settings", &aural_enhancement_audio_settings_block },
	{ _field_explanation, "Enhanced HUD (battle awareness)" },
	{ _field_real, "range:world units" },
	{ _field_explanation, "Stealth" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "agspad", 3 },
	{ _field_real, "stealth ping frequency:seconds#how often stealthed unit will ping" },
	{ _field_real, "stealth ping duration:seconds#length of ping" },
	{ _field_terminator },
};

} // namespace blofeld

