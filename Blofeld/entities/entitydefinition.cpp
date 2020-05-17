#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(entity, ENTITY_TAG, object, OBJECT_TAG, entity_block_block );

	TAG_BLOCK_FROM_STRUCT(entity_block, 1, entity_struct_definition_struct_definition );

	TAG_STRUCT(entity_struct_definition)
	{
		FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
		FIELD( _field_custom, "$$$ ENTITY $$$" ),
		FIELD( _field_real, "Entity Placeholder" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

