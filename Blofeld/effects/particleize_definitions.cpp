#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(particleman, PARTICLEMAN_TAG)
{
	FIELD( _field_explanation, "Particleize Settings" ),
	FIELD( _field_enum, "Shape" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_real, "Duration:sec" ),
	FIELD( _field_real, "Density" ),
	FIELD( _field_real, "Size:world units" ),
	FIELD( _field_struct, "Curve" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

