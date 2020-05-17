#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(crate_flags, 11)
	{
		OPTION("does not block AOE"),
		OPTION("attach texture camera hack"),
		OPTION("can be grabbed"),
		OPTION("all projectiles bounce off"),
		OPTION("targetable"),
		OPTION("crate walls block AOE#for crates that behave like a bubble shield but are not attached to equipment"),
		OPTION("crate blocks damage flash damage response"),
		OPTION("crate blocks rumble damage response"),
		OPTION("crate takes top level aoe damage#crate takes top level aoe damage when parented to another object"),
		OPTION("crate blocks forced projectile overpenetration#so that the active shield can block the splaser"),
		OPTION("unimportant#some rotational and velocity attributes are not synchronized from host to client"),
	};

	TAG_GROUP_INHERIT_FROM_BLOCK(crate, CRATE_TAG, object, OBJECT_TAG, crate_block_block );

	TAG_BLOCK_FROM_STRUCT(crate_block, 1, crate_struct_definition_struct_definition );

TAG_STRUCT(crate_struct_definition)
{
		FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
		FIELD( _field_custom, "$$$ CRATE $$$" ),
		FIELD( _field_word_flags, "flags", &crate_flags ),
		FIELD( _field_pad, "KOQVK", 2 ),
		FIELD( _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block_block ),
		FIELD( _field_long_integer, "self destruction timer:seconds" ),
		FIELD( _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize when it takes damage" ),
		FIELD( _field_string_id, "grab animation set#the animation set to use when this crate is grabbed" ),
		FIELD( _field_string_id, "grab pickup string#the string to display when the player can grab this object, from ui/hud/hud_messages" ),
		FIELD( _field_tag_reference, "projectile bounce effect#effect to play when a projectile bounces because of the \"all projectiles bounce off\" flag" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
};

} // namespace blofeld

