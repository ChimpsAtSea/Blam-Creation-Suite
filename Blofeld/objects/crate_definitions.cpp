#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(crate_struct_definition)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ CRATE $$$" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "KOQVK", 2 ),
	FIELD( _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block ),
	FIELD( _field_long_integer, "self destruction timer:seconds" ),
	FIELD( _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize when it takes damage" ),
	FIELD( _field_string_id, "grab animation set#the animation set to use when this crate is grabbed" ),
	FIELD( _field_string_id, "grab pickup string#the string to display when the player can grab this object, from ui/hud/hud_messages" ),
	FIELD( _field_tag_reference, "projectile bounce effect#effect to play when a projectile bounces because of the \"all projectiles bounce off\" flag" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(crate_block, CRATE_TAG, object, OBJECT_TAG)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ CRATE $$$" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "KOQVK", 2 ),
	FIELD( _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block ),
	FIELD( _field_long_integer, "self destruction timer:seconds" ),
	FIELD( _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize when it takes damage" ),
	FIELD( _field_string_id, "grab animation set#the animation set to use when this crate is grabbed" ),
	FIELD( _field_string_id, "grab pickup string#the string to display when the player can grab this object, from ui/hud/hud_messages" ),
	FIELD( _field_tag_reference, "projectile bounce effect#effect to play when a projectile bounces because of the \"all projectiles bounce off\" flag" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

