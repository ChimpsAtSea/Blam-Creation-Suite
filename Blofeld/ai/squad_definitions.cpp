#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(squad_groups, k_max_squad_groups_per_map)
{
	{ _field_string, "name^" },
	{ _field_short_block_index, "parent" },
	{ _field_short_block_index, "initial objective" },
	{ _field_pad, "soon to be an initial task", 2 },
	{ _field_short_block_index, "editor folder!" },
	{ _field_terminator },
};

TAG_BLOCK(squads, k_maximum_squads_per_map)
{
	{ _field_custom },
	{ _field_string, "name^" },
	{ _field_long_flags, "flags" },
	{ _field_enum, "team" },
	{ _field_short_block_index, "parent" },
	{ _field_short_block_index, "initial zone" },
	{ _field_short_block_index, "initial objective" },
	{ _field_custom_short_block_index, "initial task" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_block, "spawn formations!", &spawn_formation_block },
	{ _field_block, "spawn points!", &spawn_points_block },
	{ _field_long_enum, "wave placement filter#Filter which squads in Firefight waves can be spawned into this squad" },
	{ _field_string_id, "template" },
	{ _field_long_integer, "squad template index!" },
	{ _field_custom },
	{ _field_struct, "designer" },
	{ _field_struct, "templated*!" },
	{ _field_terminator },
};

TAG_BLOCK(spawn_formation, k_maximum_spawn_formations_per_squad)
{
	{ _field_struct, "place on" },
	{ _field_string_id, "name^" },
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" },
	{ _field_real, "roll" },
	{ _field_string_id, "formation" },
	{ _field_real, "initial movement distance#before doing anything else, the actor will travel the given distance in its forward direction" },
	{ _field_enum, "initial movement mode" },
	{ _field_short_integer, "placement script index!~" },
	{ _field_string_id, "placement script{Placement script}" },
	{ _field_string_id, "activity name" },
	{ _field_string_id, "movement set" },
	{ _field_custom_short_block_index, "point set" },
	{ _field_enum, "patrol mode" },
	{ _field_block, "points", &patrol_point_block },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "post-flags-pad", 3 },
	{ _field_terminator },
};

TAG_BLOCK(patrol_point, 32)
{
	{ _field_custom_short_block_index, "point^" },
	{ _field_word_flags, "flags" },
	{ _field_real, "delay:seconds#how long the AI should pause at this point" },
	{ _field_real, "angle:degrees#the angle-from-forward that the AI can pick at this point" },
	{ _field_string_id, "activity name" },
	{ _field_enum, "activity!" },
	{ _field_short_integer, "activity variant!" },
	{ _field_string_id, "command script" },
	{ _field_short_integer, "command script index*~" },
	{ _field_pad, "post-command-script", 2 },
	{ _field_terminator },
};

TAG_BLOCK(spawn_points, k_maximum_spawn_points_per_squad)
{
	{ _field_struct, "place on" },
	{ _field_string_id, "name^" },
	{ _field_custom_short_block_index, "cell" },
	{ _field_pad, "post-cell-index-pad", 2 },
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" },
	{ _field_real, "roll" },
	{ _field_word_flags, "flags" },
	{ _field_short_block_index, "character type" },
	{ _field_short_block_index, "initial weapon" },
	{ _field_short_block_index, "initial secondary weapon" },
	{ _field_short_block_index, "initial equipment" },
	{ _field_short_block_index, "vehicle type" },
	{ _field_enum, "seat type" },
	{ _field_enum, "grenade type" },
	{ _field_short_integer, "swarm count#number of cretures in swarm if a swarm is spawned at this location" },
	{ _field_pad, "post-swarm-count-pad", 2 },
	{ _field_string_id, "actor variant name" },
	{ _field_string_id, "vehicle variant name" },
	{ _field_string_id, "voice designator" },
	{ _field_real, "initial movement distance#before doing anything else, the actor will travel the given distance in its forward direction" },
	{ _field_enum, "initial movement mode" },
	{ _field_short_block_index, "emitter vehicle" },
	{ _field_short_block_index, "giant body" },
	{ _field_short_block_index, "biped body" },
	{ _field_string_id, "placement script{Placement script}" },
	{ _field_short_integer, "placement script index!~" },
	{ _field_pad, "post-placement-script-pad", 2 },
	{ _field_string_id, "activity name" },
	{ _field_string_id, "movement set" },
	{ _field_custom_short_block_index, "point set" },
	{ _field_enum, "patrol mode" },
	{ _field_block, "points", &patrol_point_block },
	{ _field_short_block_index, "vehicle body" },
	{ _field_pad, "post-vehicle_index-pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(cell_template, k_maximum_cells_per_squad)
{
	{ _field_string_id, "name^" },
	{ _field_struct, "place on" },
	{ _field_short_integer, "normal diff count#initial number of actors on normal difficulty" },
	{ _field_enum, "major upgrade" },
	{ _field_explanation, "Character Build" },
	{ _field_block, "character type", &character_ref_choice_block },
	{ _field_block, "initial weapon", &weapon_ref_choice_block },
	{ _field_block, "initial secondary weapon", &weapon_ref_choice_block },
	{ _field_block, "initial equipment", &equipment_ref_choice_block },
	{ _field_enum, "grenade type" },
	{ _field_pad, "post-grenade", 2 },
	{ _field_tag_reference, "vehicle type" },
	{ _field_string_id, "vehicle variant" },
	{ _field_string_id, "activity name" },
	{ _field_terminator },
};

TAG_BLOCK(character_ref_choice, k_maximum_palette_choices)
{
	{ _field_struct, "place on" },
	{ _field_tag_reference, "character type^" },
	{ _field_short_integer, "chance" },
	{ _field_pad, "post-chance", 2 },
	{ _field_terminator },
};

TAG_BLOCK(weapon_ref_choice, k_maximum_palette_choices)
{
	{ _field_struct, "place on" },
	{ _field_tag_reference, "weapon type^" },
	{ _field_short_integer, "chance" },
	{ _field_pad, "post-chance", 2 },
	{ _field_terminator },
};

TAG_BLOCK(equipment_ref_choice, k_maximum_palette_choices)
{
	{ _field_struct, "place on" },
	{ _field_tag_reference, "equipment type^" },
	{ _field_short_integer, "chance" },
	{ _field_pad, "post-chance", 2 },
	{ _field_terminator },
};

TAG_GROUP(squad_template, SQUAD_TEMPLATE_TAG)
{
	{ _field_string_id, "name^" },
	{ _field_block, "cell templates", &cell_template_block },
	{ _field_terminator },
};

} // namespace blofeld

