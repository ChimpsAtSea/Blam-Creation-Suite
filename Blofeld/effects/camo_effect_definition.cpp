#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(camo, CAMO_TAG)
{
	{ _field_explanation, "Active Camo Controls" },
	{ _field_word_flags, "Flags" },
	{ _field_pad, "KKHKKHKKL", 2 },
	{ _field_struct, "Active Camo Amount" },
	{ _field_struct, "Shadow Amount" },
	{ _field_terminator },
};

} // namespace blofeld

