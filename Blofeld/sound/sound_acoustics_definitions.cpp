#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_acoustics_palette, k_maximum_cluster_sound_palette_entries_per_structure)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_explanation, "SOUND ENVIRONMENT" ),
	FIELD( _field_struct, "reverb" ),
	FIELD( _field_explanation, "BACKGROUND SOUND" ),
	FIELD( _field_struct, "ambience" ),
	FIELD( _field_explanation, "SOUND BANK" ),
	FIELD( _field_tag_reference, "Sound bank tag" ),
	FIELD( _field_tag_reference, "DVD Only sound bank tag" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_acoustic_sector, s_scenario_acoustic_sector::k_maximum_scenario_acoustic_sectors)
{
	FIELD( _field_block, "points", &acoustic_sector_point_block ),
	FIELD( _field_real_plane_3d, "top plane!" ),
	FIELD( _field_real_plane_3d, "bottom plane!" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "occlusion value" ),
	FIELD( _field_short_block_index, "acoustics^" ),
	FIELD( _field_short_block_index, "editor folder!" ),
	FIELD( _field_real, "height" ),
	FIELD( _field_real, "sink" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(acoustic_sector_point, k_maximum_points_per_sector)
{
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_acoustic_transition, s_scenario_acoustic_transition::k_maximum_scenario_acoustic_transitions)
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
	FIELD( _field_struct, "location 0*!" ),
	FIELD( _field_struct, "location 1*!" ),
	FIELD( _field_short_block_index, "editor folder!" ),
	FIELD( _field_pad, "CKJEWRSDF", 2 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

