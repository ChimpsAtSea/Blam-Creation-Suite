#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(entity_struct_definition)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ ENTITY $$$" ),
	FIELD( _field_real, "Entity Placeholder" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(entity_block, ENTITY_TAG, object, OBJECT_TAG)
{
	FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ ENTITY $$$" ),
	FIELD( _field_real, "Entity Placeholder" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

