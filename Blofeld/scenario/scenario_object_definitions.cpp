#include <blofeld-private-pch.h>

namespace blofeld
{

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

TAG_BLOCK(scenario_object_node_orientations_block, 1)
{
	FIELD( _field_short_integer, "node count*!" ),
	FIELD( _field_pad, "paddington", 2 ),
	FIELD( _field_block, "bit vector*!", &scenario_object_node_orientations_bit_vector_block_block ),
	FIELD( _field_block, "orientations*!", &scenario_object_node_orientations_orientations_block_block ),
	FIELD( _field_terminator )
};

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

TAG_BLOCK(scriptListBlock, k_maximum_hs_source_files_per_context)
{
	FIELD( _field_string_id, "script name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(commandLinkBlock, CommandDispatcher::MAX_LINKS)
{
	FIELD( _field_long_enum, "Trigger^" ),
	FIELD( _field_long_block_index, "Target" ),
	FIELD( _field_long_enum, "Command" ),
	FIELD( _field_real, "Delay (sec)" ),
	FIELD( _field_long_flags, "Flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(pathfinding_object_index_list_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	FIELD( _field_short_integer, "bsp index" ),
	FIELD( _field_short_integer, "pathfinding object index" ),
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
	FIELD( _field_long_flags, "flags" ),
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
	FIELD( _field_long_enum, "Submenu#controls which requisition submenu this object should appear in" ),
	FIELD( _field_long_integer, "maximum allowed#cant buy more if there are too many in play" ),
	FIELD( _field_real, "price per instance" ),
	FIELD( _field_string_id, "model variant name" ),
	FIELD( _field_real, "bounty for destruction" ),
	FIELD( _field_short_integer, "min fireteam tier#0=Bronze, 1=Silver, or 2=Gold" ),
	FIELD( _field_byte_integer, "additional frag grenades" ),
	FIELD( _field_byte_integer, "additional plasma grenades" ),
	FIELD( _field_long_flags, "built-in palettes for which item is enabled by default" ),
	FIELD( _field_long_enum, "special buy" ),
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
	FIELD( _field_char_enum, "type*" ),
	FIELD( _field_char_enum, "source*" ),
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
	FIELD( _field_long_flags, "placement flags" ),
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_real_euler_angles_3d, "rotation" ),
	FIELD( _field_real, "scale" ),
	FIELD( _field_block, "node orientations!*", &scenario_object_node_orientations_block_block ),
	FIELD( _field_real, "gravity override" ),
	FIELD( _field_byte_flags, "gravity flags" ),
	FIELD( _field_pad, "ZEE", 1 ),
	FIELD( _field_char_enum, "bsp policy" ),
	FIELD( _field_byte_flags, "script flags" ),
	FIELD( _field_block, "force enabled scripts", &scriptListBlock_block ),
	FIELD( _field_block, "disabled scripts", &scriptListBlock_block ),
	FIELD( _field_struct, "manual bsp flags*", &manualBspFlagsReferences_struct_definition ),
	FIELD( _field_word_flags, "transform flags!" ),
	FIELD( _field_char_enum, "Nav Mesh Cutting" ),
	FIELD( _field_char_enum, "Nav Mesh Obstacle" ),
	FIELD( _field_byte_flags, "Nav Mesh Flags" ),
	FIELD( _field_pad, "ZEE2", 3 ),
	FIELD( _field_string_id, "light airprobe name" ),
	FIELD( _field_struct, "object id", &scenario_object_id_struct_struct_definition ),
	FIELD( _field_long_flags, "Light Channels:" ),
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
	FIELD( _field_byte_flags, "active change colors" ),
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
	FIELD( _field_enum, "Pathfinding policy" ),
	FIELD( _field_enum, "Lightmapping policy" ),
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
	FIELD( _field_char_enum, "game engine symmetric placement" ),
	FIELD( _field_byte_flags, "game engine flags" ),
	FIELD( _field_char_enum, "owner team" ),
	FIELD( _field_byte_flags, "spawn flags" ),
	FIELD( _field_char_integer, "quota minimum" ),
	FIELD( _field_char_integer, "quota maximum:<=0 for unlimited" ),
	FIELD( _field_char_enum, "remapping policy" ),
	FIELD( _field_char_enum, "teleporter channel" ),
	FIELD( _field_byte_flags, "teleporter passability" ),
	FIELD( _field_char_integer, "spawn order:-1 for random" ),
	FIELD( _field_char_integer, "user data 2" ),
	FIELD( _field_char_enum, "trait zone channel" ),
	FIELD( _field_real, "boundary width or radius" ),
	FIELD( _field_real, "boundary box length" ),
	FIELD( _field_real, "boundary positive height" ),
	FIELD( _field_real, "boundary negative height" ),
	FIELD( _field_char_enum, "boundary shape" ),
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
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_vehicle_datum_struct)
{
	FIELD( _field_enum, "Pathfinding policy" ),
	FIELD( _field_pad, "post-pathfinding", 2 ),
	FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_equipment_datum_struct)
{
	FIELD( _field_long_flags, "equipment flags" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_weapon_datum_struct)
{
	FIELD( _field_short_integer, "rounds left" ),
	FIELD( _field_short_integer, "rounds loaded" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_device_struct)
{
	FIELD( _field_short_block_index, "power group" ),
	FIELD( _field_short_block_index, "position group" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_machine_struct_v3)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
	FIELD( _field_enum, "pathfinding policy" ),
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
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_short_integer, "DON\'T TOUCH THIS!*" ),
	FIELD( _field_short_integer, "health station charges#if this control is a health station, this sets the number of charges it contains.\nUse 0 for infinite" ),
	FIELD( _field_enum, "allowed players" ),
	FIELD( _field_pad, "SCSP1", 2 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(ScenarioDispenserStruct)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_scenery_datum_struct)
{
	FIELD( _field_long_enum, "volume type" ),
	FIELD( _field_real, "height" ),
	FIELD( _field_angle_bounds, "override cone angle bounds" ),
	FIELD( _field_real, "override outer cone gain:dB" ),
	FIELD( _field_struct, "override distance parameters", &sound_distance_parameters_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_giant_datum_struct)
{
	FIELD( _field_enum, "Pathfinding policy" ),
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
	FIELD( _field_enum, "Pathfinding policy" ),
	FIELD( _field_pad, "post-path-policy", 2 ),
	FIELD( _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

