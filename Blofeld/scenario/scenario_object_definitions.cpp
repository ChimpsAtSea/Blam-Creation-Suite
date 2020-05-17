#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(scenario_object_node_orientations_bit_vector_block, 2*(((((MAXIMUM_NODES_PER_MODEL)+(k_int32_bits-1))>>k_int32_bits_bits))*sizeof(int32)))
	{
		FIELD( _field_byte_integer, "data*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_object_node_orientations_orientations_block, MAXIMUM_NODES_PER_MODEL*7)
	{
		FIELD( _field_short_integer, "number*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_object_node_orientations_block, 1)
	{
		FIELD( _field_short_integer, "node count*!" ),
		FIELD( _field_pad, "paddington", 2 ),
		FIELD( _field_block, "bit vector*!", &scenario_object_node_orientations_bit_vector_block_block ),
		FIELD( _field_block, "orientations*!", &scenario_object_node_orientations_orientations_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scriptListBlock, k_maximum_hs_source_files_per_context)
	{
		FIELD( _field_string_id, "script name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(commandLinkBlock, CommandDispatcher::MAX_LINKS)
	{
		FIELD( _field_long_enum, "Trigger^", &internal_event_enum_definition ),
		FIELD( _field_long_block_index, "Target" ),
		FIELD( _field_long_enum, "Command", &command_event_enum_definition ),
		FIELD( _field_real, "Delay (sec)" ),
		FIELD( _field_long_flags, "Flags", &commandLinkFlags ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(pathfinding_object_index_list_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_short_integer, "bsp index" ),
		FIELD( _field_short_integer, "pathfinding object index" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_scenery_block, MAXIMUM_SCENERY_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "scenery data", &scenario_scenery_datum_struct_v4_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_scenery_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_biped_block, MAXIMUM_BIPED_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "unit data", &scenario_unit_struct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_biped_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_vehicle_block, MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "unit data", &scenario_unit_struct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_struct, "vehicle data", &scenario_vehicle_datum_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_vehicle_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_equipment_block, MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "equipment data", &scenario_equipment_datum_struct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_equipment_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_weapon_block, MAXIMUM_WEAPON_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "weapon data", &scenario_weapon_datum_struct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_weapon_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(device_group_block, MAXIMUM_DEVICE_GROUPS_PER_SCENARIO)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_real, "initial value:[0,1]" ),
		FIELD( _field_long_flags, "flags", &device_group_flags ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_pad, "WAFNDIO", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_machine_block, MAXIMUM_MACHINE_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "device data", &scenario_device_struct_struct_definition ),
		FIELD( _field_struct, "machine data", &scenario_machine_struct_v3_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_machine_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_terminal_block, MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "device data", &scenario_device_struct_struct_definition ),
		FIELD( _field_struct, "terminal data", &scenario_terminal_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_terminal_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_control_block, MAXIMUM_CONTROL_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "device data", &scenario_device_struct_struct_definition ),
		FIELD( _field_struct, "control data", &scenario_control_struct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_control_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(ScenarioDispenserBlock, MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "device data", &scenario_device_struct_struct_definition ),
		FIELD( _field_struct, "dispenser data", &ScenarioDispenserStruct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(ScenarioDispenserPaletteBlock, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_sound_scenery_block, MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "sound_scenery", &sound_scenery_datum_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_sound_scenery_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_giant_block, MAXIMUM_GIANT_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "unit data", &scenario_unit_struct_struct_definition ),
		FIELD( _field_struct, "giant data", &scenario_giant_datum_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_giant_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_effect_scenery_block, MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "effect scenery data", &scenario_effect_scenery_datum_struct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_effect_scenery_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_spawner_block, MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "Entity Data", &ScenarioEntityStruct_struct_definition ),
		FIELD( _field_struct, "Spawner Data", &ScenarioSpawnerStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_spawner_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_requisition_palette_block, MAXIMUM_REQUISITION_MENU_SIZE)
	{
		FIELD( _field_explanation, "CUSTOM APPS" ),
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_tag_reference, "second name^" ),
		FIELD( _field_tag_reference, "third name^" ),
		FIELD( _field_string_id, "display_name^" ),
		FIELD( _field_long_enum, "Submenu#controls which requisition submenu this object should appear in", &requisition_submenu_global_enum ),
		FIELD( _field_long_integer, "maximum allowed#cant buy more if there are too many in play" ),
		FIELD( _field_real, "price per instance" ),
		FIELD( _field_string_id, "model variant name" ),
		FIELD( _field_real, "bounty for destruction" ),
		FIELD( _field_short_integer, "min fireteam tier#0=Bronze, 1=Silver, or 2=Gold" ),
		FIELD( _field_byte_integer, "additional frag grenades" ),
		FIELD( _field_byte_integer, "additional plasma grenades" ),
		FIELD( _field_long_flags, "built-in palettes for which item is enabled by default", &scenario_requisition_palette_presence ),
		FIELD( _field_long_enum, "special buy", &requisition_special_buy_enum ),
		FIELD( _field_long_integer, "starting ammo#1..100 for ammoless weapons, 0 = default for all weapons" ),
		FIELD( _field_real, "warm-up time:seconds#item will be unavailable until x seconds into the scenario" ),
		FIELD( _field_real, "player purchase frequency:seconds" ),
		FIELD( _field_real, "team purchase frequency:seconds" ),
		FIELD( _field_real, "price increase factor#price = original-price x increase-factor to-the n_times_bought" ),
		FIELD( _field_byte_integer, "maximum buy count:per player" ),
		FIELD( _field_byte_integer, "total maximum buy count:per team" ),
		FIELD( _field_pad, "SMYE", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_crate_block, MAXIMUM_CRATE_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition ),
		FIELD( _field_struct, "crate data", &scenario_crate_datum_struct_struct_definition ),
		FIELD( _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_crate_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_creature_block, MAXIMUM_CREATURE_DATUMS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "type" ),
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_struct, "object data", &scenario_object_datum_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_creature_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_object_id_struct)
	{
		FIELD( _field_long_integer, "unique id*" ),
		FIELD( _field_short_block_index, "origin bsp index*" ),
		FIELD( _field_char_enum, "type*", &object_type_enum_definition ),
		FIELD( _field_char_enum, "source*", &object_source_enum_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_object_reference_struct)
	{
		FIELD( _field_short_integer, "object index*" ),
		FIELD( _field_short_integer, "scenario object index*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_object_datum_struct)
	{
		FIELD( _field_custom ),
		FIELD( _field_long_flags, "placement flags", &object_location_placement_flags ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_real_euler_angles_3d, "rotation" ),
		FIELD( _field_real, "scale" ),
		FIELD( _field_block, "node orientations!*", &scenario_object_node_orientations_block_block ),
		FIELD( _field_real, "gravity override" ),
		FIELD( _field_byte_flags, "gravity flags", &object_gravity_flags ),
		FIELD( _field_pad, "ZEE", 1 ),
		FIELD( _field_char_enum, "bsp policy", &scenario_object_bsp_placement_policy_definition ),
		FIELD( _field_byte_flags, "script flags", &scenarioObjectScriptFlagsDefinition ),
		FIELD( _field_block, "force enabled scripts", &scriptListBlock_block ),
		FIELD( _field_block, "disabled scripts", &scriptListBlock_block ),
		FIELD( _field_struct, "manual bsp flags*", &manualBspFlagsReferences_struct_definition ),
		FIELD( _field_word_flags, "transform flags!", &object_transform_flags ),
		FIELD( _field_char_enum, "Nav Mesh Cutting", &NavMeshCuttingOverrideEnum ),
		FIELD( _field_char_enum, "Nav Mesh Obstacle", &BooleanOverrideEnum ),
		FIELD( _field_byte_flags, "Nav Mesh Flags", &object_navmesh_flags ),
		FIELD( _field_pad, "ZEE2", 3 ),
		FIELD( _field_string_id, "light airprobe name" ),
		FIELD( _field_struct, "object id", &scenario_object_id_struct_struct_definition ),
		FIELD( _field_long_flags, "Light Channels:", &channelDefinitionFlags ),
		FIELD( _field_non_cache_runtime_value, "runtimeObjectHandle!*" ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_pad, "NCIUNE", 2 ),
		FIELD( _field_struct, "parent id", &scenario_object_parent_struct_struct_definition ),
		FIELD( _field_long_block_flags, "can attach to bsp flags*!" ),
		FIELD( _field_real, "Directional Acceleration Mult. #Multiplier applied to all phantoms\' direction acceleration factors.  Used to scale man-cannon strength." ),
		FIELD( _field_block, "Command Links", &commandLinkBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_object_parent_struct)
	{
		FIELD( _field_pad, "der", 2 ),
		FIELD( _field_short_block_index, "parent object#if an object with this name exists, we attach to it as a child" ),
		FIELD( _field_string_id, "parent marker" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "connection marker" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_object_permutation_struct)
	{
		FIELD( _field_string_id, "variant name" ),
		FIELD( _field_byte_flags, "active change colors", &scenario_object_active_change_color_flags ),
		FIELD( _field_pad, "SLCJNEROH", 3 ),
		FIELD( _field_rgb_color, "primary color" ),
		FIELD( _field_rgb_color, "secondary color" ),
		FIELD( _field_rgb_color, "tertiary color" ),
		FIELD( _field_rgb_color, "quaternary color" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_scenery_datum_struct_v4)
	{
		FIELD( _field_custom ),
		FIELD( _field_enum, "Pathfinding policy", &pathfinding_policy_enum ),
		FIELD( _field_enum, "Lightmapping policy", &scenery_lightmap_policy_enum ),
		FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
		FIELD( _field_short_integer, "havok mopp index!" ),
		FIELD( _field_short_block_index, "ai spawning squad" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_multiplayer_object_struct)
	{
		FIELD( _field_explanation, "Multiplayer Data" ),
		FIELD( _field_string, "megalo label" ),
		FIELD( _field_string, "megalo label 2" ),
		FIELD( _field_string, "megalo label 3" ),
		FIELD( _field_string, "megalo label 4" ),
		FIELD( _field_char_enum, "game engine symmetric placement", &game_engine_symmetry_placement_flags ),
		FIELD( _field_byte_flags, "game engine flags", &global_game_engine_type_flags ),
		FIELD( _field_char_enum, "owner team", &global_multiplayer_team_designator_enum_definition ),
		FIELD( _field_byte_flags, "spawn flags", &multiplayer_object_placement_spawn_flags ),
		FIELD( _field_char_integer, "quota minimum" ),
		FIELD( _field_char_integer, "quota maximum:<=0 for unlimited" ),
		FIELD( _field_char_enum, "remapping policy", &multiplayer_object_remapping_policy ),
		FIELD( _field_char_enum, "teleporter channel", &multiplayer_teleporter_channel ),
		FIELD( _field_byte_flags, "teleporter passability", &teleporter_passability_flags ),
		FIELD( _field_char_integer, "spawn order:-1 for random" ),
		FIELD( _field_char_integer, "user data 2" ),
		FIELD( _field_char_enum, "trait zone channel", &multiplayer_teleporter_channel ),
		FIELD( _field_real, "boundary width or radius" ),
		FIELD( _field_real, "boundary box length" ),
		FIELD( _field_real, "boundary positive height" ),
		FIELD( _field_real, "boundary negative height" ),
		FIELD( _field_char_enum, "boundary shape", &multiplayer_goal_area_boundary_shape_enum ),
		FIELD( _field_pad, "boundary_pad", 3 ),
		FIELD( _field_short_integer, "spawn time:seconds" ),
		FIELD( _field_short_integer, "abandonment time:seconds" ),
		FIELD( _field_string_id, "location name" ),
		FIELD( _field_struct, "map variant parent", &scenario_object_parent_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_unit_struct)
	{
		FIELD( _field_real, "body vitality:[0,1]" ),
		FIELD( _field_long_flags, "flags", &scenario_unit_datum_flags ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_vehicle_datum_struct)
	{
		FIELD( _field_enum, "Pathfinding policy", &pathfinding_policy_enum ),
		FIELD( _field_pad, "post-pathfinding", 2 ),
		FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_equipment_datum_struct)
	{
		FIELD( _field_long_flags, "equipment flags", &scenario_equipment_flags_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_weapon_datum_struct)
	{
		FIELD( _field_short_integer, "rounds left" ),
		FIELD( _field_short_integer, "rounds loaded" ),
		FIELD( _field_long_flags, "flags", &scenario_weapon_datum_flags ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_device_struct)
	{
		FIELD( _field_short_block_index, "power group" ),
		FIELD( _field_short_block_index, "position group" ),
		FIELD( _field_long_flags, "flags", &scenario_device_flags ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_machine_struct_v3)
	{
		FIELD( _field_long_flags, "flags", &scenario_machine_flags ),
		FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
		FIELD( _field_enum, "pathfinding policy", &scenario_machine_pathfinding_policy_enum ),
		FIELD( _field_pad, "post-pathfinding-policy", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_terminal_struct)
	{
		FIELD( _field_long_integer, "pah pah" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_control_struct)
	{
		FIELD( _field_long_flags, "flags", &scenario_control_flags ),
		FIELD( _field_short_integer, "DON\'T TOUCH THIS!*" ),
		FIELD( _field_short_integer, "health station charges#if this control is a health station, this sets the number of charges it contains.\nUse 0 for infinite" ),
		FIELD( _field_enum, "allowed players", &scenario_control_character_types ),
		FIELD( _field_pad, "SCSP1", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(ScenarioDispenserStruct)
	{
		FIELD( _field_byte_flags, "flags", &ScenarioDispenserFlags ),
		FIELD( _field_pad, "pad", 3 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(sound_scenery_datum_struct)
	{
		FIELD( _field_long_enum, "volume type", &sound_volume_type_enumeration ),
		FIELD( _field_real, "height" ),
		FIELD( _field_angle_bounds, "override cone angle bounds" ),
		FIELD( _field_real, "override outer cone gain:dB" ),
		FIELD( _field_struct, "override distance parameters", &sound_distance_parameters_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_giant_datum_struct)
	{
		FIELD( _field_enum, "Pathfinding policy", &pathfinding_policy_enum ),
		FIELD( _field_pad, "post-pathfinding", 2 ),
		FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_effect_scenery_datum_struct)
	{
		FIELD( _field_real, "effect size scale" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(ScenarioEntityStruct)
	{
		FIELD( _field_real, "Entity Placeholder" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(ScenarioSpawnerStruct)
	{
		FIELD( _field_real, "Spawner Placeholder" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_crate_datum_struct)
	{
		FIELD( _field_enum, "Pathfinding policy", &pathfinding_policy_enum ),
		FIELD( _field_pad, "post-path-policy", 2 ),
		FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(object_location_placement_flags, 15)
	{
		OPTION("not automatically"),
		OPTION("unused0"),
		OPTION("unused1"),
		OPTION("unused2"),
		OPTION("lock type to env. object"),
		OPTION("lock transform to env. object"),
		OPTION("never placed"),
		OPTION("lock name to env. object"),
		OPTION("create at rest"),
		OPTION("store orientations"),
		OPTION("pvs bound"),
		OPTION("startup"),
		OPTION("attach physically"),
		OPTION("attach with scale"),
		OPTION("no parent lighting"),
	};

	TAG_ENUM(object_gravity_flags, 2)
	{
		OPTION("apply override"),
		OPTION("apply to children also"),
	};

	TAG_ENUM(object_navmesh_flags, 2)
	{
		OPTION("children inherit navmesh interaction"),
		OPTION("navmesh always loaded"),
	};

	TAG_ENUM(object_transform_flags, 1)
	{
		OPTION("mirrored"),
	};

	TAG_ENUM(scenario_object_active_change_color_flags, 4)
	{
		OPTION("primary"),
		OPTION("secondary"),
		OPTION("tertiary"),
		OPTION("quaternary"),
	};

	TAG_ENUM(scenarioObjectScriptFlagsDefinition, 3)
	{
		OPTION("scripts disabled"),
		OPTION("use override lists"),
		OPTION("scripts always run"),
	};

	TAG_ENUM(object_type_enum_definition, 16)
	{
		OPTION("biped"),
		OPTION("vehicle"),
		OPTION("weapon"),
		OPTION("equipment"),
		OPTION("terminal"),
		OPTION("projectile"),
		OPTION("scenery"),
		OPTION("machine"),
		OPTION("control"),
		OPTION("dispenser"),
		OPTION("sound_scenery"),
		OPTION("crate"),
		OPTION("creature"),
		OPTION("giant"),
		OPTION("effect_scenery"),
		OPTION("spawner"),
	};

	TAG_ENUM(object_source_enum_definition, 6)
	{
		OPTION("structure"),
		OPTION("editor"),
		OPTION("dynamic"),
		OPTION("legacy"),
		OPTION("sky"),
		OPTION("parent"),
	};

	TAG_ENUM(command_event_enum_definition, 3)
	{
		OPTION("Interact"),
		OPTION("InitShardSpawn"),
		OPTION("InitKnightTaint"),
	};

	TAG_ENUM(internal_event_enum_definition, 5)
	{
		OPTION("OnBirth"),
		OPTION("OnDeath"),
		OPTION("OnInteract"),
		OPTION("OnInitSpawnerShard"),
		OPTION("OnInitKnightTaint"),
	};

	TAG_ENUM(commandLinkFlags, 1)
	{
		OPTION("Fire Once"),
	};

	TAG_ENUM(scenario_object_bsp_placement_policy_definition, 3)
	{
		OPTION("default"),
		OPTION("always placed"),
		OPTION("manual bsp placement"),
	};

	TAG_ENUM(game_engine_symmetry_placement_flags, 3)
	{
		OPTION("ignore"),
		OPTION("symmetric"),
		OPTION("asymmetric"),
	};

	TAG_ENUM(global_game_engine_type_flags, 6)
	{
		OPTION("none"),
		OPTION("sandbox"),
		OPTION("megalogamengine"),
		OPTION("campaign"),
		OPTION("survival"),
		OPTION("firefight"),
	};

	TAG_ENUM(multiplayer_object_remapping_policy, 3)
	{
		OPTION("normal-default"),
		OPTION("do not replace"),
		OPTION("only replace"),
	};

	TAG_ENUM(multiplayer_goal_area_boundary_shape_enum, 4)
	{
		OPTION("unused"),
		OPTION("sphere"),
		OPTION("cylinder"),
		OPTION("box"),
	};

	TAG_ENUM(multiplayer_teleporter_channel, 26)
	{
		OPTION("alpha"),
		OPTION("bravo"),
		OPTION("charlie"),
		OPTION("delta"),
		OPTION("echo"),
		OPTION("foxtrot"),
		OPTION("golf"),
		OPTION("hotel"),
		OPTION("india"),
		OPTION("juliet"),
		OPTION("kilo"),
		OPTION("lima"),
		OPTION("mike"),
		OPTION("november"),
		OPTION("oscar"),
		OPTION("papa"),
		OPTION("quebec"),
		OPTION("romeo"),
		OPTION("sierra"),
		OPTION("tango"),
		OPTION("uniform"),
		OPTION("victor"),
		OPTION("whiskey"),
		OPTION("xray"),
		OPTION("yankee"),
		OPTION("zulu"),
	};

	TAG_ENUM(multiplayer_object_placement_spawn_flags, 6)
	{
		OPTION("unique spawn"),
		OPTION("not initially placed"),
		OPTION("hide unless megalo required"),
		OPTION("is shortcut object"),
		OPTION("can spawn on bipeds"),
		OPTION("spawner starts inactive"),
	};

	TAG_ENUM(pathfinding_policy_enum, 5)
	{
		OPTION("Tag Default"),
		OPTION("Pathfinding DYNAMIC"),
		OPTION("Pathfinding CUT-OUT"),
		OPTION("Pathfinding STATIC"),
		OPTION("Pathfinding NONE"),
	};

	TAG_ENUM(scenery_lightmap_policy_enum, 3)
	{
		OPTION("Tag Default"),
		OPTION("Dynamic"),
		OPTION("Per-Vertex"),
	};

	TAG_ENUM(scenario_equipment_flags_definition, 3)
	{
		OPTION("OBSOLETE0"),
		OPTION("OBSOLETE1"),
		OPTION("does accelerate (moves due to explosions)"),
	};

	TAG_ENUM(scenario_weapon_datum_flags, 3)
	{
		OPTION("initially at rest (doesn\'t fall)"),
		OPTION("obsolete"),
		OPTION("does accelerate (moves due to explosions)"),
	};

	TAG_ENUM(scenario_unit_datum_flags, 3)
	{
		OPTION("dead"),
		OPTION("opened"),
		OPTION("not enterable by player"),
	};

	TAG_ENUM(requisition_submenu_global_enum, 1)
	{
		OPTION("Support"),
	};

	TAG_ENUM(scenario_requisition_palette_presence, 4)
	{
		OPTION("empty palette"),
		OPTION("full palette"),
		OPTION("spartan palette"),
		OPTION("elite palette"),
	};

	TAG_ENUM(device_group_flags, 1)
	{
		OPTION("can change only once"),
	};

	TAG_ENUM(scenario_device_flags, 6)
	{
		OPTION("initially open (1.0)"),
		OPTION("initially off (0.0)"),
		OPTION("can change only once"),
		OPTION("position reversed"),
		OPTION("not usable from any side"),
		OPTION("closes without power"),
	};

	TAG_ENUM(scenario_machine_flags, 8)
	{
		OPTION("does not operate automatically"),
		OPTION("one-sided"),
		OPTION("never appears locked"),
		OPTION("opened by melee attack"),
		OPTION("one-sided for player"),
		OPTION("does not close automatically"),
		OPTION("ignores player"),
		OPTION("ignores ai"),
	};

	TAG_ENUM(scenario_machine_pathfinding_policy_enum, 5)
	{
		OPTION("default"),
		OPTION("discs"),
		OPTION("sectors"),
		OPTION("cut-out"),
		OPTION("none"),
	};

	TAG_ENUM(scenario_control_flags, 1)
	{
		OPTION("usable from both sides"),
	};

	TAG_ENUM(scenario_control_character_types, 3)
	{
		OPTION("any"),
		OPTION("spartan"),
		OPTION("elite"),
	};

	TAG_ENUM(ScenarioDispenserFlags, 1)
	{
		OPTION("usable from front only"),
	};

	TAG_ENUM(sound_volume_type_enumeration, 3)
	{
		OPTION("sphere"),
		OPTION("vertical cylinder"),
		OPTION("pill{volume pill}"),
	};

} // namespace blofeld

