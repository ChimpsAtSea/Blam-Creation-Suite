#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(StreamingZoneSetResourceIdBlock, 4096)
{
	{ _field_tag_reference, "streaming_reference_tag" },
	{ _field_terminator },
};

TAG_BLOCK(StreamingZoneSetResourceSubregionDataBlock, 65536)
{
	{ _field_long_integer, "block offset X" },
	{ _field_long_integer, "block offset Y" },
	{ _field_real, "min Z" },
	{ _field_real, "max Z" },
	{ _field_block, "resource levels", &StreamingZoneSetResourceLevelsBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(StreamingZoneSetResourceLevelsBlock, 4096)
{
	{ _field_byte_integer, "streaming subregion requested resolution" },
	{ _field_terminator },
};

TAG_GROUP(streamingzoneset, STREAMINGZONESET_TAG)
{
	{ _field_real_point_2d, "resource subregion AABB min" },
	{ _field_real_vector_2d, "resource subregion block size" },
	{ _field_block, "streaming resource ids", &StreamingZoneSetResourceIdBlock_block },
	{ _field_block, "streaming resource subregions", &StreamingZoneSetResourceSubregionDataBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

