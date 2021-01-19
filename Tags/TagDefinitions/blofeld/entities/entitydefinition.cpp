#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(entity, ENTITY_TAG, object, OBJECT_TAG, entity_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(entity_block, 1, entity_struct_definition_struct_definition );

	V5_TAG_STRUCT(entity_struct_definition)
	{
		{ _field_struct, "object", &object_struct_definition_struct_definition },
		{ _field_custom, "$$$ ENTITY $$$" },
		{ _field_real, "Entity Placeholder" },
		{ _field_custom },
		{ _field_terminator }
	};

} // namespace blofeld

