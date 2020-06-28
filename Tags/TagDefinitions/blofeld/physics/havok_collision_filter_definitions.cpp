#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(havok_collision_filter, HAVOK_COLLISION_FILTER_TAG, havok_collision_filter_block_block );

	TAG_BLOCK(havok_collision_filter_group_block, k_havok_group_count)
	{
		{ _field_long_flags, "filter", &collision_filter_enum },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(havok_collision_filter_block, 1, havok_collision_filter_struct_definition_struct_definition );

	TAG_STRUCT(havok_collision_filter_struct_definition)
	{
		{ _field_explanation, "specify what each group collides with", "" },
		{ _field_block, "groups", &havok_collision_filter_group_block_block },
		{ _field_pad, "alignment_pad", 4 },
		{ _field_struct, "group filter*!", &havok_group_filter_filter_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_group_filter_filter_struct)
	{
		{ _field_pointer, "hkReferencedObject vtable*~!" },
		{ _field_short_integer, "size*~!" },
		{ _field_short_integer, "count*~!" },

		{ _field_version_platform_include, _platform_type_pc, 1 },
		{ _field_pad, "8byte struct alignment", 4 },

		{ _field_pointer, "hkpCollidableCollidableFilter vtable*~!" },
		{ _field_pointer, "hkpShapeCollectionFilter vtable*~!" },
		{ _field_pointer, "hkpRayShapeCollectionFilter vtable*~!" },
		{ _field_pointer, "hkpRayCollidableFilter vtable*~!" },
		{ _field_pad, "m_prepad[2]", 8 },
		{ _field_long_integer, "m_type!" },
		{ _field_pad, "m_postpad[3]", 12 },
		{ _field_long_integer, "m_nextFreeSystemGroup*~!" },
		{ _field_long_integer, "m_collisionLookupTable00*~!" },
		{ _field_long_integer, "m_collisionLookupTable01*~!" },
		{ _field_long_integer, "m_collisionLookupTable02*~!" },
		{ _field_long_integer, "m_collisionLookupTable03*~!" },
		{ _field_long_integer, "m_collisionLookupTable04*~!" },
		{ _field_long_integer, "m_collisionLookupTable05*~!" },
		{ _field_long_integer, "m_collisionLookupTable06*~!" },
		{ _field_long_integer, "m_collisionLookupTable07*~!" },
		{ _field_long_integer, "m_collisionLookupTable08*~!" },
		{ _field_long_integer, "m_collisionLookupTable09*~!" },
		{ _field_long_integer, "m_collisionLookupTable10*~!" },
		{ _field_long_integer, "m_collisionLookupTable11*~!" },
		{ _field_long_integer, "m_collisionLookupTable12*~!" },
		{ _field_long_integer, "m_collisionLookupTable13*~!" },
		{ _field_long_integer, "m_collisionLookupTable14*~!" },
		{ _field_long_integer, "m_collisionLookupTable15*~!" },
		{ _field_long_integer, "m_collisionLookupTable16*~!" },
		{ _field_long_integer, "m_collisionLookupTable17*~!" },
		{ _field_long_integer, "m_collisionLookupTable18*~!" },
		{ _field_long_integer, "m_collisionLookupTable19*~!" },
		{ _field_long_integer, "m_collisionLookupTable20*~!" },
		{ _field_long_integer, "m_collisionLookupTable21*~!" },
		{ _field_long_integer, "m_collisionLookupTable22*~!" },
		{ _field_long_integer, "m_collisionLookupTable23*~!" },
		{ _field_long_integer, "m_collisionLookupTable24*~!" },
		{ _field_long_integer, "m_collisionLookupTable25*~!" },
		{ _field_long_integer, "m_collisionLookupTable26*~!" },
		{ _field_long_integer, "m_collisionLookupTable27*~!" },
		{ _field_long_integer, "m_collisionLookupTable28*~!" },
		{ _field_long_integer, "m_collisionLookupTable29*~!" },
		{ _field_long_integer, "m_collisionLookupTable30*~!" },
		{ _field_long_integer, "m_collisionLookupTable31*~!" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_pad, "16 byte align pad", 12 },

		{ _field_real_vector_3d, "m_pad256[0]*~!" },
		{ _field_real, "havok w m_pad256[0]*~!!" },
		{ _field_real_vector_3d, "m_pad256[1]*~!" },
		{ _field_real, "havok w m_pad256[1]*~!!" },
		{ _field_real_vector_3d, "m_pad256[2]*~!" },
		{ _field_real, "havok w m_pad256[2]*~!!" },
		{ _field_real_vector_3d, "m_pad256[3]*~!" },
		{ _field_real, "havok w m_pad256[3]*~!!" },

		{ _field_version_platform_include, _platform_type_pc, 1 },
		{ _field_pad, "8byte struct alignment", 4 },

		{ _field_terminator }
	};

	STRINGS(collision_filter_enum)
	{
		"everything",
		"environment default",
		"environment only",
		"small crate",
		"crate",
		"huge crate",
		"item",
		"projectile",
		"machine",
		"early mover machine",
		"creature",
		"biped",
		"dead biped",
		"super collidable ragdoll",
		"ragdoll",
		"vehicle",
		"decal",
		"forge dynamic scenary",
		"small expensive plant",
		"tech art custom",
		"proxy",
		"huge vehicle",
		"ignore environment",
		"character posture",
		"item blocker",
		"user00",
		"zero extent",
		"physical projectile",
		"environment invisible wall",
		"environment play collision",
		"environment bullet collision"
	};
	STRING_LIST(collision_filter_enum, collision_filter_enum_strings, _countof(collision_filter_enum_strings));

} // namespace blofeld

