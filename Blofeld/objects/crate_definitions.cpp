#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(crate, CRATE_TAG, object, OBJECT_TAG)
{
	{ _field_struct, "object" },
	{ _field_custom, "$$$ CRATE $$$" },
	{ _field_word_flags, "flags" },
	{ _field_pad, "KOQVK", 2 },
	{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block },
	{ _field_long_integer, "self destruction timer:seconds" },
	{ _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize when it takes damage" },
	{ _field_string_id, "grab animation set#the animation set to use when this crate is grabbed" },
	{ _field_string_id, "grab pickup string#the string to display when the player can grab this object, from ui/hud/hud_messages" },
	{ _field_tag_reference, "projectile bounce effect#effect to play when a projectile bounces because of the \"all projectiles bounce off\" flag" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

