#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_acoustics_palette, k_maximum_cluster_sound_palette_entries_per_structure)
{
	{ _field_string_id, "name^" },
	{ _field_explanation, "SOUND ENVIRONMENT" },
	{ _field_struct, "reverb" },
	{ _field_explanation, "BACKGROUND SOUND" },
	{ _field_struct, "ambience" },
	{ _field_explanation, "SOUND BANK" },
	{ _field_tag_reference, "Sound bank tag" },
	{ _field_tag_reference, "DVD Only sound bank tag" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_acoustic_sector, s_scenario_acoustic_sector::k_maximum_scenario_acoustic_sectors)
{
	{ _field_block, "points", &acoustic_sector_point_block },
	{ _field_real_plane_3d, "top plane!" },
	{ _field_real_plane_3d, "bottom plane!" },
	{ _field_long_flags, "flags" },
	{ _field_real, "occlusion value" },
	{ _field_short_block_index, "acoustics^" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_real, "height" },
	{ _field_real, "sink" },
	{ _field_terminator },
};

TAG_BLOCK(acoustic_sector_point, k_maximum_points_per_sector)
{
	{ _field_real_point_3d, "position" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_acoustic_transition, s_scenario_acoustic_transition::k_maximum_scenario_acoustic_transitions)
{
	{ _field_real_point_3d, "center!" },
	{ _field_real_point_3d, "forward!" },
	{ _field_real_point_3d, "up!" },
	{ _field_real, "half width!" },
	{ _field_real, "half height!" },
	{ _field_real, "sample point offset 0!" },
	{ _field_real, "sample point offset 1!" },
	{ _field_short_block_index, "sample 0*" },
	{ _field_short_block_index, "sample 1*" },
	{ _field_struct, "location 0*!" },
	{ _field_struct, "location 1*!" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_pad, "CKJEWRSDF", 2 },
	{ _field_terminator },
};

} // namespace blofeld

