#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(model_dissolve_definition, MODEL_DISSOLVE_DEFINITION_TAG, model_dissolve_definition_block_block );

	TAG_BLOCK(modelDissolveDataBlock, ModelDissolveDefinition::eTT_count)
	{
		FIELD( _field_tag_reference, "model dissolve data" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(modelDissolvePerRegionTimeOffsetBlock, MAXIMUM_REGIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "region name^" ),
		FIELD( _field_real, "region time offset" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(model_dissolve_definition_block, 1, model_dissolve_definition_struct_definition_struct_definition );

	TAG_STRUCT(model_dissolve_definition_struct_definition)
	{
		FIELD( _field_byte_flags, "flags", &modelDissolveFlags ),
		FIELD( _field_char_enum, "particle spawn position", &modelDissolveParticleSpawnPosition ),
		FIELD( _field_pad, "graaag", 2 ),
		FIELD( _field_real, "particle spawn random radius" ),
		FIELD( _field_tag_reference, "cheap particle emitter" ),
		FIELD( _field_real, "cheap particle spawn distance threshold" ),
		FIELD( _field_custom, "particle velocity factors" ),
		FIELD( _field_real, "velocity up" ),
		FIELD( _field_real, "velocity toward dissolve point" ),
		FIELD( _field_real, "velocity toward dissolve surface" ),
		FIELD( _field_real, "velocity along dissolve surface" ),
		FIELD( _field_real, "velocity random" ),
		FIELD( _field_custom ),
		FIELD( _field_real, "particle forced speed#if non-zero, we normalize the speed to this value" ),
		FIELD( _field_real, "duration" ),
		FIELD( _field_real, "extra duration#particularly for reverse dissolves, to prevent popping" ),
		FIELD( _field_real, "particle spawn time offset#particularly for reverse dissolves, to cause particles to arrive at the leading edge" ),
		FIELD( _field_block, "per-region time offset", &modelDissolvePerRegionTimeOffsetBlock_block ),
		FIELD( _field_custom, "effects" ),
		FIELD( _field_tag_reference, "dissolve point" ),
		FIELD( _field_tag_reference, "opposite dissolve point" ),
		FIELD( _field_tag_reference, "dissolve surface" ),
		FIELD( _field_tag_reference, "bounding sphere center" ),
		FIELD( _field_custom ),
		FIELD( _field_tag_reference, "finish effect" ),
		FIELD( _field_tag_reference, "knight taint crate" ),
		FIELD( _field_custom, "material" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "actual material\?", &material_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(modelDissolveFlags, 7)
	{
		OPTION("draw backfaces on overlay"),
		OPTION("reverse dissolve"),
		OPTION("pin to animation"),
		OPTION("time particles to die when arriving"),
		OPTION("needs transmission over network"),
		OPTION("can be restarted"),
		OPTION("bounding center effect is taint spawn"),
	};

	TAG_ENUM(modelDissolveParticleSpawnPosition, 3)
	{
		OPTION("dissolve surface"),
		OPTION("dissolve point"),
		OPTION("opposite from dissolve point"),
	};

} // namespace blofeld

