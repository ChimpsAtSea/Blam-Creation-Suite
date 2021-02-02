#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_BLOCK_FROM_STRUCT(
		scenario_acoustics_palette_block_definition_block,
		"scenario_acoustics_palette_block_definition",
		k_maximum_cluster_sound_palette_entries_per_structure,
		scenario_acoustics_palette_block_definition_struct);

	#define SCENARIO_ACOUSTIC_SECTOR_BLOCK_STRUCT_ID { 0xED9F5D9C, 0xFBD64377, 0x93DCA409, 0xD6DDDBB8 }
	TAG_BLOCK(
		scenario_acoustic_sector_block,
		"scenario_acoustic_sector_block",
		s_scenario_acoustic_sector::k_maximum_scenario_acoustic_sectors,
		"s_scenario_acoustic_sector",
		SCENARIO_ACOUSTIC_SECTOR_BLOCK_STRUCT_ID)
	{
		{ _field_block, "points", &acoustic_sector_point_block },
		{ _field_real_plane_3d, "top plane" },
		{ _field_real_plane_3d, "bottom plane" },
		{ _field_long_flags, "flags", &acousticPaletteFlags },
		{ _field_real, "occlusion value" },
		{ _field_short_block_index, "acoustics", &scenario_acoustics_palette_block_definition_block },
		{ _field_short_block_index, "editor folder", &g_scenario_editor_folder_block },
		{ _field_real, "height" },
		{ _field_real, "sink" },
		{ _field_terminator }
	};

	#define ACOUSTIC_SECTOR_POINT_BLOCK_ID { 0x4A9991E9, 0x655449F3, 0xA90B1648, 0x795B9508 }
	TAG_BLOCK(
		acoustic_sector_point_block,
		"acoustic_sector_point_block",
		k_maximum_points_per_sector,
		"s_acoustic_sector_point",
		ACOUSTIC_SECTOR_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_terminator }
	};

	#define SCENARIO_ACOUSTIC_TRANSITION_BLOCK_STRUCT_ID { 0xA2CCEB01, 0x558A4A16, 0x963B2BAC, 0x2F917EB4 }
	TAG_BLOCK(
		scenario_acoustic_transition_block,
		"scenario_acoustic_transition_block",
		s_scenario_acoustic_transition::k_maximum_scenario_acoustic_transitions,
		"s_scenario_acoustic_transition",
		SCENARIO_ACOUSTIC_TRANSITION_BLOCK_STRUCT_ID)
	{
		{ _field_real_point_3d, "center" },
		{ _field_real_point_3d, "forward" },
		{ _field_real_point_3d, "up" },
		{ _field_real, "half width" },
		{ _field_real, "half height" },
		{ _field_real, "sample point offset 0" },
		{ _field_real, "sample point offset 1" },
		{ _field_short_block_index, "sample 0", &scenario_acoustics_palette_block_definition_block },
		{ _field_short_block_index, "sample 1", &scenario_acoustics_palette_block_definition_block },
		{ _field_struct, "location 0", &scenario_acoustic_location_definition },
		{ _field_struct, "location 1", &scenario_acoustic_location_definition },
		{ _field_short_block_index, "editor folder", &g_scenario_editor_folder_block },
		FIELD_PAD("CKJEWRSDF", nullptr, 2),
		{ _field_terminator }
	};

	#define SCENARIO_ACOUSTICS_PALETTE_BLOCK_DEFINITION_STRUCT_ID { 0xCADEB9A2, 0x119B467B, 0x82D36013, 0xDE6C1794 }
	TAG_STRUCT(
		scenario_acoustics_palette_block_definition_struct,
		"scenario_acoustics_palette_block_definition_struct",
		"s_scenario_acoustics_palette_entry",
		SCENARIO_ACOUSTICS_PALETTE_BLOCK_DEFINITION_STRUCT_ID)
	{
		{ _field_string_id, "name" },
		{ _field_explanation, "SOUND ENVIRONMENT", "" },
		{ _field_struct, "reverb", &scenario_acoustics_environment_definition },
		{ _field_explanation, "BACKGROUND SOUND", "" },
		{ _field_struct, "ambience", &scenario_acoustics_ambience_definition },
		{ _field_explanation, "SOUND BANK", "" },
		{ _field_tag_reference, "Sound bank tag", &global_soundbank_reference },
		{ _field_tag_reference, "DVD Only sound bank tag", &global_soundbank_reference },
		{ _field_terminator }
	};

	#define SCENARIO_ACOUSTICS_ENVIRONMENT_DEFINITION_ID { 0x718F78F4, 0x7FB14DA7, 0x88A566D2, 0x3608B533 }
	TAG_STRUCT(
		scenario_acoustics_environment_definition,
		"scenario_acoustics_environment_definition",
		"s_scenario_acoustics_environment",
		SCENARIO_ACOUSTICS_ENVIRONMENT_DEFINITION_ID)
	{
		{ _field_tag_reference, "sound environment", &global_sound_environment_reference },
		{ _field_long_enum, "type", &sound_class_acoustics_string_definition },
		{ _field_real, "cutoff distance" },
		{ _field_real, "interpolation time", "seconds" },
		{ _field_terminator }
	};

	#define SCENARIO_ACOUSTICS_AMBIENCE_DEFINITION_ID { 0x35137799, 0x93F24E9E, 0x81364E61, 0xE072BBAB }
	TAG_STRUCT(
		scenario_acoustics_ambience_definition,
		"scenario_acoustics_ambience_definition",
		"s_scenario_acoustics_ambience",
		SCENARIO_ACOUSTICS_AMBIENCE_DEFINITION_ID)
	{
		{ _field_tag_reference, "background sound", &global_looping_sound_reference },
		{ _field_tag_reference, "weather sound", &global_looping_sound_reference },
		{ _field_tag_reference, "entry sound", &global_sound_reference },
		{ _field_tag_reference, "exit sound", &global_sound_reference },
		{ _field_real, "cutoff distance" },
		{ _field_real, "interpolation time", "seconds" },
		{ _field_long_flags, "scale flags DEPRICATED", &background_sound_scale_flags_definition },
		{ _field_real_fraction, "interior scale DEPRICATED" },
		{ _field_real_fraction, "portal scale DEPRICATED" },
		{ _field_real_fraction, "exterior scale DEPRICATED" },
		{ _field_terminator }
	};

	#define SCENARIO_ACOUSTIC_LOCATION_DEFINITION_ID { 0xDEE4A7BC, 0xF61B4AED, 0xB8F89514, 0x79034AFF }
	TAG_STRUCT(
		scenario_acoustic_location_definition,
		"scenario_acoustic_location_definition",
		"s_scenario_acoustic_location",
		SCENARIO_ACOUSTIC_LOCATION_DEFINITION_ID)
	{
		{ _field_short_block_index, "sector index", &scenario_acoustic_sector_block },
		{ _field_struct, "cluster reference", &scenario_acoustic_cluster_reference_definition },
		{ _field_terminator }
	};

	#define SCENARIO_ACOUSTIC_CLUSTER_REFERENCE_DEFINITION_ID { 0xCD19EBEB, 0x3BC64C0C, 0x86924A34, 0x74C2621D }
	TAG_STRUCT(
		scenario_acoustic_cluster_reference_definition,
		"scenario_acoustic_cluster_reference_definition",
		"s_cluster_reference",
		SCENARIO_ACOUSTIC_CLUSTER_REFERENCE_DEFINITION_ID)
	{
		{ _field_char_integer, "bsp index" },
		{ _field_byte_integer, "cluster index" },
		{ _field_terminator }
	};

	STRINGS(background_sound_scale_flags_definition)
	{
		"override default scale",
		"use adjacent cluster as portal scale",
		"use adjacent cluster as exterior scale",
		"scale with weather intensity"
	};
	STRING_LIST(background_sound_scale_flags_definition, background_sound_scale_flags_definition_strings, _countof(background_sound_scale_flags_definition_strings));

	STRINGS(acousticPaletteFlags)
	{
		"occlude if above",
		"occlude if below"
	};
	STRING_LIST(acousticPaletteFlags, acousticPaletteFlags_strings, _countof(acousticPaletteFlags_strings));

} // namespace macaque

} // namespace blofeld

