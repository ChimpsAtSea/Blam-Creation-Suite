#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		ai_mission_dialogue_group,
		AI_MISSION_DIALOGUE_TAG,
		nullptr,
		INVALID_TAG,
		ai_mission_dialogue_block );

	TAG_BLOCK_FROM_STRUCT(
		ai_mission_dialogue_block,
		"ai_mission_dialogue_block",
		1,
		ai_mission_dialogue_struct_definition);

	#define MISSION_DIALOGUE_LINES_BLOCK_ID { 0xB95BD27F, 0x5B6545A1, 0xB83D0094, 0x922D3337 }
	TAG_BLOCK(
		mission_dialogue_lines_block,
		"mission_dialogue_lines_block",
		k_max_lines_per_scenario,
		"mission_dialogue_line",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MISSION_DIALOGUE_LINES_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "variants", &mission_dialogue_variants_block },
		{ _field_string_id, "default sound effect" },
		{ _field_terminator }
	};

	#define MISSION_DIALOGUE_VARIANTS_BLOCK_ID { 0x5DE3B90C, 0xABBB4DE3, 0x870EFC07, 0x7BB2AA80 }
	TAG_BLOCK(
		mission_dialogue_variants_block,
		"mission_dialogue_variants_block",
		k_max_variants_per_line,
		"mission_dialogue_variant",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MISSION_DIALOGUE_VARIANTS_BLOCK_ID)
	{
		{ _field_string_id, "variant designation", "3-letter designation for the character", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "sound", &sound_reference },
		{ _field_string_id, "sound effect" },
		{ _field_terminator }
	};

	#define AI_SCENE_BLOCK_ID { 0x9265CAD2, 0x80B9454D, 0xB8A86BFD, 0xB708BD17 }
	TAG_BLOCK(
		ai_scene_block,
		"ai_scene_block",
		k_max_scenes_per_scenario,
		"ai_scene",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_SCENE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &scene_flags },
		{ _field_block, "trigger conditions", &ai_scene_trigger_block },
		{ _field_useless_pad, "" },
		{ _field_block, "roles", &ai_scene_role_block },
		{ _field_terminator }
	};

	#define AI_SCENE_TRIGGER_BLOCK_ID { 0x1D8A8E7B, 0xE8B24BB6, 0x9E90F7D4, 0x225EF2B1 }
	TAG_BLOCK(
		ai_scene_trigger_block,
		"ai_scene_trigger_block",
		1,
		"ai_scene_trigger",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_SCENE_TRIGGER_BLOCK_ID)
	{
		{ _field_enum, "combination rule", &combination_rules_enum },
		FIELD_PAD_EX("NJBJMKU", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "triggers", &trigger_references_block },
		{ _field_terminator }
	};

	#define AI_SCENE_ROLE_BLOCK_ID { 0x06C92A6B, 0x349D43D3, 0x8915D8F3, 0x4A28DC0C }
	TAG_BLOCK(
		ai_scene_role_block,
		"ai_scene_role_block",
		k_max_roles_per_scene,
		"ai_scene_role",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_SCENE_ROLE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_enum, "group", &role_group_enum },
		FIELD_PAD_EX("XZUW", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_useless_pad, "" },
		{ _field_block, "role variants", &ai_scene_role_variants_block },
		{ _field_terminator }
	};

	#define AI_SCENE_ROLE_VARIANTS_BLOCK_ID { 0x20B5EEB2, 0x6BD64491, 0xA3E87909, 0xC58A4822 }
	TAG_BLOCK(
		ai_scene_role_variants_block,
		"ai_scene_role_variants_block",
		k_max_variants_per_line,
		"ai_scene_role_variant",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_SCENE_ROLE_VARIANTS_BLOCK_ID)
	{
		{ _field_string_id, "variant designation", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define AI_SCENARIO_MISSION_DIALOGUE_BLOCK_ID { 0xCF7DF219, 0x442542E9, 0xB68E0E7E, 0xDE85A19D }
	TAG_BLOCK(
		ai_scenario_mission_dialogue_block,
		"ai_scenario_mission_dialogue_block",
		1,
		"ai_scenario_mission_dialogue",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_SCENARIO_MISSION_DIALOGUE_BLOCK_ID)
	{
		{ _field_tag_reference, "mission dialogue", &ai_mission_dialogue_reference },
		{ _field_terminator }
	};

	#define AI_MISSION_DIALOGUE_STRUCT_DEFINITION_ID { 0x7A2D35B4, 0xCD53450D, 0xAEB0B227, 0x6940C1F4 }
	TAG_STRUCT_V6(
		ai_mission_dialogue_struct_definition,
		"ai_mission_dialogue_struct_definition",
		"ai_mission_dialogue",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_MISSION_DIALOGUE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "lines", &mission_dialogue_lines_block },
		{ _field_terminator }
	};

	STRINGS(role_group_enum)
	{
		"group 1",
		"group 2",
		"group 3"
	};
	STRING_LIST(role_group_enum, role_group_enum_strings, _countof(role_group_enum_strings));

	STRINGS(scene_flags)
	{
		"scene can play multiple times",
		"enable combat dialogue"
	};
	STRING_LIST(scene_flags, scene_flags_strings, _countof(scene_flags_strings));



} // namespace blofeld

