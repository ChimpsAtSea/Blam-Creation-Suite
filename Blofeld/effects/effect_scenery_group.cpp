#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(effect_scenery, EFFECT_SCENERY_TAG, object, OBJECT_TAG, effect_scenery_block_block );

	TAG_BLOCK_FROM_STRUCT(effect_scenery_block, 1, effect_scenery_struct_definition_struct_definition );

	TAG_STRUCT(effect_scenery_struct_definition)
	{
		FIELD( _field_struct, "object", &object_struct_definition_struct_definition ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

