#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		effect_scenery_group,
		EFFECT_SCENERY_TAG,
		&object_group,
		OBJECT_TAG,
		effect_scenery_block );

	TAG_BLOCK_FROM_STRUCT(
		effect_scenery_block,
		"effect_scenery_block",
		1,
		effect_scenery_struct_definition);

	#define EFFECT_SCENERY_STRUCT_DEFINITION_ID { 0x575B0686, 0x25B7457D, 0xBBB14145, 0x173BB6C9 }
	TAG_STRUCT(
		effect_scenery_struct_definition,
		"effect_scenery_struct_definition",
		"effect_scenery_struct_definition",
		EFFECT_SCENERY_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

