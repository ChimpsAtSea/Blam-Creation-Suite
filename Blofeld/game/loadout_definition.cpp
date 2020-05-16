#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(loadout_globals_definition_struct_definition)
{
	FIELD( _field_block, "loadouts", &loadout_definition_block ),
	FIELD( _field_block, "loadout palettes", &loadout_palette_definition_block ),
	FIELD( _field_block, "loadout names", &loadout_name_block ),
	FIELD( _field_block, "default custom loadouts", &custom_loadout_defaults_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(loadout_definition_struct)
{
	FIELD( _field_string_id, "loadout name^" ),
	FIELD( _field_string_id, "app1#name of an element from custom_app_globals/custom_apps.  Can be left empty." ),
	FIELD( _field_string_id, "app2#see above" ),
	FIELD( _field_string_id, "initial primary weapon#name of an element from global starting weapons block. Other values:\n(empty) - unchanged\nunchanged - unchanged\ndefault - take from starting profiles in scenario\nnone - no weapon\nrandom - use random item from valid starting weapons" ),
	FIELD( _field_string_id, "initial primary weapon variant name" ),
	FIELD( _field_string_id, "initial secondary weapon#see above" ),
	FIELD( _field_string_id, "initial secondary weapon variant name" ),
	FIELD( _field_string_id, "initial equipment#see above" ),
	FIELD( _field_char_enum, "initial grenade count" ),
	FIELD( _field_pad, "SDJCESLRN", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_loadout_options_block, 1)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "DLVKJSER", 3 ),
	FIELD( _field_block, "loadout palettes", &game_engine_loadout_palette_entry_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_loadout_palette_entry_block, k_maximum_game_engine_static_loadout_palettes)
{
	FIELD( _field_string_id, "palette name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(loadout_definition_block, k_maximum_loadouts, loadout_definition_struct_struct_definition );

TAG_BLOCK(loadout_palette_definition_block, k_maximum_loadout_palettes)
{
	FIELD( _field_string_id, "palette name" ),
	FIELD( _field_block, "loadout choices", &loadout_index_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(loadout_index_block, k_maximum_loadouts_per_palette)
{
	FIELD( _field_short_block_index, "loadout^" ),
	FIELD( _field_pad, "padding0", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(loadout_name_block, k_maximum_loadout_names)
{
	FIELD( _field_string_id, "display name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(custom_loadout_defaults_block, k_maximum_loadout_custom_slot_count, loadout_definition_struct_struct_definition );

TAG_GROUP(loadout_globals_definition_block, LOADOUT_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_block, "loadouts", &loadout_definition_block ),
	FIELD( _field_block, "loadout palettes", &loadout_palette_definition_block ),
	FIELD( _field_block, "loadout names", &loadout_name_block ),
	FIELD( _field_block, "default custom loadouts", &custom_loadout_defaults_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

