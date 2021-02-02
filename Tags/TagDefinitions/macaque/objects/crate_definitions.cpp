#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		crate_group,
		CRATE_TAG,
		&object_group,
		OBJECT_TAG,
		crate_block );

	TAG_BLOCK_FROM_STRUCT(
		crate_block,
		"crate_block",
		1,
		crate_struct_definition);

	#define CRATE_STRUCT_DEFINITION_ID { 0x793C3A87, 0x506C4035, 0xBF3BFC95, 0xF0459BE4 }
	TAG_STRUCT(
		crate_struct_definition,
		"crate_struct_definition",
		"_crate_definition",
		CRATE_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		FIELD_CUSTOM("$$$ CRATE $$$", nullptr, _field_id_function_group_begin),
		{ _field_word_flags, "flags", &crate_flags },
		FIELD_PAD("KOQVK", nullptr, 2),
		{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block },
		{ _field_long_integer, "self destruction timer", "seconds" },
		{ _field_tag_reference, "particleize", &global_particleize_parameters_reference },
		{ _field_string_id, "grab animation set", "the animation set to use when this crate is grabbed" },
		{ _field_string_id, "grab pickup string", "the string to display when the player can grab this object, from ui/hud/hud_messages" },
		{ _field_tag_reference, "projectile bounce effect", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	STRINGS(crate_flags)
	{
		"does not block AOE",
		"attach texture camera hack",
		"can be grabbed",
		"all projectiles bounce off",
		"targetable",
		"crate walls block AOE#for crates that behave like a bubble shield but are not attached to equipment",
		"crate blocks damage flash damage response",
		"crate blocks rumble damage response",
		"crate takes top level aoe damage#crate takes top level aoe damage when parented to another object",
		"crate blocks forced projectile overpenetration#so that the active shield can block the splaser",
		"unimportant#some rotational and velocity attributes are not synchronized from host to client"
	};
	STRING_LIST(crate_flags, crate_flags_strings, _countof(crate_flags_strings));

} // namespace macaque

} // namespace blofeld

