#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(light_cone, LIGHT_CONE_TAG)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "gosh", 3 },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_real, "angle fade range:degrees" },
	{ _field_real, "angle fade cutoff:degrees" },
	{ _field_real, "far fade range:wus" },
	{ _field_real, "far fade cutoff:wus" },
	{ _field_terminator },
};

} // namespace blofeld

