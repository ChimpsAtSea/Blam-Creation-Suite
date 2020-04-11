#pragma once

struct nicename("camera_track") tag_group('trak') s_camera_track_definition_legacy
{
	struct nicename("Camera Points") s_camera_points_definition_legacy
	{
		float nicename("Position i") position_i;
		float nicename("Position j") position_j;
		float nicename("Position k") position_k;
		float nicename("Orientation i") orientation_i;
		float nicename("Orientation j") orientation_j;
		float nicename("Orientation k") orientation_k;
		float nicename("Orientation w") orientation_w;
	};

	s_undefined32_legacy __unknown0;
	s_tag_block_legacy<s_camera_points_definition_legacy> nicename("Camera Points") camera_points_block;
};

