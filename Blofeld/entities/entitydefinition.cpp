#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(entity, ENTITY_TAG, object, OBJECT_TAG)
{
	FIELD( _field_struct, "object" ),
	FIELD( _field_custom, "$$$ ENTITY $$$" ),
	FIELD( _field_real, "Entity Placeholder" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

