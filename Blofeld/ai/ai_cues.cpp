#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(ai_cue_template_block, k_max_ai_cue_templates)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_flags, "template_flags" ),
	FIELD( _field_block, "firing points", &firing_point_payload_block_block ),
	FIELD( _field_block, "stimulus", &stimulus_payload_block_block ),
	FIELD( _field_block, "combat cue", &combat_cue_payload_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(firing_point_payload_block, 1)
{
	FIELD( _field_real, "radius" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(stimulus_payload_block, 1)
{
	FIELD( _field_string_id, "stimulus type" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(combat_cue_payload_block, 1)
{
	FIELD( _field_real_point_3d, "position!" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_word_flags, "flags!" ),
	FIELD( _field_word_flags, "posture flags!" ),
	FIELD( _field_short_block_index, "area^!" ),
	FIELD( _field_short_integer, "cluster index!" ),
	FIELD( _field_short_integer, "cluster bsp*" ),
	FIELD( _field_char_integer, "bits and pad!" ),
	FIELD( _field_pad, "PAD1", 1 ),
	FIELD( _field_real_euler_angles_2d, "normal!" ),
	FIELD( _field_angle, "facing!" ),
	FIELD( _field_long_integer, "lastAbsoluteRejectionGameTime!" ),
	FIELD( _field_enum, "preference" ),
	FIELD( _field_pad, "post-preference", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_cue_block, k_max_ai_cues_per_level)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_integer, "quick cue*!" ),
	FIELD( _field_short_integer, "editor folder!" ),
	FIELD( _field_real_point_3d, "position!" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" ),
	FIELD( _field_real, "roll" ),
	FIELD( _field_custom, "distribution" ),
	FIELD( _field_struct, "distribution", &cue_distribution_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "payload" ),
	FIELD( _field_struct, "payload", &cue_payload_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_pad, "no-cue-definition-index", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(task_distribution_block, k_max_task_distributions_per_cue)
{
	FIELD( _field_short_block_index, "objective" ),
	FIELD( _field_custom_short_block_index, "task" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(radial_distribution_block, k_max_radial_distributions_per_cue)
{
	FIELD( _field_real, "radius" ),
	FIELD( _field_short_integer, "travel time (ticks)" ),
	FIELD( _field_pad, "post-travel-time", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(probability_distribution_block, k_max_probability_distributions_per_cue)
{
	FIELD( _field_real, "chance per second" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(character_distribution_block, k_max_character_distributions_per_cue)
{
	FIELD( _field_short_block_index, "character" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "post-flags", 1 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(weapon_distribution_block, k_max_weapon_distributions_per_cue)
{
	FIELD( _field_short_block_index, "weapon" ),
	FIELD( _field_pad, "post-weapon-palette-index", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(script_payload_block, 1)
{
	FIELD( _field_string_id, "script function name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(combat_sync_action_group_payload_block, 1)
{
	FIELD( _field_string_id, "sync action group name" ),
	FIELD( _field_real, "cooldown#seconds" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_full_cue_block, k_max_ai_cues_per_level)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_integer, "quick cue*!" ),
	FIELD( _field_short_block_index, "editor folder!" ),
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_real_euler_angles_2d, "facing!" ),
	FIELD( _field_real, "roll!" ),
	FIELD( _field_explanation, "Distribution" ),
	FIELD( _field_custom, "distribution" ),
	FIELD( _field_struct, "distribution", &cue_distribution_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "Payload" ),
	FIELD( _field_custom, "payload" ),
	FIELD( _field_struct, "payload", &cue_payload_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_long_block_index, "cue definition index!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(ai_quick_cue_block, k_max_ai_cues_per_level)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "post-flags", 1 ),
	FIELD( _field_short_block_index, "editor folder!" ),
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
	FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
	FIELD( _field_real_euler_angles_2d, "facing!" ),
	FIELD( _field_real, "roll!" ),
	FIELD( _field_block, "tasks*!", &task_distribution_block_block ),
	FIELD( _field_short_block_index, "character" ),
	FIELD( _field_short_block_index, "weapon" ),
	FIELD( _field_string_id, "template" ),
	FIELD( _field_long_block_index, "cue definition index!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cue_distribution_struct)
{
	FIELD( _field_block, "tasks*!", &task_distribution_block_block ),
	FIELD( _field_struct, "distribution", &cue_stimulus_distribution_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cue_stimulus_distribution_struct)
{
	FIELD( _field_block, "radius", &radial_distribution_block_block ),
	FIELD( _field_block, "probability", &probability_distribution_block_block ),
	FIELD( _field_block, "characters", &character_distribution_block_block ),
	FIELD( _field_block, "weapons", &weapon_distribution_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cue_payload_struct)
{
	FIELD( _field_block, "firing points", &firing_point_payload_block_block ),
	FIELD( _field_block, "script", &script_payload_block_block ),
	FIELD( _field_block, "combat sync action", &combat_sync_action_group_payload_block_block ),
	FIELD( _field_block, "stimulus", &stimulus_payload_block_block ),
	FIELD( _field_block, "combat cue", &combat_cue_payload_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

