#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(camo, CAMO_TAG)
{
	FIELD( _field_explanation, "Active Camo Controls" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_pad, "KKHKKHKKL", 2 ),
	FIELD( _field_struct, "Active Camo Amount" ),
	FIELD( _field_struct, "Shadow Amount" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

