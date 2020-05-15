#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(modelDissolvePerRegionTimeOffsetBlock, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_string_id, "region name^" },
	{ _field_real, "region time offset" },
	{ _field_terminator },
};

TAG_BLOCK(modelDissolveDataBlock, ModelDissolveDefinition::eTT_count)
{
	{ _field_tag_reference, "model dissolve data" },
	{ _field_terminator },
};

TAG_GROUP(model_dissolve_definition, MODEL_DISSOLVE_DEFINITION_TAG)
{
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "particle spawn position" },
	{ _field_pad, "graaag", 2 },
	{ _field_real, "particle spawn random radius" },
	{ _field_tag_reference, "cheap particle emitter" },
	{ _field_real, "cheap particle spawn distance threshold" },
	{ _field_custom, "particle velocity factors" },
	{ _field_real, "velocity up" },
	{ _field_real, "velocity toward dissolve point" },
	{ _field_real, "velocity toward dissolve surface" },
	{ _field_real, "velocity along dissolve surface" },
	{ _field_real, "velocity random" },
	{ _field_custom },
	{ _field_real, "particle forced speed#if non-zero, we normalize the speed to this value" },
	{ _field_real, "duration" },
	{ _field_real, "extra duration#particularly for reverse dissolves, to prevent popping" },
	{ _field_real, "particle spawn time offset#particularly for reverse dissolves, to cause particles to arrive at the leading edge" },
	{ _field_block, "per-region time offset", &modelDissolvePerRegionTimeOffsetBlock_block },
	{ _field_custom, "effects" },
	{ _field_tag_reference, "dissolve point" },
	{ _field_tag_reference, "opposite dissolve point" },
	{ _field_tag_reference, "dissolve surface" },
	{ _field_tag_reference, "bounding sphere center" },
	{ _field_custom },
	{ _field_tag_reference, "finish effect" },
	{ _field_tag_reference, "knight taint crate" },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

