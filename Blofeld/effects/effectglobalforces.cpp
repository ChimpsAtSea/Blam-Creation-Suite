#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(effect_global_force, EFFECT_GLOBAL_FORCE_TAG, effect_global_force_block_block )

TAG_BLOCK_FROM_STRUCT(effect_global_force_block, 1, effect_global_force_struct_definition_struct_definition );

TAG_STRUCT(effect_global_force_struct_definition)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "grog", 3 ),
	FIELD( _field_real, "force strength#positive pushes out, negative pulls in" ),
	FIELD( _field_real, "sphere falloff begin:wus#doesn\'t work on cylinders, due to shader constant constraints" ),
	FIELD( _field_real, "sphere falloff end:wus#doesn\'t work on cylinders, due to shader constant constraints" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

