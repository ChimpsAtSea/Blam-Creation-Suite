#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(effect_global_force_struct_definition)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "grog", 3 ),
	FIELD( _field_real, "force strength#positive pushes out, negative pulls in" ),
	FIELD( _field_real, "sphere falloff begin:wus#doesn\'t work on cylinders, due to shader constant constraints" ),
	FIELD( _field_real, "sphere falloff end:wus#doesn\'t work on cylinders, due to shader constant constraints" ),
	FIELD( _field_terminator )
};

TAG_GROUP(effect_global_force_block, EFFECT_GLOBAL_FORCE_TAG)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "grog", 3 ),
	FIELD( _field_real, "force strength#positive pushes out, negative pulls in" ),
	FIELD( _field_real, "sphere falloff begin:wus#doesn\'t work on cylinders, due to shader constant constraints" ),
	FIELD( _field_real, "sphere falloff end:wus#doesn\'t work on cylinders, due to shader constant constraints" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

