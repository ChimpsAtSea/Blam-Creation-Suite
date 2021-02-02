#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		havok_collision_filter_group,
		HAVOK_COLLISION_FILTER_TAG,
		nullptr,
		INVALID_TAG,
		havok_collision_filter_block );

	TAG_BLOCK_FROM_STRUCT(
		havok_collision_filter_block,
		"havok_collision_filter_block",
		1,
		havok_collision_filter_struct_definition);

	#define HAVOK_COLLISION_FILTER_GROUP_BLOCK_ID { 0x6049342A, 0xAB34415C, 0xAF0AB27C, 0x68DABDD9 }
	TAG_BLOCK(
		havok_collision_filter_group_block,
		"havok_collision_filter_group_block",
		k_havok_group_count,
		"s_havok_collision_filter_group",
		HAVOK_COLLISION_FILTER_GROUP_BLOCK_ID)
	{
		{ _field_long_flags, "filter", &collision_filter_enum },
		{ _field_terminator }
	};

	#define HAVOK_COLLISION_FILTER_STRUCT_DEFINITION_ID { 0x509AF768, 0xBE0F4CC5, 0xAAA65F16, 0xBEAB01E6 }
	TAG_STRUCT(
		havok_collision_filter_struct_definition,
		"havok_collision_filter_struct_definition",
		"s_havok_collision_filter_definition",
		HAVOK_COLLISION_FILTER_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "specify what each group collides with", "" },
		{ _field_block, "groups", &havok_collision_filter_group_block },
		FIELD_PAD("alignment_pad", nullptr, 4),
		{ _field_struct, "group filter", &havok_group_filter_filter_struct },
		{ _field_terminator }
	};

	#define HAVOK_GROUP_FILTER_FILTER_STRUCT_ID { 0x14C2A328, 0xA8CD64B0, 0xCDFB8BE7, 0xDBAF80A0 }
	TAG_STRUCT(
		havok_group_filter_filter_struct,
		"havok_group_filter_filter_struct",
		"hkpGroupFilter",
		HAVOK_GROUP_FILTER_FILTER_STRUCT_ID)
	{
		{ _field_long_integer, "hkReferencedObject vtable", _field_id_zero_data },
		{ _field_short_integer, "size" },
		{ _field_short_integer, "count" },
		{ _field_long_integer, "hkpCollidableCollidableFilter vtable", _field_id_zero_data },
		{ _field_long_integer, "hkpShapeCollectionFilter vtable", _field_id_zero_data },
		{ _field_long_integer, "hkpRayShapeCollectionFilter vtable", _field_id_zero_data },
		{ _field_long_integer, "hkpRayCollidableFilter vtable", _field_id_zero_data },
		FIELD_PAD("m_prepad", nullptr, 8),
		{ _field_long_integer, "m_type" },
		FIELD_PAD("m_postpad", nullptr, 12),
		{ _field_long_integer, "m_nextFreeSystemGroup" },
		{ _field_long_integer, "m_collisionLookupTable00" },
		{ _field_long_integer, "m_collisionLookupTable01" },
		{ _field_long_integer, "m_collisionLookupTable02" },
		{ _field_long_integer, "m_collisionLookupTable03" },
		{ _field_long_integer, "m_collisionLookupTable04" },
		{ _field_long_integer, "m_collisionLookupTable05" },
		{ _field_long_integer, "m_collisionLookupTable06" },
		{ _field_long_integer, "m_collisionLookupTable07" },
		{ _field_long_integer, "m_collisionLookupTable08" },
		{ _field_long_integer, "m_collisionLookupTable09" },
		{ _field_long_integer, "m_collisionLookupTable10" },
		{ _field_long_integer, "m_collisionLookupTable11" },
		{ _field_long_integer, "m_collisionLookupTable12" },
		{ _field_long_integer, "m_collisionLookupTable13" },
		{ _field_long_integer, "m_collisionLookupTable14" },
		{ _field_long_integer, "m_collisionLookupTable15" },
		{ _field_long_integer, "m_collisionLookupTable16" },
		{ _field_long_integer, "m_collisionLookupTable17" },
		{ _field_long_integer, "m_collisionLookupTable18" },
		{ _field_long_integer, "m_collisionLookupTable19" },
		{ _field_long_integer, "m_collisionLookupTable20" },
		{ _field_long_integer, "m_collisionLookupTable21" },
		{ _field_long_integer, "m_collisionLookupTable22" },
		{ _field_long_integer, "m_collisionLookupTable23" },
		{ _field_long_integer, "m_collisionLookupTable24" },
		{ _field_long_integer, "m_collisionLookupTable25" },
		{ _field_long_integer, "m_collisionLookupTable26" },
		{ _field_long_integer, "m_collisionLookupTable27" },
		{ _field_long_integer, "m_collisionLookupTable28" },
		{ _field_long_integer, "m_collisionLookupTable29" },
		{ _field_long_integer, "m_collisionLookupTable30" },
		{ _field_long_integer, "m_collisionLookupTable31" },
		FIELD_PAD("16 byte align pad", nullptr, 12),
		{ _field_real_vector_3d, "m_pad256" },
		{ _field_real, "havok w m_pad256" },
		{ _field_real_vector_3d, "m_pad256" },
		{ _field_real, "havok w m_pad256" },
		{ _field_real_vector_3d, "m_pad256" },
		{ _field_real, "havok w m_pad256" },
		{ _field_real_vector_3d, "m_pad256" },
		{ _field_real, "havok w m_pad256" },
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

} // namespace macaque

} // namespace blofeld

