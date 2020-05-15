#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(ai_cue_template, k_max_ai_cue_templates)
{
	{ _field_string_id, "name^" },
	{ _field_long_flags, "template_flags" },
	{ _field_block, "firing points", &firing_point_payload_block },
	{ _field_block, "stimulus", &stimulus_payload_block },
	{ _field_block, "combat cue", &combat_cue_payload_block },
	{ _field_terminator },
};

TAG_BLOCK(firing_point_payload, 1)
{
	{ _field_real, "radius" },
	{ _field_terminator },
};

TAG_BLOCK(stimulus_payload, 1)
{
	{ _field_string_id, "stimulus type" },
	{ _field_terminator },
};

TAG_BLOCK(combat_cue_payload, 1)
{
	{ _field_real_point_3d, "position!" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_word_flags, "flags!" },
	{ _field_word_flags, "posture flags!" },
	{ _field_short_block_index, "area^!" },
	{ _field_short_integer, "cluster index!" },
	{ _field_short_integer, "cluster bsp*" },
	{ _field_char_integer, "bits and pad!" },
	{ _field_pad, "PAD1", 1 },
	{ _field_real_euler_angles_2d, "normal!" },
	{ _field_angle, "facing!" },
	{ _field_long_integer, "lastAbsoluteRejectionGameTime!" },
	{ _field_enum, "preference" },
	{ _field_pad, "post-preference", 2 },
	{ _field_terminator },
};

TAG_BLOCK(ai_cue, k_max_ai_cues_per_level)
{
	{ _field_string_id, "name^" },
	{ _field_byte_flags, "flags" },
	{ _field_char_integer, "quick cue*!" },
	{ _field_short_integer, "editor folder!" },
	{ _field_real_point_3d, "position!" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" },
	{ _field_real, "roll" },
	{ _field_custom, "distribution" },
	{ _field_struct, "distribution" },
	{ _field_custom },
	{ _field_custom, "payload" },
	{ _field_struct, "payload" },
	{ _field_custom },
	{ _field_pad, "no-cue-definition-index", 4 },
	{ _field_terminator },
};

TAG_BLOCK(ai_full_cue, k_max_ai_cues_per_level)
{
	{ _field_string_id, "name^" },
	{ _field_byte_flags, "flags" },
	{ _field_char_integer, "quick cue*!" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "facing!" },
	{ _field_real, "roll!" },
	{ _field_explanation, "Distribution" },
	{ _field_custom, "distribution" },
	{ _field_struct, "distribution" },
	{ _field_custom },
	{ _field_explanation, "Payload" },
	{ _field_custom, "payload" },
	{ _field_struct, "payload" },
	{ _field_custom },
	{ _field_long_block_index, "cue definition index!" },
	{ _field_terminator },
};

TAG_BLOCK(ai_quick_cue, k_max_ai_cues_per_level)
{
	{ _field_string_id, "name^" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "post-flags", 1 },
	{ _field_short_block_index, "editor folder!" },
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "facing!" },
	{ _field_real, "roll!" },
	{ _field_block, "tasks*!", &task_distribution_block },
	{ _field_short_block_index, "character" },
	{ _field_short_block_index, "weapon" },
	{ _field_string_id, "template" },
	{ _field_long_block_index, "cue definition index!" },
	{ _field_terminator },
};

TAG_BLOCK(task_distribution, k_max_task_distributions_per_cue)
{
	{ _field_short_block_index, "objective" },
	{ _field_custom_short_block_index, "task" },
	{ _field_terminator },
};

} // namespace blofeld

