#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		entity_group,
		ENTITY_TAG,
		&object_group,
		OBJECT_TAG,
		entity_block );

	TAG_BLOCK_FROM_STRUCT(
		entity_block,
		"entity_block",
		1,
		entity_struct_definition);

	#define ENTITY_STRUCT_DEFINITION_ID { 0xC09EE68E, 0xC51440C4, 0x84421DAA, 0xB13D1D3E }
	TAG_STRUCT(
		entity_struct_definition,
		"entity_struct_definition",
		"EntityDefinitionInternal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ENTITY_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		FIELD_CUSTOM_EX("$$$ ENTITY $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "Entity Placeholder" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};



} // namespace blofeld

