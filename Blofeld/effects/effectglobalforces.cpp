#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(effect_global_force, EFFECT_GLOBAL_FORCE_TAG)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "grog", 3 },
	{ _field_real, "force strength#positive pushes out, negative pulls in" },
	{ _field_real, "sphere falloff begin:wus#doesn\'t work on cylinders, due to shader constant constraints" },
	{ _field_real, "sphere falloff end:wus#doesn\'t work on cylinders, due to shader constant constraints" },
	{ _field_terminator },
};

} // namespace blofeld

