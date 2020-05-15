#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(mission_dialogue_lines, k_max_lines_per_scenario)
{
	{ _field_string_id, "name^" },
	{ _field_block, "variants", &mission_dialogue_variants_block },
	{ _field_string_id, "default sound effect" },
	{ _field_terminator },
};

TAG_BLOCK(mission_dialogue_variants, k_max_variants_per_line)
{
	{ _field_string_id, "variant designation#3-letter designation for the character^" },
	{ _field_tag_reference, "sound" },
	{ _field_string_id, "sound effect" },
	{ _field_terminator },
};

TAG_BLOCK(ai_scene, k_max_scenes_per_scenario)
{
	{ _field_string_id, "name^" },
	{ _field_long_flags, "flags" },
	{ _field_block, "trigger conditions", &ai_scene_trigger_block },
	{ _field_useless_pad },
	{ _field_block, "roles", &ai_scene_role_block },
	{ _field_terminator },
};

TAG_BLOCK(ai_scene_trigger, 1)
{
	{ _field_enum, "combination rule" },
	{ _field_pad, "NJBJMKU", 2 },
	{ _field_block, "triggers", &trigger_references_block },
	{ _field_terminator },
};

TAG_BLOCK(ai_scene_role, k_max_roles_per_scene)
{
	{ _field_string_id, "name^" },
	{ _field_enum, "group" },
	{ _field_pad, "XZUW", 2 },
	{ _field_useless_pad },
	{ _field_block, "role variants", &ai_scene_role_variants_block },
	{ _field_terminator },
};

TAG_BLOCK(ai_scene_role_variants, k_max_variants_per_line)
{
	{ _field_string_id, "variant designation^" },
	{ _field_terminator },
};

TAG_BLOCK(ai_scenario_mission_dialogue, 1)
{
	{ _field_tag_reference, "mission dialogue" },
	{ _field_terminator },
};

TAG_GROUP(ai_mission_dialogue, AI_MISSION_DIALOGUE_TAG)
{
	{ _field_block, "lines", &mission_dialogue_lines_block },
	{ _field_terminator },
};

} // namespace blofeld

