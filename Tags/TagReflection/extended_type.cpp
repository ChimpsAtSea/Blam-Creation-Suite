#include "tagreflection-private-pch.h"

h_extended_type::h_extended_type(
	h_type* parent,
	unsigned char _global_vftable_index,
	unsigned short _local_vftable_index) :
	h_type(parent)
{
	__global_vftable_index = _global_vftable_index;
	__local_vftable_index = _local_vftable_index;
	debug_point;
}
