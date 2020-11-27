#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(model_dissolve_definition, MODEL_DISSOLVE_DEFINITION_TAG, model_dissolve_definition_block_block );

	TAG_BLOCK(modelDissolveDataBlock, ModelDissolveDefinition::eTT_count)
	{
		{ _field_tag_reference, "model dissolve data", &Tag::Reference<struct ModelDissolveDefinition>::s_defaultDefinition },
		{ _field_terminator }
	};

	TAG_BLOCK(modelDissolvePerRegionTimeOffsetBlock, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_string_id, "region name^" },
		{ _field_real, "region time offset" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(model_dissolve_definition_block, 1, model_dissolve_definition_struct_definition_struct_definition );

	TAG_STRUCT(model_dissolve_definition_struct_definition)
	{
		{ _field_byte_flags, "flags", &modelDissolveFlags },
		{ _field_char_enum, "particle spawn position", &modelDissolveParticleSpawnPosition },
		{ _field_pad, "graaag", 2 },
		{ _field_real, "particle spawn random radius" },
		{ _field_tag_reference, "cheap particle emitter", &Tag::Reference<struct s_cheap_particle_emitter>::s_defaultDefinition },
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
		{ _field_tag_reference, "dissolve point", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "opposite dissolve point", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "dissolve surface", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "bounding sphere center", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_custom },
		{ _field_tag_reference, "finish effect", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "knight taint crate", &Tag::Reference<struct crate_definition>::s_defaultDefinition },
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_terminator }
	};

	STRINGS(modelDissolveFlags)
	{
		"draw backfaces on overlay",
		"reverse dissolve",
		"pin to animation",
		"time particles to die when arriving",
		"needs transmission over network",
		"can be restarted",
		"bounding center effect is taint spawn"
	};
	STRING_LIST(modelDissolveFlags, modelDissolveFlags_strings, _countof(modelDissolveFlags_strings));

	STRINGS(modelDissolveParticleSpawnPosition)
	{
		"dissolve surface",
		"dissolve point",
		"opposite from dissolve point"
	};
	STRING_LIST(modelDissolveParticleSpawnPosition, modelDissolveParticleSpawnPosition_strings, _countof(modelDissolveParticleSpawnPosition_strings));

} // namespace blofeld

