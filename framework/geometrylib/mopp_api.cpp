#include "geometrylib-private-pch.h"

t_mopp_box_result box_mopps_request(s_mopp_box_request* mopp_box_requests, unsigned int num_box_requests)
{
	if (mopp_box_requests == nullptr || num_box_requests == 0)
	{
		return nullptr;
	}

	return nullptr;
}

void box_mopps_destroy(t_mopp_box_result mopp_box_result_handle)
{
	s_mopp_box_result* mopp_box_result = const_cast<s_mopp_box_result*>(mopp_box_result_handle);

	if (mopp_box_result->mopp_codes)
	{
		delete[] mopp_box_result->mopp_codes;
	}
	if (mopp_box_result->hit_index_to_shape_index)
	{
		delete[] mopp_box_result->hit_index_to_shape_index;
	}
	if (mopp_box_result->shape_index_to_hit_index)
	{
		delete[] mopp_box_result->shape_index_to_hit_index;
	}

	delete mopp_box_result;
}
