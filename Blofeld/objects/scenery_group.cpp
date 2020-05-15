#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(scenery, SCENERY_TAG, object, OBJECT_TAG)
{
	{ _field_struct, "object" },
	{ _field_explanation, "Pathfinding" },
	{ _field_enum, "pathfinding policy" },
	{ _field_word_flags, "flags" },
	{ _field_explanation, "Lightmapping" },
	{ _field_enum, "lightmapping policy" },
	{ _field_pad, "WGW", 2 },
	{ _field_tag_reference, "Structure Lighting Tag" },
	{ _field_useless_pad },
	{ _field_terminator },
};

} // namespace blofeld

