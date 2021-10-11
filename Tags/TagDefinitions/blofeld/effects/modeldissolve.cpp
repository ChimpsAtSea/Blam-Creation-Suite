#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		model_dissolve_definition_group,
		MODEL_DISSOLVE_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		model_dissolve_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		model_dissolve_definition_block,
		"model_dissolve_definition_block",
		1,
		model_dissolve_definition_struct_definition);

	#define MODELDISSOLVEDATABLOCK_ID { 0x95694A9F, 0x93E94F6B, 0x8959AD40, 0x96A8A349 }
	TAG_BLOCK(
		modelDissolveDataBlock_block,
		"modelDissolveDataBlock",
		ModelDissolveDefinition::eTT_count,
		"Tag::Reference<ModelDissolveDefinition>",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MODELDISSOLVEDATABLOCK_ID)
	{
		{ _field_tag_reference, "model dissolve data", &Tag::Reference<struct ModelDissolveDefinition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define MODELDISSOLVEPERREGIONTIMEOFFSETBLOCK_ID { 0xF1ED5F99, 0x06FF4668, 0x8C2EFC8F, 0x2EF5CEE3 }
	TAG_BLOCK(
		modelDissolvePerRegionTimeOffsetBlock_block,
		"modelDissolvePerRegionTimeOffsetBlock",
		MAXIMUM_REGIONS_PER_MODEL,
		"ModelDissolveRegionTimeOffset",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MODELDISSOLVEPERREGIONTIMEOFFSETBLOCK_ID)
	{
		{ _field_string_id, "region name", FIELD_FLAG_INDEX },
		{ _field_real, "region time offset" },
		{ _field_terminator }
	};

	#define MODEL_DISSOLVE_DEFINITION_STRUCT_DEFINITION_ID { 0xB46D6344, 0x9E9A42C1, 0xA96370B0, 0xA5728CF5 }
	TAG_STRUCT(
		model_dissolve_definition_struct_definition,
		"model_dissolve_definition_struct_definition",
		"ModelDissolveDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_DISSOLVE_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_byte_flags, "flags", &modelDissolveFlags },
		{ _field_char_enum, "particle spawn position", &modelDissolveParticleSpawnPosition },
		FIELD_PAD_EX("graaag", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "particle spawn random radius" },
		{ _field_tag_reference, "cheap particle emitter", &Tag::Reference<struct s_cheap_particle_emitter>::s_defaultDefinition },
		{ _field_real, "cheap particle spawn distance threshold" },
		FIELD_CUSTOM_EX("particle velocity factors", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "velocity up" },
		{ _field_real, "velocity toward dissolve point" },
		{ _field_real, "velocity toward dissolve surface" },
		{ _field_real, "velocity along dissolve surface" },
		{ _field_real, "velocity random" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_real, "particle forced speed", "if non-zero, we normalize the speed to this value" },
		{ _field_real, "duration" },
		{ _field_real, "extra duration", "particularly for reverse dissolves, to prevent popping" },
		{ _field_real, "particle spawn time offset", "particularly for reverse dissolves, to cause particles to arrive at the leading edge" },
		{ _field_block, "per-region time offset", &modelDissolvePerRegionTimeOffsetBlock_block },
		FIELD_CUSTOM_EX("effects", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_tag_reference, "dissolve point", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "opposite dissolve point", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "dissolve surface", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "bounding sphere center", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_tag_reference, "finish effect", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "knight taint crate", &Tag::Reference<struct crate_definition>::s_defaultDefinition },
		FIELD_CUSTOM_EX("material", nullptr, FIELD_FLAG_NONE, _field_id_shader_template),
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_begin),
		{ _field_struct, "actual material?", &material_struct },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_end),
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

