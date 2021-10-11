#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_SCENERY_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		{ _field_terminator }
	};



} // namespace blofeld

