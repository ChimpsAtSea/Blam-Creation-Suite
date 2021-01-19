#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(loadout_globals_definition, LOADOUT_GLOBALS_DEFINITION_TAG, loadout_globals_definition_block_block );

	V5_TAG_BLOCK(game_engine_loadout_palette_entry_block, k_maximum_game_engine_static_loadout_palettes)
	{
		{ _field_string_id, "palette name^" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(game_engine_loadout_options_block, 1)
	{
		{ _field_byte_flags, "flags", &loadout_flags_definition },
		{ _field_pad, "DLVKJSER", 3 },
		{ _field_block, "loadout palettes", &game_engine_loadout_palette_entry_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(loadout_definition_block, k_maximum_loadouts, loadout_definition_struct_struct_definition );

	V5_TAG_BLOCK(loadout_index_block, k_maximum_loadouts_per_palette)
	{
		{ _field_short_block_index, "loadout^" },
		{ _field_pad, "padding0", 2 },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(loadout_palette_definition_block, k_maximum_loadout_palettes)
	{
		{ _field_string_id, "palette name" },
		{ _field_block, "loadout choices", &loadout_index_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(loadout_name_block, k_maximum_loadout_names)
	{
		{ _field_string_id, "display name^" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(custom_loadout_defaults_block, k_maximum_loadout_custom_slot_count, loadout_definition_struct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(loadout_globals_definition_block, 1, loadout_globals_definition_struct_definition_struct_definition );

	V5_TAG_STRUCT(loadout_globals_definition_struct_definition)
	{
		{ _field_block, "loadouts", &loadout_definition_block_block },
		{ _field_block, "loadout palettes", &loadout_palette_definition_block_block },
		{ _field_block, "loadout names", &loadout_name_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "default custom loadouts", &custom_loadout_defaults_block_block },

		{ _field_terminator }
	};

	V5_TAG_STRUCT(loadout_definition_struct)
	{
		{ _field_string_id, "loadout name^" },
		
		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_string_id, "app1#name of an element from custom_app_globals/custom_apps.  Can be left empty." },
		{ _field_string_id, "app2#see above" },
		
		{ _field_string_id, "initial primary weapon#name of an element from global starting weapons block. Other values:\n(empty) - unchanged\nunchanged - unchanged\ndefault - take from starting profiles in scenario\nnone - no weapon\nrandom - use random item from valid starting weapons" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "initial primary weapon variant name" },

		{ _field_string_id, "initial secondary weapon#see above" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "initial secondary weapon variant name" },

		{ _field_string_id, "initial equipment#see above" },
		{ _field_char_enum, "initial grenade count", &player_trait_initial_grenade_count_enum },
		{ _field_pad, "SDJCESLRN", 3 },
		{ _field_terminator }
	};

	STRINGS(loadout_flags_definition)
	{
		"custom loadouts enabled",
		"spartan loadouts enabled",
		"elite loadouts enabled",
		"map loadouts enabled"
	};
	STRING_LIST(loadout_flags_definition, loadout_flags_definition_strings, _countof(loadout_flags_definition_strings));

	TAG_REFERENCE(global_loadout_globals_reference, LOADOUT_GLOBALS_DEFINITION_TAG);

} // namespace blofeld

