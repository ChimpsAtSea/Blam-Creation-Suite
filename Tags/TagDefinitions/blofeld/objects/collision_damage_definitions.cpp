#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(collision_damage, COLLISION_DAMAGE_TAG, collision_damage_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(collision_damage_block, 1, collision_damage_struct_definition_struct_definition );

	V5_TAG_STRUCT(collision_damage_struct_definition)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_long_flags, "Flags", &collisionDamageFlags },

		{ _field_legacy, _field_explanation, "Applying collision damage", "for things that want to cause more or less collision damage" },
		{ _field_legacy, _field_real, "Apply collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage" },
		{ _field_legacy, _field_real, "Friendly apply collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" },
		{ _field_legacy, _field_explanation, "Game collision damage parameters", "0 - means take default value from globals.globals" },
		{ _field_legacy, _field_real, "minimum velocity for game damage#if you are going below this velocity we stop all game damage" },
		{ _field_legacy, _field_struct, "game collision damage", &collision_damage_function_struct_definition },
		{ _field_legacy, _field_real_bounds, "game acceleration#0-Infinity" },
		{ _field_legacy, _field_explanation, "Applying absolute collision damage", "for things that want to cause more or less collision damage" },
		{ _field_legacy, _field_real, "Apply absolute collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage" },
		{ _field_legacy, _field_real, "Friendly apply absolute collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" },
		{ _field_legacy, _field_explanation, "Absolute collision damage parameters", "0 - means take default value from globals.globals" },
		{ _field_legacy, _field_real, "minimum velocity for absolute damage#if you are going below this velocity we stop all absolute damage" },
		{ _field_legacy, _field_struct, "absolute collision damage", &collision_damage_function_struct_definition },
		{ _field_legacy, _field_real_bounds, "absolute acceleration#0-Infinity" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "Alternative damage effect", "Overrides the damage effect from globals.globals" },
		{ _field_legacy, _field_tag_reference, "alternative damage effect", &Tag::Reference<struct s_damage_effect_definition>::s_defaultDefinition },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(collision_damage_function)
	{
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "mapping", &mapping_function_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(collisionDamageFlags)
	{
		"Don\'t scale damage#typically, we scale the damage to make only \"lethal\" collision damage kill people; this flag overrides that behavior",
		"Object may choose not to deal damage#in some cases (notably, the thruster pack) we should ask an object if it wants to opt out of dealing damage for one reason or another"
	};
	STRING_LIST(collisionDamageFlags, collisionDamageFlags_strings, _countof(collisionDamageFlags_strings));

} // namespace blofeld

