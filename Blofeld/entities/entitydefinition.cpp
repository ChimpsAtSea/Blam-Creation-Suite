#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(entity, ENTITY_TAG, object, OBJECT_TAG)
{
	{ _field_struct, "object" },
	{ _field_custom, "$$$ ENTITY $$$" },
	{ _field_real, "Entity Placeholder" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

