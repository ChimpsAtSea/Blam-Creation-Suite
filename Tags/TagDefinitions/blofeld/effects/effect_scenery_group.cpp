#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(effect_scenery, EFFECT_SCENERY_TAG, object, OBJECT_TAG, effect_scenery_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(effect_scenery_block, 1, effect_scenery_struct_definition_struct_definition );

	V5_TAG_STRUCT(effect_scenery_struct_definition)
	{
		{ _field_struct, "object", &object_struct_definition_struct_definition },
		{ _field_terminator }
	};

} // namespace blofeld

