#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(streamingzoneset, STREAMINGZONESET_TAG, streamingzoneset_block_block );

	TAG_BLOCK_FROM_STRUCT(streamingzoneset_block, 1, streamingzoneset_struct_definition_struct_definition );

	TAG_BLOCK(StreamingZoneSetResourceIdBlock, 4096)
	{
		FIELD( _field_tag_reference, "streaming_reference_tag" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(StreamingZoneSetResourceSubregionDataBlock, 65536)
	{
		FIELD( _field_long_integer, "block offset X" ),
		FIELD( _field_long_integer, "block offset Y" ),
		FIELD( _field_real, "min Z" ),
		FIELD( _field_real, "max Z" ),
		FIELD( _field_block, "resource levels", &StreamingZoneSetResourceLevelsBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(StreamingZoneSetResourceLevelsBlock, 4096)
	{
		FIELD( _field_byte_integer, "streaming subregion requested resolution" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(streamingzoneset_struct_definition)
{
		FIELD( _field_real_point_2d, "resource subregion AABB min" ),
		FIELD( _field_real_vector_2d, "resource subregion block size" ),
		FIELD( _field_block, "streaming resource ids", &StreamingZoneSetResourceIdBlock_block ),
		FIELD( _field_block, "streaming resource subregions", &StreamingZoneSetResourceSubregionDataBlock_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

