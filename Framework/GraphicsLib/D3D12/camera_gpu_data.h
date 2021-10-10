#pragma once

struct r_camera_d3d12
{
	float4x4 view_perspective;
	float4x4 view_perspective_transposed;
	float4x4 inverse_view_perspective;
	float4x4 perspective_transposed;
	float4x4 view_transposed;
	float4x4 perspective;
	float4x4 view;
	float4 position;
	float4 view_position;
	float2 feedback_scan_offset;
	float near_distance;
	float far_distance;
	int feedback_scan_offset_mask;
	int frame_index;
};
