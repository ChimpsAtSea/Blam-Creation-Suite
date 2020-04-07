#pragma once

struct nicename("camera_track") tag_group('trak') s_camera_track_definition
{
	struct nicename("Camera Points") s_camera_points_definition
	{
		float nicename("Position i") position_i;
		float nicename("Position j") position_j;
		float nicename("Position k") position_k;
		float nicename("Orientation i") orientation_i;
		float nicename("Orientation j") orientation_j;
		float nicename("Orientation k") orientation_k;
		float nicename("Orientation w") orientation_w;
	};

	Undefined32 __unknown0;
	s_tag_block_definition<s_camera_points_definition> nicename("Camera Points") camera_points_block;
};

