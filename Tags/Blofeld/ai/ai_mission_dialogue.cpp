#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(ai_mission_dialogue, AI_MISSION_DIALOGUE_TAG, ai_mission_dialogue_block_block );

	TAG_BLOCK(mission_dialogue_variants_block, k_max_variants_per_line)
	{
		{ _field_string_id, "variant designation#3-letter designation for the character^" },
		{ _field_tag_reference, "sound", &sound_reference },
		{ _field_string_id, "sound effect" },
		{ _field_terminator }
	};

	TAG_BLOCK(mission_dialogue_lines_block, k_max_lines_per_scenario)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "variants", &mission_dialogue_variants_block_block },
		{ _field_string_id, "default sound effect" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(ai_mission_dialogue_block, 1, ai_mission_dialogue_struct_definition_struct_definition );

	TAG_BLOCK(ai_scene_trigger_block, 1)
	{
		{ _field_enum, "combination rule", &combination_rules_enum },
		{ _field_pad, "NJBJMKU", 2 },
		{ _field_block, "triggers", &trigger_references_block },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_scene_role_variants_block, k_max_variants_per_line)
	{
		{ _field_string_id, "variant designation^" },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_scene_role_block, k_max_roles_per_scene)
	{
		{ _field_string_id, "name^" },
		{ _field_enum, "group", &role_group_enum },
		{ _field_pad, "XZUW", 2 },
		{ _field_useless_pad },
		{ _field_block, "role variants", &ai_scene_role_variants_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_scene_block, k_max_scenes_per_scenario)
	{
		{ _field_string_id, "name^" },
		{ _field_long_flags, "flags", &scene_flags },
		{ _field_block, "trigger conditions", &ai_scene_trigger_block_block },
		{ _field_useless_pad },
		{ _field_block, "roles", &ai_scene_role_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_scenario_mission_dialogue_block, 1)
	{
		{ _field_tag_reference, "mission dialogue", &ai_mission_dialogue_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(ai_mission_dialogue_struct_definition)
	{
		{ _field_block, "lines", &mission_dialogue_lines_block_block },
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

