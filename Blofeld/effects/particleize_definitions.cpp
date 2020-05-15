#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(particleman, PARTICLEMAN_TAG)
{
	{ _field_explanation, "Particleize Settings" },
	{ _field_enum, "Shape" },
	{ _field_word_flags, "Flags" },
	{ _field_real, "Duration:sec" },
	{ _field_real, "Density" },
	{ _field_real, "Size:world units" },
	{ _field_struct, "Curve" },
	{ _field_terminator },
};

} // namespace blofeld

