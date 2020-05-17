#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(squad_template, SQUAD_TEMPLATE_TAG)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "cell templates", &cell_template_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(squad_groups_block, k_max_squad_groups_per_map)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_short_block_index, "parent" ),
		FIELD( _field_short_block_index, "initial objective" ),
		FIELD( _field_pad, "soon to be an initial task", 2 ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(patrol_point_block, 32)
	{
		FIELD( _field_custom_short_block_index, "point^" ),
		FIELD( _field_word_flags, "flags", &patrol_point_flags ),
		FIELD( _field_real, "delay:seconds#how long the AI should pause at this point" ),
		FIELD( _field_real, "angle:degrees#the angle-from-forward that the AI can pick at this point" ),
		FIELD( _field_string_id, "activity name" ),
		FIELD( _field_enum, "activity!", &g_activity_enum ),
		FIELD( _field_short_integer, "activity variant!" ),
		FIELD( _field_string_id, "command script" ),
		FIELD( _field_short_integer, "command script index*~" ),
		FIELD( _field_pad, "post-command-script", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(spawn_formation_block, k_maximum_spawn_formations_per_squad)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
		FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
		FIELD( _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" ),
		FIELD( _field_real, "roll" ),
		FIELD( _field_string_id, "formation" ),
		FIELD( _field_real, "initial movement distance#before doing anything else, the actor will travel the given distance in its forward direction" ),
		FIELD( _field_enum, "initial movement mode", &actor_movement_modes ),
		FIELD( _field_short_integer, "placement script index!~" ),
		FIELD( _field_string_id, "placement script{Placement script}" ),
		FIELD( _field_string_id, "activity name" ),
		FIELD( _field_string_id, "movement set" ),
		FIELD( _field_custom_short_block_index, "point set" ),
		FIELD( _field_enum, "patrol mode", &patrol_mode_enum ),
		FIELD( _field_block, "points", &patrol_point_block_block ),
		FIELD( _field_byte_flags, "flags", &spawn_formation_flags ),
		FIELD( _field_pad, "post-flags-pad", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(spawn_points_block, k_maximum_spawn_points_per_squad)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_custom_short_block_index, "cell" ),
		FIELD( _field_pad, "post-cell-index-pad", 2 ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
		FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
		FIELD( _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" ),
		FIELD( _field_real, "roll" ),
		FIELD( _field_word_flags, "flags", &starting_location_flags ),
		FIELD( _field_short_block_index, "character type" ),
		FIELD( _field_short_block_index, "initial weapon" ),
		FIELD( _field_short_block_index, "initial secondary weapon" ),
		FIELD( _field_short_block_index, "initial equipment" ),
		FIELD( _field_short_block_index, "vehicle type" ),
		FIELD( _field_enum, "seat type", &ai_placement_seat_preference_enum ),
		FIELD( _field_enum, "grenade type", &global_ai_grenade_type_enum ),
		FIELD( _field_short_integer, "swarm count#number of cretures in swarm if a swarm is spawned at this location" ),
		FIELD( _field_pad, "post-swarm-count-pad", 2 ),
		FIELD( _field_string_id, "actor variant name" ),
		FIELD( _field_string_id, "vehicle variant name" ),
		FIELD( _field_string_id, "voice designator" ),
		FIELD( _field_real, "initial movement distance#before doing anything else, the actor will travel the given distance in its forward direction" ),
		FIELD( _field_enum, "initial movement mode", &actor_movement_modes ),
		FIELD( _field_short_block_index, "emitter vehicle" ),
		FIELD( _field_short_block_index, "giant body" ),
		FIELD( _field_short_block_index, "biped body" ),
		FIELD( _field_string_id, "placement script{Placement script}" ),
		FIELD( _field_short_integer, "placement script index!~" ),
		FIELD( _field_pad, "post-placement-script-pad", 2 ),
		FIELD( _field_string_id, "activity name" ),
		FIELD( _field_string_id, "movement set" ),
		FIELD( _field_custom_short_block_index, "point set" ),
		FIELD( _field_enum, "patrol mode", &patrol_mode_enum ),
		FIELD( _field_block, "points", &patrol_point_block_block ),
		FIELD( _field_short_block_index, "vehicle body" ),
		FIELD( _field_pad, "post-vehicle_index-pad", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(character_palette_choice_block, k_maximum_palette_choices)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_short_block_index, "character type^" ),
		FIELD( _field_custom ),
		FIELD( _field_short_integer, "chance" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(weapon_palette_choice_block, k_maximum_palette_choices)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_short_block_index, "weapon type^" ),
		FIELD( _field_custom ),
		FIELD( _field_short_integer, "chance" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(equipment_palette_choice_block, k_maximum_palette_choices)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_short_block_index, "equipment type^" ),
		FIELD( _field_custom ),
		FIELD( _field_short_integer, "chance" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cell_block, k_maximum_cells_per_squad)
	{
		FIELD( _field_explanation, "Character Build" ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_short_integer, "normal diff count#initial number of actors on normal difficulty" ),
		FIELD( _field_enum, "major upgrade", &major_upgrade_enum ),
		FIELD( _field_block, "character type", &character_palette_choice_block_block ),
		FIELD( _field_block, "initial weapon", &weapon_palette_choice_block_block ),
		FIELD( _field_block, "initial secondary weapon", &weapon_palette_choice_block_block ),
		FIELD( _field_block, "initial equipment", &equipment_palette_choice_block_block ),
		FIELD( _field_enum, "grenade type", &global_ai_grenade_type_enum ),
		FIELD( _field_short_block_index, "vehicle type" ),
		FIELD( _field_string_id, "vehicle variant" ),
		FIELD( _field_string_id, "Placement script" ),
		FIELD( _field_short_integer, "placement script index!~" ),
		FIELD( _field_pad, "plsc", 2 ),
		FIELD( _field_string_id, "activity name" ),
		FIELD( _field_string_id, "movement set" ),
		FIELD( _field_custom_short_block_index, "point set" ),
		FIELD( _field_enum, "patrol mode", &patrol_mode_enum ),
		FIELD( _field_block, "points!", &patrol_point_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(squads_block, k_maximum_squads_per_map)
	{
		FIELD( _field_custom ),
		FIELD( _field_string, "name^" ),
		FIELD( _field_long_flags, "flags", &squad_flags ),
		FIELD( _field_enum, "team", &ai_team_enum ),
		FIELD( _field_short_block_index, "parent" ),
		FIELD( _field_short_block_index, "initial zone" ),
		FIELD( _field_short_block_index, "initial objective" ),
		FIELD( _field_custom_short_block_index, "initial task" ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_block, "spawn formations!", &spawn_formation_block_block ),
		FIELD( _field_block, "spawn points!", &spawn_points_block_block ),
		FIELD( _field_long_enum, "wave placement filter#Filter which squads in Firefight waves can be spawned into this squad", &wave_placement_filter_enum ),
		FIELD( _field_string_id, "template" ),
		FIELD( _field_long_integer, "squad template index!" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "designer", &squad_definition_internal_struct_struct_definition ),
		FIELD( _field_struct, "templated*!", &squad_definition_internal_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(character_ref_choice_block, k_maximum_palette_choices)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_tag_reference, "character type^" ),
		FIELD( _field_short_integer, "chance" ),
		FIELD( _field_pad, "post-chance", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(weapon_ref_choice_block, k_maximum_palette_choices)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_tag_reference, "weapon type^" ),
		FIELD( _field_short_integer, "chance" ),
		FIELD( _field_pad, "post-chance", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(equipment_ref_choice_block, k_maximum_palette_choices)
	{
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_tag_reference, "equipment type^" ),
		FIELD( _field_short_integer, "chance" ),
		FIELD( _field_pad, "post-chance", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(cell_template_block, k_maximum_cells_per_squad)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition ),
		FIELD( _field_short_integer, "normal diff count#initial number of actors on normal difficulty" ),
		FIELD( _field_enum, "major upgrade", &major_upgrade_enum ),
		FIELD( _field_explanation, "Character Build" ),
		FIELD( _field_block, "character type", &character_ref_choice_block_block ),
		FIELD( _field_block, "initial weapon", &weapon_ref_choice_block_block ),
		FIELD( _field_block, "initial secondary weapon", &weapon_ref_choice_block_block ),
		FIELD( _field_block, "initial equipment", &equipment_ref_choice_block_block ),
		FIELD( _field_enum, "grenade type", &global_ai_grenade_type_enum ),
		FIELD( _field_pad, "post-grenade", 2 ),
		FIELD( _field_tag_reference, "vehicle type" ),
		FIELD( _field_string_id, "vehicle variant" ),
		FIELD( _field_string_id, "activity name" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(squad_definition_internal_struct)
	{
		FIELD( _field_block, "cells", &cell_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(patrol_point_flags, 1)
	{
		OPTION("single use"),
	};

	TAG_ENUM(patrol_mode_enum, 3)
	{
		OPTION("ping-pong"),
		OPTION("loop"),
		OPTION("random"),
	};

	TAG_ENUM(starting_location_flags, 9)
	{
		OPTION("infection form explode"),
		OPTION("n/a"),
		OPTION("always place"),
		OPTION("initially hidden"),
		OPTION("vehicle destroyed when no driver"),
		OPTION("vehicle open"),
		OPTION("actor surface emerge"),
		OPTION("actor surface emerge auto"),
		OPTION("actor surface emerge upwards"),
	};

	TAG_ENUM(ai_placement_seat_preference_enum, 8)
	{
		OPTION("DEFAULT"),
		OPTION("passenger"),
		OPTION("gunner"),
		OPTION("driver"),
		OPTION("small cargo"),
		OPTION("large cargo"),
		OPTION("NO driver"),
		OPTION("NO vehicle"),
	};

	TAG_ENUM(actor_movement_modes, 3)
	{
		OPTION("default"),
		OPTION("climbing"),
		OPTION("flying"),
	};

	TAG_ENUM(major_upgrade_enum, 5)
	{
		OPTION("normal"),
		OPTION("few"),
		OPTION("many"),
		OPTION("none"),
		OPTION("all"),
	};

	TAG_ENUM(squad_flags, 9)
	{
		OPTION("unused"),
		OPTION("blind"),
		OPTION("deaf"),
		OPTION("braindead"),
		OPTION("initially placed"),
		OPTION("units not enterable by player"),
		OPTION("fireteam absorber"),
		OPTION("squad is runtime(DO NOT USE)!"),
		OPTION("no wave spawn"),
	};

	TAG_ENUM(spawn_formation_flags, 1)
	{
		OPTION("no vertical offset for flying"),
	};

	TAG_ENUM(g_activity_enum, 31)
	{
		OPTION("none"),
		OPTION("patrol"),
		OPTION("stand"),
		OPTION("crouch"),
		OPTION("stand_drawn"),
		OPTION("crouch_drawn"),
		OPTION("combat"),
		OPTION("backup"),
		OPTION("guard"),
		OPTION("guard_crouch"),
		OPTION("guard_wall"),
		OPTION("typing"),
		OPTION("kneel"),
		OPTION("gaze"),
		OPTION("poke"),
		OPTION("sniff"),
		OPTION("track"),
		OPTION("watch"),
		OPTION("examine"),
		OPTION("sleep"),
		OPTION("at_ease"),
		OPTION("cower"),
		OPTION("tai_chi"),
		OPTION("pee"),
		OPTION("doze"),
		OPTION("eat"),
		OPTION("medic"),
		OPTION("work"),
		OPTION("cheering"),
		OPTION("injured"),
		OPTION("captured"),
	};

	TAG_ENUM(ai_team_enum, 9)
	{
		OPTION("default"),
		OPTION("player"),
		OPTION("human"),
		OPTION("covenant"),
		OPTION("brute"),
		OPTION("mule"),
		OPTION("spare"),
		OPTION("covenant_player"),
		OPTION("forerunner"),
	};

} // namespace blofeld

