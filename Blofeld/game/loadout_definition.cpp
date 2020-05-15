#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(loadout_definition, k_maximum_loadouts)
{
	{ _field_string_id, "loadout name^" },
	{ _field_string_id, "app1#name of an element from custom_app_globals/custom_apps.  Can be left empty." },
	{ _field_string_id, "app2#see above" },
	{ _field_string_id, "initial primary weapon#name of an element from global starting weapons block. Other values:\n(empty) - unchanged\nunchanged - unchanged\ndefault - take from starting profiles in scenario\nnone - no weapon\nrandom - use random item from valid starting weapons" },
	{ _field_string_id, "initial primary weapon variant name" },
	{ _field_string_id, "initial secondary weapon#see above" },
	{ _field_string_id, "initial secondary weapon variant name" },
	{ _field_string_id, "initial equipment#see above" },
	{ _field_char_enum, "initial grenade count" },
	{ _field_pad, "SDJCESLRN", 3 },
	{ _field_terminator },
};

TAG_BLOCK(loadout_palette_definition, k_maximum_loadout_palettes)
{
	{ _field_string_id, "palette name" },
	{ _field_block, "loadout choices", &loadout_index_block },
	{ _field_terminator },
};

TAG_BLOCK(loadout_index, k_maximum_loadouts_per_palette)
{
	{ _field_short_block_index, "loadout^" },
	{ _field_pad, "padding0", 2 },
	{ _field_terminator },
};

TAG_BLOCK(loadout_name, k_maximum_loadout_names)
{
	{ _field_string_id, "display name^" },
	{ _field_terminator },
};

TAG_BLOCK(custom_loadout_defaults, k_maximum_loadout_custom_slot_count)
{
	{ _field_string_id, "loadout name^" },
	{ _field_string_id, "app1#name of an element from custom_app_globals/custom_apps.  Can be left empty." },
	{ _field_string_id, "app2#see above" },
	{ _field_string_id, "initial primary weapon#name of an element from global starting weapons block. Other values:\n(empty) - unchanged\nunchanged - unchanged\ndefault - take from starting profiles in scenario\nnone - no weapon\nrandom - use random item from valid starting weapons" },
	{ _field_string_id, "initial primary weapon variant name" },
	{ _field_string_id, "initial secondary weapon#see above" },
	{ _field_string_id, "initial secondary weapon variant name" },
	{ _field_string_id, "initial equipment#see above" },
	{ _field_char_enum, "initial grenade count" },
	{ _field_pad, "SDJCESLRN", 3 },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_loadout_options, 1)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "DLVKJSER", 3 },
	{ _field_block, "loadout palettes", &game_engine_loadout_palette_entry_block },
	{ _field_terminator },
};

TAG_BLOCK(game_engine_loadout_palette_entry, k_maximum_game_engine_static_loadout_palettes)
{
	{ _field_string_id, "palette name^" },
	{ _field_terminator },
};

TAG_GROUP(loadout_globals_definition, LOADOUT_GLOBALS_DEFINITION_TAG)
{
	{ _field_block, "loadouts", &loadout_definition_block },
	{ _field_block, "loadout palettes", &loadout_palette_definition_block },
	{ _field_block, "loadout names", &loadout_name_block },
	{ _field_block, "default custom loadouts", &custom_loadout_defaults_block },
	{ _field_terminator },
};

} // namespace blofeld

