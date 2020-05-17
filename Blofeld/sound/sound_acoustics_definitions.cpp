#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK_FROM_STRUCT(scenario_acoustics_palette_block_definition, k_maximum_cluster_sound_palette_entries_per_structure, scenario_acoustics_palette_block_definition_struct_struct_definition );

	TAG_BLOCK(acoustic_sector_point_block, k_maximum_points_per_sector)
	{
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_acoustic_sector_block, s_scenario_acoustic_sector::k_maximum_scenario_acoustic_sectors)
	{
		FIELD( _field_block, "points", &acoustic_sector_point_block_block ),
		FIELD( _field_real_plane_3d, "top plane!" ),
		FIELD( _field_real_plane_3d, "bottom plane!" ),
		FIELD( _field_long_flags, "flags", &acousticPaletteFlags ),
		FIELD( _field_real, "occlusion value" ),
		FIELD( _field_short_block_index, "acoustics^" ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_real, "height" ),
		FIELD( _field_real, "sink" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_acoustic_transition_block, s_scenario_acoustic_transition::k_maximum_scenario_acoustic_transitions)
	{
		FIELD( _field_real_point_3d, "center!" ),
		FIELD( _field_real_point_3d, "forward!" ),
		FIELD( _field_real_point_3d, "up!" ),
		FIELD( _field_real, "half width!" ),
		FIELD( _field_real, "half height!" ),
		FIELD( _field_real, "sample point offset 0!" ),
		FIELD( _field_real, "sample point offset 1!" ),
		FIELD( _field_short_block_index, "sample 0*" ),
		FIELD( _field_short_block_index, "sample 1*" ),
		FIELD( _field_struct, "location 0*!", &scenario_acoustic_location_definition_struct_definition ),
		FIELD( _field_struct, "location 1*!", &scenario_acoustic_location_definition_struct_definition ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_pad, "CKJEWRSDF", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_acoustics_palette_block_definition_struct)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_explanation, "SOUND ENVIRONMENT" ),
		FIELD( _field_struct, "reverb", &scenario_acoustics_environment_definition_struct_definition ),
		FIELD( _field_explanation, "BACKGROUND SOUND" ),
		FIELD( _field_struct, "ambience", &scenario_acoustics_ambience_definition_struct_definition ),
		FIELD( _field_explanation, "SOUND BANK" ),
		FIELD( _field_tag_reference, "Sound bank tag" ),
		FIELD( _field_tag_reference, "DVD Only sound bank tag" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_acoustics_environment_definition)
	{
		FIELD( _field_tag_reference, "sound environment" ),
		FIELD( _field_long_enum, "type", &sound_class_acoustics_string_definition ),
		FIELD( _field_real, "cutoff distance" ),
		FIELD( _field_real, "interpolation time{interpolation speed}:seconds" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_acoustics_ambience_definition)
	{
		FIELD( _field_tag_reference, "background sound" ),
		FIELD( _field_tag_reference, "weather sound#plays when rain is active, weather rate gets applied to scale." ),
		FIELD( _field_tag_reference, "entry sound#plays when entering this area" ),
		FIELD( _field_tag_reference, "exit sound#plays when leaving this area" ),
		FIELD( _field_real, "cutoff distance" ),
		FIELD( _field_real, "interpolation time{interpolation speed}:seconds" ),
		FIELD( _field_long_flags, "scale flags DEPRICATED!", &background_sound_scale_flags_definition ),
		FIELD( _field_real_fraction, "interior scale DEPRICATED!" ),
		FIELD( _field_real_fraction, "portal scale DEPRICATED!" ),
		FIELD( _field_real_fraction, "exterior scale DEPRICATED!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_acoustic_location_definition)
	{
		FIELD( _field_short_block_index, "sector index*!" ),
		FIELD( _field_struct, "cluster reference*!", &scenario_acoustic_cluster_reference_definition_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_acoustic_cluster_reference_definition)
	{
		FIELD( _field_char_integer, "bsp index*!" ),
		FIELD( _field_byte_integer, "cluster index*!" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(background_sound_scale_flags_definition, 4)
	{
		OPTION("override default scale"),
		OPTION("use adjacent cluster as portal scale"),
		OPTION("use adjacent cluster as exterior scale"),
		OPTION("scale with weather intensity"),
	};

	TAG_ENUM(acousticPaletteFlags, 2)
	{
		OPTION("occlude if above"),
		OPTION("occlude if below"),
	};

} // namespace blofeld

