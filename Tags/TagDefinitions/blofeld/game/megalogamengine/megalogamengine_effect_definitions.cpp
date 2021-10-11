#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		multiplayerEffects_group,
		MULTIPLAYEREFFECTS_TAG,
		nullptr,
		INVALID_TAG,
		multiplayerEffects_block );

	TAG_BLOCK_FROM_STRUCT(
		multiplayerEffects_block,
		"multiplayerEffects_block",
		1,
		multiplayerEffects_struct_definition);

	#define MULTIPLAYEREFFECTSBLOCK_ID { 0xF6E8B719, 0xC1EE4D13, 0xAA4A949C, 0x284C8CDC }
	TAG_BLOCK(
		multiplayerEffectsBlock_block,
		"multiplayerEffectsBlock",
		k_multiplayer_effect_maximum_count,
		"s_multiplayer_effect",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYEREFFECTSBLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "effect", &effect_reference$3 },
		{ _field_terminator }
	};

	#define MULTIPLAYEREFFECTS_STRUCT_DEFINITION_ID { 0x32C93FFF, 0x6C6B4352, 0xB86FFA53, 0x76DFFF61 }
	TAG_STRUCT(
		multiplayerEffects_struct_definition,
		"multiplayerEffects_struct_definition",
		"s_megalogamengine_effect_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYEREFFECTS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "effects", &multiplayerEffectsBlock_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_multiplayer_effect_group_reference, MULTIPLAYEREFFECTS_TAG);



} // namespace blofeld

