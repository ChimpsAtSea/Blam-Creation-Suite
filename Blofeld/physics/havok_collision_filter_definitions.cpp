#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(havok_collision_filter, HAVOK_COLLISION_FILTER_TAG, havok_collision_filter_block_block )

TAG_BLOCK_FROM_STRUCT(havok_collision_filter_block, 1, havok_collision_filter_struct_definition_struct_definition );

TAG_BLOCK(havok_collision_filter_group_block, k_havok_group_count)
{
	FIELD( _field_long_flags, "filter" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_collision_filter_struct_definition)
{
	FIELD( _field_explanation, "specify what each group collides with" ),
	FIELD( _field_block, "groups", &havok_collision_filter_group_block_block ),
	FIELD( _field_pad, "alignment_pad", 4 ),
	FIELD( _field_struct, "group filter*!", &havok_group_filter_filter_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(havok_group_filter_filter_struct)
{
	FIELD( _field_long_integer, "hkReferencedObject vtable*~!" ),
	FIELD( _field_short_integer, "size*~!" ),
	FIELD( _field_short_integer, "count*~!" ),
	FIELD( _field_long_integer, "hkpCollidableCollidableFilter vtable*~!" ),
	FIELD( _field_long_integer, "hkpShapeCollectionFilter vtable*~!" ),
	FIELD( _field_long_integer, "hkpRayShapeCollectionFilter vtable*~!" ),
	FIELD( _field_long_integer, "hkpRayCollidableFilter vtable*~!" ),
	FIELD( _field_pad, "m_prepad[2]", 8 ),
	FIELD( _field_long_integer, "m_type!" ),
	FIELD( _field_pad, "m_postpad[3]", 12 ),
	FIELD( _field_long_integer, "m_nextFreeSystemGroup*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable00*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable01*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable02*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable03*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable04*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable05*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable06*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable07*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable08*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable09*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable10*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable11*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable12*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable13*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable14*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable15*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable16*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable17*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable18*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable19*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable20*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable21*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable22*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable23*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable24*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable25*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable26*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable27*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable28*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable29*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable30*~!" ),
	FIELD( _field_long_integer, "m_collisionLookupTable31*~!" ),
	FIELD( _field_pad, "16 byte align pad", 12 ),
	FIELD( _field_real_vector_3d, "m_pad256[0]*~!" ),
	FIELD( _field_real, "havok w m_pad256[0]*~!!" ),
	FIELD( _field_real_vector_3d, "m_pad256[1]*~!" ),
	FIELD( _field_real, "havok w m_pad256[1]*~!!" ),
	FIELD( _field_real_vector_3d, "m_pad256[2]*~!" ),
	FIELD( _field_real, "havok w m_pad256[2]*~!!" ),
	FIELD( _field_real_vector_3d, "m_pad256[3]*~!" ),
	FIELD( _field_real, "havok w m_pad256[3]*~!!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

