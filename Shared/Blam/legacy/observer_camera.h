#pragma once

struct s_observer_camera
{
	real_vector3d position;
	real_vector3d position_shift;
	float look;
	float look_shift;
	float depth;
	float unknown0;
	real_vector3d forward;
	real_vector3d up;
	float field_of_view;
	float unknown1;
	float unknown2;
};
