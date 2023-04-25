#pragma once

typedef struct mopp_box_request
{
	float half_extents_x;
	float half_extents_y;
	float half_extents_z;
} s_mopp_box_request;

typedef struct mopp_box_result
{
	void* mopp_codes;
	unsigned int mopp_codes_bytes;
	unsigned int* hit_index_to_shape_index;
	unsigned int* shape_index_to_hit_index;
	float code_info_x;
	float code_info_y;
	float code_info_z;
	float code_info_w;
	unsigned char build_type;
} s_mopp_box_result;
typedef s_mopp_box_result const* t_mopp_box_result;

BCS_SHARED t_mopp_box_result box_mopps_request(s_mopp_box_request* mopp_box_requests, unsigned int num_box_requests);
BCS_SHARED void box_mopps_destroy(t_mopp_box_result mopp_box_result);
