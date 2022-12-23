#pragma once 

#define _binary_search(data, count, get_key_function, search_key, result_out) \
do \
{ \
	uint32_t search_index = 0; \
	uint32_t search_end = count - 1; \
	while (search_index <= search_end) \
	{ \
		uint32_t search_middle = (search_index + search_end) / 2; \
		auto key = get_key_function(data, search_middle); \
		if (key < search_key) \
		{ \
			search_index = search_middle + 1; \
		} \
		else if (key > search_key) \
		{ \
			search_end = search_middle - 1; \
		} \
		else /*(key == search_key)*/ \
		{ \
			result_out = data + search_middle; \
			break; \
		} \
	} \
} while(false)
