#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		streamingzoneset_group,
		STREAMINGZONESET_TAG,
		nullptr,
		INVALID_TAG,
		streamingzoneset_block );

	TAG_BLOCK_FROM_STRUCT(
		streamingzoneset_block,
		"streamingzoneset_block",
		1,
		streamingzoneset_struct_definition);

	#define STREAMINGZONESETRESOURCEIDBLOCK_ID { 0xB75F1E6A, 0xC7404EA3, 0x9887D440, 0x19A74440 }
	TAG_BLOCK(
		StreamingZoneSetResourceIdBlock_block,
		"StreamingZoneSetResourceIdBlock",
		4096,
		"StreamingZoneSetResourceId",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STREAMINGZONESETRESOURCEIDBLOCK_ID)
	{
		{ _field_tag_reference, "streaming_reference_tag", &bitmap_reference$3 },
		{ _field_terminator }
	};

	#define STREAMINGZONESETRESOURCESUBREGIONDATABLOCK_ID { 0x3659BA90, 0xEB274E39, 0x8321B278, 0x21709F01 }
	TAG_BLOCK(
		StreamingZoneSetResourceSubregionDataBlock_block,
		"StreamingZoneSetResourceSubregionDataBlock",
		65536,
		"StreamingZoneSetResourceSubregionData",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STREAMINGZONESETRESOURCESUBREGIONDATABLOCK_ID)
	{
		{ _field_long_integer, "block offset X" },
		{ _field_long_integer, "block offset Y" },
		{ _field_real, "min Z" },
		{ _field_real, "max Z" },
		{ _field_block, "resource levels", &StreamingZoneSetResourceLevelsBlock_block },
		{ _field_terminator }
	};

	#define STREAMINGZONESETRESOURCELEVELSBLOCK_ID { 0x6AF99B48, 0x35C844BC, 0xBD960219, 0x46328592 }
	TAG_BLOCK(
		StreamingZoneSetResourceLevelsBlock_block,
		"StreamingZoneSetResourceLevelsBlock",
		4096,
		"StreamingZoneSetResourceLevel",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STREAMINGZONESETRESOURCELEVELSBLOCK_ID)
	{
		{ _field_byte_integer, "streaming subregion requested resolution" },
		{ _field_terminator }
	};

	#define STREAMINGZONESET_STRUCT_DEFINITION_ID { 0x19F43470, 0xE59943F7, 0xBC349E62, 0x10A61807 }
	TAG_STRUCT(
		streamingzoneset_struct_definition,
		"streamingzoneset_struct_definition",
		"StreamingZoneSet",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STREAMINGZONESET_STRUCT_DEFINITION_ID)
	{
		{ _field_real_point_2d, "resource subregion AABB min" },
		{ _field_real_vector_2d, "resource subregion block size" },
		{ _field_block, "streaming resource ids", &StreamingZoneSetResourceIdBlock_block },
		{ _field_block, "streaming resource subregions", &StreamingZoneSetResourceSubregionDataBlock_block },
		{ _field_terminator }
	};



} // namespace blofeld

