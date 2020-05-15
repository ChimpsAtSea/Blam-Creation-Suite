#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_scenery, MAXIMUM_SCENERY_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "scenery data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_scenery_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_biped, MAXIMUM_BIPED_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "unit data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_biped_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_vehicle, MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "unit data" },
	{ _field_struct, "multiplayer data" },
	{ _field_struct, "vehicle data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_vehicle_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_equipment, MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "equipment data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_equipment_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_weapon, MAXIMUM_WEAPON_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "weapon data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_weapon_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(device_group, MAXIMUM_DEVICE_GROUPS_PER_SCENARIO)
{
	{ _field_string, "name^" },
	{ _field_real, "initial value:[0,1]" },
	{ _field_long_flags, "flags" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_pad, "WAFNDIO", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_machine, MAXIMUM_MACHINE_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "device data" },
	{ _field_struct, "machine data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_machine_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_terminal, MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "device data" },
	{ _field_struct, "terminal data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_terminal_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_control, MAXIMUM_CONTROL_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "device data" },
	{ _field_struct, "control data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_control_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(ScenarioDispenserBlock, MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "device data" },
	{ _field_struct, "dispenser data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(ScenarioDispenserPaletteBlock, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_sound_scenery, MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "sound_scenery" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_sound_scenery_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_giant, MAXIMUM_GIANT_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "unit data" },
	{ _field_struct, "giant data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_giant_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_effect_scenery, MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "effect scenery data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_effect_scenery_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_spawner, MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "Entity Data" },
	{ _field_struct, "Spawner Data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_spawner_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_requisition_palette, MAXIMUM_REQUISITION_MENU_SIZE)
{
	{ _field_explanation, "CUSTOM APPS" },
	{ _field_tag_reference, "name^" },
	{ _field_tag_reference, "second name^" },
	{ _field_tag_reference, "third name^" },
	{ _field_string_id, "display_name^" },
	{ _field_long_enum, "Submenu#controls which requisition submenu this object should appear in" },
	{ _field_long_integer, "maximum allowed#cant buy more if there are too many in play" },
	{ _field_real, "price per instance" },
	{ _field_string_id, "model variant name" },
	{ _field_real, "bounty for destruction" },
	{ _field_short_integer, "min fireteam tier#0=Bronze, 1=Silver, or 2=Gold" },
	{ _field_byte_integer, "additional frag grenades" },
	{ _field_byte_integer, "additional plasma grenades" },
	{ _field_long_flags, "built-in palettes for which item is enabled by default" },
	{ _field_long_enum, "special buy" },
	{ _field_long_integer, "starting ammo#1..100 for ammoless weapons, 0 = default for all weapons" },
	{ _field_real, "warm-up time:seconds#item will be unavailable until x seconds into the scenario" },
	{ _field_real, "player purchase frequency:seconds" },
	{ _field_real, "team purchase frequency:seconds" },
	{ _field_real, "price increase factor#price = original-price x increase-factor to-the n_times_bought" },
	{ _field_byte_integer, "maximum buy count:per player" },
	{ _field_byte_integer, "total maximum buy count:per team" },
	{ _field_pad, "SMYE", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_crate, MAXIMUM_CRATE_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_struct, "permutation data" },
	{ _field_struct, "crate data" },
	{ _field_struct, "multiplayer data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_crate_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_creature, MAXIMUM_CREATURE_DATUMS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "type" },
	{ _field_custom },
	{ _field_short_block_index, "name^" },
	{ _field_struct, "object data" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_creature_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

} // namespace blofeld

